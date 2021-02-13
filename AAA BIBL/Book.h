#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include "User.h"

using namespace std;

class Book
{
private:
    string title;
    string author;
    static const int numberOfBooks = 5;
    int chosenBook;
    User allBooks[numberOfBooks];
public:

    Book();
    Book(string title, string author);
    void show();
    void chooseABook();
    void BookIsTaken();
    void showAllBooks();
    void showPiecesBooks();
    void showTakenBooks();
    void borrowBook();
    void cancelBorrowing();
    void checkBorrow();
    friend void waitForReaction();
    void sendInformationsAboutBook();
};

#endif // BOOK_H
