#使用循环取出"My house is full of toys"中每个单词的首字母，并存储到列表对象中

s = "My house is full of toys"
words = s.split()
initials = []
for word in words:
    initials.append(word[0])
print(initials)
