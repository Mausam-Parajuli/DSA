G = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [],
    'E': ['F'],
    'F': []
}
s = input('Enter starting vertex:')

def breadthFirst(G, s):
    queue = []
    visited = []
    queue.append(s)
    while queue:
        value = queue.pop(0)
        visited.append(value)
        for adjacent in G[value]:
            if adjacent not in queue and adjacent not in visited:
                queue.append(adjacent)
    return visited

bft = breadthFirst(G, s)
print(f'The breadth first traversal list is \n{ bft}')
