/**
  视图控制层---实现 "成绩" 实体的流程控制及视图函数
  文件名：ScoreController.CPP
 */
#include <stdio.h>
#include "ScoreWork.h"
#include "CourseWork.h"
//调用成绩业务1:显示所有学生的成绩
void toDisplayAllScore(StudentNode *L, CourseNode *LC)
{
	Student stu; //定义空学生
	displayScore(L,stu,1,LC); //调用业务1(mode=1) 
}
//调用成绩业务1:显示班级学生的成绩
void toDisplayScoreByClassName(StudentNode *L, CourseNode *LC)
{
	Student stu; //定义空学生
	printf("请输入班级名称:");
	scanf("%s",stu.className);
	displayScore(L,stu,2,LC); //调用业务1(mode=2)
}
//调用成绩业务1:显示一个学生的成绩
void toDisplayScoreById(StudentNode *L, CourseNode *LC)
{
	Student stu; //定义空学生
	printf("请学生学号:");
	scanf("%d",&stu.id);
	displayScore(L,stu,3,LC); //调用业务1(mode=3)
}
//调用成绩业务2:增加一个学生的全部成绩
void toAddScoreByStudent(StudentNode *&L, CourseNode *LC)
{
//1:输入学生学号
	int id;
	printf("请输入学生学号:");
	scanf("%d",&id);
//2:调用业务输入所有课程的成绩
	if(addScoreByStudent(L,id,LC)==false)
		printf("学生不存在，增加成绩失败！\n");
	else
		printf("增加学生成绩成功！\n");
}
//调用成绩业务3:增加一门课程的成绩
void toAddScoreByCourse(StudentNode *&L, CourseNode *LC)
{
//1:输入课程号
	int cId;
	printf("请输入课程号:");
	scanf("%d",&cId);
//2:调用业务输入所有学生的成绩
	if(addScoreByCourse(L,cId,LC)==false)
		printf("课程不存在，增加成绩失败！\n");
	else
		printf("增加课程成绩成功！\n");
}
//调用成绩业务4:增加学生一个课程的成绩
void toAddAScoreByStudent(StudentNode *&L, CourseNode *LC)
{
//1:输入学号和课程号
	int id,cId;
	printf("请输入学号和课程号:");
	scanf("%d %d",&id,&cId);
//2:调用业务增加学生的一个成绩
	int rtnValue=addAScoreByStudent(L,id,cId,LC);
	if(rtnValue==1)
		printf("课程不存在，增加失败！\n");
	else if(rtnValue==2)
		printf("未找到学生，增加失败！\n");
	else
		printf("增加课程成绩成功！\n");
}
//调用成绩业务5:清空(销毁)一个学生的全部成绩
void toDestroyScoreByStudent(StudentNode *&L)
{
//1:输入学生学号
	int id;
	printf("请输入学生学号:");
	scanf("%d",&id);
//2:调用业务清空学生成绩
	if(destroyScoreByStudent(L,id)==false)
		printf("学号为%d的学生不存在，清空学生成绩失败！\n",id);
	else
		printf("学号为%d的学生成绩已经被清空！\n",id);
}
//调用成绩业务6:清空(销毁)所有学生的全部成绩
void toDestroyALLScore(StudentNode *&L)
{
	destroyALLScore(L);
	printf("所有学生的全部成绩被清空！\n");
}
//调用成绩业务7:删除学生一个课程成绩
void toDeleteAScoreByStudent(StudentNode *L, CourseNode *LC)
{
//1:输入学号和课程号
	int id,cId;
	printf("请输入学号和课程号:");
	scanf("%d %d",&id,&cId);
//2:调用业务删除学生的一个成绩
	int rtnValue=deleteAScoreByStudent(L,id,cId,LC);
	if(rtnValue==1)
		printf("课程不存在，删除失败！\n");
	else if(rtnValue==2)
		printf("未找到学生，删除失败！\n");
	else if(rtnValue==3)
		printf("未找到成绩，删除失败！\n");
	else
		printf("删除课程成绩成功！\n");
}
// 扩展功能：成绩分布直方图（控制层）
void toShowScoreHistogram(StudentNode *LS, CourseNode *LC)
{
	printf("\n========== 成绩分布直方图 ==========\n");
	
	if (LC == NULL || LC->cNext == NULL) {
		printf("暂无课程数据，请先创建课程！\n");
		return;
	}
	
	if (LS == NULL || LS->next == NULL) {
		printf("暂无学生数据！\n");
		return;
	}
	
	// 显示所有课程供用户选择
	displayCourse(LC);
	
	int cId;
	printf("\n请输入要查看的课程编号：");
	scanf("%d", &cId);
	
	showScoreHistogram(LS, LC, cId);
	
	printf("====================================\n");
}
