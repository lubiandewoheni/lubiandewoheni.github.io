#用切片方式输入一个字符串判断是否是回文字符串

str1 = input("请输入一个字符串：")
if str1 == str1[::-1]:
    print("是回文字符串")
else:
    print("不是回文字符串")
