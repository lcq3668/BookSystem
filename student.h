#ifndef STUDENT_H
#define STUDENT_H

struct Student{
        char name[16];
        char department[18];
        char phoneNumber[14];
        char dateGraduating[11];                           // 截止日期是毕业日期
        char ID[13];
        struct Student * next;
        char sexual[16];    
};
typedef struct Student Student;
// 读者学号 ，读者姓名、性别、电话、所在院系、截止日期等。 截止日期是毕业之时
void setName(Student* stu,const char* name);
void setDepartment(Student* stu, const  char* department);
void setPhoneNumber(Student* stu, const char* phoneNumber);
void setDateGraduating(Student* stu,  const char* dateGraduating);
void setID(Student* stu, const char* newID);
void setSexual(Student* stu, const char* sexual);
Student getStuInfo(const Student* stu);
#endif