#列表工具函数
def max_in_list(L):
    """
    功能:找出列表最大值
    参数:
    - L 列表
    返回值:
    - 列表最大值
    """
    max = L[0]
    for i in L:
        if i > max:
            max = i
    print(max)
    return max

def min_in_list(L):
    """
    功能:找出列表最小值
    参数:
    - L 列表
    返回值:
    - 列表最小值
    """
    min = L[0]
    for i in L:
        if i < min:
            min = i
    print(min)
    return min

def avg_of_list(L):
    """
    功能:求列表平均值
    参数:
    - L 列表
    返回值:
    - 列表平均值
    """
    sum = 0
    for i in L:
        sum += i
    print(sum/len(L))
    return sum/len(L)

def stats(L):
    """
    功能:找出列表最大值，最小值，平均值，总和
    参数:
    - L 列表
    返回值:
    - 列表最大值，最小值，平均值，总和
    """
    max = max_in_list(L)
    min = min_in_list(L)
    avg = avg_of_list(L)
    total = sum(L)
    print(f"最大值:{max}最小值:{min}平均值:{avg}总和:{total}")

#===主循环===
while True:
    print("===========")
    print("1.最大值")
    print("2.最小值")
    print("3.平均值")
    print("4.全部")
    print("5.退出")
    print("-----------")

    choice = input("选择操作选项:")
    L = list(map(int,input("输入列表(用空格分隔):").split()))

    if choice == '1':
        max_in_list(L)

    elif choice == '2':
        min_in_list(L)

    elif choice == '3':
        avg_of_list(L)

    elif choice == '4':
        stats(L)

    elif choice == '5':
        print("再见！")
        break
    
    else:
        print("无效选择")
