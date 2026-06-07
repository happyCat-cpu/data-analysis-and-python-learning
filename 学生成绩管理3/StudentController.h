#ifndef STUDENTCONTROLLER_H
#define STUDENTCONTROLLER_H
#include "DataType.h"
/**
  视图控制层---声明 "学生" 实体的流程控制及视图函数
  文件名：StudentController.H
 */
#include "DataType.h"
//调用业务1：初始化学生
void toInitStudent(StudentNode *&L);
//调用业务2：输出全部学生
void toDisplayALLStudent(StudentNode *L);
//调用业务2：输出班级的学生
void toDisplayStudentByClassName(StudentNode *L);
//调用业务2：输出一个学生
void toDisplayStudentById(StudentNode *L);
//调用业务3：增加学生
void toAddStudent(StudentNode *&L);
//调用业务4：修改学生
void toUpdateStudent(StudentNode *&L);
//调用业务5：删除学生
void toDeleteStudent(StudentNode *&L);
//调用业务6：清空(销毁)所有学生
void toDestroyStudent(StudentNode *&L);
// 扩展功能：按姓名模糊查找学生（控制层）
void toSearchStudentByName(StudentNode *LS);
// 扩展功能：导出学生名单到文件（控制层）
void toExportStudentList(StudentNode *LS);
// 扩展功能：从文件导入学生（控制层）
void toImportStudentFromFile(StudentNode *&LS);
#endif
