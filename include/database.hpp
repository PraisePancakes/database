#pragma once
#include "user.hpp"
#include "schema.hpp"
#include "hashtable.hpp"
#include <ctime>
#include <vector>

/*
    This class is responsible for..
        1. serializing/archiving the state of the db into a json formatted file
            i. there are two serialization libraries that was on my mind when thinking of the structure for this archive.
                This archive is supposed to be very light weight and doesnt need to take up too much memory when invoking calls.
                So with that in mind I went with Cereal. Check out their documents here : https://uscilab.github.io/cereal/
                Cereal is a perfect light weight dependency that will help with implementing serialization
*/

class User;
class HashTable;

typedef struct _dbstate
{
    bool SortedByOldestItem;
    bool SortedByNewestItem;
    _dbstate()
    {
        this->SortedByNewestItem = false;
        this->SortedByOldestItem = false;
    };
} _dbstate;

class DataBase : public Schema
{
    HashTable *dbTable;
    _dbstate *currentState;

public:
    DataBase();
    DataBase(const std::string &collectionName);

    void Insert(User &user);
    void List() const;
    void SortByOldest();
    void SortByNewest();
    void SetID(size_t id) override;
    User *FindByKey(const std::string &key);
    User *FindByID(size_t id) const;
    void Introduce() const override;
    const std::string GetName() const override;
    unsigned long int GetID() const override;

    ~DataBase();
};