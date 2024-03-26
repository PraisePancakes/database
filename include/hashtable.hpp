#pragma once
#include "user.hpp"

class User;

typedef struct HashItem
{
    std::string key;
    User *user;
    HashItem(const std::string &key, User &user)
    {
        this->key = key;
        this->user = &user;
    };
} Item;

class HashTable
{
public:
    HashTable();
    void Clear();
    static const int TABLE_SIZE = 1000001;
    HashItem *table[TABLE_SIZE];
    size_t hash(const std::string &key);
    void Insert(HashItem *item);
    size_t GetSize() const;

    HashItem *Get(const std::string &key);
    HashItem *GetByIndex(size_t index) const;

    void List() const;
};