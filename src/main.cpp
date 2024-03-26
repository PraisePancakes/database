#include <iostream>
#include "../include/user.hpp"
#include "../include/database.hpp"
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    DataBase db("Collection1");
    system("cls");

    User user1("User1");
    sleep(3);
    User user2("User2");
    sleep(3);
    User user3("User3");
    sleep(3);
    User user4("User4");
    sleep(3);
    User user5("User5");

    db.Insert(user1);

    db.Insert(user2);

    db.Insert(user3);

    db.Insert(user4);

    db.Insert(user5);

    int db_process = 0;
    const int DB_END_PROCESS = 5;

    do
    {
        system("cls");
        db.Introduce();
        std::cout << "PROCESSES :: [1] view collection list [2] sort collection list [3] view item by username [4] view item by id [5] end process" << std::endl;
        std::cin >> db_process;
        getchar();

        switch (db_process)
        {
        case 1:
        {
            db.List();
            std::cout << "Enter any key to go back..." << std::endl;
            getchar();
        }

        break;
        case 2:
        {
            int db_sort_process = 0;
            const int DB_END_SORT_PROCESS = 3;
            do
            {
                std::cout << "[1] sort by oldest items  [2] sort by newest items  [3] back" << std::endl;
                std::cin >> db_sort_process;
                db.List();
                switch (db_sort_process)
                {
                case 1:
                    db.SortByOldest();
                    break;
                case 2:
                    db.SortByNewest();
                    break;
                case 3:
                    std::cout << "SORTING PROCESS ENDED" << std::endl;
                    std::cout << "Enter any key to go back..." << std::endl;
                    getchar();
                    break;
                default:
                    std::cout << "SORTING PROCESS ENDED" << std::endl;
                    std::cout << "Enter any key to go back..." << std::endl;
                    getchar();
                    break;
                }
            } while (db_sort_process != DB_END_SORT_PROCESS);
        }
        break;
        case 3:
        {
            std::string username = "";
            std::cout << "Enter Username : ";
            std::cin >> username;
            getchar();

            User *found = db.FindByKey(username);

            if (found == NULL)
            {
                std::cout << "Could not retrieve user data :: User not found " << std::endl;
                std::cout << "Enter any key to go back..." << std::endl;
                getchar();
                break;
            }

            found->Introduce();
            std::cout << "Enter any key to go back..." << std::endl;
            getchar();
        }
        break;
        case 4:
        {
            size_t id = 0;
            std::cout << "Enter Id : ";
            std::cin >> id;
            getchar();

            User *found = db.FindByID(id);

            if (found == NULL)
            {
                std::cout << "Could not retrieve user data :: User not found " << std::endl;
                std::cout << "Enter any key to go back..." << std::endl;
                getchar();
                break;
            }

            found->Introduce();
            std::cout << "Enter any key to go back..." << std::endl;
            getchar();
        }
        break;
        case 5:
            std::cout << "process ended" << std::endl;
            break;
        default:
            std::cout << "[ERROR] invalid process request " << std::endl;
            break;
        };

    } while (db_process != DB_END_PROCESS);

    return EXIT_FAILURE;
}