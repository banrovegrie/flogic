from typing import List
from copy import deepcopy
from pprint import pprint
import math
from enum import Enum

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

    def __eq__(self, x):
        return self.__hash__() == x.__hash__()
    
    def get_hash(self):
        sorted_pentagons = sorted(self.pentagons, key=lambda x: (x.center[0], x.center[1]))
        mapping = {pentagon.pentagon_id: idx + 1 for idx, pentagon in enumerate(sorted_pentagons)}
        mapping[0] = 0
        l = [(mapping[pentagon.pentagon_id], pentagon.orientation.value, tuple(map(lambda x: mapping[x], pentagon.edges))) for pentagon in self.pentagons]
        return sorted(l)     

    def __hash__(self):
        return hash(tuple(self.get_hash()))


    def __repr__(self):
        return "------------\n" + "\n".join([str(pentagon) for pentagon in self.pentagons]) + "\n***********" + str(self.get_hash()) + "]"


def remove_isomorphic_chains(chains):
    return set(chains)


def main():
    chains: List[PentagonChain] = [PentagonChain()]
    N = 16
    for i in range(N - 1):
        gen_chains = []
        for pentagon_chain in chains:
            new_chains = pentagon_chain.generate_new_chains()
            gen_chains.extend(new_chains)
        chains = remove_isomorphic_chains(gen_chains) 
        print(chains)
        print(f"Done for {i + 2} printing {len(chains)} chains")
    pprint(f"Found {len(chains)} chains")

    
if __name__ == "__main__":
    main()
