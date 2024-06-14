#输入体重和身高值，根据BMI计算公式和国内、国际的BMI分类指标，分别输出国内、国际评价标准中“偏瘦”、“正常”等信息

weight = float(input("请输入体重(kg)："))
height = float(input("请输入身高(m)："))
bmi = weight / (height * height)
print("您的BMI指数为：",bmi)
print("国内评价标准：",end="")
if bmi < 18.5:
    print("偏瘦")
elif 18.5 <= bmi < 25:
    print("正常")
elif 25 <= bmi < 30:
    print("偏胖")
else:
    print("肥胖")
print("国际评价标准：",end="")
if bmi < 18.5:
    print("偏瘦")
elif 18.5 <= bmi < 24:
    print("正常")
elif 24 <= bmi < 28:
    print("偏胖")
else:
    print("肥胖")