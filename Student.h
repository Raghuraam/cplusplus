#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>
#include "Book.h"
using namespace std;

static int student_counter = 0;

class Book;

class Student
{
    private:
        int id;
        string name;
        vector<Book*> books_borrowed;

    public:
        Student(string name): id(++student_counter), name(name)
        {
            cout << "Student Constructor called" << endl; 
        }


};
#endif //STUDENT_H
