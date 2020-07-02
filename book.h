#ifndef BOOK_H
#define BOOK_H
struct Book{
    char name[48];
    char publishingHouse[32];
    char category[24];
    char ISBN[16];
    char author[16];
    char datePublishing[11];
    unsigned int  pages;
    unsigned int amount;                                // 在与数据库相关的课程设计时，应该将这一个属性从Book类移除，将之添加到库存里面
    struct Book  * next;
};
typedef struct Book Book;
void setPublishingHouse( Book* book,const char * publishingHouse);
void setBookName( Book* book,const char* name);
void setISBN( Book* book,const char* newISBN);
void setDatePublishing( Book* book,const char* datePublishing);
void setCategory( Book* book,const char* );
void setPages( Book* book,unsigned int pages); 
void setAmount( Book* book,unsigned int amount); 
void setAuthor(Book* book, const char* author);
Book getBookInfo( const Book* book);
#endif