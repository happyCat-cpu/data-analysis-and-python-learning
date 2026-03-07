

scores = []

i = 0
for i in range(10):
    scores.append(int(input("输入评委打分:")))
#input返回是字符串，需要int转成数字
#不能直接给空列表赋值，需要用append

scores.sort()
scores.pop(0)
scores.pop() #不加下标默认删最后一个

sum = 0

for i in scores:
    sum += i

average = sum / 8

print("选手的成绩是:",average)
input()
