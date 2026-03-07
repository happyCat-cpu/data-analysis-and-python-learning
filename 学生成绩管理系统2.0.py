#学生成绩管理系统2.0（字典）

students = {}

while True:
    #========选项表========
    print("\n" + "="*30)
    print("1.添加学生")
    print("2.查看所有学生")
    print("3.计算平均分")
    print("4.查找学生")
    print("5.删除学生")
    print("6.退出")
    #======================

    choice = input("请选择（1-6）：")
    
    #==========选择操作==========
    #选择1
    if choice == '1':
        name = input("输入学生名字：")
        score = input("输入学生成绩：")
        #检验成绩是否有效
        try:
            score = float(score)
            students[name] = score
            print(f"已添加学生{name}-成绩{score}")
        except:
            print("成绩必须是数字")

    #选择2
    elif choice == '2':
        if len(students) == 0:
            print("还未添加学生")
        else:
            print("\n===学生列表===")
            #按名字排序显示
            for name in sorted(students.keys()):
                print(f"1.{name}--{students[name]}")

    #选择3
    elif choice == '3':
        if len(students) == 0:
            print("还未添加学生")
        else:
            avg = sum(students.values()) / len(students)
            max_score = max(students.values())
            min_score = min(students.values())
            top_name = []
            bottom_name = []
            for name,score in students.items():
                if score == max_score:
                    top_name.append(name)
                if score == min_score:
                    bottom_name.append(name)
            print(f"平均分为{avg:^.1f}")
            print(f"最高分为{top_name}{max_score}")
            print(f"最低分为{bottom_name}{min_score}")

    #选择4
    elif choice == '4':
        name = input("输入想查看学生名字：")
        if name in students:
            print(f"学生{name}的成绩是{students[name]}分")
        else:
            print(f"找不到学生{name}")

    #选择5
    elif choice == '5':
        name = input("输入想删除学生名字：")
        if name in students:
            print(f"学生{name}已删除")
        else:
            print(f"找不到学生{name}")
    
    #选择6
    elif choice == '6':
        print("再见！")
        break

    #无效选择
    else:
        print("无效选择")
        
    #============================
    
