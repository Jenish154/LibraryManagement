#include <stdio.h>
#include "library.h"

void handle_display_book(struct Library *lib)
{
    display_books(lib);
}

void handle_remove_book(struct Library *lib)
{
    char title[100];
    printf("\nEnter the title of the book you want removed: ");
    scanf("%s", title);

    remove_book(lib, title);
    printf("Book with title: %s was removed\n\n", title);
}

void handle_add_books(struct Library *lib)
{
    char title[100], author[100];
    printf("\nEnter the title of the book you want to add: ");
    scanf("%s", title);
    printf("Enter the author of this book: ");
    scanf("%s", author);

    add_book(lib, title, author);
    printf("Book with title: %s and author: %s added\n\n", title, author);
}

void display_menu(struct Library *lib) 
{
    printf("-----------------------------------------------------------\n");
    printf("Welcome to the library\n");
    int con = 1;
    while (con)
    {
        int query;

        printf("Enter 1 to display all books\n");
        printf("Enter 2 to add a book\n");
        printf("Enter 3 to remove a book from the library\n");
        printf("Enter 4 to exit the library\n");
        printf("Enter your choice: ");
        scanf("%d", &query);

        switch (query)
        {
            case 1:
                handle_display_book(lib);
                break;
            case 2:
                handle_add_books(lib);
                break;
            case 3:
                handle_remove_book(lib);
                break;
            case 4:
                con = 0;
                break;
            default:
                printf("Enter a valid choice\n");
                break;
        }
    }

    printf("-----------------------------------------------------------\n");

}

int main()
{
    struct Library lib = 
    {
        .books = {},
        .num_books = 0
    };

    display_menu(&lib);
    
    return 0;
}