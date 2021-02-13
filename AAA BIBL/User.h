#ifndef USER_H
#define USER_H


class User
{

public:
    char name[40];
    char surename[40];
    int number;
    bool borrow;

    User();
    User(char [], char [], int, bool);
    void borrowBook();
    void cancelBorrowing();
    void show();
    bool isBorrowed();
    void dateOfBorrow();

};


#endif // USER_H
