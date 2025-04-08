def makeGraph(mx = 5):
    return [[0 for _ in range(mx)] for _ in range(mx)]

def addEdge(graph, x, y):
    from copy import deepcopy
    graph = deepcopy(graph)
    graph[x][y] = 1
    graph[y][x] = 1
    return graph

def neighbours(graph, x):
    return [1 for i in range(len(graph)) if graph[x][i] == 1]

g = makeGraph()
g1 = addEdge(g, 2, 3)

print(neighbours(g1, 4))