#include"../record.h"
#include<stdio.h>
#include<string.h>
#include<time.h>
int main(int argc , char *argv[]){
        FILE *fp = fopen("recordsData.txt","w");
        if(fp == NULL){
                printf("There is no target file\n");
                return 0;
        }
        Record temp;
        time_t now;
        strcpy(temp.ID,"3115003668");
        strcpy(temp.ISBN,"7773115003668");
        temp.current = time(&now);
        temp.deadline = now + (time_t)86400;
        fwrite(&temp,sizeof(Record),1,fp);

        strcpy(temp.ID,"3115003667");
        strcpy(temp.ISBN,"7773115003667");
        temp.current = now + (time_t)86400;
        temp.deadline = temp.current + (time_t)86400;
        fwrite(&temp,sizeof(Record),1,fp);
        fclose(fp);

        fp = fopen("recordsData.txt","r");
        if(fp == NULL){
                printf("There is no target file\n");
                return 0;
        }

        Record m;
        for(int i=2;i>=1;i--){
                fread(&m,sizeof(Record),1,fp);
                printf("m.ISBN is: %s \n",m.ISBN);
                printf("m.ID is: %s \n",m.ID);
                printf("s.current is %ld\n",m.current);
                printf("s.deadline is %ld\n",m.deadline);
                printf("\n\n"); 
        }
        fclose(fp);
        return 0;
}