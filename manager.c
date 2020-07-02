#include"manager.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXMODIFIEDTIMES 3
#define FINE 0.1
#define RECONDPERDAY 86400
int counterStudentData = 0;
int   counterBookData = 0;
int counterRecordData = 0;
void login(){
        FILE * Login;
        Manager m2;
        Login = fopen("./Manager/managers.txt","r");
        if(Login == NULL){
                printf("open file failed\n");
                exit(0);
        }
        size_t n =fread(&m2,sizeof(m2),1,Login);
        if(n != 1){
                printf("%ld\n",n);
                printf("error in  read managers.txt\n");
                exit(0);
        }
        fclose(Login);
        Manager m1;
       
        while(1){
                printf("*********************************Login**********************************\n");
                printf("Please input your name  and you can input at most %ld character.\n",sizeof(m1.name)-3);
                if(NULL == fgets(m1.name,sizeof(m1.name),stdin)){
                        printf("error in  get m1.name\n");
                        exit(0);
                 }
                 /* Linux 系统*/
                if(strlen(m1.name)==(sizeof(m1.name)-1) ){
                
                        printf("The length of name is over. Please input again\n");
                        while(getchar()!='\n');
                        continue;
                }
                /*in Linux*/
                m1.name[strlen(m1.name)-1]='\0';

                /* Windows 系统*/
                        /*
                        if(strlen(m1.name)==(sizeof(m1.name)-1) ){
                        if(m1.name[sizeof(m1.name)-2]=='\n'){
                                printf("The length of name is OK\n");
                        }
                        else{
                                printf("The length of name is over\n");
                        }
                        }
                        //in windwos
                        m1.name[strlen(m1.name)-2]='\0';
                        */

                printf("Please input your password  and you can input at most %ld character.\n",sizeof(m1.password)/sizeof(m1.password[0])-3);
                if(fgets(m1.password,sizeof(m1.password),stdin) == NULL){
                        printf("error in  get m1.password\n");
                        exit(0);
                }


                /* Linux 系统*/
                if(strlen(m1.password)==(sizeof(m1.password)-1) ){
                        
                        printf("The length of password is over. Please input again\n");
                        while(getchar()!='\n');
                        continue;
                }
                /*in Linux*/
                m1.password[strlen(m1.password)-1]='\0';

                /* Windows 系统*/
                        /*
                        if(strlen(m1.password)==(sizeof(m1.password)-1) ){
                        if(m1.password[sizeof(m1.password)-2]=='\n'){
                                printf("The length of password is OK\n");
                        }
                        else{
                                printf("The length of password is over\n");
                        }
                        }
                        // m1.password[strlen(m1.password)-2]='\0';
                        */


                if(strcmp(m1.name,m2.name) == 0  && strcmp(m1.password,m2.password)==0){
                        printf("Login successfully\n");
                        break;
                }
                printf("wrong name or wrong password\n");
         }

}

void  addUser(Student ** studentsData){
        Student * temp = (Student*)malloc(sizeof(Student));
        if(temp == NULL){
                printf(" malloc failed in function : addUser\n");
                exit(0);
        }
        getID(temp->ID,sizeof(temp->ID));

        

        /* name */
        while(1){
            printf("Please input student's name,whose length is at most %ld\n",sizeof(temp->name)-3);
            if(fgets(temp->name,sizeof(temp->name),stdin)==NULL){
                printf("error in  get name\n");
                exit(0);
            }
            /*in LInux*/
            if(strlen(temp->name)==(sizeof(temp->name)-1) ){
                printf("The length of name is over. Please input again\n");
                while(getchar()!='\n');
                continue;
            }
            /*in Windows*/
            /*
            if(temp->name[strlen(temp->name)-1] != '\n' ){
                printf("The length of name is over. Please input again\n");
                while(getchar()!='\n');
                continue;
            }
            */
            break;
        }
        /*In LInux*/
        temp->name[strlen(temp->name)-1]='\0';
        /*In windows*/
        /*
        temp->name[strlen(temp->name)-2]='\0';
         */


        /* department */
        while(1){
            printf("Please input student's department,whose length is at most %ld\n",sizeof(temp->department)-3);
            if(fgets(temp->department,sizeof(temp->department),stdin)==NULL){
                printf("error in  get department\n");
                exit(0);
            }
            if(strlen(temp->department)==(sizeof(temp->department)-1) ){
                printf("The length of department is over: %ld. Please input again\n",strlen(temp->department));
                while(getchar()!='\n');
                continue;
            }
            printf("THe length is %ld\n",strlen(temp->department));
            break;
        }
        /*In LInux*/
        temp->department[strlen(temp->department)-1]='\0';
        /*In windows*/
        /*
        temp->department[strlen(temp->department)-2]='\0';
         */



        /* phoneNumber */
        while(1){
            printf("Please input student's phoneNumber,whose length is at most %ld\n",sizeof(temp->phoneNumber)-3);
            if(fgets(temp->phoneNumber,sizeof(temp->phoneNumber),stdin)==NULL){
                printf("error in  get phoneNumber\n");
                exit(0);
            }
            if(strlen(temp->phoneNumber)==(sizeof(temp->phoneNumber)-1) ){
                printf("The length of phoneNumber is over: %ld. Please input again\n",strlen(temp->phoneNumber));
                while(getchar()!='\n');
                continue;
            }
            printf("THe length is %ld\n",strlen(temp->phoneNumber));
            break;
        }
        /*In LInux*/
        temp->phoneNumber[strlen(temp->phoneNumber)-1]='\0';
        /*In windows*/
        /*
        temp->phoneNumber[strlen(temp->phoneNumber)-2]='\0';
         */





        /* dateGraduating */
        while(1){
            printf("Please input student's dateGraduating,whose length is at most %ld\n",sizeof(temp->dateGraduating)-3);
            if(fgets(temp->dateGraduating,sizeof(temp->dateGraduating),stdin)==NULL){
                printf("error in  get dateGraduating\n");
                exit(0);
            }
            if(strlen(temp->dateGraduating)==(sizeof(temp->dateGraduating)-1) ){
                printf("The length of dateGraduating is over: %ld. Please input again\n",strlen(temp->dateGraduating));
                while(getchar()!='\n');
                continue;
            }
            printf("THe length is %ld\n",strlen(temp->dateGraduating));
            break;
        }
        /*In LInux*/
        temp->dateGraduating[strlen(temp->dateGraduating)-1]='\0';
        /*In windows*/
        /*
        temp->dateGraduating[strlen(temp->dateGraduating)-2]='\0';
         */



    /* sexual */
        while(1){
            printf("Please input student's sexual,whose length is at most %ld\n",sizeof(temp->sexual)-3);
            if(fgets(temp->sexual,sizeof(temp->sexual),stdin)==NULL){
                printf("error in  get sexual\n");
                exit(0);
            }
            if(strlen(temp->sexual)==(sizeof(temp->sexual)-1) ){
                printf("The length of sexual is over: %ld. Please input again\n",strlen(temp->sexual));
                while(getchar()!='\n');
                continue;
            }
            printf("THe length is %ld\n",strlen(temp->sexual));
            break;
        }
        /*In LInux*/
        temp->sexual[strlen(temp->sexual)-1]='\0';
        /*In windows*/
        /*
        temp->sexual[strlen(temp->sexual)-2]='\0';
         */

        temp->next = *studentsData; 
        *studentsData = temp;
        counterStudentData++;
        if(counterStudentData >=  MAXMODIFIEDTIMES){
                // write into the Studentdata.txt
                writeStudentsData(temp);
                counterStudentData = 0;
        }
}


void deleteUser(const char* ID,Student ** studentsData){
        Student * current = *studentsData; 
        if(current != NULL){
                Student * previous;
                if(strcmp(ID,current->ID) == 0){
                        *studentsData = current->next;
                        free(current);
                        counterStudentData++;
                        if(counterStudentData >= MAXMODIFIEDTIMES){
                                // write into the Studentdata.txt
                                writeStudentsData(*studentsData);
                                counterStudentData = 0;
                                printf("delete user successfully\n");
                        }
                }
                else{
                        previous = current;
                        current = current->next;
                        while(current != NULL){
                                if(strcmp(ID,current->ID) == 0){
                                        previous->next = current->next;
                                        free(current);
                                        counterStudentData++;
                                        if(counterStudentData >= MAXMODIFIEDTIMES){
                                                // write into the Studentdata.txt
                                                writeStudentsData(*studentsData);
                                                counterStudentData = 0;
                                        }
                                        break;
                                }
                                previous = current;
                                current = current->next;
                        }
                        if(current == NULL){
                                printf("Could not find the student\n");
                        }
                        else{
                                printf("delete user successfully\n");
                        }
                }
        }
        else{
                printf("The list of StudentData is empty\n");
        }
}


void updateUser(const char * ID,Student * studentsData){
        // 函数体里面调用 set 函数
        Student * tempHead = studentsData;
        if(studentsData != NULL){
                 while(studentsData != NULL){
                        if(strcmp(ID,studentsData->ID) == 0){
                                break;
                        }
                        studentsData = studentsData->next;
                }
                
        }
        else{
                printf("The list of StudentData is empty\n");
                return ;
        }
        if(studentsData == NULL){
                printf("There is no the student \n");
                return ;
        }
        int flag;
        while (1)
        {
                /* code */
        
        
        printf("****************************************************************\n");
        printf("\t\t\tinput 1 to change ID\n");
        printf("\t\t\tinput 2 to change name\n");
        printf("\t\t\tinput 3 to change department\n");
        printf("\t\t\tinput 4 to change phoneNumber\n");
        printf("\t\t\tinput 5 to change sexual\n");
        printf("\t\t\tinput 6 to change dateGraduating\n");
        printf("****************************************************************\n");

        scanf("%d",&flag);
        while(getchar()!='\n');
        if(flag == 1){
                char ID[13];
                getID(ID,sizeof(ID));
                setID(studentsData,ID);
                counterStudentData++;
                break;
        }
        else if(flag == 2){
                char name[16];
                while(1){
                        printf("Please input student's name,whose length is at most %ld\n",sizeof(name)-3);
                        if(fgets(name,sizeof(name),stdin)==NULL){
                                printf("error in  get name\n");
                                exit(0);
                        }
                        /*in LInux*/
                        if(strlen(name)==(sizeof(name)-1) ){
                                printf("The length of name is over. Please input again\n");
                                while(getchar()!='\n');
                                continue;
                        }
                        /*in Windows*/
                        /*
                        if(temp->name[strlen(temp->name)-1] != '\n' ){
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
               setName(studentsData,name);
               counterStudentData++;
               break;
        }
        else if(flag == 3){
                char department[18];
                while(1){
                        printf("Please input student's department,whose length is at most %ld\n",sizeof(department)-3);
                        if(fgets(department,sizeof(department),stdin)==NULL){
                                printf("error in  get department\n");
                                exit(0);
                        }
                        if(strlen(department)==(sizeof(department)-1) ){
                                printf("The length of department is over: %ld. Please input again\n",strlen(department));
                                while(getchar()!='\n');
                                continue;
                        }
                        printf("THe length is %ld\n",strlen(department));
                        break;
                        }
                /*In LInux*/
                department[strlen(department)-1]='\0';
                /*In windows*/
                /*
                department[strlen(department)-2]='\0';
                */
               setDepartment(studentsData,department);
               counterStudentData++;
               break;
        }
        else if(flag == 4){
                char phoneNumber[14];
                while(1){
                        printf("Please input student's phoneNumber,whose length is at most %ld\n",sizeof(phoneNumber)-3);
                        if(fgets(phoneNumber,sizeof(phoneNumber),stdin)==NULL){
                                printf("error in  get phoneNumber\n");
                                exit(0);
                        }
                        if(strlen(phoneNumber)==(sizeof(phoneNumber)-1) ){
                                printf("The length of phoneNumber is over: %ld. Please input again\n",strlen(phoneNumber));
                                while(getchar()!='\n');
                                continue;
                        }
                        printf("THe length is %ld\n",strlen(phoneNumber));
                        break;
                }
                /*In LInux*/
                phoneNumber[strlen(phoneNumber)-1]='\0';
                /*In windows*/
                /*
                phoneNumber[strlen(phoneNumber)-2]='\0';
                */
               setPhoneNumber(studentsData,phoneNumber);
               counterStudentData++;
               break;
        }
        else if(flag == 5){
                char sexual[7];    
                while(1){
                        printf("Please input student's sexual,whose length is at most %ld\n",sizeof(sexual)-3);
                        if(fgets(sexual,sizeof(sexual),stdin)==NULL){
                                printf("error in  get sexual\n");
                                exit(0);
                        }
                        if(strlen(sexual)==(sizeof(sexual)-1) ){
                                printf("The length of sexual is over: %ld. Please input again\n",strlen(sexual));
                                while(getchar()!='\n');
                                continue;
                        }
                        printf("THe length is %ld\n",strlen(sexual));
                        break;
                }
                /*In LInux*/
                sexual[strlen(sexual)-1]='\0';
                /*In windows*/
                /*
                sexual[strlen(sexual)-2]='\0';
                */
               setSexual(studentsData,sexual);
               counterStudentData++;
               break;
        }
        else if(flag == 6){
                char dateGraduating[11];    
                while(1){
                        printf("Please input student's dateGraduating,whose length is at most %ld\n",sizeof(dateGraduating)-3);
                        if(fgets(dateGraduating,sizeof(dateGraduating),stdin)==NULL){
                                printf("error in  get dateGraduating\n");
                                exit(0);
                        }
                        if(strlen(dateGraduating)==(sizeof(dateGraduating)-1) ){
                                printf("The length of dateGraduating is over: %ld. Please input again\n",strlen(dateGraduating));
                                while(getchar()!='\n');
                                continue;
                        }
                        printf("THe length is %ld\n",strlen(dateGraduating));
                        break;
                }
                /*In LInux*/
                dateGraduating[strlen(dateGraduating)-1]='\0';
                /*In windows*/
                /*
                dateGraduating[strlen(dateGraduating)-2]='\0';
                */
               setDateGraduating(studentsData,dateGraduating);
               counterStudentData++;
               break;
        }
        }
        if(counterStudentData >= MAXMODIFIEDTIMES){
                writeStudentsData(tempHead);
                counterStudentData = 0;
        }
}

Student searchStudent(const char * ID,Student * studentsData){
        
        if(studentsData != NULL){
                 while(studentsData != NULL){
                        if(strcmp(ID,studentsData->ID) == 0){
                                return *studentsData;
                        }
                        studentsData = studentsData->next;
                }
                
        }
        else{
                printf("The list of StudentData is empty\n");
        }            
        Student temp;
        setID(&temp,"-1");
        return  temp;            // 返回  -1的 ID  表示没找到。
}

double checkFees(const char* ID,Student * studentsData,const  char* ISBN,Book* bookData,Record* recordData){
        while(recordData != NULL){
                if(strcmp(ID,recordData->ID)==0  && strcmp(ISBN,recordData->ISBN)==0){
                        break;
                }
                recordData = recordData->next;
        }
        if(recordData==NULL){
                return -1.0;
        }
        else{
                time_t now;
                if(recordData->deadline > time(&now)){
                        return 0.0;
                }
                else{
                        return (now/RECONDPERDAY - recordData->deadline/RECONDPERDAY)*FINE;
                }
        }
}


void addBook(Book** bookData){
        Book * temp = (Book*)malloc(sizeof(Book));
        if(temp == NULL){
                printf(" malloc failed in function : addUser\n");
                exit(0);
        }
        getISBN(temp->ISBN,sizeof(temp->ISBN));

        

        /* name */
        while(1){
            printf("Please input book's name,whose length is at most %ld\n",sizeof(temp->name)-3);
            if(fgets(temp->name,sizeof(temp->name),stdin)==NULL){
                printf("error in  get name\n");
                exit(0);
            }
            /*in LInux*/
            if(strlen(temp->name)==(sizeof(temp->name)-1) ){
                printf("The length of name is over. Please input again\n");
                while(getchar()!='\n');
                continue;
            }
            /*in Windows*/
            /*
            if(temp->name[strlen(temp->name)-1] != '\n' ){
                printf("The length of name is over. Please input again\n");
                while(getchar()!='\n');
                continue;
            }
            */
            break;
        }
        /*In LInux*/
        temp->name[strlen(temp->name)-1]='\0';
        /*In windows*/
        /*
        temp->name[strlen(temp->name)-2]='\0';
         */


        /* category */
        while(1){
            printf("Please input book's category,whose length is at most %ld\n",sizeof(temp->category)-3);
            if(fgets(temp->category,sizeof(temp->category),stdin)==NULL){
                printf("error in  get category\n");
                exit(0);
            }
            if(strlen(temp->category)==(sizeof(temp->category)-1) ){
                printf("The length of category is over: %ld. Please input again\n",strlen(temp->category));
                while(getchar()!='\n');
                continue;
            }
            printf("THe length is %ld\n",strlen(temp->category));
            break;
        }
        /*In LInux*/
        temp->category[strlen(temp->category)-1]='\0';
        /*In windows*/
        /*
        temp->category[strlen(temp->category)-2]='\0';
         */



        /* author */
        while(1){
            printf("Please input book's author,whose length is at most %ld\n",sizeof(temp->author)-3);
            if(fgets(temp->author,sizeof(temp->author),stdin)==NULL){
                printf("error in  get author\n");
                exit(0);
            }
            if(strlen(temp->author)==(sizeof(temp->author)-1) ){
                printf("The length of author is over: %ld. Please input again\n",strlen(temp->author));
                while(getchar()!='\n');
                continue;
            }
            printf("THe length is %ld\n",strlen(temp->author));
            break;
        }
        /*In LInux*/
        temp->author[strlen(temp->author)-1]='\0';
        /*In windows*/
        /*
        temp->author[strlen(temp->author)-2]='\0';
         */




        
        /* datePublishing */
        while(1){
            printf("Please input book  's datePublishing,whose length is at most %ld\n",sizeof(temp->datePublishing)-3);
            if(fgets(temp->datePublishing,sizeof(temp->datePublishing),stdin)==NULL){
                printf("error in  get datePublishing\n");
                exit(0);
            }
            if(strlen(temp->datePublishing)==(sizeof(temp->datePublishing)-1) ){
                printf("The length of datePublishing is over: %ld. Please input again\n",strlen(temp->datePublishing));
                while(getchar()!='\n');
                continue;
            }
            printf("THe length is %ld\n",strlen(temp->datePublishing));
            break;
        }
        /*In LInux*/
        temp->datePublishing[strlen(temp->datePublishing)-1]='\0';
        /*In windows*/
        /*
        temp->datePublishing[strlen(temp->datePublishing)-2]='\0';
         */



    /* publishingHouse */
        while(1){
            printf("Please input book's publishingHouse,whose length is at most %ld\n",sizeof(temp->publishingHouse)-3);
            if(fgets(temp->publishingHouse,sizeof(temp->publishingHouse),stdin)==NULL){
                printf("error in  get publishingHouse\n");
                exit(0);
            }
            if(strlen(temp->publishingHouse)==(sizeof(temp->publishingHouse)-1) ){
                printf("The length of publishingHouse is over: %ld. Please input again\n",strlen(temp->publishingHouse));
                while(getchar()!='\n');
                continue;
            }
            printf("THe length is %ld\n",strlen(temp->publishingHouse));
            break;
        }
        /*In LInux*/
        temp->publishingHouse[strlen(temp->publishingHouse)-1]='\0';
        /*In windows*/
        /*
        temp->publishingHouse[strlen(temp->publishingHouse)-2]='\0';
         */

    /* pages */
        while(1){
                printf("Please input book's pages\n");
                scanf("%d",&temp->pages);
                while (getchar() != '\n');
                break;
        }

    /* amount */
        while(1){
                printf("Please input book's amount\n");
                scanf("%d",&temp->amount);
                while (getchar() != '\n');
                break;
        }

        temp->next = *bookData; 
        *bookData = temp;
        counterBookData++;
        if(counterBookData >= MAXMODIFIEDTIMES){
                // write into the Studentdata.txt
                writeBooksData(temp);
                counterBookData = 0;
        }
}

void deleteBookByISBN(const char* ISBN,Book** bookData ){
        Book * current = *bookData; 
        if(current != NULL){
                Book * previous;
                if(strcmp(ISBN,current->ISBN) == 0){
                        *bookData = current->next;
                        free(current);
                        counterBookData++;
                        if(counterBookData >= MAXMODIFIEDTIMES){
                                // write into the Studentdata.txt
                                writeBooksData(*bookData);
                                counterBookData = 0;
                                printf("delete book information successfully\n");
                        }
                }
                else{
                        previous = current;
                        current = current->next;
                        while(current != NULL){
                                if(strcmp(ISBN,current->ISBN) == 0){
                                        previous->next = current->next;
                                        free(current);
                                        counterBookData++;
                                        if(counterBookData >= MAXMODIFIEDTIMES){
                                                // write into the Bookdata.txt
                                                writeBooksData(*bookData);
                                                counterBookData = 0;
                                        }
                                        break;
                                }
                                previous = current;
                                current = current->next;
                        }
                        if(current == NULL){
                                printf("Could not find the book\n");
                        }
                        else{
                                printf("delete book information successfully\n");
                        }
                }
        }
        else{
                printf("The list of BookData is empty\n");
        }
}
void deleteBookByName(const char* name,Book** bookData ){
        Book * current = *bookData; 
        if(current != NULL){
                Book * previous;
                if(strcmp(name,current->name) == 0){
                        *bookData = current->next;
                        free(current);
                        counterBookData++;
                        if(counterBookData >= MAXMODIFIEDTIMES){
                                // write into the Bookdata.txt
                                writeBooksData(*bookData);
                                counterBookData = 0;
                                printf("delete book information successfully\n");
                        }
                }
                else{
                        previous = current;
                        current = current->next;
                        while(current != NULL){
                                if(strcmp(name,current->name) == 0){
                                        previous->next = current->next;
                                        free(current);
                                        counterBookData++;
                                        if(counterBookData >= MAXMODIFIEDTIMES){
                                                // write into the Bookdata.txt
                                                writeBooksData(*bookData);
                                                counterBookData = 0;
                                        }
                                        break;
                                }
                                previous = current;
                                current = current->next;
                        }
                        if(current == NULL){
                                printf("Could not find the book\n");
                        }
                        else{
                                printf("delete book information successfully\n");
                        }
                }
        }
        else{
                printf("The list of BookData is empty\n");
        }
}
void updateBookByISBN(const char* ISBN,Book* bookData){
        // 函数体里面调用 set 函数
        Book * tempHead = bookData;
        if(bookData != NULL){
                 while(bookData != NULL){
                        if(strcmp(ISBN,bookData->ISBN) == 0){
                                break;
                        }
                        bookData = bookData->next;
                }
                
        }
        else{
                printf("The list of BooksData is empty\n");
                return ;
        }
        if(bookData == NULL){
                printf("There is no the book \n");
                return ;
        }
        int flag;
        while (1)
        {
                /* code */
        
        
        printf("****************************************************************\n");
        printf("\t\t\tinput 1 to change ISBN\n");
        printf("\t\t\tinput 2 to change name\n");
        printf("\t\t\tinput 3 to change category\n");
        printf("\t\t\tinput 4 to change author\n");
        printf("\t\t\tinput 5 to change datePublishing\n");
        printf("\t\t\tinput 6 to change publishingHouse\n");
        printf("\t\t\tinput 7 to change pages\n");
        printf("\t\t\tinput 8 to change amount\n");
        printf("****************************************************************\n");

        scanf("%d",&flag);
        while(getchar()!='\n');
        if(flag == 1){
                char ISBN[16];
                getISBN(ISBN,sizeof(ISBN));
                setISBN(bookData,ISBN);
                counterBookData++;
                break;
        }
        else if(flag == 2){
                char name[48];
                while(1){
                        printf("Please input book's name,whose length is at most %ld\n",sizeof(name)-3);
                        if(fgets(name,sizeof(name),stdin)==NULL){
                                printf("error in  get name\n");
                                exit(0);
                        }
                        /*in LInux*/
                        if(strlen(name)==(sizeof(name)-1) ){
                                printf("The length of name is over. Please input again\n");
                                while(getchar()!='\n');
                                continue;
                        }
                        /*in Windows*/
                        /*
                        if(temp->name[strlen(temp->name)-1] != '\n' ){
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
               setBookName(bookData,name);
               counterBookData++;
               break;
        }
        else if(flag == 3){
                char category[24];
                while(1){
                        printf("Please input book's category,whose length is at most %ld\n",sizeof(category)-3);
                        if(fgets(category,sizeof(category),stdin)==NULL){
                                printf("error in  get category\n");
                                exit(0);
                        }
                        if(strlen(category)==(sizeof(category)-1) ){
                                printf("The length of category is over: %ld. Please input again\n",strlen(category));
                                while(getchar()!='\n');
                                continue;
                        }
                        printf("THe length is %ld\n",strlen(category));
                        break;
                        }
                /*In LInux*/
                category[strlen(category)-1]='\0';
                /*In windows*/
                /*
                category[strlen(category)-2]='\0';
                */
               setCategory(bookData,category);
               counterBookData++;
               break;
        }
        else if(flag == 4){
                char author[16];
                while(1){
                        printf("Please input book's author,whose length is at most %ld\n",sizeof(author)-3);
                        if(fgets(author,sizeof(author),stdin)==NULL){
                                printf("error in  get author\n");
                                exit(0);
                        }
                        if(strlen(author)==(sizeof(author)-1) ){
                                printf("The length of author is over: %ld. Please input again\n",strlen(author));
                                while(getchar()!='\n');
                                continue;
                        }
                        printf("THe length is %ld\n",strlen(author));
                        break;
                }
                /*In LInux*/
                author[strlen(author)-1]='\0';
                /*In windows*/
                /*
                author[strlen(author)-2]='\0';
                */
               setAuthor(bookData,author);
               counterBookData++;
               break;
        }
        else if(flag == 5){
                char datePublishing[11];    
                while(1){
                        printf("Please input book's datePublishing,whose length is at most %ld\n",sizeof(datePublishing)-3);
                        if(fgets(datePublishing,sizeof(datePublishing),stdin)==NULL){
                                printf("error in  get datePublishing\n");
                                exit(0);
                        }
                        if(strlen(datePublishing)==(sizeof(datePublishing)-1) ){
                                printf("The length of datePublishing is over: %ld. Please input again\n",strlen(datePublishing));
                                while(getchar()!='\n');
                                continue;
                        }
                        printf("THe length is %ld\n",strlen(datePublishing));
                        break;
                }
                /*In LInux*/
                datePublishing[strlen(datePublishing)-1]='\0';
                /*In windows*/
                /*
                datePublishing[strlen(datePublishing)-2]='\0';
                */
               setDatePublishing(bookData,datePublishing);
               counterBookData++;
               break;
        }
        else if(flag == 6){
                char publishingHouse[32];    
                while(1){
                        printf("Please input book's publishingHouse,whose length is at most %ld\n",sizeof(publishingHouse)-3);
                        if(fgets(publishingHouse,sizeof(publishingHouse),stdin)==NULL){
                                printf("error in  get publishingHouse\n");
                                exit(0);
                        }
                        if(strlen(publishingHouse)==(sizeof(publishingHouse)-1) ){
                                printf("The length of publishingHouse is over: %ld. Please input again\n",strlen(publishingHouse));
                                while(getchar()!='\n');
                                continue;
                        }
                        printf("THe length is %ld\n",strlen(publishingHouse));
                        break;
                }
                /*In LInux*/
                publishingHouse[strlen(publishingHouse)-1]='\0';
                /*In windows*/
                /*
                publishingHouse[strlen(publishingHouse)-2]='\0';
                */
               setPublishingHouse(bookData,publishingHouse);
               counterBookData++;
               break;
        }
        else if(flag == 7){
                unsigned int pages;
                printf("Please input book's pages\n");
                scanf("%d",&pages);
                setPages(bookData,pages);
                counterBookData++;
               break;
        }
        else if(flag == 8){
                unsigned int amount;
                printf("Please input book's amount\n");
                scanf("%d",&amount);
                setAmount(bookData,amount);
                counterBookData++;
               break;
        }
        }
        if(counterBookData >= MAXMODIFIEDTIMES){
                printf("writting books data\n");
                writeBooksData(tempHead);
                counterBookData = 0;
        }
}

void updateBookByName(const char* name,Book* bookData){
        // 函数体里面调用 set 函数
        Book * tempHead = bookData;
        if(bookData != NULL){
                 while(bookData != NULL){
                        if(strcmp(name,bookData->name) == 0){
                                break;
                        }
                        bookData = bookData->next;
                }
                
        }
        else{
                printf("The list of BooksData is empty\n");
                return ;
        }
        if(bookData == NULL){
                printf("There is no the book \n");
                return ;
        }
        int flag;
        while (1)
        {
                /* code */
        
        
        printf("****************************************************************\n");
        printf("\t\t\tinput 1 to change ISBN\n");
        printf("\t\t\tinput 2 to change name\n");
        printf("\t\t\tinput 3 to change category\n");
        printf("\t\t\tinput 4 to change author\n");
        printf("\t\t\tinput 5 to change datePublishing\n");
        printf("\t\t\tinput 6 to change publishingHouse\n");
        printf("\t\t\tinput 7 to change pages\n");
        printf("\t\t\tinput 8 to change amount\n");
        printf("****************************************************************\n");

        scanf("%d",&flag);
        while(getchar()!='\n');
        if(flag == 1){
                char ISBN[16];
                getISBN(ISBN,sizeof(ISBN));
                setISBN(bookData,ISBN);
                counterBookData++;
                break;
        }
        else if(flag == 2){
                char name[48];
                while(1){
                        printf("Please input book's name,whose length is at most %ld\n",sizeof(name)-3);
                        if(fgets(name,sizeof(name),stdin)==NULL){
                                printf("error in  get name\n");
                                exit(0);
                        }
                        /*in LInux*/
                        if(strlen(name)==(sizeof(name)-1) ){
                                printf("The length of name is over. Please input again\n");
                                while(getchar()!='\n');
                                continue;
                        }
                        /*in Windows*/
                        /*
                        if(temp->name[strlen(temp->name)-1] != '\n' ){
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
               setBookName(bookData,name);
               counterBookData++;
               break;
        }
        else if(flag == 3){
                char category[24];
                while(1){
                        printf("Please input book's category,whose length is at most %ld\n",sizeof(category)-3);
                        if(fgets(category,sizeof(category),stdin)==NULL){
                                printf("error in  get category\n");
                                exit(0);
                        }
                        if(strlen(category)==(sizeof(category)-1) ){
                                printf("The length of category is over: %ld. Please input again\n",strlen(category));
                                while(getchar()!='\n');
                                continue;
                        }
                        printf("THe length is %ld\n",strlen(category));
                        break;
                        }
                /*In LInux*/
                category[strlen(category)-1]='\0';
                /*In windows*/
                /*
                category[strlen(category)-2]='\0';
                */
               setCategory(bookData,category);
               counterBookData++;
               break;
        }
        else if(flag == 4){
                char author[16];
                while(1){
                        printf("Please input book's author,whose length is at most %ld\n",sizeof(author)-3);
                        if(fgets(author,sizeof(author),stdin)==NULL){
                                printf("error in  get author\n");
                                exit(0);
                        }
                        if(strlen(author)==(sizeof(author)-1) ){
                                printf("The length of author is over: %ld. Please input again\n",strlen(author));
                                while(getchar()!='\n');
                                continue;
                        }
                        printf("THe length is %ld\n",strlen(author));
                        break;
                }
                /*In LInux*/
                author[strlen(author)-1]='\0';
                /*In windows*/
                /*
                author[strlen(author)-2]='\0';
                */
               setAuthor(bookData,author);
               counterBookData++;
               break;
        }
        else if(flag == 5){
                char datePublishing[11];    
                while(1){
                        printf("Please input book's datePublishing,whose length is at most %ld\n",sizeof(datePublishing)-3);
                        if(fgets(datePublishing,sizeof(datePublishing),stdin)==NULL){
                                printf("error in  get datePublishing\n");
                                exit(0);
                        }
                        if(strlen(datePublishing)==(sizeof(datePublishing)-1) ){
                                printf("The length of datePublishing is over: %ld. Please input again\n",strlen(datePublishing));
                                while(getchar()!='\n');
                                continue;
                        }
                        printf("THe length is %ld\n",strlen(datePublishing));
                        break;
                }
                /*In LInux*/
                datePublishing[strlen(datePublishing)-1]='\0';
                /*In windows*/
                /*
                datePublishing[strlen(datePublishing)-2]='\0';
                */
               setDatePublishing(bookData,datePublishing);
               counterBookData++;
               break;
        }
        else if(flag == 6){
                char publishingHouse[32];    
                while(1){
                        printf("Please input book's publishingHouse,whose length is at most %ld\n",sizeof(publishingHouse)-3);
                        if(fgets(publishingHouse,sizeof(publishingHouse),stdin)==NULL){
                                printf("error in  get publishingHouse\n");
                                exit(0);
                        }
                        if(strlen(publishingHouse)==(sizeof(publishingHouse)-1) ){
                                printf("The length of publishingHouse is over: %ld. Please input again\n",strlen(publishingHouse));
                                while(getchar()!='\n');
                                continue;
                        }
                        printf("THe length is %ld\n",strlen(publishingHouse));
                        break;
                }
                /*In LInux*/
                publishingHouse[strlen(publishingHouse)-1]='\0';
                /*In windows*/
                /*
                publishingHouse[strlen(publishingHouse)-2]='\0';
                */
               setPublishingHouse(bookData,publishingHouse);
               counterBookData++;
               break;
        }
        else if(flag == 7){
                unsigned int pages;
                printf("Please input book's pages\n");
                scanf("%d",&pages);
                setPages(bookData,pages);
                counterBookData++;
               break;
        }
        else if(flag == 8){
                unsigned int amount;
                printf("Please input book's amount\n");
                scanf("%d",&amount);
                setAmount(bookData,amount);
                counterBookData++;
               break;
        }
        }
        if(counterBookData >= MAXMODIFIEDTIMES){
                printf("writting books data\n");
                writeBooksData(tempHead);
                counterBookData = 0;
        }
}



Book* searchBookByISBN(const  char* ISBN,Book* bookData){
        if(bookData != NULL){
                 while(bookData != NULL){
                        if(strcmp(ISBN,bookData->ISBN) == 0){
                                return bookData;
                        }
                        bookData = bookData->next;
                }
                
        }
        else{
                printf("The list of BookData is empty\n");
        }            

        return  NULL;            // 返回  -1的 ISBN  表示没找到。
}

Book searchBookByName(const  char* name,Book* bookData){                 // 相当与 getInfo 函数
        if(bookData != NULL){
                while(bookData != NULL){
                        if(strcmp(name,bookData->name) == 0){
                                return *bookData;
                        }
                        bookData = bookData->next;
                }
                
        }
        else{
                printf("The list of BookData is empty\n");
        }            
        Book temp;
        setISBN(&temp,"-1");
        return  temp;            // 返回  -1的 ISBN  表示没找到。
}
/*
void borrowBook(const char* ID, const char* ISBN);
void returnBook(const char* ID, const char* ISBN);
*/

void addRecord(const char* ID, const char *  ISBN,Record ** recordData){
        Record * temp = (Record*)malloc(sizeof(Record));
        if(temp == NULL){
                printf(" malloc failed in function : addRecord\n");
                exit(0);
        }
        strcpy(temp->ID,ID);
        strcpy(temp->ISBN,ISBN);
        temp->current = time(NULL);
        temp->deadline = temp->current + RECONDPERDAY;
        temp->next = *recordData;
        *recordData = temp;
        counterRecordData++;
        if(counterRecordData >= MAXMODIFIEDTIMES){
                // write into the Studentdata.txt
                writeRecordsData(temp);
                counterRecordData = 0;
        }
}

double deleteRecord(const char* ID, const char* ISBN, Record** recordData){
        Record * current = *recordData; 
        if(current != NULL){
                double cost;
                Record * previous;
                if(strcmp(ID,current->ID) == 0 && strcmp(ISBN,current->ISBN) == 0 ){
                        *recordData = current->next;
                        cost = current->deadline > time(NULL)?0.0:(time(NULL)/RECONDPERDAY - current->deadline/RECONDPERDAY)*FINE;
                        free(current);
                        printf("delete record successfully\n");
                        counterRecordData++;
                        if(counterRecordData >= MAXMODIFIEDTIMES){
                                // write into the Studentdata.txt
                                writeRecordsData(*recordData);
                                counterRecordData = 0;
                        }
                        return cost;
                }
                else{
                        previous = current;
                        current = current->next;
                        while(current != NULL){
                                if(strcmp(ID,current->ID) == 0 && strcmp(ISBN,current->ISBN) == 0 ){
                                        previous->next = current->next;
                                        cost = current->deadline > time(NULL)?0.0:(time(NULL)/RECONDPERDAY - current->deadline/RECONDPERDAY)*FINE;
                                        free(current);
                                        counterRecordData++;
                                        if(counterRecordData >= MAXMODIFIEDTIMES){
                                                // write into the Studentdata.txt
                                                writeRecordsData(*recordData);
                                                counterRecordData = 0;
                                        }
                                        break;
                                }
                                previous = current;
                                current = current->next;
                        }
                        if(current == NULL){
                                printf("Could not find the record\n");
                                return   -1.0;
                        }
                        else{
                                printf("delete record successfully\n");
                                return cost;
                        }
                }
        }
        else{
                printf("The list of RecordData is empty\n");
                return -2.0;
        }
}

void writeStudentsData(const Student* s){
        FILE* fp= fopen("./StudentsData/studentsData.txt","w");
        if(fp == NULL){
                printf("could not open the target file in function writeStudentsData\n");
                exit(0);
        }
        while(s != NULL){
                fwrite(s,sizeof(Student),1,fp);
                s = s->next;
        }
        fclose(fp);
}

void writeBooksData(const Book* b){
        FILE* fp= fopen("./BooksData/booksData.txt","w");
        if(fp == NULL){
                printf("could not open the target file in function writeBooksData\n");
                exit(0);
        }
        while(b != NULL){
                fwrite(b,sizeof(Book),1,fp);
                b = b->next;
        }
        fclose(fp);
}

void writeRecordsData(const Record*r){
        FILE* fp= fopen("./RecordsData/recordsData.txt","w");
        if(fp == NULL){
                printf("could not open the target file in function writeRecordsData\n");
                exit(0);
        }
        while(r != NULL){
                fwrite(r,sizeof(Record),1,fp);
                r = r->next;
        }
        fclose(fp);
}

void checkInExit(const Student* s, const Book*b,const Record* r){
        if(counterStudentData != 0){
                writeStudentsData(s);
        }
        if(counterBookData != 0){
                writeBooksData(b);
        }
        if(counterRecordData != 0){
                writeRecordsData(r);
        }
}


void borrowBook(const char* ID,Student * studentsData,const  char* ISBN,Book* bookData,Record ** recordsData){
        Student temps = searchStudent(ID,studentsData);
        if(strcmp(temps.ID,"-1") == 0){
                printf("could not find this target student\n");
        }
        Book* tempb = searchBookByISBN(ISBN,bookData);
        if(tempb == NULL){
                printf("could not find this target book\n");
                return ;
        }
        if(tempb->amount<1){
                printf("There's not a single book left.");
                return ;
        }
        addRecord(ID,ISBN,recordsData);
        setAmount(tempb,tempb->amount-(unsigned int )1);
        counterBookData++;                                
        printf("Borrow book successfully\n");
}

void returnBook(const char* ID,Student * studentsData,const  char* ISBN,Book* bookData,Record ** recordsData){
        Student temps = searchStudent(ID,studentsData);
        if(strcmp(temps.ID,"-1") == 0){
                printf("could not find this target student\n");
                return ;
        }
        Book* tempb = searchBookByISBN(ISBN,bookData);
        if(tempb == NULL){
                printf("could not find this target book\n");
                return ;
        }
        double flag = deleteRecord(ID,ISBN,recordsData);
        if(flag >= (double)0.0){
                setAmount(tempb,tempb->amount + (unsigned int )1);
                counterBookData++; 
                printf("The student should pay %lf yuan\n",flag);
        }
        else{
                printf("could not find the record.");
        }
        
}


void getID(char * ID, unsigned long sizeID){
        /* ID 替换了 temp->ID , sizeID 替换了 sizeof(temp->ID)*/
        while(1){
            printf("Please input student's ID,whose length is at most %ld\n",sizeID - (unsigned long)3);
            if(fgets(ID,sizeID,stdin)==NULL){
                printf("error in  get ID\n");
                exit(0);
            }
            printf("The length of ID is %ld. \n",strlen(ID));
            /*in Linux*/
            if(strlen(ID)==(sizeID-1) ){
                printf("The length of ID is over. Please input again\n");
                while(getchar()!='\n');
                continue;
            }

            /*in Windows*/
            /*
            if(ID[strlen(ID)-1] != '\n' ){
                printf("The length of ID is over. Please input again\n");
                while(getchar()!='\n');
                continue;
            }
            */
            break;
        }
        /*In LInux*/
        ID[strlen(ID)-1]='\0';
        /*In windows*/
        /*
        ID[strlen(ID)-2]='\0';
        */
}

void getISBN(char * ISBN, unsigned long sizeISBN){
        while(1){
                printf("Please input book's ISBN,whose length is at most %ld\n",sizeISBN- (unsigned long)3);
                if(fgets(ISBN,sizeISBN,stdin)==NULL){
                        printf("error in  get ISBN\n");
                        exit(0);
                }
                printf("The length of ISBN is %ld. \n",strlen(ISBN));
                /*in Linux*/
                if(strlen(ISBN)==(sizeISBN-1) ){
                        printf("The length of ISBN is over. Please input again\n");
                        while(getchar()!='\n');
                        continue;
                }

                /*in Windows*/
                /*
                if(temp->ISBN[strlen(temp->ISBN)-1] != '\n' ){
                        printf("The length of ISBN is over. Please input again\n");
                        while(getchar()!='\n');
                        continue;
                }
                */
                        /*In LInux*/
                ISBN[strlen(ISBN)-1]='\0';
                /*In windows*/
                /*
                ISBN[strlen(ISBN)-2]='\0';
                */
                if(strlen(ISBN) != 13){
                        printf("The ISBN must contains 13 digites\n");
                        continue;
                }
                break;
        }
}

