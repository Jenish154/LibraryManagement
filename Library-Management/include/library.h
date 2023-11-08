#ifndef LIBRARY_H
#define LIBRARY_H

struct Book
{
    char title[100];
    char author[100];
    int book_id;
};

struct Library
{
    int num_books;
    struct Book books[200];
};

void add_book(struct Library *lib, char title[100], char author[100]);
void remove_book(struct Library *lib, char title[100]);
void display_books(struct Library *lib);

#endif