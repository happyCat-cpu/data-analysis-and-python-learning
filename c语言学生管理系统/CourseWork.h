#ifndef COURSEWORK_H
#define COURSEWORK_H
#include "DataType.h"
/**
  模型层（业务层）头文件---声明 "课程" 实体的业务操作函数
  文件名：CourseWork.h
 */
//业务1：创建课程链表
void createCourse(CourseNode *&LC);
//业务2：显示全部课程
void displayCourse(CourseNode *LC);
//业务3：根据课程编号取得课程名称
bool getCourseName(CourseNode *LC, int cId, char cName[]);
//辅助业务1：根据课程编号定位课程
CourseNode* locateCourse(CourseNode *LC, int cId);
//辅助业务2：统计课程数
int getCourseNumber(CourseNode *LC);
//辅助业务3：取得所有课程的课程号和课程名称
bool getCourseIdsAndNames(CourseNode *LC, int cIds[]);
// 扩展功能：根据课程编号删除课程（同时清空所有学生的该科成绩）
bool deleteCourseById(CourseNode *&LC, StudentNode *LS, int cId);
// 扩展功能：修改课程名称
bool updateCourseName(CourseNode *LC, int cId, char newName[]);
#endif
