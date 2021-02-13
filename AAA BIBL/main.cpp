#include <iostream>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <cstdio>
#include "User.h"
#include "Book.h"
#include "Library.h"

using namespace std;

void showMenu()
{
    cout << "Wybierz opcje:" << endl << endl;
    cout << "1 - Wypozycz ksiazke." << endl;
    cout << "2 - Anuluj wypozyczanie." << endl;
    cout << "3 - Wyswietl wszystkie tytuly" << endl;
    cout << "4 - Wyswietl wszystkie ksiazki i ich dostepnosc" << endl;
    cout << "5 - Wyswietl wypozyczenia uzytkownikow" << endl;
    cout << "6 - Zamknij system" << endl;
}

void waitForReaction()
{
    cout << endl << "(Wcisnij dowolny przycisk, aby wyjsc)" << endl;
    getchar();
}

int main()
{

    Library library;
    library.addBook("Solaris","Stanislaw Lem");
    library.addBook("Taniec ze Smokami","George R.R. Martin");
    library.addBook("Tatuazysta w Auschwitz","Heather Morris");
    library.addBook("Cujo","Stephen King");
    library.addBook("Potop","Henryk Sienkiewicz");
    library.addBook("Silmarillion","J.R.R. Tolkien");
    library.addBook("Druzyna Pierscienia","J.R.R. Tolkien");
    library.addBook("Ostatnie Zyczenia","Andrzej Sapkowski");
    library.addBook("Harry Potter i Wiezien Azkabanu","J.K. Rowling");
    library.addBook("Czarownik Iwanow","Andrzej Pilipiuk");
    library.addBook("Konan Destylator","Andrzej Pilipiuk");
    library.addBook("Jezyk C++ Szkola Programowania","Stephen Prata");
    library.addBook("Piecdziesiat Twarzy Greya","E.L. James");
    library.addBook("Miecz Przeznaczenia","Andrzej Sapkowski");
    library.addBook("Blaze","Richard Bachman");
    library.addBook("To","Stephen King");
    library.addBook("Starcie Krolow","George R.R. Martin");
    library.addBook("Wszystko o... Pszczolach","Jack Guichard, Carole Xenard");
    library.addBook("Ze Srodka do Srodka","Grzegorz Pac");
    library.addBook("Astrofizyka Dla Zabieganych","Neil deGrasse Tyson");

    showMenu();
    char znak;
    znak = getch();

    while(znak != '6')
    {

        system("cls");

        switch(znak)
        {
            case '1':
                library.borrowBook();
                break;
            case '2':
                library.cancelBorrowing();
                break;
            case '3':
                library.BookIsTaken();
                system("pause");
                break;
            case '4':
                library.showPiecesBooks();
                system("pause");
                break;
            case '5':
                library.showTakenBooks();
                system("pause");
                break;
            case '8':
                library.readBooksFromBase();
                system("pause");
                break;
        }

        system("cls");
        showMenu();
        znak = getchar();

    }
    library.cleanBase();
    library.sendBookToBase();

    return 0;
}
