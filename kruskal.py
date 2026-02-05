G = {
    'A': {'B':1, 'D':4},
    'B': {'A':1, 'C':3, 'E':3},
    'C': {'B':3, 'F':2, 'E':1},
    'D': {'A':4, 'E':1},
    'E': {'D':1, 'B':3, 'C':1, 'F':4},
    'F': {'C':2, 'E':4}
}

nodes = ['A', 'B', 'C', 'D', 'E', 'F']
n = len(nodes)

edges = []
for u in G:
    for v in G[u]:
        if (v, u, G[u][v]) not in edges:  
            edges.append((u, v, G[u][v]))

def get_weight(edge):
    return edge[2]
edges.sort(key=get_weight)

parent = {}
for node in G:
    parent[node] = node

def notCycle(u, v):
    def find(node):
        while parent[node] != node:
            node = parent[node]
        return node
    
    root_u = find(u)
    root_v = find(v)
    if root_u != root_v:
        parent[root_v] = root_u 
        return True
    return False

def kruskal(G):
    mst = []
    total_weight = 0
    for u, v, w in edges:
        if (u, v, w) not in mst:
            if notCycle(u, v):
                mst.append((u, v, w))
                total_weight += w
    
    print("Minimum Spanning Tree :")
    for u, v, w in mst:
        print(f"{u} - {v} : {w}")
    print("Total weight:", total_weight)

kruskal(G)
