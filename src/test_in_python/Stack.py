from collections import deque

def listMethod():
    stack = []
    stack.append(2)
    stack.append("hello")
    print(stack.pop())
    print(stack.pop())

    for i in range(1000000):
        stack.append(i)
        print(i)

    stack.clear()

    try:
        stack.pop()
    except:
        print("Empty")

def dequeMethod():
    stack = deque()
    stack.append(4)
    stack.append("world")
    print(stack.pop())
    print(stack.pop())

listMethod()
#dequeMethod()
