#使用循环结构和range()函数求1-100内所有奇数的和，并输出

sum = 0
for i in range(1,101):
    if i%2 == 1:
        sum += i
print(sum)