#include <iostream>
#include "../include/user.hpp"
#include "../include/database.hpp"
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    DataBase db("Collection1");
    system("cls");

    int db_process = 0;
    const int DB_END_PROCESS = 4;
    User user1("User1");
    User user2("User2");
    db.Insert(user1);
    db.Insert(user2);

    do
    {
        system("cls");
        db.Introduce();
        std::cout << "PROCESSES :: [1] view collection list [2] sort collection list [3] view item by id [4] end process" << std::endl;
        std::cin >> db_process;
        getchar();

        switch (db_process)
        {
        case 1:
        {
            db.List();
            std::cout << "press any key to go back...";
            getchar();
        }

        break;
        case 2:
        {
        }
        break;
        case 3:
        {
        }
        break;
        case 4:
            std::cout << "process ended" << std::endl;
            break;
        default:
            std::cout << "[ERROR] invalid process request " << std::endl;
            break;
        };

    } while (db_process != DB_END_PROCESS);

    return EXIT_FAILURE;
}