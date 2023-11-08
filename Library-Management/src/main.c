#include <stdio.h>
#include "library.h"

void display_menu() 
{

}

int main()
{
    struct Library lib = 
    {
        .books = {},
        .num_books = 0
    };
    add_book(&lib, "First One", "Jenish P");
    for (int i=0; i<202; i++) {
        add_book(&lib, "Jenish", "Hello");
    }
    remove_book(&lib, "First One");
    display_books(&lib);
    return 0;
}