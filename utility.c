#include"utility.h"
#include<stdio.h>
#include<stdlib.h>
Student* getStudentsData(){
        FILE *stuF;
        
        stuF = fopen("./StudentsData/studentsData.txt","r");
        if(stuF == NULL){
                stuF = fopen("./StudentsData/studentsData.txt","w");
                if(stuF == NULL){
                        return NULL;
                }
                else{
                        fclose(stuF);
                        stuF = fopen("./StudentsData/studentsData.txt","r");
                        if(stuF == NULL){
                               
                                return NULL;
                        }
                }
                        
        }
        Student temp;
        Student* res = NULL;
        int n = 1;
        while(fread(&temp,sizeof(Student),n,stuF) == n){
                Student* newOne = (Student*) malloc(sizeof(Student));
                *newOne = temp;
                newOne->next = res;
                res = newOne;
        }
        fclose(stuF);
        return res;
}

Book* getBooksData(){
        FILE *bookF;
        bookF = fopen("./BooksData/booksData.txt","r");
        if(bookF == NULL){
                bookF = fopen("./BooksData/booksData.txt","w");
                if(bookF == NULL){
                        return NULL;
                }
                else{
                        fclose(bookF);
                        bookF = fopen("./BooksData/booksData.txt","r");
                        if(bookF == NULL){
                               
                                return NULL;
                        }
                }
                        
        }
        Book temp;
        Book* res = NULL;
        int n = 1;
        while(fread(&temp,sizeof(Book),n,bookF) == n){
                Book* newOne = (Book*) malloc(sizeof(Book));
                *newOne = temp;
                newOne->next = res;
                res = newOne;
        }
        fclose(bookF);
        return res;
}

Record* getRecordsData(){
        FILE * recordF;
        recordF = fopen("./RecordsData/recordsData.txt","r");
        if(recordF == NULL){
                recordF = fopen("./RecordsData/recordsData.txt","w");
                if(recordF == NULL){
                        return NULL;
                }
                else{
                        fclose(recordF);
                        recordF = fopen("./RecordsData/recordsData.txt","r");
                        if(recordF == NULL){
                               
                                return NULL;
                        }
                } 
        }
        Record temp;
        Record* res = NULL;
        int n = 1;
        while(fread(&temp,sizeof(Record),n,recordF) == n){
                Record* newOne = (Record*) malloc(sizeof(Record));
                *newOne = temp;
                newOne->next = res;
                res = newOne;
        }
        fclose(recordF);
        return res;
}
