#include"../utility.h"
#include<stdio.h>
#include<stdlib.h>
int main(int argc , char* argv[]){
        
        Student* s = getStudentsData();
        while(s != NULL){
                printf("s.ID is: %s \n",s->ID);
                printf("s.name is: %s \n",s->name);
                printf("s.sexual is: %s \n",s->sexual);
                printf("s.department is: %s \n",s->department);
                printf("s.phoneNumber is: %s \n",s->phoneNumber);
                printf("s.dateGraduating is: %s \n",s->dateGraduating);
                printf("\n\n"); 
                s = s->next;
        }
        
        
        Book* b = getBooksData();
        while(b != NULL){
                printf("b->ISBN is: %s \n",b->ISBN);
                printf("b->name is: %s \n",b->name);
                printf("b->author is: %s \n",b->author);
                printf("b->category is: %s \n",b->category);
                printf("b->publishingHouse is: %s \n",b->publishingHouse);
                printf("b->datePublishing is: %s \n",b->datePublishing);
                printf("b->pages is %d\n",b->pages);
                printf("b->amount is %d\n",b->amount);
                printf("\n\n"); 
                b = b->next;
        }
        
       
        Record* r = getRecordsData();
        while(r != NULL){
                printf("r->ISBN is: %s \n",r->ISBN);
                printf("r->ID is: %s \n",r->ID);
                printf("r->current is : %ld\n",r->current);
                printf("r->deadline is : %ld\n",r->deadline);
                printf("\n\n"); 
                r = r->next;
        }
        
        return 0;
}