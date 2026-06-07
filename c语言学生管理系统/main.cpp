#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataType.h"
#include "CourseController.h"
#include "StudentController.h"
#include "ScoreController.h"
//测试课程的各业务
void testCourse(CourseNode *&LC)
{
	printf("课程业务1测试...\n");
	toCreateCourse(LC);
// printf("课程业务2测试...\n");
// toDisplayCourse(LC);
// printf("课程业务3测试...\n");
// toGetCourseName(LC);
}
//测试学生的各业务
void testStudent(StudentNode *&L, CourseNode *&LC)
{
	printf("业务1--初始化学生\n");
	toInitStudent(L);
	printf("业务3--显示全部学生\n");
	toDisplayALLStudent(L);
// printf("业务3--显示班级学生\n");
// toDisplayStudentByClassName(L);
// printf("业务3--显示一个学生\n");
// toDisplayStudentById(L); 
// printf("业务4--增加学生\n");
// toAddStudent(L);
// toDisplayALLStudent(L);
// toAddStudent(L);
// toDisplayALLStudent(L);
// printf("业务5--修改学生\n");
// toUpdateStudent(L);
// toDisplayALLStudent(L);
// printf("业务6--删除学生\n");
// toDeleteStudent(L);
// toDisplayALLStudent(L);
// toDeleteStudent(L);
// toDisplayALLStudent(L);
// printf("业务2--销毁学生\n");
// toDestroyStudent(L);
// toDisplayALLStudent(L);
}
//测试成绩的各业务
void testScore(StudentNode *&L, CourseNode *&LC)
{
	printf("成绩业务1--显示所有学生的成绩\n");
	toDisplayAllScore(L,LC);
// printf("成绩业务1--显示班级学生的成绩\n");
// toDisplayScoreByClassName(L);
// printf("成绩业务1--显示一个学生的成绩\n");
// toDisplayScoreById(L);
// printf("成绩业务2--增加学生所有的成绩\n");
// toAddScoreByStudent(L,LC); 
// toDisplayAllScore(L);
// printf("成绩业务3--增加课程所有的成绩\n");
// toAddScoreByCourse(L,LC); 
// toDisplayAllScore(L);
// printf("成绩业务4--增加学生一个课程成绩\n");
// toAddAScoreByStudent(L,LC); 
// toAddAScoreByStudent(L,LC); 
// toAddAScoreByStudent(L,LC); 
// toDisplayAllScore(L);
// printf("成绩业务5--清空一个学生的成绩\n");
// toDestroyScoreByStudent(L);
// toDisplayAllScore(L);
// printf("成绩业务6--清空所有学生的成绩\n");
// toDestroyALLScore(L);
// toDisplayAllScore(L);
// printf("成绩业务7--删除学生一个课程成绩\n");
// toDeleteAScoreByStudent(L,LC); 
// toDeleteAScoreByStudent(L,LC); 
// toDeleteAScoreByStudent(L,LC); 
// toDisplayAllScore(L);
}
//主菜单函数
void toShowMenu()
{
	system("cls");
	printf("******成绩管理系统 v2026(已添加六个新功能)******\n");
	printf(" 主菜单\n\n");
	printf(" [课程管理]\n");
	printf(" A)创建课程 B)显示课程 C)查找课程名称\n");
	printf(" V)删除课程 W)修改课程名称	[新功能]\n\n");  // 新增
	printf(" [学生管理]\n");
	printf(" D)初始化学生 E)显示全部学生 F)显示班级学生 G)显示一个学生\n");
	printf(" H)增加学生 I)修改学生 J)删除学生 K)销毁学生\n");
	printf(" Z)按姓名模糊查找 U)导出学生名单 Y)从文件导入学生	[新功能]\n\n");  // 新增
	printf(" [成绩管理]\n");
	printf(" L)显示所有成绩 M)显示班级成绩 N)显示学生成绩\n");
	printf(" O)增加学生全部成绩 P)增加课程全部成绩 Q)增加学生一个成绩\n");
	printf(" R)清空一个学生成绩 S)清空所有学生成绩 T)删除学生一个成绩\n");
	printf(" 1)成绩分布直方图	[新功能]\n\n");  // 新增
	printf(" X)退出系统\n\n");
	printf("请选择:");
}
//主函数
int main()
{
	StudentNode *L=NULL; //学生链表的头结点(公共类型) 
	CourseNode *LC=NULL; //课程链表的头结点
	
	/*
	6-22：应该在main中，建立带头结点的空链表，课程和学生实体
	*/
	char choice; //保存选择的菜单
	bool flag=true; //运行标志变量
	while(flag)
	{
		toShowMenu(); //显示菜单
		scanf("%c",&choice); //输入菜单
		if(choice>='A' && choice<='Z') choice+=32; //转换为小写字母
		switch(choice)
		{
//课程管理
			case 'a': toCreateCourse(LC); break;
			case 'b': toDisplayCourse(LC); break;
			case 'c': toGetCourseName(LC); break;
//学生管理
			case 'd': toInitStudent(L); break;
			case 'e': toDisplayALLStudent(L); break;
			case 'f': toDisplayStudentByClassName(L); break;
			case 'g': toDisplayStudentById(L); break;
			case 'h': toAddStudent(L); break;
			case 'i': toUpdateStudent(L); break;
			case 'j': toDeleteStudent(L); break;
			case 'k': toDestroyStudent(L); break;
//成绩管理
			case 'l': toDisplayAllScore(L,LC); break;
			case 'm': toDisplayScoreByClassName(L,LC); break;
			case 'n': toDisplayScoreById(L,LC); break;
			case 'o': toAddScoreByStudent(L,LC); break;
			case 'p': toAddScoreByCourse(L,LC); break;
			case 'q': toAddAScoreByStudent(L,LC); break;
			case 'r': toDestroyScoreByStudent(L); break;
			case 's': toDestroyALLScore(L); break;
			case 't': toDeleteAScoreByStudent(L,LC); break;
			case 'v':toDeleteCourse(LC, L);  break;  // LS 是你的学生链表头指针
			case 'w':toUpdateCourseName(LC); break;
			case 'z':toSearchStudentByName(L); break;
			case 'u': toExportStudentList(L); break;
			case 'y': toImportStudentFromFile(L); break;
			case '1':toShowScoreHistogram(L, LC); break;
//退出系统
			case 'x': printf("Bye!!!"); flag=false; //退出系统
		}
		getchar(); //吸收回车键
		printf("\n");
		system("pause");
	}
// testCourse(LC);
// testStudent(L,LC);
// testScore(L,LC);
	return 0;
}
