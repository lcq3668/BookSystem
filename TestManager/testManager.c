#include"../manager.h"
#include"../utility.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char* argv[]){
        login();
        Student* s = getStudentsData();
        Book *b = getBooksData();
        Record *r = getRecordsData(); 
        int flag;
        while(1){
                printf("*****************************************************************\n");
                printf("*\tinput 1 to add student(user)\n");
                printf("*\tinput 2 to delete student(user)\n");
                printf("*\tinput 3 to update student(user)\n");
                printf("*\tinput 4 to search student(user)\n");
                printf("*\tinput 5 to add book\n");
                printf("*\tinput 6 to delete book by ISBN  \n");
                printf("*\tinput 7 to delete book by name  \n");
                printf("*\tinput 8 to update book by ISBN  \n");
                printf("*\tinput 9 to update book by name  \n");
                printf("*\tinput 10 to search book by ISBN  \n");
                printf("*\tinput 11 to search book by name  \n");
                printf("*\tinput 12 to borrow  book  \n");
                printf("*\tinput 13 to return   book  \n");
                printf("*\tinput other digit to exit \n");
                printf("*****************************************************************\n");
                scanf("%d",&flag);
                while (getchar() !='\n');
                
                if(flag == 1){
                        addUser(&s);
                }
                else if(flag == 2){
                        char ID[13];
                        getID(ID,sizeof(ID));
                        deleteUser(ID,&s);
                }
                else if(flag == 3){
                        char ID[13];
                        getID(ID,sizeof(ID));
                        updateUser(ID,s);
                }
                else if(flag  == 4 ){
                        char ID[13];
                        getID(ID,sizeof(ID));
                        Student temp = searchStudent( ID,s);
                        if(strcmp(temp.ID,"-1") == 0){
                                printf("could not  find the target student\n");
                        }
                        else{
                                printf("stu.ID is: %s \n",temp.ID);
                                printf("stu.name is: %s \n",temp.name);
                                printf("stu.sexual is: %s \n",temp.sexual);
                                printf("stu.department is: %s \n",temp.department);
                                printf("stu.phoneNumber is: %s \n",temp.phoneNumber);
                                printf("stu.dateGraduating is: %s \n",temp.dateGraduating);
                                printf("\n\n"); 
                        }
                }
                else if(flag == 5){
                        addBook(&b);
                }
                else if(flag == 6){
                        char ISBN[16];
                        getISBN(ISBN,sizeof(ISBN));
                        deleteBookByISBN(ISBN,&b);
                }
                else if(flag == 7){
                        char name[48];
                        while(1){
                                printf("Please input book's name,whose length is at most %ld\n",sizeof(name)-3);
                                if(fgets(name,sizeof(name),stdin)==NULL){
                                        printf("error in  get name\n");
                                        exit(0);
                                }
                                printf("The length of name is %ld. \n",strlen(name));
                                /*in Linux*/
                                if(strlen(name)==(sizeof(name)-1) ){
                                        printf("The length of name is over. Please input again\n");
                                        while(getchar()!='\n');
                                        continue;
                                }

                                /*in Windows*/
                                /*
                                if(name[strlen(name)-1] != '\n' ){
                                        printf("The length of name is over. Please input again\n");
                                        while(getchar()!='\n');
                                        continue;
                                }
                                */
                                break;
                        }
                        /*In LInux*/
                        name[strlen(name)-1]='\0';
                        /*In windows*/
                        /*
                        name[strlen(name)-2]='\0';
                        */
                        deleteBookByName(name,&b);
                }
                else if(flag == 8){
                        char ISBN[16];
                        getISBN(ISBN,sizeof(ISBN));
                        updateBookByISBN(ISBN,b);
                }
                else if(flag == 9){
                        char name[48];
                        while(1){
                                printf("Please input book's name,whose length is at most %ld\n",sizeof(name)-3);
                                if(fgets(name,sizeof(name),stdin)==NULL){
                                        printf("error in  get name\n");
                                        exit(0);
                                }
                                printf("The length of name is %ld. \n",strlen(name));
                                /*in Linux*/
                                if(strlen(name)==(sizeof(name)-1) ){
                                        printf("The length of name is over. Please input again\n");
                                        while(getchar()!='\n');
                                        continue;
                                }

                                /*in Windows*/
                                /*
                                if(name[strlen(name)-1] != '\n' ){
                                        printf("The length of name is over. Please input again\n");
                                        while(getchar()!='\n');
                                        continue;
                                }
                                */
                                break;
                        }
                        /*In LInux*/
                        name[strlen(name)-1]='\0';
                        /*In windows*/
                        /*
                        name[strlen(name)-2]='\0';
                        */
                        
                        updateBookByName(name,b);
                }
                else if(flag == 10){
                        char ISBN[16];
                        getISBN(ISBN,sizeof(ISBN));
                       Book* target = searchBookByISBN(ISBN,b);
                        if(target == NULL){
                                printf("could not  find the target book\n");
                        }
                        else{
                                printf("book.ISBN is: %s \n",target->ISBN);
                                printf("book.name is: %s \n",target->name);
                                printf("book.author is: %s \n",target->author);
                                printf("book.category is: %s \n",target->category);
                                printf("book.publishingHouse is: %s \n",target->publishingHouse);
                                printf("book.datePublishing is: %s \n",target->datePublishing);
                                printf("book.pages is: %d \n",target->pages);
                                printf("book.amount is: %d \n",target->amount);
                                printf("\n\n"); 
                        }
                }
                else if(flag == 11){
                        char name[48];
                        while(1){
                                printf("Please input book's name,whose length is at most %ld\n",sizeof(name)-3);
                                if(fgets(name,sizeof(name),stdin)==NULL){
                                        printf("error in  get name\n");
                                        exit(0);
                                }
                                printf("The length of name is %ld. \n",strlen(name));
                                /*in Linux*/
                                if(strlen(name)==(sizeof(name)-1) ){
                                        printf("The length of name is over. Please input again\n");
                                        while(getchar()!='\n');
                                        continue;
                                }

                                /*in Windows*/
                                /*
                                if(name[strlen(name)-1] != '\n' ){
                                        printf("The length of name is over. Please input again\n");
                                        while(getchar()!='\n');
                                        continue;
                                }
                                */
                                break;
                        }
                        /*In LInux*/
                        name[strlen(name)-1]='\0';
                        /*In windows*/
                        /*
                        name[strlen(name)-2]='\0';
                        */
                        
                        Book target = searchBookByName(name,b);
                        if(strcmp(target.ISBN,"-1") == 0){
                                printf("could not  find the target book\n");
                        }
                        else{
                                printf("book.ISBN is: %s \n",target.ISBN);
                                printf("book.name is: %s \n",target.name);
                                printf("book.author is: %s \n",target.author);
                                printf("book.category is: %s \n",target.category);
                                printf("book.publishingHouse is: %s \n",target.publishingHouse);
                                printf("book.datePublishing is: %s \n",target.datePublishing);
                                printf("book.pages is: %d \n",target.pages);
                                printf("book.amount is: %d \n",target.amount);
                                printf("\n\n"); 
                        }
                }
                else if( flag == 12){
                        char ID[13];
                        getID(ID,sizeof(ID));
                        char ISBN[16];
                        getISBN(ISBN,sizeof(ISBN));
                       borrowBook(ID,s,ISBN,b,&r);
                }
                else if(flag == 13){
                        char ID[13];
                        getID(ID,sizeof(ID));
                        char ISBN[16];
                        getISBN(ISBN,sizeof(ISBN));
                        returnBook(ID,s,ISBN,b,&r);
                }
                else{
                        // 检查 是否有还没写入的数据
                        checkInExit(s,b,r);
                        exit(0);
                }
        }
        return 0  ;
}