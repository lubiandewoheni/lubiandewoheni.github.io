#随机生成 [0,10]范围的整数，分别组成集合A和集合B，输出A和B的内容、长度、最大值、最小值以及它们的并集、交集和差集。

import random

A = set()
B = set()
for i in range(10):
    A.add(random.randint(0, 10))
    B.add(random.randint(0, 10))
print("A:", A)
print("B:", B)
print("A的长度：", len(A))
print("B的长度：", len(B))
print("A的最大值：", max(A))
print("B的最大值：", max(B))
print("A的最小值：", min(A))
print("B的最小值：", min(B))
print("A和B的并集：", A | B)
print("A和B的交集：", A & B)
a = A - B
b = B - A
print("A和B的差集：", a)
print("B和A的差集：", b)
print("A和B的对称差集：", a | b)