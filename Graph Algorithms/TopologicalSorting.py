class Graph:
	def __init__(self, V):
		self.V = V
		self.E = 0
		self.adjList = [[] for _ in xrange(V)]
		return 

	def addEdge(self, u, v):
		self.adjList[u].append(v)
		return

	def topological_order(self):
		# Kahn's Algorithm

		Inorder = [0] * self.V
		for u in xrange(self.V):
			for v in self.adjList[u]:
				Inorder[v] += 1

		TO = []
		S = filter(lambda x: Inorder[x]==0, range(self.V))
		while len(S)>0:
			f = S.pop(0)
			TO.append(f)
			for v in self.adjList[f]:
				Inorder[v] -= 1
				if Inorder[v]==0:
					S.append(v)
		
		if len(TO)!=self.V:
			print "ERROR! Given graph is not a DAG."
		return TO	
	
if __name__=='__main__':
	g = Graph(5)
	g.addEdge(3,1)
	g.addEdge(3,0)
	g.addEdge(2,0)
	g.addEdge(2,4)
	print g.topological_order()