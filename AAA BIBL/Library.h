#ifndef LIBRARY_H
#define LIBRARY_H
#include "Book.h"

class Library
{
private:

    static const int listOfBooks = 20;
    int takeABook;
    Book allBooks[listOfBooks];
    int numberOfAddedBooks;

public:
    Library();
    void addBook(string title,string author);
    void takeBook();
    void showAllBooksInBase();
    void BookIsTaken();
    void showPiecesBooks();
    void showTakenBooks();
    void borrowBook();
    void cancelBorrowing();
    void checkBorrow();
    void cleanBase();
    void sendBookToBase();
    void sendUsersToBase();
    void readBooksFromBase();

};

#endif // LIBRARY_H
