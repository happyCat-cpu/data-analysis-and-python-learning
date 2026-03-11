#判断素数
import math

def is_prime(n):
    """
    功能:判断一个数是不是素数
    参数:
    - n 要进行判断的整数
    返回值:
    - True 是素数
    - False 不是素数
    """
    if n <= 1:
        return False
    
    if n <= 3:
        return True
    
    if n % 2 == 0:
        return False
    
    for i in range(3,int(math.isqrt(n))+1,2):
            if n % i == 0:
                return False
    return True

def print_prime(start,end):
    """
    功能：打印start到end中的素数
    参数:
    - start 数字范围的起点
    - end 数字范围的终点
    返回值:
    - 一系列范围内的素数
    """
    primes = []
    for i in range(start,end+1):
        if is_prime(i):
            primes.append(i)
    print(primes)

#===主循环===
while True:
    print("===========")
    print("1.判断素数")
    print("2.打印素数")
    print("3.退出")
    print("-----------")

    choice = input("选择操作选项:")

    if choice == '1':
        num = int(input("要进行判断的数字："))
        print(is_prime(num))

    elif choice == '2':
        start = int(input("输入起点:"))
        end = int(input("输入终点:"))
        print_prime(start,end)

    elif choice == '3':
        print("再见！")
        break

    else:
        print("无效选择")
