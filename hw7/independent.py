from random import randrange
from copy import deepcopy
import sys

def fill_graph(n):
	graph = {}
	edges = []
	for i in range(n):
		for j in range(n):
			if i == j: continue
			if randrange(0, 2) == 1:	# 1/2 probability
				edges.append((i, j))

	for (u, v) in edges:
		graph[u] = graph.get(u, []) + [v]
		graph[v] = graph.get(v, []) + [u]
	
	for i in range(n):
		graph[i] = set(graph.get(i, []))

	return graph

def independent(graph):
	result = []
	degrees = []
	for v in graph:
		degrees.append((v, len(graph[v])))
	degrees.sort(key=lambda d: d[1])
	
	while(degrees):
		(v, d) = degrees.pop(0)
		result.append(v)
		for u in graph[v]:
			try:
				for (w, deg) in degrees:
					if (u == w): degrees.remove((w, deg))
			except:
				pass
	return result

def del_neighbors(v, graph):
	result = deepcopy(graph)
	for e in result[v]:
		result.pop(e, None)
	result.pop(v, None)
	return result

def independent2(graph):
	n = len(graph)
	if n <= 1:
		return n
	for v, edges in graph.items():
		in_graph = del_neighbors(v, graph)
		in_count = independent2(in_graph) + 1

		out_graph = deepcopy(graph)
		out_graph.pop(v)
		out_count = independent2(out_graph)
		break
	return max(in_count, out_count)

if __name__ == "__main__":
	n = int(sys.argv[1])
	trials = int(sys.argv[2])
	graph = fill_graph(n)

	total1, total2 = 0, 0
	for i in range(trials):
		total1 += len(independent(graph))
		total2 += independent2(graph)
	
	print("independent1")
	print("total " + str(total1))
	print("average " + str(total1 / trials))

	print("\nindependent2")
	print("total " + str(total2))
	print("average " + str(total2 / trials))
