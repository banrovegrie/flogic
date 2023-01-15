from typing import List
from copy import deepcopy
from pprint import pprint
from enum import Enum
from collections import defaultdict
import networkx as nx
import time
import math
import numpy as np
from pprint import pprint

def rotate(point, angle):
    """
    Rotate a point counterclockwise by a given angle around a given origin.

    The angle should be given in radians.
    """
    px, py = point

    qx = math.cos(angle) * (px ) - math.sin(angle) * (py)
    qy = math.sin(angle) * (px) + math.cos(angle) * (py)
    return qx, qy

class Orientation(Enum):
    UP = 0
    DOWN = 1

class Pentagon:
    def __init__(self, pentagon_id, orientation, edge_no, parent_pentagon, center):
        self.pentagon_id = pentagon_id
        self.orientation: orientation = orientation
        self.edges = [0, 0, 0, 0, 0]
        self.edges[edge_no] = parent_pentagon
        self.center = center

    def get_edges(self):
        return self.edges
    
    def use_edge(self, edge, parent_pentagon):
        self.edges[edge] = parent_pentagon

    def get_free_edges(self):
        free_edges = [idx for idx, e in enumerate(self.edges) if e == 0]
        return free_edges

    def __repr__(self):
        return f"({self.pentagon_id} ⬆️ {self.orientation} * {self.edges})"

# 0 up facing
# 1 down facing
# DOWN
#0 0, 1.61803398875
#1 -1.5388417685877, 0.50000000000003
#2 -0.95105651629522, -1.309016994375
#3 0.95105651629522, -1.309016994375
#4 1.5388417685877, 0.50000000000003
pent_offset = {
    Orientation.UP : [(0, -1.61803398875),
     (1.5388417685877, -0.50000000000003), 
     (0.95105651629522, 1.309016994375), 
     (-0.95105651629522, 1.309016994375), 
     (-1.5388417685877, -0.50000000000003)],
    Orientation.DOWN: [(0, 1.61803398875), 
     (-1.5388417685877, 0.50000000000003),
     (-0.95105651629522, -1.309016994375),
     (0.95105651629522, -1.309016994375),
     (1.5388417685877, 0.50000000000003)]
}

def euc_add(c1, c2):
    return (c1[0] + c2[0], c1[1] + c2[1])

def euc_sub(c1, c2):
    return (c1[0] - c2[0], c1[1] - c2[1])

def euc_round(c1, x):
    return round(c1[0], x), round(c1[1], x)

def new_pentagon_info(pentagon, edge):
    return euc_add(pent_offset[pentagon.orientation][edge], pentagon.center)

def euc_dist(c1, c2):
    return math.sqrt((c1[0] - c2[0]) ** 2 + (c1[1] - c2[1]) ** 2)

def check_no_collision(center, chain):
    # check if distance of new center from all other centers is > 1
    return all(euc_dist(center, pentagon.center) >= 1.6180339887 for pentagon in chain.pentagons)

# UP
#0 0, -1.61803398875
#1 1.5388417685877, -0.50000000000003
#2 0.95105651629522, 1.309016994375
#3 -0.95105651629522, 1.309016994375
#4 -1.5388417685877, -0.50000000000003





class PentagonChain:
    def __init__(self):
        self.pentagons = [Pentagon(1, Orientation.UP, 0, 0, (0.0, 0.0))]


    def generate_new_chains(self):
        chains = []
        pentagon_id = len(self.pentagons) + 1
        for pentagon in self.pentagons:
            for edge in pentagon.get_free_edges():
                new_center = new_pentagon_info(pentagon, edge)
                if not check_no_collision(new_center, self):
                    continue
                new_chain = deepcopy(self)
                new_orientation = Orientation.DOWN if pentagon.orientation == Orientation.UP else Orientation.UP
                new_pentagon = Pentagon(pentagon_id, new_orientation, edge, pentagon.pentagon_id, new_center)
                new_chain.pentagons[pentagon.pentagon_id - 1].use_edge(edge, new_pentagon.pentagon_id)
                new_chain.pentagons.append(new_pentagon)
                chains.append(new_chain)
        return chains

    def __repr__(self):
        return "------------\n" + "\n".join([str(pentagon) for pentagon in self.pentagons]) + "\n"


def remove_isomorphic_chains(chains):
    mp = defaultdict(list)
    l = len(chains)
    # print(chains)
    t0 = time.time()
    rotator = lambda t: np.matmul(t, np.array([[np.cos(np.pi / 5), -np.sin(np.pi / 5)], [np.sin(np.pi / 5), np.cos(np.pi / 5)]]))
    vfunc = np.vectorize(rotator)
    for idx, chain in enumerate(chains):
        # print(chain)
        for pentagon in chain.pentagons:
            new_origin = pentagon.center
            new_centers = np.array([euc_sub(c.center, new_origin) for c in chain.pentagons])
            # print(new_centers)
            for _ in range(10):
                new_centers = [np.matmul(t, np.array([[np.cos(np.pi / 5), -np.sin(np.pi / 5)], [np.sin(np.pi / 5), np.cos(np.pi / 5)]])) for t in new_centers]
                rounded_centers = sorted(np.around(new_centers, 10).tolist())
                # new_centers = list(map(lambda x: rotate(x, math.radians(36)), new_centers))
                # rounded_centers = tuple(sorted(map(lambda x: euc_round(x, 7), new_centers)))
                hsh = hash(tuple(tuple(x) for x in rounded_centers))
                # print(idx, rounded_centers, hsh)
                if  0 <= hsh < l:
                    continue
                mp[idx].append(hsh)

    t1 = time.time()
    print("Hashing took", t1 - t0)
    # list idx has n hashes considering each of them centers
    # pprint(mp)
    G = nx.Graph(mp)
    components = nx.connected_components(G)
    t2 = time.time()
    print("Graphing took", t2 - t1)
    ans = []
    for c in components:
        # print(c)
        c = [x for x in c if 0 <= x < l]
        ans.append(c[0])
    return [chains[x] for x in ans]


def main():
    chains: List[PentagonChain] = [PentagonChain()]
    N = 16
    for i in range(N - 1):
        gen_chains = []
        t0 = time.time()
        for pentagon_chain in chains:
            new_chains = pentagon_chain.generate_new_chains()
            gen_chains.extend(new_chains)
        t1 = time.time()
        print("Generation took", t1 - t0)
        chains = remove_isomorphic_chains(gen_chains) 
        # print(chains)
        print(f"Done for {i + 2} printing {len(chains)} chains")
    pprint(f"Found {len(chains)} chains")

    
if __name__ == "__main__":
    main()

# 7
## (1 ⬆️ Orientation.UP * [2, 0, 0, 0, 0])
## (2 ⬆️ Orientation.DOWN * [1, 0, 0, 0, 3])
## (3 ⬆️ Orientation.UP * [0, 0, 0, 0, 2])

# 6
# (1 ⬆️ Orientation.UP * [2, 0, 0, 0, 0])
# (2 ⬆️ Orientation.DOWN * [1, 0, 0, 3, 0])
# (3 ⬆️ Orientation.UP * [0, 0, 0, 2, 0])

# 5
# (1 ⬆️ Orientation.UP * [2, 0, 0, 0, 0])
# (2 ⬆️ Orientation.DOWN * [1, 0, 3, 0, 0])
# (3 ⬆️ Orientation.UP * [0, 0, 2, 0, 0])