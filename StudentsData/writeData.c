#include"../student.h"
#include<stdio.h>
#include<string.h>
int main(int argc , char *argv[]){
        FILE *fp = fopen("studentsData.txt","w");
        if(fp == NULL){
                printf("There is no target file\n");
                return 0;
        }
        Student temp;
        strcpy(temp.ID,"3115003667");
        strcpy(temp.name,"LCQ");
        strcpy(temp.department,"CS");
        strcpy(temp.phoneNumber,"13119659879");
        strcpy(temp.sexual,"female");
        strcpy(temp.dateGraduating,"20190626");
        fwrite(&temp,sizeof(Student),1,fp);

        strcpy(temp.ID,"3115003668");
        fwrite(&temp,sizeof(Student),1,fp);
        fclose(fp);

        fp = fopen("studentsData.txt","r");
        if(fp == NULL){
                printf("There is no target file\n");
                return 0;
        }

        Student m;
        for(int i=2;i>=1;i--){
                fread(&m,sizeof(Student),1,fp);
                printf("s.ID is: %s \n",m.ID);
                printf("s.name is: %s \n",m.name);
                printf("s.sexual is: %s \n",m.sexual);
                printf("s.department is: %s \n",m.department);
                printf("s.phoneNumber is: %s \n",m.phoneNumber);
                printf("s.dateGraduating is: %s \n",m.dateGraduating);
                printf("\n\n"); 
        }
        fclose(fp);
        return 0;
}