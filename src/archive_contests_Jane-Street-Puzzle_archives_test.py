from typing import List
class Pentagon:
    def __init__(self, orientation, center, join_edge):
        self.orientation = orientation
        self.center_coordinates = center
        self.edges = [0, 0, 0, 0, 0]
        self.edges[join_edge] = 1

    def get_edges(self):
        return self.edges
    
    def use_edge(self, edge):
        self.edges[edge] = 1

    def get_free_edges(self, edge):
        free_edges = [idx for idx, e in enumerate(self.edges) if e == 0]
        return free_edges

class PentagonChain:
    def __init__(self):
        self.pentagons = List[Pentagon]



    def generate_new_chains():
        for pentagon in self.pentagons:
            for edge in pentagon.get_free_edges():
                center_offset, new_edge = get_new_pentagon_info(pentagon.orientation, edge)
                new_pentagon = Pentagon(1 - pentagon.orientation, center_offset, new_edge)
                new_pentagon.use_edge(edge)
                self.pentagons.append(new_pentagon)


def remove_isomorphic_chains():
    pass
pentagons: List[PentagonChain] = []

for i in range(17):
    all_chains = []
    for pentagon_chain in pentagons:
        new_chains = pentagon_chain.generate_new_chains()
        all_chains.append(new_chains)

    pentagons = remove_isomorphic_chains(all_chains)

    
print(pentagons)
