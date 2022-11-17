from typing import List
from copy import deepcopy
from pprint import pprint

class Pentagon:
    def __init__(self, pentagon_id, orientation, edge_no, parent_pentagon):
        self.pentagon_id = pentagon_id
        self.orientation = orientation
        self.edges = [0, 0, 0, 0, 0]
        self.edges[edge_no] = parent_pentagon

    def get_edges(self):
        return self.edges
    
    def use_edge(self, edge, parent_pentagon):
        self.edges[edge] = parent_pentagon

    def get_free_edges(self):
        free_edges = [idx for idx, e in enumerate(self.edges) if e == 0]
        return free_edges

    def __repr__(self):
        return f"({self.pentagon_id} ⬆️ {self.orientation} * {self.edges})"

class PentagonChain:
    def __init__(self):
        self.pentagons = [Pentagon(1, 0, 0, 0)]


    def generate_new_chains(self):
        chains = []
        pentagon_id = len(self.pentagons) + 1
        for pentagon in self.pentagons:
            for edge in pentagon.get_free_edges():
                new_chain = deepcopy(self)
                new_pentagon = Pentagon(pentagon_id, 1 - pentagon.orientation, edge, pentagon.pentagon_id)
                new_chain.pentagons[pentagon.pentagon_id - 1].use_edge(edge, new_pentagon.pentagon_id)
                new_chain.pentagons.append(new_pentagon)
                chains.append(new_chain)
        return chains
            
    def __repr__(self):
        return "------------\n" + "\n".join([str(pentagon) for pentagon in self.pentagons]) + "]"


def remove_isomorphic_chains():
    pass

def main():
    chains: List[PentagonChain] = [PentagonChain()]
    N = 17
    for _ in range(N - 1):
        gen_chains = []
        for pentagon_chain in chains:
            new_chains = pentagon_chain.generate_new_chains()
            gen_chains.extend(new_chains)
        chains = gen_chains
        print(f"Done for {_} printing {len(chains)} chains")
    pprint(f"Found {len(chains)} chains")

    
if __name__ == "__main__":
    main()
