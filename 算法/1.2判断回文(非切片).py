#用循环方式输入一个字符串判断是否是回文字符串

s = input("请输入一个字符串：")
len1 = len(s)
i = 0
j = len1 - 1
while i < j:
    if s[i] != s[j]:
        print("不是回文字符串")
        break
    i += 1
    j -= 1
else:
    print("是回文字符串")
