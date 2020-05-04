from collections import deque
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

startTime = time.time()
listMethod()
print("Execution Time for List Based Stack: ", time.time() - startTime, " seconds")
startTime = time.time()
dequeMethod()
print("Execution Time for Deque Based Stack: ", time.time() - startTime, " seconds")
