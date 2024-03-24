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
    static const int TABLE_SIZE = 1000001;
    HashItem *table[TABLE_SIZE];
    size_t hash(const std::string &key);

public:
    HashTable();
    void Insert(HashItem *item);
    HashItem *Get(const std::string &key);
    void List() const;
};