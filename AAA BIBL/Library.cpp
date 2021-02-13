#include <iostream>
#include "Library.h"
#include <windows.h>
#include <fstream>
#include <cstdlib>

using namespace std;

Library::Library()
{
        takeABook = 0;
        numberOfAddedBooks = 0;
}

    void Library::addBook(string title, string author)
    {
        if(numberOfAddedBooks<listOfBooks)
            {
                allBooks[numberOfAddedBooks] = Book(title,author);
                numberOfAddedBooks++;

               // cout << "Dodano Ksiazke: " << Ttitle << ", "<<Aauthor<<endl;
            }
            else
            {
                cout << "Maksymalna liczba ksiazek dodana" << endl;

            }
    }
    void Library::takeBook()
    {
        cout<<endl;
        cout << "Wybierz ksiazke z listy ksiazek dostepnych do wypozyczenia (lub 0 aby wyjsc):" << endl << endl;
        cin >> takeABook;
            if(takeABook < 0 || takeABook > numberOfAddedBooks)
                {
                    if(takeABook != 0)
                        {
                            takeABook = 0;
                            cout << "Nie ma takiej ksiazki" << endl << endl;
                            system("pause");
                        }
                }
    }

    void Library::cleanBase()
    {
        fstream file;
        file.open("ListOfBooks.txt",ios::out);
        file.close();
    }

    void Library::readBooksFromBase()
    {
        string a[20];
        string b[20];
        string something[20];
        fstream file1;
        string line1;
        int lineNumber=1;
        int numberOfBook=0;
        file1.open("ListOfBooks.txt",ios::in);
        if(file1.good()==false)
        {
            cout<<"Plik zostal uszkodzony badz nie istnieje"<<endl;
            exit(0);
        }
        while(getline(file1,line1))
        {
            switch(lineNumber)
            {
                case 1: a[lineNumber]=line1; break;
                case 2: b[lineNumber]=line1; break;
                case 3: something[lineNumber]=line1; break;
            }
            if(lineNumber==3){lineNumber=0;numberOfBook++;}
            lineNumber++;
        }
        file1.close();

        for(int i=0; i<=19; i++)
        {
            cout<<a[i]<<endl;
            cout<<b[i]<<endl;
            cout<<something[i]<<endl;
        }
    }

    void Library::sendUsersToBase()
    {

    }


    void Library::showAllBooksInBase()
    {
        int i = 0;
        for(i = i; i < numberOfAddedBooks; i++)
            {
                cout <<  i+1 <<". "<<endl;
                allBooks[i].show();
                cout << endl;
            }
        cout << endl << "Wszystkich ksiazek: " << numberOfAddedBooks << endl;
    }

    void Library::BookIsTaken()
    {
        int i = 0;
        for(i = i; i < listOfBooks; i++)
        {
            allBooks[i].show();
            allBooks[i].BookIsTaken();
            cout<<endl;
        }
    }

    void Library::sendBookToBase()
    {
        for(int i=0;i<listOfBooks;i++)
            {
                allBooks[i].sendInformationsAboutBook();
            }
    }

    void Library::showPiecesBooks()
    {
        int i = 0;
        for(i = i; i < listOfBooks; i++)
            {
                allBooks[i].show();
                allBooks[i].showPiecesBooks();
            }
    }

    void Library::showTakenBooks()
    {
        int i = 0;
        for(i = i; i < listOfBooks; i++)
            {
                allBooks[i].show();
                allBooks[i].showTakenBooks();
            }
    }

    void Library::borrowBook()
    {
        cout << "Wypozycz:" << endl << endl << endl;
        showAllBooksInBase();
        takeBook();
        if(takeABook != 0)
            {
            allBooks[takeABook-1].borrowBook();
            }
    }

    void Library::cancelBorrowing()
    {
        cout << "Anuluj wypozyczanie:" << endl << endl << endl;
        showAllBooksInBase();
        takeBook();
        if(takeABook != 0)
            {
                allBooks[takeABook-1].cancelBorrowing();
            }
    }

    void Library::checkBorrow()
    {
        cout << "Sprawdz wypozyczanie:" << endl << endl << endl;
        showAllBooksInBase();
        takeBook();
        if(takeABook != 0)
        {
            allBooks[takeABook-1].checkBorrow();
        }
    }


