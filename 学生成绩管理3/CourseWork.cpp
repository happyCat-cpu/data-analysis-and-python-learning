/**
  模型层（业务层）---实现 "课程" 实体的业务操作函数
  文件名：CourseWork.CPP
 */
#include <stdio.h> //系统头文件：导入系统输入输出函数scanf()和printf()
#include <malloc.h> //系统头文件：导入动态分配malloc()函数
#include <string.h> //系统头文件：导入字符串处理函数
#include "CourseWork.h" //用户头文件：导入课程实体业务层的相关操作函数
#include "DataType.h"
#define N 10 //课程数
//业务1：创建课程链表
void createCourse(CourseNode *&LC)
{
//1:定义课程数组 (样本课程)
	char course[N][50]={"高等数学","大学英语","线性代数","计算机导论",
		"C语言","数据结构","数据库系统","操作系统",
		"Java语言","单片机"};
//2:创建课程链表
	LC=(CourseNode*)malloc(sizeof(CourseNode)); //创建学生链表的头结点
	LC->cNext=NULL;
	CourseNode *pc,*r; //定义尾指针(使用尾插法创建链表) 
	r=LC;
	for(int i=0;i<10;i++)
	{
		pc=(CourseNode*)malloc(sizeof(CourseNode)); //生成课程结点
		pc->cId=i+1; //封装课程编号
		strcpy(pc->cName,course[i]); //封装课程名称
		r->cNext=pc; //尾插法
		r=pc;
	}
	r->cNext=NULL; //尾插法收尾
}
//业务2：显示全部课程
void displayCourse(CourseNode *LC)
{
//遍历课程链表
	CourseNode *pc=NULL; //定义课程链表结点
	pc=LC->cNext; //指向首结点
	while(pc!=NULL)
	{
		printf("%d\t%s\n",pc->cId,pc->cName); //输出课程编号和课程名称
		pc=pc->cNext; //下一个结点
	}
}
//业务3：根据课程编号取得课程名称
bool getCourseName(CourseNode *LC, int cId, char cName[])
{
	CourseNode *pc=NULL;
	pc=locateCourse(LC,cId); //查找定位课程
	if(pc==NULL) return false; //不存在课程
	else
	{
		strcpy(cName,pc->cName); //存在课程
		return true;
	}
}
//辅助业务1：根据课程编号定位课程
CourseNode* locateCourse(CourseNode *LC, int cId)
{
//遍历链表查找课程
	CourseNode *pc=NULL; //定义课程链表结点
	pc=LC->cNext; //指向首结点
	while(pc!=NULL && pc->cId!=cId)
		pc=pc->cNext; //下一个结点
	return pc;
}
//辅助业务2：统计课程数
int getCourseNumber(CourseNode *LC)
{
//遍历链表统计课程
	int count=0; //统计课程数
	CourseNode *pc=NULL;
	pc=LC->cNext; //指向首结点
	while(pc!=NULL)
	{
		count++;
		pc=pc->cNext; //下一个结点
	}
	return count;
}
//辅助业务3：取得所有课程的课程号和课程名称
bool getCourseIdsAndNames(CourseNode *LC, int cIds[])
{
//1:判断链表是否为空
	if(LC==NULL || LC->cNext==NULL) return false;
//2:链表非空，遍历取得课程号和课程名称
	int i=0; //数组下标
	CourseNode *pc=NULL;
	pc=LC->cNext; //指向首结点
	while(pc!=NULL)
	{
		cIds[i++]=pc->cId; //取得课程编号
		pc=pc->cNext; //下一个结点
	}
	return true;
}
// 扩展功能：根据课程编号删除课程（同时清空所有学生的该科成绩）
bool deleteCourseById(CourseNode *&LC, StudentNode *LS, int cId)
{
	if (LC == NULL || LC->cNext == NULL) {
		printf("课程链表为空，无法删除！\n");
		return false;
	}
	
	// ========== 第一步：查找并删除课程节点 ==========
	CourseNode *prev = LC;
	CourseNode *curr = LC->cNext;
	
	while (curr != NULL) {
		if (curr->cId == cId) {
			// 找到要删除的课程
			prev->cNext = curr->cNext;
			free(curr);
			printf("课程 [编号:%d] 已从课程表中删除！\n", cId);
			break;
		}
		prev = curr;
		curr = curr->cNext;
	}
	
	if (curr == NULL) {
		printf("未找到课程编号 %d 的课程！\n", cId);
		return false;
	}
	
	// ========== 第二步：遍历所有学生，删除该课程的成绩 ==========
	if (LS == NULL || LS->next == NULL) {
		printf("没有学生数据，无需清理成绩。\n");
		return true;
	}
	
	StudentNode *pStu = LS->next;  // 跳过头结点
	int deleteCount = 0;
	
	while (pStu != NULL) {
		ScoreNode *prevSc = NULL;
		ScoreNode *currSc = pStu->stu.LS;  // 学生成绩链表的头指针（注意：可能是带头结点或不带）
		
		// 假设成绩链表是带头结点的，如果不是请告知调整
		if (currSc != NULL && currSc->scNext != NULL) {
			prevSc = currSc;
			currSc = currSc->scNext;
			
			while (currSc != NULL) {
				if (currSc->cId == cId) {
					// 找到要删除的成绩节点
					prevSc->scNext = currSc->scNext;
					free(currSc);
					deleteCount++;
					break;  // 每个学生只有一门该课程的成绩
				}
				prevSc = currSc;
				currSc = currSc->scNext;
			}
		}
		
		pStu = pStu->next;
	}
	
	printf("已清理 %d 名学生的该课程成绩！\n", deleteCount);
	return true;
}
// 扩展功能：修改课程名称
bool updateCourseName(CourseNode *LC, int cId, char newName[])
{
	if (LC == NULL || LC->cNext == NULL) {
		printf("课程链表为空！\n");
		return false;
	}
	
	CourseNode *p = locateCourse(LC, cId);
	
	if (p == NULL) {
		printf("未找到课程编号 %d 的课程！\n", cId);
		return false;
	}
	
	printf("原课程名称：%s\n", p->cName);
	printf("新课程名称：%s\n", newName);
	
	strcpy(p->cName, newName);
	printf("课程名称修改成功！\n");
	
	return true;
}
