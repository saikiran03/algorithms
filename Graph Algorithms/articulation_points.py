N = 1005
adj = [[0]*N for i in xrange(N)]
disc = [0]*N
low = [float('inf')]*N
visited = [False]*N
parent = [None]*N
AP = [False]*N
time = 0

def dfs(vertex, V, time):
	child = 0
	visited[vertex] = True
	disc[vertex] = low[vertex] = time + 1
	
	for i in xrange(V):

		if adj[vertex][i]:
			if visited[i]==False:
		
				child = child + 1
				parent[i] = vertex

				dfs(i, V, time+1)
				low[vertex] = min(low[vertex], low[i])

				if parent[vertex]==None and child>1:
					AP[vertex] = True
				
				if parent[vertex]!=None and low[i]>=disc[vertex]:
					AP[vertex] = True
			
			elif parent[vertex]!=i:
				low[vertex] = min(low[vertex], disc[i])