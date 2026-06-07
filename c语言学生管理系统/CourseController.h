#ifndef COURSECONTROLLER_H
#define COURSECONTROLLER_H
#include "DataType.h"
#include "CourseWork.h"
/**
  视图控制层---声明 "课程" 实体的流程控制及视图函数
  文件名：CourseController.h
  */
//调用业务1：创建课程链表
void toCreateCourse(CourseNode *&LC);
//调用业务2：显示全部课程
void toDisplayCourse(CourseNode *LC);
//调用业务3：根据课程编号取得课程名称
void toGetCourseName(CourseNode *LC);
// 扩展功能：删除课程（控制层）
void toDeleteCourse(CourseNode *&LC, StudentNode *LS);
// 扩展功能：修改课程名称（控制层）
void toUpdateCourseName(CourseNode *LC);
#endif
