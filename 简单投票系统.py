#投票系统

count = {}

def vote():
    name = input("输入投票对象:")
    if name in count:
        count[name] += 1
    else:
        count[name] = 1
    print("投票成功")

def show_votes():
    if len(count) != 0:
        print(count)
    else:
        print("还未投票")

def show_max():
    if len(count) != 0:
        print(max(count.items(),key=lambda x:x[1]))
    else:
        print("还未投票")
    
#===主循环===
while True:
    print("===投票系统===")
    print("1.投票")
    print("2.查看投票情况")
    print("3.最多票获得者")
    print("4.退出")
    print("---------------")

    choice = input("输入你的选项:")

    if choice == '1':
        vote()

    elif choice == '2':
        show_votes()

    elif choice == '3':
        show_max()

    elif choice =='4':
        print("再见！")
        break

    else:
        print("无效选择")
        
