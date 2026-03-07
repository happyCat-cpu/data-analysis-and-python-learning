#学生成绩管理系统（列表）

students = [] #存放学生名字
scores = []   #存放对应成绩

while True:
    #========选项表========
    print("\n" + "="*30)
    print("1.添加学生")
    print("2.查看所有学生")
    print("3.计算平均分")
    print("4.退出")
    #======================

    choice = input("请选择(1-4):")
    
    #==========选择操作==========
    #选择1
    if choice == '1':
        name = input("输入学生名字：")
        score = input("输入学生成绩：")
        #检验成绩是否有效
        try:
            score = float(score)
            students.append(name)
            scores.append(int(score))
            print(f"已添加学生{name}-成绩{score}")
        except:
            print("成绩必须是数字")

    #选择2
    elif choice == '2':
        if len(students) == 0:
            print("还未添加学生")
        else:
            print("\n===学生列表===")
            for i in range(len(students)):
                print(f"1.{students[i]}--{scores[i]}")

    #选择3
    elif choice == '3':
        if len(students) == 0:
            print("还未添加学生")
        else:
            avg = sum(scores) / len(scores)
            print(f"平均分为{avg:^10.1f}")

    #选择4
    elif choice == '4':
        print("再见！")
        break

    #无效选择
    else:
        print("无效选择")
        
    #============================

        
