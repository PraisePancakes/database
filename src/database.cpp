#include "../include/database.hpp"
#include <algorithm>
#include <cmath>

DataBase::DataBase() : Schema(), currentState(new _dbstate)
{
    dbTable = new HashTable();
};

DataBase::DataBase(const std::string &collectionName) : Schema(collectionName), currentState(new _dbstate)
{
    dbTable = new HashTable();
}

void DataBase::Insert(User &user)
{
    HashItem *newItem = new HashItem(user.GetName(), user);
    dbTable->Insert(newItem);
};

unsigned long int DataBase::GetID() const
{
    return this->id;
}

void DataBase::List() const
{
    dbTable->List();
};

/*
    WHY WE COULD USE BINARY SEARCH HERE
    for the FindById algorithm, binary search is the perfect and most efficient way to find a user by their id.
    The reason is because the user constructor uses a static count each time a user is created and that static value will be assigned to the users ID.

    what does this mean?
    Users should be inserted into the data base as soon as they are created,
    this can change so that creating the user will push the user into the database through the user constructor.
    The problem with that approach however is that the db has to be passed by REFERENCE to each user object. so say we are on a x86-64 architechture. This means that
    each variable being passed by reference is 8 bytes. This seems feasible compared to the REAL size of the db object however, if there are lets say, 4 million users, then that means
    that there will be 32 million bytes being used just from the User class constructors alone. This is a tremendous fault in the design and needs to be taken into account.
    However, currently we are not passing any references to the constructor, so the size goes down from 32 million bytes to 0. Now back to the algorithm. The only way for this to work for now is to insert
    users in order from which they are created into the db. In the future, I can maybe keep track of the inserts and sort as we insert which would be an interesting feature to add. I can also possibly
    implement a hash table for all the ids and each id can be a string (key) rather than an int



*/

User *DataBase::FindById(int id)
{
}

User *DataBase::FindByKey(const std::string &key)
{
    HashItem *item = dbTable->Get(key);
    if (item == NULL)
    {
        return NULL;
    }

    return item->user;
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
}

void DataBase::SortMostRecent(){

};

DataBase::~DataBase()
{
    delete this->currentState;
    delete this->dbTable;
};