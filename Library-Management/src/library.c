#include <stdio.h>
#include "library.h"
#include <string.h>

const int NUM_OF_BOOKS = 200;

void remove_element_from_array(struct Book books[NUM_OF_BOOKS], int ind, int max)
{
    for (int i = ind; i < max; i++)
    {
        books[ind] = books[ind+1];
        books[ind].book_id = ind;
    }
}

void add_book(struct Library *lib, char title[100], char author[100])
{
    //check if maximum capacity is reached
    if (lib->num_books >= NUM_OF_BOOKS - 1) 
    {
        printf("Maximum capacity of %d reached. Book not added, remove another to add this one.\n", NUM_OF_BOOKS);
        return;
    }

    int num_books = lib->num_books;
    struct Book new_book;

    //Note for me: strcpy is more safe 
    strcpy(new_book.title, title);
    strcpy(new_book.author, author);
    new_book.book_id = num_books;

    //adding the book
    lib->books[num_books] = new_book;
    lib->num_books = num_books + 1;

}

void remove_book(struct Library *lib, char title[100])
{
    //remove book from the library with title
    struct Book curr_book;
    for (int i = 0; i < lib->num_books; i++) 
    {
        curr_book = lib->books[i];
        if (strcmp(title, curr_book.title) == 0) 
        {
            remove_element_from_array(lib->books, i, lib->num_books);
        }
    }
    lib->num_books = lib->num_books - 1;
}

void display_books(struct Library *lib)
{
    //For diplaying all the books in the order they are added.


    printf("###################################################################################\n");
    if (lib->num_books == 0) 
    {
        printf("No books added yet!\n");
    }
    for (int i = 0; i<lib->num_books; i++)
    {
        struct Book book = lib->books[i];
        printf("%d. Title: %s Author: %s\n", book.book_id + 1, book.title, book.author);

    }
    printf("###################################################################################\n");
}