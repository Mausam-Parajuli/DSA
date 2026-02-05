G = {
    's':{'t':10, 'y':5},
    't':{'y':2, 'x':1},
    'x':{'z':4},
    'y':{'x':9, 't':3, 'z':2},
    'z':{'x':6, 's':7}
}

import math
def INITIALIZE_SINGLE_SOURCE(G, s):
    cost = dict()
    prev = dict()
    for vertex in G.keys():
        cost[vertex] = math.inf
        prev[vertex] = " "
    cost[s] = 0
    return cost, prev

def RELAX(G, u, v, cost, prev):
    if cost[v] > cost[u] + G[u][v]:
        cost[v] = cost[u] + G[u][v]
        prev[v] = u
    return cost, prev

from queue import PriorityQueue
def DJ(G, s):
    cost, prev = INITIALIZE_SINGLE_SOURCE(G, s)
    PQ = PriorityQueue()
    for vertex in G.keys():
        PQ.put((cost[vertex], vertex))
    visited = []
    while(len(visited) != len(G.keys())):
        _, currentVertex = PQ.get()
        visited.append(currentVertex)
        for neighbour in G[currentVertex]:
            if neighbour not in visited:
                cost, prev = RELAX(G, currentVertex, neighbour, cost, prev)
                PQ.put((cost[neighbour], neighbour))
    return cost, prev

#path construction

def RECONSTRUCT_PATH(vertex, prev):
    path = vertex
    while prev[vertex] != " ":
        path = prev[vertex] + "->" + path
        vertex = prev[vertex]
    return path

#call the function
s = 's'
cost, prev = DJ(G, s)
for vertex in G.keys():
    print(f"Shortest path from {s} to {vertex} is {RECONSTRUCT_PATH(vertex, prev)}")
    print(f"Cost is {cost[vertex]}")

