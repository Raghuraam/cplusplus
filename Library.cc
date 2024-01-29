#include <iostream>
#include "Book.h"
#include "Student.h"

void load_books()
{
    Book* book1 = new Book("Ikigai", "life style", false);
    Book* book2 = new Book("The 5 AM Club", "life style", false);
    Book* book3 = new Book("TATA Stories", "Non-finction", false);
    Book* book4 = new Book("Harry potter", "fantasy", false);
    Book* book5 = new Book("The sapiens", "Non-finction", false);
}


int main()
{
    Student* s1 = new Student("user1");
    load_books();

}