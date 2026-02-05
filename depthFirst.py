G = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [],
    'E': ['F'],
    'F': []
}
def depthFirst(G , s):
    stack = []
    visited = []
    stack.append(s)
    while stack:
        value = stack.pop()
        visited.append(value)
        for adjacent in G[value]:
            if adjacent not in stack and adjacent not in visited:
                stack.append(adjacent)
        
    return visited

s = input('Enter the starting vertex')        
        
returned_list = depthFirst(G ,s)
print(returned_list)