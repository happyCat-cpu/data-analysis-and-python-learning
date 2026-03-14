import json

class StudentManager:
    """学生成绩管理类"""
    def __init__(self):
        self.students = {}
        self.load_from_file()

    def add(self):
        name = input("请输入学生名字:")

        if name in self.students:
            print(f"学生{name}已存在")
            return

        try:
            score = float(input("请输入学生成绩:"))
            self.students[name] = score
            print(f"已添加学生{name}--{score}")
        except ValueError:
            print("无效成绩")

    def show_all(self):
        if not self.students:
            print("还没有学生信息")
            return

        print("\n====学生列表===")
        for i,(name,score) in enumerate(self.students.items(),1):
            print(f"{i}.{name}--{score}")

    def get_avg(self):
        if not self.students:
            print("还没有学生信息")
            return

        avg = sum(self.students.values()) / len(self.students)
        print(f"平均分为:{avg}分")

    def get_max_min(self):
        if not self.students:
            print("还没有学生信息")
            return

        max_score = max(self.students.values())
        min_score = min(self.students.values())
        max_list = [name for name,score in self.students.items() if score == max_score]
        min_list = [name for name,score in self.students.items() if score == min_score]

        print(f"最高分为{max_score}:{max_list}")
        print(f"最低分为{min_score}:{min_list}")

    def updata(self):
        name = input("请输入学生名字:")

        if name not in self.students:
            print("没有学生信息")
            return

        try:
            new_score = float(input("请输入新成绩:"))
            self.students[name] = new_score
            print("修改成功")
        except ValueError:
            print("无效成绩")

    def delete(self):
        name = input("请输入学生名字:")

        if name not in self.students:
            print("学生不存在")
            return

        del self.students[name]
        print(f"学生{name}已删除")

    def search(self):
        name = input("请输入学生名字:")
        if name not in self.students:
            print("学生不存在")
            return

        print(f"学生{name}的成绩是{self.students[name]}")

    def save_to_file(self,filename = "students.json"):
        try:
            with open(filename,"w",encoding='utf-8') as f:
                json.dump(self.students,f,ensure_ascii=False,indent=2)
            print(f"数据已保存到{filename}")
        except Exception as e:
            print(f"保存失败:{e}")

    def load_from_file(self,filename="students.json"):
        try:
            with open(filename,"r",encoding='utf-8') as f:
                self.students = json.load(f)
            print(f"已从{filename}加载{len(self.students)}条数据")
        except FileNotFoundError:
            print("没有找到保存的文件,starting with empty data")
            self.students = {}
        except Exception as e:
            print(f"加载失败:{e}")
            self.students = {}

    def menu(self):
        while True:
            print("\n"+"="*30)
            print("1.添加学生")
            print("2.显示所有学生")
            print("3.计算平均分")
            print("4.最高分和最低分")
            print("5.修改成绩")
            print("6.删除学生")
            print("7.查找学生")
            print("8.退出")
            print("="*30)

            choice = input("请输入你的选择:")

            if choice == '1':
                self.add()
            elif choice == '2':
                self.show_all()
            elif choice == '3':
                self.get_avg()
            elif choice == '4':
                self.get_max_min()
            elif choice == '5':
                self.updata()
            elif choice == '6':
                self.delete()
            elif choice == '7':
                self.search()
            elif choice == '8':
                answer = input("确定要退出吗？（y/n）:")
                if answer == 'y':
                    self.save_to_file()
                    print("再见！")
                    break
            else:
                print("无效选择")

if __name__ == "__main__":
    manager = StudentManager()
    manager.menu()
