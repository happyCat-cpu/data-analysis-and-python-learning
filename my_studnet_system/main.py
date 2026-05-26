#主程序
from model import StudentManager
from utils import input_name,input_score,print_menu

def main():
    manager = StudentManager()

    while True:
        print_menu()
        choice = input("请输入(1-12)：")

        if choice == '1':
            print("开始添加学生(按q退出)")
            while True:
                name = input_name("请输入姓名(按q退出):")
                if name == 'q':
                    break
                score = input_score()
                manager.add(name,score)

        elif choice == '2':
            manager.show_all()

        elif choice == '3':
            manager.get_avg()

        elif choice == '4':
            keyword = input_name("请输入名字或关键字:")
            print(manager.find(keyword))

        elif choice == '5':
            name = input_name()
            new_score = input_score()
            manager.update(name,new_score)

        elif choice == '6':
            name = input_name()
            manager.delete(name)

        elif choice == '7':
            manager.show_by_score()

        elif choice == '8':
            manager.get_stats()

        elif choice == '9':
            manager.score_grade()

        elif choice == '10':
            print(manager.export_csv())

        elif choice == '11':
            print(manager.show_distribution())

        elif choice == '12':
            manager.save()
            print("再见！")
            break

        else:
            print("选择无效！")

if __name__ == "__main__":
    main()
