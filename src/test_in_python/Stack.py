from collections import deque
from queue import LifoQueue
import time
import os
import psutil

def listMethod():
    stack = []

    startTime = time.time()
    for i in range(1000000):
        stack.append(i)
    print("Push Elements Time: ", (time.time() - startTime) / 100, "seconds")

    listProcess = psutil.Process(os.getpid())
    print(listProcess.memory_info().rss, " bytes used after pushing in list")

    startTime = time.time()
    for j in range(1000000):
        stack.pop()
    print("Pop Elements Time: ", (time.time() - startTime) / 100, "seconds")

    listProcess = psutil.Process(os.getpid())
    print(listProcess.memory_info().rss, " bytes used after popping in list")

def dequeMethod():
    stack = deque()

    startTime = time.time()
    for i in range(1000000):
        stack.append(i)
    print("Push Elements Time: ", (time.time() - startTime) / 100, "seconds")

    dequeProcess = psutil.Process(os.getpid())
    print(dequeProcess.memory_info().rss, " bytes used after pushing in deque")

    startTime = time.time()
    for j in range(1000000):
        stack.pop()
    print("Pop Elements Time: ", (time.time() - startTime) / 100, "seconds")

    dequeProcess = psutil.Process(os.getpid())
    print(dequeProcess.memory_info().rss, " bytes used after popping in deque")

def lifoQueueMethod():
    stack = LifoQueue(maxsize = 1000000)

    startTime = time.time()
    for i in range(1000000):
        stack.put(i)
    print("Push Elements Time: ", (time.time() - startTime) / 100, "seconds")

    lifoProcess = psutil.Process(os.getpid())
    print(lifoProcess.memory_info().rss, " bytes used after pushing in LIFO")

    startTime = time.time()
    for j in range(1000000):
        stack.get()
    print("Pop Elements Time: ", (time.time() - startTime) / 100, "seconds")

    lifoProcess = psutil.Process(os.getpid())
    print(lifoProcess.memory_info().rss, " bytes used after popping in lifo")

initProcess = psutil.Process(os.getpid())
print(initProcess.memory_info().rss, " initial bytes used")
print("")

startTime = time.time()
listMethod()
print("Execution Time for List Based Stack: ", time.time() - startTime, "seconds")
print("")

startTime = time.time()
dequeMethod()
print("Execution Time for Deque Based Stack: ", time.time() - startTime, "seconds")
print("")

startTime = time.time()
lifoQueueMethod()
print("Execution Time for Lifo Queue Based Stack: ", time.time() - startTime, "seconds")
print("")

#Multiple Tests
# startTime = time.time()
# for i in range(100):
#     listMethod()
# print("Average Execution Time for List Based Stack: ", (time.time() - startTime) / 100, "seconds")

# startTime = time.time()
# for j in range(100):
#     dequeMethod()
# print("Average Execution Time for Deque Based Stack: ", (time.time() - startTime) / 100, "seconds")

# startTime = time.time()
# for k in range(100):
#     lifoQueueMethod()
# print("Average Execution Time for Lifo Based Stack: ", (time.time() - startTime) / 100, "seconds")






