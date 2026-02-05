
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

start = input('Enter the starting node: ')

def prim (G, start):
    mst = {}
    mst[start] = {'cost':0, 'parent':None}
    selected = []
    selected.append(start)
    weight_mst = 0
    
    while len(selected) != n:
        min_value = 100000000
        min_key = None
        for u in selected:
            for v in G[u]:
                if v not in selected and G[u][v] < min_value:
                    min_value = G[u][v]
                    min_key = v
                    daddy = u 
                    
        weight_mst = weight_mst + min_value
        selected.append(min_key)
        mst[min_key] = {'cost': min_value, 'parent': daddy}

    print(mst)
    def display(mst):
        print("The mimimum spanning tree is given below:\n")
        for i in mst.keys():
            if mst[i]['parent'] == None:
                continue
            print(f"{mst[i]['parent']} -- {mst[i]['cost']} -- {i}")
        print(f"Weight of MST = {weight_mst}")

    display(mst)

prim(G, start)               

