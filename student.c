#include"student.h"
#include<string.h>
void setName(Student* stu,const char* name){
        strcpy(stu->name,name);
}
void setDepartment(Student* stu,const  char* department){
        strcpy(stu->department,department);
}
void setPhoneNumber(Student* stu, const char* phoneNumber){
        strcpy(stu->phoneNumber,phoneNumber);
}
void setDateGraduating(Student* stu,  const char* dateGraduating){
        strcpy(stu->dateGraduating,dateGraduating);
}
void setID(Student* stu, const char* newID){
        strcpy(stu->ID,newID);
}
void setSexual(Student* stu, const char* sexual){
        strcpy(stu->sexual,sexual);
}
Student getStuInfo(const Student* stu){
        return *stu;
}
