#pragma once
#include "user.hpp"
#include "schema.hpp"
#include <ctime>
#include <vector>

/*
    This class is responsible for..
        1. serializing/archiving the state of the db into a json formatted file
            i. there are two serialization libraries that was on my mind when thinking of the structure for this archive.
                This archive is supposed to be very light weight and doesnt need to take up too much memory when invoking calls.
                So with that in mind I went with Cereal. Check out their documents here : https://uscilab.github.io/cereal/
*/

class User;

typedef struct _dbstate
{
    bool SortedByOldestItem;
    bool SortedByNewestItem;
    _dbstate()
    {
        this->SortedByNewestItem = true;
        this->SortedByOldestItem = false;
    };
} _dbstate;

class DataBase : public Schema
{
    std::vector<User> users;
    _dbstate *currentState;

public:
    DataBase();
    DataBase(const std::string &collectionName);

    void Insert(const User &user);
    void List() const;
    void SortMostRecent();
    void SortLeastRecent();
    User *FindById(int id);
    void Introduce() const override;
    const std::string GetName() const override;
    unsigned long int GetID() const override;

    ~DataBase();
};