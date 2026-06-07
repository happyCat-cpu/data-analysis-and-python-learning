/**
  视图控制层---实现 "学生" 实体的流程控制及视图函数
  文件名：StudentController.CPP
 */
#include <stdio.h> //系统头文件：导入系统输入输出函数scanf()和printf()
#include "StudentWork.h" //用户头文件：导入学生实体业务层的相关操作函数
#include <stdio.h>
#include <string.h>
//调用业务1：初始化学生
void toInitStudent(StudentNode *&L)
{
	initStudent(L);
	printf("学生初始化完成！\n");
}
//调用业务2：输出全部学生
void toDisplayALLStudent(StudentNode *L)
{
	Student stu; //创建空学生
	displayStudent(L,stu,1); //mode=1:全部学生
}
//调用业务2：输出班级的学生
void toDisplayStudentByClassName(StudentNode *L)
{
	Student stu; //创建空学生
	printf("请输入班级名称:");
	scanf("%s",stu.className);
	displayStudent(L,stu,2); //mode=2:班级学生
}
//调用业务2：输出一个学生
void toDisplayStudentById(StudentNode *L)
{
	Student stu; //创建空学生
	printf("请输入学生学号:");
	scanf("%d",&stu.id);
	displayStudent(L,stu,3); //mode=3:一个学生
}
//调用业务3：增加学生
void toAddStudent(StudentNode *&L)
{
//1:定义一个新学生
	Student stu;
	stu.LS=NULL; //新学生的成绩为空
//2:输入学生信息
	printf("请输入学生的信息：\n");
	printf("学号:"); scanf("%3d",&stu.id);
	printf("姓名:"); scanf("%s",stu.name); getchar(); //吸收回车键
	printf("性别:"); scanf("%c",&stu.sex); getchar(); //吸收回车键
	printf("班级:"); scanf("%s",stu.className);
//3:判断学号是否已经存在
	if(locateStudent(L,stu.id)!=NULL)
	{
		printf("学号为%d的学生已经存在，插入学生失败！\n",stu.id);
		return;
	}
//4:调用业务函数，插入学生
	if(addStudent(L,stu))
		printf("学生增加成功！\n");
	else
		printf("学生增加失败！\n");
}
//调用业务4：修改学生
void toUpdateStudent(StudentNode *&L)
{
//1:定义新旧学生
	Student oldStu,newStu;
//2:输入要修改的学生学号
	printf("请输入要修改学生的学号：");
	scanf("%3d",&oldStu.id);
//3:判断学生是否存在
	if(locateStudent(L,oldStu.id)==NULL)
	{
		printf("更新的学生不存在，学生更新失败！\n");
		return;
	}
//4:学生存在，输入学生的新信息
	printf("请输入学生新的信息：\n");
	printf("学号:"); scanf("%3d",&newStu.id);
	printf("姓名:"); scanf("%s",newStu.name); getchar(); //吸收回车键
	printf("性别:"); scanf("%c",&newStu.sex); getchar(); //吸收回车键
	printf("班级:"); scanf("%s",newStu.className);
//5:调用业务函数，修改学生
	if(updateStudent(L,oldStu,newStu))
		printf("学生更新成功！\n");
	else
		printf("学生更新失败！\n");
}
//调用业务5：删除学生
void toDeleteStudent(StudentNode *&L)
{
//1:定义要删除的学生
	Student stu;
	StudentNode *p; //指向被删除的学生
	ScoreNode *pSc; //指向被删除学生的成绩
//2:输入要删除学生的学号
	printf("请输入要删除学生的学号：");
	scanf("%3d",&stu.id);
	getchar(); //吸收多余的回车键
//3:判断学生是否存在
	p=locateStudent(L,stu.id); //查找定位学生
	if(p==NULL)
	{
		printf("删除的学生不存在，学生删除失败！\n");
		return;
	}
//4:进一步确认学生是否被删除
	char choice; //保存询问结果
	pSc=p->stu.LS->scNext; //指向学生的成绩链表首结点
	if(pSc!=NULL)
	{
		printf("提醒：学生有存储成绩，如果删除学生，相应的成绩也会被删除！\n");
		printf("真的要删除学生吗(y/n)？");
		choice=getchar(); //输入 y or n 
		if(choice!='Y' && choice!='y')
		{
			printf("删除学生中止！\n");
			return; //不删除学生
		}
	}
//5:调用业务函数，删除学生
	if(deleteStudent(L,stu))
		printf("学生删除成功！\n");
	else
		printf("学生删除失败！\n");
}
//调用业务6：清空(销毁)所有学生
void toDestroyStudent(StudentNode *&L)
{
	destroyStudent(L);
	printf("学生销毁完成！\n");
}
// 扩展功能：按姓名模糊查找学生（控制层）
void toSearchStudentByName(StudentNode *LS)
{
	printf("\n========== 模糊查找学生 ==========\n");
	
	if (LS == NULL || LS->next == NULL) {
		printf("暂无学生数据，请先添加学生！\n");
		return;
	}
	
	char keyword[20];
	printf("请输入姓名关键词（支持模糊匹配）：");
	scanf("%s", keyword);
	
	searchStudentByName(LS, keyword);
	
	printf("================================\n");
}
// 扩展功能：导出学生名单到文件（控制层）
void toExportStudentList(StudentNode *LS)
{
	printf("\n========== 导出学生名单 ==========\n");
	
	if (LS == NULL || LS->next == NULL) {
		printf("暂无学生数据，请先添加学生！\n");
		return;
	}
	
	char filename[100];
	printf("请输入导出文件名（如：学生名单.csv）：");
	scanf("%s", filename);
	
	// 自动添加 .csv 后缀（如果没有）
	if (strstr(filename, ".csv") == NULL) {
		strcat(filename, ".csv");
	}
	
	if (exportStudentList(LS, filename)) {
		printf("文件已保存到当前目录\n");
	} else {
		printf("导出失败！\n");
	}
	
	printf("==================================\n");
}

// 扩展功能：从文件导入学生（控制层）
void toImportStudentFromFile(StudentNode *&LS)
{
	printf("\n========== 导入学生名单 ==========\n");
	printf("文件格式要求：\n");
	printf("  第一行为表头，从第二行开始每行：学号,姓名,性别,班级\n");
	printf("  示例：\n");
	printf("    1001,张三,m,计科1班\n");
	printf("    1002,李四,f,软工2班\n");
	printf("--------------------------------\n");
	
	char filename[100];
	printf("请输入要导入的文件名：");
	scanf("%s", filename);
	
	importStudentFromFile(LS, filename);
	
	printf("==================================\n");
}
