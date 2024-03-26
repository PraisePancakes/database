#include "../include/database.hpp"
#include <algorithm>
#include <cmath>

bool compareByCreationTime(const User *user1, const User *user2)
{
    return user1->GetCreatedAt() < user2->GetCreatedAt();
}

bool compareByCreationTimeReverse(const User *user1, const User *user2)
{
    return user1->GetCreatedAt() > user2->GetCreatedAt();
}

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

User *DataBase::FindByID(size_t id) const
{
    HashItem *item = dbTable->GetByIndex(id);
    if (item == nullptr)
    {
        return nullptr; // Return nullptr if item is not found
    }
    return item->user;
}

void DataBase::SetID(size_t id){};

unsigned long int DataBase::GetID() const
{
    return this->id;
}

void DataBase::List() const
{
    if (currentState->SortedByNewestItem)
    {
        std::vector<User *> users;
        for (size_t i = 0; i < HashTable::TABLE_SIZE; ++i)
        {
            HashItem *item = dbTable->GetByIndex(i);
            if (item)
            {
                users.push_back(item->user);
            }
        }
        std::sort(users.begin(), users.end(), compareByCreationTime);

        for (const auto &user : users)
        {

            user->Introduce();
        }
    }
    else if (currentState->SortedByOldestItem)
    {
        std::vector<User *> users;
        for (size_t i = 0; i < HashTable::TABLE_SIZE; ++i)
        {
            HashItem *item = dbTable->GetByIndex(i);
            if (item)
            {
                users.push_back(item->user);
            }
        }

        std::sort(users.begin(), users.end(), compareByCreationTimeReverse);

        for (const auto &user : users)
        {
            user->Introduce();
        }
    }
    else
    {
        for (size_t i = 0; i < HashTable::TABLE_SIZE; ++i)
        {
            HashItem *item = dbTable->GetByIndex(i);
            if (item)
            {
                item->user->Introduce();
            }
        }
    }
}

/*
   SEARCHING ALGORITHMS ARE CONSTANT TIME LOOKUPS BECAUSE WE NOW IMPLEMENTED A HASH TABLE FOR THE USERS
*/

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
    std::cout << "      state               : Sorted By Insertion" << std::endl;
    std::cout << "      collectionName      : " << this->GetName() << std::endl;
    std::cout << "      collectionId        : " << this->id << std::endl;
    std::cout << "      createdAt           : " << StringifyTime(this->createdAt) << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
}

void DataBase::SortByOldest()
{
    this->currentState->SortedByOldestItem = true;
    this->currentState->SortedByNewestItem = false;
}

void DataBase::SortByNewest()
{
    this->currentState->SortedByOldestItem = false;
    this->currentState->SortedByNewestItem = true;
};

DataBase::~DataBase()
{
    delete this->currentState;
    delete this->dbTable;
};