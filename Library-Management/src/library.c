#include <stdio.h>
#include "library.h"

void add_book(struct Library *lib, char title[100], char author[100])
{
    //check if maximum capacity is reached
    if (lib->num_books == 199) 
    {
        printf("Maximum capacity reached. Book not added, remove another to add this one.\n");
        return;
    }

    int num_books = lib->num_books;
    struct Book new_book = 
    {
        .title = title,
        .author = author,
        .book_id = num_books
    };

    //adding the book
    lib->books[num_books] = new_book;
    lib->num_books = num_books + 1;

}

void remove_book(struct Library *lib, char titile[100])
{

}

void display_books(struct Library *lib)
{
    //For diplaying all the books in the order they are added.

    struct Book books[200] = lib->books;

    printf("###################################################################################\n");

    for (int i = 0; i<lib->num_books; i++)
    {
        struct Book book = books[i];
        printf("%d. Title: %s Author: %s\n", book.book_id, book.title, book.author);

    }
    printf("###################################################################################\n");
}