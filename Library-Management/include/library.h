#ifndef LIBRARY_H
#define LIBRARY_H

extern const int NUM_OF_BOOKS;

struct Book
{
    char title[100];
    char author[100];
    int book_id;
};

struct Library
{
    int num_books;
    struct Book books[];
};

void add_book(struct Library *lib, char title[100], char author[100]);
void remove_book(struct Library *lib, char title[100]);
void display_books(struct Library *lib);

#endif