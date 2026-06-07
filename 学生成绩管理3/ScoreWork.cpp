/**
  模型层（业务层）---实现 "成绩" 实体的业务操作函数 
  文件名：ScoreWork.CPP
 */
#include <stdio.h> //系统头文件：导入系统输入输出函数scanf()和printf()
#include <malloc.h> //系统头文件：导入动态分配malloc()函数
#include <string.h> //系统头文件：导入字符串处理函数
#include "DataType.h"
#include "StudentWork.h" //用户头文件：导入学生实体业务层的相关操作函数
#include "CourseWork.h" //用户头文件：导入课程实体业务层的相关操作函数
#include "ScoreWork.h" //用户头文件：导入成绩实体业务层的相关操作函数
//业务1：显示学生成绩
//mode: 1=全部成绩 2=班级成绩 3=个人成绩
void displayScore(StudentNode *L, Student stu, int mode, CourseNode *LC)
{
//1:显示表头
	printf("学号\t姓名\t 班级\t\t"); //输出表头 (6-26:输出尽量放控制层)
	CourseNode *pc=LC->cNext;
	while(pc!=NULL)
	{
		printf("#%-3d",pc->cId);
		pc=pc->cNext;
	}
	printf("\n");
//2:遍历学生链表,输出学生的成绩
	StudentNode *p; //定义学生结点指针
	p=L->next; //p指向学生链表首结点
	while(p!=NULL)
	{
//按三种模式筛选学生
		if(mode==3 && p->stu.id==stu.id) //模式3：输出个人成绩
		{
			showStudentScoreDetails(p->stu,LC); //调用业务输出学生信息
			break;
		}
		else if(mode==2 && strcmp(p->stu.className,stu.className)==0)
//模式2：输出班级成绩
			showStudentScoreDetails(p->stu,LC); //调用业务输出学生信息
		else if(mode==1) //模式2：输出全部学生成绩
			showStudentScoreDetails(p->stu,LC); //调用业务输出学生信息
		p=p->next; //下一个学生
	}
}
//业务2：增加一个学生的全部成绩
bool addScoreByStudent(StudentNode *&L, int id, CourseNode *LC)
{
//1:调用业务清空学生的所有成绩
	if(destroyScoreByStudent(L,id)==false) //未找到学生，清空失败
		return false;
//2:查找定位学生
	StudentNode *p; //定义学生链表的结点
	p=locateStudent(L,id); //定位学生
//3:输入并保存所有成绩
	int score; //定义成绩变量 score
	CourseNode *pc=LC->cNext; //定义课程链表结点,并指向首结点
	ScoreNode *pSc,*r; //定义成绩链表的结点指针
	pSc=r=p->stu.LS;
//6-28: 不能用i作循环, 因为课程号不一定连续
	while(pc!=NULL) //遍历所有课程，输入成绩
	{
		printf("#%d[%s]: ",pc->cId,pc->cName); //循环输出课程编号和名称
		scanf("%d",&score); //循环输入成绩
		pSc=(ScoreNode*)malloc(sizeof(ScoreNode)); //生成成绩结点
		pSc->cId=pc->cId; //保存课程号
		pSc->score=score; //保存成绩
		r->scNext=pSc; //尾插法插入成绩结点
		r=pSc; //更新尾指针
		pc=pc->cNext; //处理下一门课程
	}
	r->scNext=NULL; //尾插法收尾
	return true;
}
//业务3:增加一门课程的全部成绩
bool addScoreByCourse(StudentNode *&L, int cId, CourseNode *LC)
{
//1:查找课程
	CourseNode *pc; //定义课程链表结点
	pc=locateCourse(LC,cId); //查找定位课程
	if(pc==NULL) return false; //课程不存在
	printf("请输入[%s]课程全部学生的成绩\n",pc->cName);
//2:遍历学生链表
	ScoreNode *pSc; //定义成绩链表结点 
	StudentNode *p=L->next; //定义学生链表结点，并指向首结点
	int score; //定义成绩变量
	while(p!=NULL)
	{
		printf("%s：",p->stu.name); //循环输出姓名
		scanf("%d",&score); //循环输入成绩
		pSc=locateStudentScore(p->stu,cId); //定位学生的课程成绩
		if(pSc==NULL) //不存在旧成绩
		{
			pSc=(ScoreNode*)malloc(sizeof(ScoreNode)); //生成成绩的新结点
			pSc->cId=cId; //保存课程号
			pSc->score=score; //保存成绩
			pSc->scNext=p->stu.LS->scNext; //使用头插法插入成绩结点
			p->stu.LS->scNext=pSc;
			sortStudentScoreByCid(p->stu); //成绩链表重新排序
		}
		else //找到学生的旧成绩(成绩已存在) 
			pSc->score=score; //替换旧成绩
		p=p->next; //处理下一个学生
	}
	return true;
}
//业务4:增加学生一个课程成绩
int addAScoreByStudent(StudentNode *&L, int id, int cId, CourseNode *LC)
{
//1:查找课程
	CourseNode *pc; //定义课程链表结点
	pc=locateCourse(LC,cId); //查找定位课程
	if(pc==NULL) return 1; //课程不存在
//2:查找定位学生
	StudentNode *p; //定义学生链表的结点
	p=locateStudent(L,id); //查找定位学生
	if(p==NULL) return 2; //未找到学生
//3:输入成绩
	int score; //定义成绩变量
	printf("请输入学生%s[%s]课程的成绩：",p->stu.name,pc->cName);
	scanf("%d",&score); //输入成绩
//4:保存成绩(插入或替换) 
	ScoreNode *pSc; //定义成绩链表的结点
	pSc=locateStudentScore(p->stu,cId); //查找定位课程成绩
	if(pSc==NULL) //不存在旧成绩
		//(插入新成绩)
	{
		pSc=(ScoreNode*)malloc(sizeof(ScoreNode)); //生成成绩结点
		pSc->cId=cId; //保存课程号
		pSc->score=score; //保存成绩
		pSc->scNext=p->stu.LS->scNext; //使用头插法插入结点
		p->stu.LS->scNext=pSc;
		sortStudentScoreByCid(p->stu); //成绩链表重新排序
	}
	else //存在旧成绩 (更新旧成绩) 
		pSc->score=score; //替换旧成绩
	return 0;
}
//业务5：清空(销毁)一个学生的全部成绩
bool destroyScoreByStudent(StudentNode *&L, int id)
{
//1:查找定位学生
	StudentNode *p; //定义学生链表的结点
	p=locateStudent(L,id); //查找定位学生
	if(p==NULL) return false; //学生不存在，直接返回
//2:删除学生的所有成绩
	ScoreNode *preSc,*pSc; //定义同步指针
	preSc=p->stu.LS->scNext; //指向学生成绩链表的首结点
	if(preSc==NULL)
		return true; //学生的成绩链表为空，返回
	pSc=preSc->scNext; //指向学生成绩链表的第2个结点
	while(pSc!=NULL) //遍历删除成绩结点
	{
		free(preSc);
		preSc=pSc;
		pSc=pSc->scNext;
	}
	free(preSc);
//3:收尾工作
	p->stu.LS->scNext=NULL; //学生的成绩链表置空(保留头结点)
	return true;
}
//业务6：清空(销毁)所有学生的全部成绩
void destroyALLScore(StudentNode *&L)
{
//1:遍历学生链表
	StudentNode *p; //定义学生链表的结点
	p=L->next; //指向学生链表的首结点
	while(p!=NULL)
	{
//2:删除每个学生的所有成绩
		destroyScoreByStudent(L, p->stu.id); //调用业务，清空学生成绩
		p=p->next; //处理下一个学生
	}
}
//业务7:删除学生一个课程成绩
int deleteAScoreByStudent(StudentNode *L, int id, int cId, CourseNode *LC)
{
//1:查找课程
	CourseNode *pc; //定义课程链表结点
	pc=locateCourse(LC,cId); //查找定位课程
	if(pc==NULL) return 1; //课程不存在，返回
//2:查找定位学生
	StudentNode *p; //定义学生链表的结点
	p=locateStudent(L,id); //查找定位学生
	if(p==NULL) return 2; //未找到学生，返回
//3:查找定位成绩
	ScoreNode *preSc,*pSc; //定义成绩链表的结点
	pSc=locateStudentScore(p->stu,cId); //查找定位课程成绩
	if(pSc==NULL) return 3; //未找到课程成绩，返回
//4:定位删除结点的前驱
	preSc=p->stu.LS; //指向成绩链表的头结点
	while(preSc->scNext!=NULL && preSc->scNext->cId!=cId)
		preSc=preSc->scNext; //指针移动
//5:删除成绩
	pSc=preSc->scNext;
	preSc->scNext=pSc->scNext;
	free(pSc); //删除结点
	return 0;
}
//辅助业务1:定位学生成绩（根据学生学号、课程编号）
ScoreNode* locateStudentScore(Student stu, int cId)
{
	ScoreNode *pSc=stu.LS->scNext; //定义成绩链表结点，并指向首结点
//遍历成绩链表，定位学生成绩
	while(pSc!=NULL && pSc->cId!=cId)
		pSc=pSc->scNext; //下一个成绩结点
//返回结果值
	return pSc;
}
//辅助业务2：学生成绩链表排序（按课程号升序）
void sortStudentScoreByCid(Student &stu)
{
//1：链表为空或只有一个结点，直接返回
	if(stu.LS->scNext==NULL) return;
//2：使用插入法排序
	ScoreNode *preSc,*pSc,*qSc;
	pSc=stu.LS->scNext->scNext; //指向成绩链表的第2个结点
	stu.LS->scNext->scNext=NULL; //第1个结点后面断开链表
	while(pSc!=NULL)
	{
		qSc=pSc->scNext; //临时保存后面的结点
		preSc=stu.LS; //指向头结点
//定位到插入位置
		while(preSc->scNext!=NULL && preSc->scNext->cId<pSc->cId)
			preSc=preSc->scNext;
//插入结点
		pSc->scNext=preSc->scNext;
		preSc->scNext=pSc;
		pSc=qSc; //遍历链表剩余的结点
	}
}
//辅助业务3：显示成绩表的表头
void showScoreTableHeader(CourseNode *LC)
{
//定义课程号和课程名称数组
	int n=getCourseNumber(LC);
	int *cIds=(int*)malloc(n*sizeof(int)); //动态一维数组
//取得课程号
	if(getCourseIdsAndNames(LC,cIds)==false)
		return;
//输出表头
	printf("学号 姓名 班级\n"); //输出表头 (6-26:输出尽量放控制层)
	for(int i=0;i<n;i++)
	{
		printf("#%d\t",cIds[i]);
	}
}
//辅助业务4：显示一个学生的详细成绩
void showStudentScoreDetails(Student stu, CourseNode *LC)
{
//1:输出学生基本信息
	printf("%-8d",stu.id); //输出学号
	printf("%-10s",stu.name); //输出姓名
	printf("%-14s",stu.className); //输出班级名称
//2:遍历成绩链表
	CourseNode *pc; //定义课程链表结点指针
	ScoreNode *pSc; //定义成绩链表结点指针
	pc=LC->cNext; //pc指向课程链表的首结点
	pSc=stu.LS->scNext; //pSc指向成绩链表的首结点
	while(pSc!=NULL && pc!=NULL)
	{
		if(pSc->cId==pc->cId) //两个链表的课程号相同
		{
			printf("%-4d",pSc->score); //输出成绩
			pc=pc->cNext; //下一门课程
		}
		else
		{
			printf(" "); //输出空位置(4个空格)
			pc=pc->cNext; //下一门课程
			continue; //循环短路
		}
		pSc=pSc->scNext; //下一个成绩
	}
	printf("\n");
}
// 扩展功能：成绩分布直方图（文本版）
void showScoreHistogram(StudentNode *LS, CourseNode *LC, int cId)
{
	if (LS == NULL || LS->next == NULL) {
		printf("暂无学生数据！\n");
		return;
	}
	
	// 检查课程是否存在
	CourseNode *pCourse = locateCourse(LC, cId);
	if (pCourse == NULL) {
		printf("未找到课程编号 %d 的课程！\n", cId);
		return;
	}
	
	// 成绩分段计数器
	int level1 = 0;  // 0-59
	int level2 = 0;  // 60-69
	int level3 = 0;  // 70-79
	int level4 = 0;  // 80-89
	int level5 = 0;  // 90-100
	
	StudentNode *pStu = LS->next;
	int totalCount = 0;  // 有成绩的学生数
	
	while (pStu != NULL) {
		// 查找该学生是否有这门课的成绩
		ScoreNode *pSc = pStu->stu.LS;
		if (pSc != NULL) {
			pSc = pSc->scNext;  // 跳过头结点
			while (pSc != NULL) {
				if (pSc->cId == cId) {
					int score = pSc->score;
					if (score >= 0 && score <= 59) level1++;
					else if (score >= 60 && score <= 69) level2++;
					else if (score >= 70 && score <= 79) level3++;
					else if (score >= 80 && score <= 89) level4++;
					else if (score >= 90 && score <= 100) level5++;
					totalCount++;
					break;
				}
				pSc = pSc->scNext;
			}
		}
		pStu = pStu->next;
	}
	
	if (totalCount == 0) {
		printf("没有学生选修课程 【%s】 或没有成绩记录！\n", pCourse->cName);
		return;
	}
	
	// 输出直方图
	printf("\n========== 【%s】成绩分布直方图 ==========\n", pCourse->cName);
	printf("=========================================\n");
	printf("分数段\t人数\t直方图\n");
	printf("-----------------------------------------\n");
	
	// 计算最大人数用于缩放（让直方图显示适中）
	int maxCount = level1;
	if (level2 > maxCount) maxCount = level2;
	if (level3 > maxCount) maxCount = level3;
	if (level4 > maxCount) maxCount = level4;
	if (level5 > maxCount) maxCount = level5;
	
	// 缩放比例：如果最大人数超过20，每个*代表2人
	int scale = 1;
	if (maxCount > 20) scale = 2;
	
	// 输出每个分数段的直方图
	printf("90-100\t%d\t", level5);
	for (int i = 0; i < level5 / scale; i++) printf("*");
	if (level5 > 0) printf(" (%d人)\n", level5);
	else printf("(0人)\n");
	
	printf("80-89\t%d\t", level4);
	for (int i = 0; i < level4 / scale; i++) printf("*");
	if (level4 > 0) printf(" (%d人)\n", level4);
	else printf("(0人)\n");
	
	printf("70-79\t%d\t", level3);
	for (int i = 0; i < level3 / scale; i++) printf("*");
	if (level3 > 0) printf(" (%d人)\n", level3);
	else printf("(0人)\n");
	
	printf("60-69\t%d\t", level2);
	for (int i = 0; i < level2 / scale; i++) printf("*");
	if (level2 > 0) printf(" (%d人)\n", level2);
	else printf("(0人)\n");
	
	printf("0-59\t%d\t", level1);
	for (int i = 0; i < level1 / scale; i++) printf("*");
	if (level1 > 0) printf(" (%d人)\n", level1);
	else printf("(0人)\n");
	
	printf("-----------------------------------------\n");
	printf("参考人数：%d人\n", totalCount);
	
	// 计算及格率、优秀率
	int passCount = level2 + level3 + level4 + level5;
	int excellentCount = level4 + level5;
	printf("及格率：%.1f%%\n", (float)passCount / totalCount * 100);
	printf("优秀率(≥80)：%.1f%%\n", (float)excellentCount / totalCount * 100);
	printf("=========================================\n");
}
