#学生成绩管理系统（列表）

students = {}

#===选项系统===
def input_scores():
    name = input("输入学生名字：")
    
    if name in students:
        print(f"学生{name}已经存在")
        return

    try:
        score = float(input("输入学生成绩:"))
        students[name] = score
        print(f"已添加学生{name}-成绩{score}")
    except:
        print("成绩必须是数字")

def show_all():
    if not students:
        print("还未添加学生")
    else:
        print("\n===学生列表===")
        for i,(name,score) in enumerate(students.items(),1):
            print(f"{i}.{name}--{score}")

def avg_scores():
    if not students:
        print("还未添加学生")
    else:
        avg = sum(students.values()) / len(students)
        print(f"平均分为{avg:.1f}")

def find_max_min():
    if not students:
        print("还未添加学生")
    else:
        max_score = max(students.values())
        min_score = min(students.values())
        
        max_top = [name for name,score in students.items() if score == max_score]
        min_top = [name for name,score in students.items() if score == min_score]
        print(f"最高分:{max_score}:{",".join(max_top)}\n最低分:{min_score}:{",".join(min_top)}")

def show_report():
    find_max_min()
    avg_scores()
    show_all()

def update_score():
    name = input("输入学生名字：")
    
    if name not in students:
        print(f"学生{name}不存在")
        return
    try:
        new_score = float(input("输入新成绩:"))
        students[name] = new_score
        print("修改成功")
    except ValueError:
        print("成绩必须是数字")
        
#===主系统===            
while True:
    #========选项表========
    print("\n" + "="*30)
    print("1.添加学生")
    print("2.查看所有学生")
    print("3.计算平均分")
    print("4.最高分和最低分")
    print("5.打印成绩报告")
    print("6.修改学生成绩")
    print("7.退出")
    #======================

    choice = input("请选择(1-7):")
    
    #==========选择操作==========
    #选择1
    if choice == '1':
        input_scores()

    #选择2
    elif choice == '2':
        show_all()

    #选择3
    elif choice == '3':
        avg_scores()

    #选择4
    elif choice == '4':
        find_max_min()

    #选择5
    elif choice == '5':
        show_report()

    #选择6
    elif choice == '6':
        update_score()
        
    #选择7
    elif choice == '7':
        print("再见！")
        break

    #无效选择
    else:
        print("无效选择")
        
    #============================

        
