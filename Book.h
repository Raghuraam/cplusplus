#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include "Student.h"
using namespace std;

static int book_conter = 0;

class Book
{
    private:
        int id;
        string name;
        string genre;
        bool isBorrowed;
        Student* student;

    public:
        Book(string name, string genre, bool isBorrowed): id(++book_conter), name(name), genre(genre), isBorrowed(isBorrowed), student(nullptr)
        {
            cout << "Book Constructor called" << endl;
        }

};

#endif //BOOK_H