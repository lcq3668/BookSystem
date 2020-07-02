#include"../book.h"
#include<stdio.h>
#include<string.h>
int main(int argc , char *argv[]){
        FILE *fp = fopen("booksData.txt","w");
        if(fp == NULL){
                printf("There is no target file\n");
                return 0;
        }
        Book temp;
        strcpy(temp.ISBN,"7773115003667");
        strcpy(temp.name,"计算机导论");
        strcpy(temp.author,"Tom");
        strcpy(temp.category,"计算机");
        strcpy(temp.publishingHouse,"工业出版社");
        strcpy(temp.datePublishing,"20090307");
        temp.pages = 50;
        fwrite(&temp,sizeof(Book),1,fp);

        strcpy(temp.ISBN,"7773115003668");
        fwrite(&temp,sizeof(Book),1,fp);
        fclose(fp);

        fp = fopen("booksData.txt","r");
        if(fp == NULL){
                printf("There is no target file\n");
                return 0;
        }

        Book m;
        for(int i=2;i>=1;i--){
                fread(&m,sizeof(Book),1,fp);
                printf("s.ISBN is: %s \n",m.ISBN);
                printf("s.name is: %s \n",m.name);
                printf("s.author is: %s \n",m.author);
                printf("s.category is: %s \n",m.category);
                printf("s.publishingHouse is: %s \n",m.publishingHouse);
                printf("s.datePublishing is: %s \n",m.datePublishing);
                printf("s.pages is %d\n",m.pages);
                printf("\n\n"); 
        }
        fclose(fp);
        return 0;
}