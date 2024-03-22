#include <iostream>
#include "../include/user.hpp"
#include "../include/database.hpp"
#include <unistd.h>

int main(int argc, char *argv[])
{
    DataBase db("Collection1");
    system("cls");
    db.Introduce();

    User user1("User1");
    sleep(3);
    User user2("User2");

    db.Insert(user1);
    db.Insert(user2);

    db.SortMostRecent();
    db.List();

    return EXIT_FAILURE;
}