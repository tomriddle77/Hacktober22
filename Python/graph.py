# Graph implementaion in python

__author__ = "Abhinay Yadav"

from collections import deque

class Graph:
    def __init__(self):
        self.vertices = set()
        self.graph = {}


    def add_vertex(self,v):
        self.vertices.add(v)
        self.graph[v]=[]
    
    def add_edge(self, u, v, directed :bool=False):
        if u not in self.vertices:
            self.add_vertex(u)
        if v not in self.vertices:
            self.add_vertex(v)
        self.graph[u].append(v)
        if directed:
                self.graph[v].append(u)

    
    def display(self):

        for k in self.graph:
            print(f"{k} --> {self.graph[k]}")



    def bfs(self, start):

        visited = [False] *( len(self.vertices) +1 )
        visited[start]=True
        q= deque()
        q.append(start)

        def bfsInner():
            while q:
                node = q.popleft()
                print(node, end=" ")
                for ele in self.graph[node]:
                    if not visited[ele]:
                        q.append(ele)
                        visited[ele]=True
        bfsInner()
        for element in self.vertices:
            if not visited[element]:
                visited[element]=True
                q.append(element)
                bfsInner()

        
if __name__=="__main__":
    graph = Graph()
    graph.add_edge(4,3, True)
    graph.add_edge(4,5)
    graph.add_edge(1,2, True)
    graph.display()
    graph.bfs(4)