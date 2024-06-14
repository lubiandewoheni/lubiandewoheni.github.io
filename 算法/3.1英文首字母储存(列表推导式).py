#使用列表推导式取出"My house is full of toys"中每个单词的首字母，并存储到列表对象中

A = 'My house is full of toys'
S = [A.split()[i][0] for i in range(0, len(A.split()))]
print(S)
