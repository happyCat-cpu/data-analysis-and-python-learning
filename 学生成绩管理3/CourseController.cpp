/**
  视图控制层---实现 "课程" 实体的流程控制及视图函数
  文件名：CourseController.CPP
 */
#include <stdio.h> //系统头文件：导入系统输入输出函数scanf()和printf()
#include "CourseWork.h" //用户头文件：导入课程实体业务层的相关操作函数

//调用业务1：创建课程链表
void toCreateCourse(CourseNode *&LC)
{
	createCourse(LC);
	printf("课程链表创建完成！\n");
}

//调用业务2：显示全部课程
void toDisplayCourse(CourseNode *LC)
{
	printf("编号\t课程名称\n"); //输出表头
	displayCourse(LC); //调用业务2，实现功能
	printf("\n课程总数：%d 门\n", getCourseNumber(LC));  //额外增加输出课程总数
}

//调用业务3：根据课程编号取得课程名称
void toGetCourseName(CourseNode *LC)
{
	int cId; //定义课程号
	char cName[20]; //定义课程名称
	printf("请输入课程号:");
	scanf("%d",&cId); //输入课程号
	if(getCourseName(LC,cId,cName))
		printf("课程名称:%s\n",cName);
	else
		printf("查无课程！\n");
}
// 扩展功能：删除课程（控制层）
void toDeleteCourse(CourseNode *&LC, StudentNode *LS)
{
	printf("\n========== 删除课程 ==========\n");
	
	if (LC == NULL || LC->cNext == NULL) {
		printf("暂无课程数据，无法删除！\n");
		return;
	}
	
	// 先显示所有课程供用户选择
	displayCourse(LC);
	
	int cId;
	printf("\n请输入要删除的课程编号：");
	scanf("%d", &cId);
	
	char confirm;
	printf("确认删除课程编号 %d 及其所有学生的该科成绩？(y/n)：", cId);
	scanf(" %c", &confirm);
	
	if (confirm == 'y' || confirm == 'Y') {
		if (deleteCourseById(LC, LS, cId)) {
			printf("课程删除成功！\n");
		} else {
			printf("课程删除失败！\n");
		}
	} else {
		printf("已取消删除操作。\n");
	}
	
	printf("==============================\n");
}
// 扩展功能：修改课程名称（控制层）
void toUpdateCourseName(CourseNode *LC)
{
	printf("\n========== 修改课程名称 ==========\n");
	
	if (LC == NULL || LC->cNext == NULL) {
		printf("暂无课程数据，请先创建课程！\n");
		return;
	}
	
	// 先显示所有课程供用户选择
	displayCourse(LC);
	
	int cId;
	char newName[20];
	
	printf("\n请输入要修改的课程编号：");
	scanf("%d", &cId);
	
	printf("请输入新的课程名称：");
	scanf("%s", newName);
	
	char confirm;
	printf("确认将课程编号 %d 的名称修改为 \"%s\"？(y/n)：", cId, newName);
	scanf(" %c", &confirm);
	
	if (confirm == 'y' || confirm == 'Y') {
		if (updateCourseName(LC, cId, newName)) {
			printf("修改成功！\n");
		} else {
			printf("修改失败！\n");
		}
	} else {
		printf("已取消修改操作。\n");
	}
	
	printf("==================================\n");
}
