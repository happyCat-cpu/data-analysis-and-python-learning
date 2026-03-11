#选课系统
students = ["小明","小红","小刚","小丽"]
courses  = ["python","java","数学","英语"]
selected  = {s:[] for s in students}

#===选课系统===
def select_course():
    name = input("请输入要选课学生的名字：")
    if name not in selected:
        print("没有该学生")
        return

    print("可选课表:",courses)
    
    course = input("输入选课课程：")

    if course not in courses:
        print("没有可选课程")
        return
    if course in selected[name]:
        print("已选过此课程")
    else:
        selected[name].append(course)
        print(f"学生{name}已选入{course}")

def drop_course():
    name = input("请输入要退课学生的名字：")
    if name not in selected:
        print("没有该学生")
        return

    print(f"当前学生{name}的课表{selected[name]}")
    course = input("输入退课课程：")

    if course not in selected[name]:
        print("未选入课程")
        return
    else:
        selected[name].remove(course)
        print(f"学生{name}已退选{course}")

def show_student_course():
    name = input("请输入要查看学生的名字：")
    if name not in selected:
        print("没有该学生")
        return
    else:
        print(f"学生{name}的课表为{selected[name]}")

def show_course_student():
    course = input("请输入要查看的课程：")
    if course not in courses:
        print("没有该课程")
        return

    for s,c in selected.items():
        if course in c:
            print(f"{s}")
            

def show_all():
    for s,c in selected.items():
        print({f"·学生{s}--{c}"})

#===主循环===
while True:
    print("="*10,"选课","="*10)
    print("1.为学生选课")
    print("2.退课")
    print("3.查看某学生的课表")
    print("4.查看选了某门课的学生")
    print("5.查看所有学生的课表")
    print("6.退出")
    print("-"*25)

    choice = input("请输入要执行的操作：")

    if choice == '1':
        select_course()

    elif choice == '2':
        drop_course()

    elif choice == '3':
        show_student_course()

    elif choice == '4':
        show_course_student()

    elif choice == '5':
        show_all()

    elif choice == '6':
        answer = input("确定要退出吗？(y/n):")
        if answer == 'y':
            print("再见！")
            break

    else:
        print("无效选择")
