#include <iostream>
#include <string.h>
#include <windows.h>
#include <winbase.h>

#include "User.h"

using namespace std;

        User::User()
            {
                strcpy(name, "");
                strcpy(surename, "");
                number = 0;
                borrow = false;
            }

        User::User(char Nname[], char Ssurename[], int number, bool borrow)

            {
                strcpy(name, Nname);
                strcpy(surename, Ssurename);
                this->number=number;
                this->borrow=borrow;
            }

        void User::borrowBook()
            {
                if(borrow)
                    {
                        cout << "Ksiazka jest juz wypozyczona.";
                    }
                else
                    {
                        cout << "Podaj imie: ";
                        cin >> name;
                        cout << "Podaj nazwisko: ";
                        cin >> surename;
                        borrow = true;
                        cout << endl << "Ksiazka " << number << " zostala wypozyczona: " << name << " " << surename << ".";
                        system("pause");
                    }
            }

        void User::cancelBorrowing()
            {
                if(borrow)
                    {
                        strcpy(name, "");
                        strcpy(surename, "");
                        borrow = false;
                        cout << "Wypozyczanie anulowane." << endl;
                        system("pause");
                    }
                else
                    {
                      cout << "Nie ma takiego wypozyczenia." << endl;
                      system("pause");
                    }
            }

        void User::dateOfBorrow()
        {
            SYSTEMTIME st;
            GetSystemTime(&st);
            int nextMonth;
            int nextYear;
            int nextDay;
            cout<<"Wypozyczono dnia: "<<st.wDayOfWeek<<"."<<st.wMonth<<"."<<st.wYear<<" o godzinie: "<<st.wHour<<":"<<st.wMinute<<endl;
            nextMonth=st.wMonth+1;
            if(nextMonth==13)
            {
                nextMonth=1;
                nextYear=st.wYear+1;
                cout<<"Data zwrotu: "<<st.wDayOfWeek<<"."<<nextMonth<<"."<<st.wYear<<endl;
            }
            if(st.wDayOfWeek==29&&st.wMonth==2)
            {
                nextDay=st.wDayOfWeek+1;
                cout<<"Data zwrotu: "<<nextDay<<"."<<nextMonth<<"."<<st.wYear<<endl;
            }
            else
            {
                cout<<"Data zwrotu: "<<st.wDayOfWeek<<"."<<nextMonth<<"."<<st.wYear<<endl;
            }
            cout<<"Kazdy jeden dzien oddania ksiazki po terminie wynisi 1zl kary!"<<endl;
        }

        void User::show()
            {
                if(borrow)
                    {
                        cout<< "Numer: " << number << ", " << name << " " << surename << endl;
                        dateOfBorrow();
                    }
                else
                    {
                        cout << "Numer: " << number << " do wypozyczenia" << endl;
                    }
            }

        bool User::isBorrowed()
            {
                return borrow;
            }

