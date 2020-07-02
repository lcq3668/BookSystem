#ifndef MANAGER_H
#define MANAGER_H
#include"student.h"
#include"book.h"
#include"record.h"
struct Manager{
        char  name[22];
        char password[16];
        
};
typedef struct Manager Manager;

void login();

void  addUser(Student ** studentsData);
void deleteUser(const char* ID,Student ** studentsData);
void updateUser(const char * ID,Student * studentsData); // 函数体里面调用 set 函数
Student searchStudent(const char * ID,Student * studentsData);  // search 只是读，不改变链表，故只需用一级指针

double checkFees(const char* ID,Student * studentsData,const  char* ISBN,Book* bookData,Record* recordData);


void addBook( Book** bookData);
void deleteBookByISBN(const char* ISBN,Book** bookData );
void deleteBookByName(const char* name,Book** bookData );
void updateBookByISBN(const char* ISBN,Book* bookData);
void updateBookByName(const char* name,Book* bookData);
Book* searchBookByISBN(const  char* ISBN,Book* bookData);
Book searchBookByName(const  char* name,Book* bookData);               // 相当与 getInfo 函数

void addRecord(const char* ID, const char *  ISBN,Record ** recordData);
double deleteRecord(const char* ID, const char* ISBN, Record** recordData);

void borrowBook(const char* ID,Student * studentsData,const  char* ISBN,Book* bookData,Record ** recordsData); // 还要添加 record的数据
void returnBook(const char* ID,Student * studentsData,const  char* ISBN,Book* bookData,Record ** recordsData);   // 还要添加 record的数据


void writeStudentsData(const Student*);
void writeBooksData(const Book*);
void writeRecordsData(const Record*);

void checkInExit(const Student* s,const Book* b,const Record* r);  // 还要添加 Book ,Record等参数

void getID(char * ID, unsigned long limit);
void getISBN(char * ISBN, unsigned long limit);
#endif
