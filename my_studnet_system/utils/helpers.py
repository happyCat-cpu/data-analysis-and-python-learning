def input_score(prompt="请输入成绩："):
    while True:
        try:
            score = float(input(prompt))
            return score
        except ValueError:
            print("成绩必须是数字！请重新输入")

def input_name(prompt="请输入姓名："):
    return input(prompt).strip()

def print_menu():
    print("\n"+"="*30)
    print("1.添加学生")
    print("2.显示所有学生")
    print("3.计算平均分")
    print("4.查找学生")
    print("5.修改成绩")
    print("6.删除学生")
    print("7.按成绩排序显示")
    print("8.统计信息")
    print("9.成绩等级")
    print("10.导出CSV")
    print("11.成绩分布图")
    print("12.保存退出")
    print("="*30)
