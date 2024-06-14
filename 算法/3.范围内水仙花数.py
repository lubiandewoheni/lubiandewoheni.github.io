#接收用户输入的起始整数和终止整数（三位），计算两个整数范围内所有的水仙花数并输出

a = int(input("请输入起始整数："))
b = int(input("请输入终止整数："))
if a < 100 or a > 999 or b < 100 or b > 999:
    print("输入有误")
else:
    for i in range(a, b+1):
        #检查该数字是否等于其第一位、第二位和第三位的立方之和
        if i == int(str(i)[0])**3+int(str(i)[1])**3+int(str(i)[2])**3:
            print(i)
