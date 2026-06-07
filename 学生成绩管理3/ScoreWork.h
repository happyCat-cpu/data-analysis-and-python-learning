#ifndef SCOREWORK_H
#define SCOREWORK_H
#include "DataType.h"
/**
  模型层（业务层）---声明 "成绩" 实体的业务操作函数
  文件名：ScoreWork.H
 */
//业务1：显示学生成绩
//mode: 1=全部成绩 2=班级成绩 3=个人成绩
void displayScore(StudentNode *L, Student stu, int mode, CourseNode *LC);
//业务2:增加一个学生的全部成绩
bool addScoreByStudent(StudentNode *&L, int id, CourseNode *LC);
//业务3:增加一门课程的全部成绩
bool addScoreByCourse(StudentNode *&L, int cId, CourseNode *LC);
//业务4:增加学生一个课程成绩
int addAScoreByStudent(StudentNode *&L, int id, int cId, CourseNode *LC);
//业务5:清空(销毁)一个学生的全部成绩
bool destroyScoreByStudent(StudentNode *&L, int id);
//业务6:清空(销毁)所有学生的全部成绩
void destroyALLScore(StudentNode *&L);
//业务7:删除学生一个课程成绩
int deleteAScoreByStudent(StudentNode *L, int id, int cId, CourseNode *LC);
//辅助业务1:定位学生成绩
ScoreNode* locateStudentScore(Student stu, int cId);
//辅助业务2：学生成绩链表排序（按课程号升序）
void sortStudentScoreByCid(Student &stu);
//辅助业务3：显示成绩表的表头
void showScoreTableHeader(CourseNode *LC);
//辅助业务4：显示一个学生的详细成绩
void showStudentScoreDetails(Student stu, CourseNode *LC);
// 扩展功能：成绩分布直方图
void showScoreHistogram(StudentNode *LS, CourseNode *LC, int cId);
#endif
