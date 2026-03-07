#计算器
print("===简单计算器===")

history = []
first = True

while True:
    cmd = input("按q退出，按回车继续：")
    if cmd == 'q':
        break

    
    #====输入系统===============================================
    try:
        if first:
            num1 = int(input("输入第一个数字："))
            first = False
        else:
            print("当前结果：{}".format(result))
            num1 = result
            
            
        op = input("输入运算符号（+,-,*,/,%,**）[按c清除上一次结果]：")
        
        if op == 'c':
            first = True
            continue
            
        num2 = int(input("输入第二个数字："))
    except:
        print("请按要求输入")
        continue
    #===========================================================



    #====计算系统===============================================
    sum = 0

    if op == '+':
        sum = num1 + num2

    elif op == '-':
        sum = num1 - num2

    elif op == '*':
        sum = num1*num2

    elif op == '/':
        if num2 ==0:
            print("分母不能为0")
            continue
        sum = num1/num2

    elif op == '%':
        if num2 ==0:
            print("无效输入")
            continue
        sum = num1%num2

    elif op == '**':    #幂运算
        sum = num1 ** num2
        
    else:
        print("请输入有效运算符")
        continue
    #===========================================================


    #====输出系统===============================================
    print("{} {} {} = {}".format(num1,op,num2,sum))
    result = sum

    #保存记录
    history.append("{:10.2f} {} {:10.2f} = {:10.2f}".format(num1,op,num2,sum))

    show = input("按h查看历史记录，按回车继续：")
    if show == 'h':
        for i,record in enumerate(history,1):
            print("{}.){}".format(i,record))
    #============================================================
        
input()
