#!/usr/bin/env python

"""priority_queue.py: Priority queue implentaion in python."""

__author__      = "Abhinay Yadav"

class PriorityQueueNode:

    def __init__(self, value,priority):
        self.value=value
        self.priority=priority
    
    def __str__(self):
        return f"{self.value}"

class PriorityQueue:

    def __init__(self):
        self.pq =[]

    def getSize(self):
        return len(self.pq)
    
    def isEmpty(self):
        return self.getSize() == 0

    def __perColateUp(self):
        childIndex = self.getSize() -1
        while childIndex > 0:
            parentIndex = (childIndex-1)//2
            if self.pq[childIndex].priority > self.pq[parentIndex].priority:
                self.pq[childIndex] , self.pq[parentIndex] = self.pq[parentIndex] , self.pq[childIndex]
                childIndex = parentIndex
            else: break  



    def insert(self, value, priority):

        node = PriorityQueueNode(value,priority)
        self.pq.append(node)
        self.__perColateUp()

    def __str__(self):
        for i in self.pq:
            print(i)
        return ""

q = PriorityQueue()

q.insert(1,2)

q.insert(2,5)

q.insert(1,2)

print(q)