#include "../include/database.hpp"
#include <algorithm>
#include <cmath>

DataBase::DataBase() : Schema(), currentState(new _dbstate)
{
    this->users = {};
};

DataBase::DataBase(const std::string &collectionName) : Schema(collectionName), currentState(new _dbstate)
{
    this->users = {};
}

void DataBase::Insert(const User &user)
{
    users.push_back(user);
};

unsigned long int DataBase::GetID() const
{
    return this->id;
}

void DataBase::List() const
{
    if (users.size() == 0)
    {
        std::cout << "List currently contains no items" << std::endl;
    }
    else
    {
        for (size_t i = 0; i < users.size(); i++)
        {
            std::cout << "{ \n      USER " << i << std::endl;
            this->users[i].Introduce();
            std::cout << "}" << std::endl;
        };
    }
};

/*
    WHY WE USE BINARY SEARCH HERE
    for the FindById algorithm, binary search is the perfect and most efficient way to find a user by their id.
    The reason is because the user constructor uses a static count each time a user is created and that static value will be assigned to the users ID.

    what does this mean?
    Users should be inserted into the data base as soon as they are created,
    this can change so that creating the user will push the user into the database through the user constructor.
    The problem with that approach however is that the db has to be passed by REFERENCE to each user object. so say we are on a x86-64 bit architechture. This means that
    each variable being passed by reference is 8 bytes. This seems feasible compared to the REAL size of the db object however, if there are lets say, 4 million users, then that means
    that there will be 32 million bytes being used just from the User class constructors alone. This is a tremendous fault in the design and needs to be taken into account.
    However, currently we are not passing any references to the constructor, so the size goes down from 32 million bytes to 0. Now back to the algorithm. The only way for this to work for now is to insert
    users in order from which they are created into the db. In the future, I can maybe keep track of the inserts and sort as we insert which would be an interesting feature to add.



*/

User *DataBase::FindById(int id)
{
    int left = 0;
    int right = users.size() - 1;

    while (left <= right)
    {
        int mid = std::floor((right + left) / 2);

        if (users[mid].GetID() == id)
        {
            return &users[mid];
        };

        if (id > users[mid].GetID())
        {
            left = mid + 1;
        }

        if (id < users[mid].GetID())
        {
            right = mid - 1;
        }
    };

    return NULL;
};

const std::string DataBase::GetName() const
{
    return this->name;
};

void DataBase::Introduce() const
{
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "      currentState        : " << (currentState->SortedByNewestItem ? "Most recent items first" : "Least recent items first") << std::endl;
    std::cout << "      collectionName      : " << this->GetName() << std::endl;
    std::cout << "      collectionId        : " << this->id << std::endl;
    std::cout << "      createdAt           : " << StringifyTime(this->createdAt) << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
}

void DataBase::SortLeastRecent()
{
    this->currentState->SortedByOldestItem = true;
    this->currentState->SortedByNewestItem = false;

    auto compareByDate = [](const User &a, const User &b)
    {
        return a.GetCreatedAt() < b.GetCreatedAt();
    };

    std::sort(users.begin(), users.end(), compareByDate);
}

void DataBase::SortMostRecent()
{
    this->currentState->SortedByNewestItem = true;
    this->currentState->SortedByOldestItem = false;

    auto compareByDate = [](const User &a, const User &b)
    {
        return a.GetCreatedAt() > b.GetCreatedAt();
    };
    std::sort(users.begin(), users.end(), compareByDate);
};

DataBase::~DataBase()
{
    delete this->currentState;
};