import random

num = random.randint(1,100)

guess = 0

max = 100

min = 1

flag = 1

print("请猜一个数字：")

while guess != num:
    
    if flag:
        guess = int(input())
        flag = 0
    else:
        guess = int(input("未猜中，请继续猜："))

    if guess < min or guess > max:
        print("请输入指定区间的数字")
        continue
    
    if guess < num:
        min = guess+1
        print(f"请输入{min}到{max}的数")
    elif guess > num:
        max = guess-1
        print(f"请输入{min}到{max}的数")



print("恭喜你猜中了")
print("——游戏结束——")
input("-按回车键退出-")
