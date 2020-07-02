#include"book.h"
#include<string.h>
void setPublishingHouse( Book* book,const char * publishingHouse){
      strcpy(book->publishingHouse,publishingHouse);
}
void setBookName( Book* book,const char* name){
      strcpy(book->name,name);
}
void setISBN( Book* book,const char* newISBN){
      strcpy(book->ISBN,newISBN);
}
void setDatePublishing( Book* book,const char* datePublishing){
      strcpy(book->datePublishing,datePublishing);
}
void setCategory( Book* book,const char* category){
      strcpy(book->category,category);
}
void setPages( Book* book,unsigned int pages){
      book->pages = pages;
}
void setAmount( Book* book,unsigned int amount){
      book->amount = amount;
}
void setAuthor( Book* book,const char* author){
      strcpy(book->author,author);
}
Book getBookInfo( const Book* book){
        return *book;
}