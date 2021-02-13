#include <iostream>
#include <string.h>
#include <windows.h>
#include <fstream>

#include "Book.h"

using namespace std;

Book::Book()
{

    chosenBook = 0;
    int i = 0;
    for(i = i; i < numberOfBooks; i++)
        {
            allBooks[i] = User("","",i+1,false);
        }
}

Book::Book(string title,string author)
    {
        this->title=title;
        this->author=author;
        chosenBook = 0;
        int i = 0;
        for(i = i; i < numberOfBooks; i++)
            {
                allBooks[i] = User("","",i+1,false);
            }
    }

    void Book::show()
    {
        cout<<endl;
        cout << "Tytul: " << title <<endl;
        cout <<"Autor: " <<author<<endl;

    }

    void Book::chooseABook()
    {
        cout << "Wybierz ksiazke z listy (lub 0 aby wyjsc):" << endl << endl;
        cin >> chosenBook;
        if(chosenBook < 0 || chosenBook > numberOfBooks)
            {
                if(chosenBook != 0)
                    {
                        chosenBook = 0;
                        cout << "Nie ma takiego id." << endl << endl;
                    }
            }
    }

    void Book::BookIsTaken()
    {
        chosenBook = 0;
    }

    void Book::showAllBooks()
    {
        int i = 0;
        for(i = i; i < numberOfBooks; i++)
            {
                allBooks[i].show();
            }
        cout << endl << "Wszystkich ksiazek: " << numberOfBooks << endl;
    }

    void Book::showPiecesBooks()
    {
        int i = 0;
        int free = 0;
        for(i = i; i < numberOfBooks; i++)
        {
            if(!allBooks[i].isBorrowed())
                {
                    allBooks[i].show();
                    free++;
                }

        }
        cout << "Do wypozyczenia: " << free << endl;
        cout<<endl;
    }

    void Book::showTakenBooks()
    {
        int i = 0;
        int taken = 0;
        for(i = i; i < numberOfBooks; i++)
        {
            if(allBooks[i].isBorrowed())
                {
                    allBooks[i].show();
                    taken++;
                }
        }
        cout << "Wypozyczone: " << taken << endl;
    }

    void Book::borrowBook()
    {
        cout << "Wypozycz:" << endl << endl << endl;
        showPiecesBooks();
        chooseABook();
        if(chosenBook != 0)
            {
                allBooks[chosenBook-1].borrowBook();
            }
        void waitForReaction();
    }

    void Book::cancelBorrowing()
    {
        cout << "Anuluj wypozyczanie:" << endl << endl << endl;
        showTakenBooks();
        chooseABook();
        if(chosenBook != 0)
            {
                allBooks[chosenBook-1].cancelBorrowing();
            }
        void waitForReaction();
    }

    void Book::checkBorrow()
    {
        cout << "Sprawdz wypozyczanie:" << endl << endl << endl;
        chooseABook();
        if(chosenBook != 0)
            {
                allBooks[chosenBook-1].show();
                BookIsTaken();
            }
       void waitForReaction();
    }

    void Book::sendInformationsAboutBook()
    {
        fstream file;
        string helper = "/////////////////////////////////";
        file.open("ListOfBooks.txt",ios::out | ios::app);
        file<<title<<endl;
        file<<author<<endl;
        file<<helper<<endl;
        file.close();
    }

