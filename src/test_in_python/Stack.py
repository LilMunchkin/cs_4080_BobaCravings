from collections import deque
from queue import LifoQueue
import time

def listMethod():
    stack = []

    for i in range(1000000):
        stack.append(i)

    for j in range(1000000):
        stack.pop()

def dequeMethod():
    stack = deque()

    for i in range(1000000):
        stack.append(i)

    for j in range(1000000):
        stack.pop()

def lifoQueueMethod():
    stack = LifoQueue(maxsize = 1000000)

    for i in range(1000000):
        stack.put(i)

    for j in range(1000000):
        stack.get()

startTime = time.time()
listMethod()
print("Execution Time for List Based Stack: ", time.time() - startTime, " seconds")
startTime = time.time()
dequeMethod()
print("Execution Time for Deque Based Stack: ", time.time() - startTime, " seconds")
startTime = time.time()
lifoQueueMethod()
print("Execution Time for Lifo Queue Based Stack: ", time.time() - startTime, " seconds")