#成绩管理系统
import json
import os

class StudentManager:
    def __init__(self,filename = "data/students.json"):
        self.filename = filename
        self.students = {}
        self.load()
        
    #添加学生
    def add(self,name,score):
        if name in self.students:
            print(f"学生{name}已存在！")
            return
        try:
            score = float(score)
        except ValueError:
            print("成绩必须是数字！")
            return
        
        self.students[name] = score
        print(f"学生{name}--{score}添加成功！")
        
        
    #显示所有学生
    def show_all(self):
        if not self.students:
            print("还未添加有学生！")
            return
        print("===学生成绩列表===")
        for i,(name,score) in enumerate(self.students.items(),1):
            print(f"{i}.{name}--{score}")
            
        
    #计算平均分
    def get_avg(self):
        if not self.students:
            print("还未添加有学生！")
            return
        sum_score = 0
        for each in self.students.values():
            sum_score += each
        avg = sum_score / len(self.students)
        print(f"===班级平均分===\n\t{avg:.1f}")
        
    #查找学生(含模糊搜索功能)
    def find(self,keyword):
        if not self.students:
            return "还没有学生数据"

        if keyword in self.students:
            return f"学生{keyword}的成绩为{self.students[keyword]}"

        #模糊搜索
        results = {name:score for name,score in self.students.items()
                  if keyword in name}

        if not results:
            return f"未找到包含'{keyword}'的学生"

        #打印结果
        result = f"===包含'{keyword}'的学生名单===\n"
        for i,(name,score) in enumerate(results.items(),1):
            result += f"{i}.{name}:{score}\n"
        return result
            
    #修改成绩
    def update(self,name,new_score):
        if name not in self.students:
            print(f"学生{name}不存在！")
            return
        try:
            score = float(new_score)
        except ValueError:
            print("成绩必须是数字！")
            return
        self.students[name] = score
        print(f"学生{name}成绩已修改为{score}!")
        
    #删除学生
    def delete(self,name):
        if name not in self.students:
            print(f"学生{name}不存在！")
            return
        result = input("确定要删除学生{name1}吗?(y/n):")
        if result == 'y':
            del self.students[name]
            print(f"学生{name}已删除！")
        else:
            return
        
    #按成绩排序显示
    def show_by_score(self):
        if not self.students:
            print("还未添加有学生！")
            return
        lst = []
        for name,score in self.students.items():
            lst.append((name,score))
        n = len(self.students)
        for i in range(n-1):
            for j in range(n-1-i):
                if lst[j+1][1] > lst[j][1]:
                    lst[j+1],lst[j] = lst[j],lst[j+1]
        print("===学生成绩排名===")
        for i,(name,score) in enumerate(lst,1):
            print(f"{i}.{name}--{score}")
        
        
    #统计信息
    def get_stats(self):
        top_student = max(self.students.items(),key = lambda x:x[1])
        bottom_student = min(self.students.items(),key = lambda x:x[1])
        pass_students = {}
        for name,score in self.students.items():
            if score >= 60:
                pass_students[name] = score
        print(f"第一名是:{top_student[0]}--{top_student[1]}")
        print(f"最后一名是:{bottom_student[0]}--{bottom_student[1]}")
        print("===成绩及格名单===")
        for i,(name,score) in enumerate(pass_students.items(),1):
            print(f"{i}.{name}--{score}")
        print(f"总共及格人数{len(pass_students)},及格率为{len(pass_students)/len(self.students):.1f}")
        
    #成绩等级
    def score_grade(self):
        if not self.students:
            print("还未添加有学生！")
            return
        
        grade = {
            'A':[],
            'B':[],
            'C':[],
            'D':[],
            'E':[]
        }
        
        for name,score in self.students.items():
            if score > 100:
                print(f"学生{name}成绩错误！")
            elif score >= 90:
                grade['A'].append(name)
            elif score >= 80:
                grade['B'].append(name)
            elif score >= 70:
                grade['C'].append(name)
            elif score >= 60:
                grade['D'].append(name)
            else:
                grade['E'].append(name)

        for level,names in grade.items():
            if names:
                print(f"\n==={level}===")
                for i,name in enumerate(names,1):
                    print(f"{i}.{name}")

    #导出CSV
    def export_csv(self,filename=None):
        import csv
        if filename is None:
            filename = self.filename.replace('.json','.csv')

        try:
            with open(filename,'w',newline='',encoding='utf-8') as f:
                writer = csv.writer(f)
                writer.writerow(["姓名","成绩"])
                for name,score in self.students.items():
                    writer.writerow([name,score])
            return f"已导出到{filename}"
        except Exception as e:
            return f"导出失败{e}"

    #成绩分布图
    def show_distribution(self):
        if not self.students:
            return "还没有学生数据"

        ranges = [(90,101,"90-100"),(80,90,"80-89"),(70,80,"70-79"),
                  (60,70,"60-69"),(0,60,"0-59")]

        result = "===成绩分布图===\n"
        for low,high,label in ranges:
            count = sum(1 for score in self.students.values()
                        if low <= score <high)
            bar = "█" * count
            result += f"{label}: {bar} ({count}人)\n"
        return result
        
    #退出保存
    def save(self):
        with open(self.filename,"w",encoding="utf-8") as f:
            json.dump(self.students,f,ensure_ascii=False,indent=2)
        print("---数据已保存---")
        
    #启动加载
    def load(self):
        if os.path.exists(self.filename):
            try:
                with open(self.filename,"r",encoding="utf-8") as f:
                    self.students = json.load(f)
                print(f"数据加载成功，共{len(self.students)}名学生")
            except:
                print("加载失败，使用空数据")
        else:
            print("没有找到存档文件，使用空数据")

def main():
    manager = StudentManager()

    while True:
        pass

if __name__ == "__main__":
    main()
