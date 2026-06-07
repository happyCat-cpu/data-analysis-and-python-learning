/**
  模型层（业务层）---实现 "学生" 实体的业务操作函数
  文件名：StudentWork.cpp
 */
#include <stdio.h> //系统头文件：导入系统输入输出函数scanf()和printf()
#include <malloc.h> //系统头文件：导入动态分配malloc()函数
#include <string.h> //系统头文件：导入字符串处理函数
#include "StudentWork.h" //用户头文件：导入学生实体业务层的相关操作函数
#define N 5 //学生样本的人数
#define M 10 //学生样本的成绩数
//业务1：初始化学生(创建5条样本数据) 
void initStudent(StudentNode *&L)
{
//1:创建头结点
	L=(StudentNode*)malloc(sizeof(StudentNode));
	L->next=NULL;
//2:定义样本数据 (5个学生、每个学生3个成绩) 
	Student stu[N]={{1,"Tom",'m',"bigdata1",NULL},
		{2,"Scott",'f',"bigdata1",NULL},
		{3,"Mary",'f',"bigdata1",NULL},
		{4,"Betty",'f',"bigdata2",NULL},
		{5,"Peter",'m',"bigdata2",NULL}};
	int score[N][M]={1,70,2,85,3,94,4,88,5,80,
		1,66,2,55,3,82,4,75,5,80,
		1,82,2,94,3,98,4,85,5,84,
		1,76,2,87,3,82,4,75,5,60,
		1,50,2,70,3,85,4,75,5,92};
//3:将样本数据插入链表
	int i,j;
	StudentNode *p; //定义学生链表结点
	ScoreNode *pSc; //定义成绩链表结点
	for(i=N-1;i>=0;i--)
	{
		p=(StudentNode*)malloc(sizeof(StudentNode)); //生成学生结点
		p->stu=stu[i]; //封装学生信息到学生结点
		p->stu.LS=(ScoreNode*)malloc(sizeof(ScoreNode));//创建学生的成绩链表
		p->stu.LS->scNext=NULL; //设置学生的成绩为空
		p->next=L->next; //使用头插法插入学生结点
		L->next=p;
		for(j=M-1;j>=0;)
		{
			pSc=(ScoreNode*)malloc(sizeof(ScoreNode)); //生成成绩结点
			pSc->score=score[i][j--]; //封装成绩到成绩结点
			pSc->cId=score[i][j--]; //封装课程id到成绩结点
//使用头插法插入成绩结点
			pSc->scNext=p->stu.LS->scNext;
			p->stu.LS->scNext=pSc;
		}
	}
	return;
}
//业务2：显示学生信息
//mode：1=全部学生 2=按班级 3=按学号
void displayStudent(StudentNode *L, Student stu, int mode)
{
	printf("学号\t姓名\t性别\t班级\n"); //输出表头
//1:定义变量
	int count=0; //保存统计的人数
	StudentNode *p; //定义学生结点指针
	p=L->next; //p指向链表首结点
//2:遍历学生链表
	while(p!=NULL)
	{
		if(mode==3 && p->stu.id==stu.id) //按学号输出
		{
			showStudentDetails(p->stu); //调用辅助业务1输出学生信息
			count++;
			break;
		}
		else if(mode==2 && strcmp(p->stu.className,stu.className)==0) //按班级输出
		{
			showStudentDetails(p->stu); //调用辅助业务1输出学生信息
			count++;
		}
		else if(mode==1) //输出全部学生
		{
			showStudentDetails(p->stu); //调用辅助业务1输出学生信息
			count++;
		}
		p=p->next; //处理下一个学生
	}
//3:输出查找统计结果
	if(mode==3)
	{
		if(count==0) printf("查无此人！\n");
	}
	else
		printf("总人数:%d人\n",count);
}
//业务3：增加学生
bool addStudent(StudentNode *&L, Student stu)
{
	StudentNode *pre,*p;
//1:封装增加的学生信息
	p=(StudentNode*)malloc(sizeof(StudentNode)); //生成一个学生结点
	p->stu=stu;
	p->stu.LS=(ScoreNode*)malloc(sizeof(ScoreNode)); //创建学生的成绩链表
	p->stu.LS->scNext=NULL; //设置学生的成绩为空
//2:定位到插入的位置(按学号递增顺序插入)
	pre=L; //指向头结点
	while(pre->next!=NULL && pre->next->stu.id<stu.id)
		pre=pre->next;
//3:插入到链表
	p->next=pre->next;
	pre->next=p;
	return true;
}
//业务4：修改学生
bool updateStudent(StudentNode *&L, Student oldStu, Student newStu)
{
	StudentNode *p;
//1:定位旧的学生
	p=locateStudent(L,oldStu.id); //调用辅助业务2查找学生
//2:用新学生替换旧学生
	newStu.LS=p->stu.LS; //保存学生的成绩
	p->stu=newStu; //新学生替换旧学生
	return true;
}
//业务5：删除学生
bool deleteStudent(StudentNode *&L, Student stu)
{
	StudentNode *pre,*p; //设置学生链表的同步指针
	ScoreNode *preSc,*pSc; //设置成绩链表的同步指针
//1:定位要删除的学生
	pre=L; //指向学生链表头结点
	while(pre->next!=NULL && pre->next->stu.id!=stu.id)
		pre=pre->next;
	p=pre->next; //指向要删除的学生
//2:删除学生成绩
	preSc=p->stu.LS; //指向成绩链表的头结点
	pSc=preSc->scNext; //指向成绩链表的首结点
	while(pSc!=NULL)
	{
		free(preSc);
		preSc=pSc;
		pSc=pSc->scNext;
	}
	free(preSc);
//3:删除学生信息
	pre->next=p->next;
	free(p); //删除学生结点
	return true;
}
//业务6：清空(销毁)所有学生
void destroyStudent(StudentNode *&L)
{
	if(L->next==NULL) return; //学生链表为空
	StudentNode *pre,*p; //定义学生链表的同步指针
	p=L->next; //p指向首结点
//1:先清空成绩链表
	ScoreNode *preSc, *pSc; //定义成绩链表的同步指针
	while(p!=NULL)
	{
		preSc=p->stu.LS; //指向成绩链表的头结点(前驱指针) 
		pSc=preSc->scNext; //指向成绩链表的后面结点(后继指针)
		while(pSc!=NULL)
		{
			free(preSc); //删除前驱结点
			preSc=pSc;
			pSc=pSc->scNext;
		}
		free(preSc); //删除最后一个结点
		p=p->next; //处理下一个学生的成绩 
	}
//2:后清空学生链表
	pre=L; //pre指向头结点
	p=pre->next; //p指向首结点
	while(p!=NULL)
	{
		free(pre); //删除前驱结点
		pre=p;
		p=p->next; //处理下一个学生
	}
	free(pre); //删除最后一个结点
	L->next=NULL;
}
//辅助业务1：显示一个学生的详细信息
void showStudentDetails(Student stu)
{
	printf("%d\t",stu.id); //学号
	printf("%s\t",stu.name); //姓名
	printf("%s\t",(stu.sex=='m')?"男":"女"); //性别
	printf("%s\t\n",stu.className); //班级名称
}
//辅助业务2：定位学生
StudentNode* locateStudent(StudentNode *L, int id)
{
//1:定义学生链表结点指针
	StudentNode *p;
	p=L->next; //指向学生链表的首结点
//2:遍历学生链表
	while(p!=NULL && p->stu.id!=id)
		p=p->next;
//3:返回结果
	return p; //返回前驱
}
// 扩展功能：按姓名模糊查找学生
void searchStudentByName(StudentNode *LS, char keyword[])
{
	// 检查链表是否有效（带头结点的情况）
	if (LS == NULL) {
		printf("学生链表未初始化！\n");
		return;
	}
	
	if (LS->next == NULL) {
		printf("暂无学生数据！请先添加学生。\n");
		return;
	}
	
	StudentNode *p = LS->next;
	int foundCount = 0;
	
	printf("\n========== 模糊查找结果 ==========\n");
	printf("关键词：%s\n", keyword);
	printf("--------------------------------\n");
	printf("学号\t姓名\t性别\t班级\n");
	printf("--------------------------------\n");
	
	while (p != NULL) {
		// 使用 strstr 判断姓名中是否包含关键词
		if (strstr(p->stu.name, keyword) != NULL) {
			printf("%d\t%s\t%c\t%s\n", 
				   p->stu.id, 
				   p->stu.name, 
				   p->stu.sex, 
				   p->stu.className);
			foundCount++;
		}
		p = p->next;
	}
	
	printf("--------------------------------\n");
	printf("共找到 %d 名学生\n", foundCount);
	printf("==================================\n");
	
	if (foundCount == 0) {
		printf("未找到姓名包含 \"%s\" 的学生！\n", keyword);
	}
}
// 扩展功能：导出学生名单到文件（CSV格式，可用Excel打开）
bool exportStudentList(StudentNode *LS, char filename[])
{
	if (LS == NULL || LS->next == NULL) {
		printf("暂无学生数据，无法导出！\n");
		return false;
	}
	
	FILE *fp = fopen(filename, "w");
	if (fp == NULL) {
		printf("无法创建文件 %s！\n", filename);
		return false;
	}
	
	// 写入CSV表头
	fprintf(fp, "学号,姓名,性别,班级\n");
	
	StudentNode *p = LS->next;
	int count = 0;
	
	while (p != NULL) {
		fprintf(fp, "%d,%s,%c,%s\n", 
				p->stu.id, 
				p->stu.name, 
				p->stu.sex, 
				p->stu.className);
		count++;
		p = p->next;
	}
	
	fclose(fp);
	printf("成功导出 %d 名学生到文件 %s\n", count, filename);
	return true;
}
// 扩展功能：从文件导入学生（批量添加）
bool importStudentFromFile(StudentNode *&LS, char filename[])
{
	FILE *fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("无法打开文件 %s！\n", filename);
		return false;
	}
	
	// 先检查链表是否已初始化（带头结点）
	if (LS == NULL) {
		LS = (StudentNode*)malloc(sizeof(StudentNode));
		LS->next = NULL;
	}
	
	char line[200];
	int successCount = 0;
	int failCount = 0;
	
	// 跳过表头行（第一行）
	fgets(line, sizeof(line), fp);
	
	// 逐行读取数据
	while (fgets(line, sizeof(line), fp) != NULL) {
		Student newStu;
		char sexChar;
		
		// 解析CSV格式：学号,姓名,性别,班级
		int result = sscanf(line, "%d,%[^,],%c,%[^\n]", 
							&newStu.id, 
							newStu.name, 
							&sexChar, 
							newStu.className);
		
		if (result != 4) {
			failCount++;
			continue;  // 格式错误，跳过这一行
		}
		
		newStu.sex = sexChar;
		newStu.LS = (ScoreNode*)malloc(sizeof(ScoreNode));  // 创建成绩链表头结点
		newStu.LS->scNext = NULL;
		
		// 检查学号是否已存在
		StudentNode *exist = locateStudent(LS, newStu.id);
		if (exist != NULL) {
			failCount++;
			continue;  // 学号已存在，跳过
		}
		
		// 添加到链表
		addStudent(LS, newStu);
		successCount++;
	}
	
	fclose(fp);
	printf("导入完成：成功 %d 人，失败 %d 人\n", successCount, failCount);
	return successCount > 0;
}
