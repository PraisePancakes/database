#include "../include/database.hpp"
#include <algorithm>

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

User *DataBase::FindById(int id)
{
    for (size_t i = 0; i < users.size(); i++)
    {
        if (this->users[i].GetID() == id)
        {
            std::cout << "__FOUND USER: " << std::endl;
            return &users[i];
        }
    }

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