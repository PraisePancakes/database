#include "../include/hashtable.hpp"

HashTable::HashTable()
{
    for (size_t i = 0; i < this->TABLE_SIZE; i++)
    {
        this->table[i] = nullptr;
    }
};

HashItem *HashTable::GetByIndex(size_t index) const
{
    return this->table[index];
};

size_t HashTable::hash(const std::string &key)
{
    size_t hash = 0;
    size_t index;

    for (size_t i = 0; i < key.length(); i++)
    {
        hash += (int)key[i];
    }

    index = hash % this->TABLE_SIZE;

    return index;
};

void HashTable::Insert(HashItem *item)
{
    size_t idx = hash(item->key);
    item->user->SetID(idx);
    this->table[idx] = item;
};

size_t HashTable::GetSize() const { return this->TABLE_SIZE; };

HashItem *HashTable::Get(const std::string &key)
{
    int idx = hash(key);
    if (idx >= 0 && idx < TABLE_SIZE)
    {
        return this->table[idx];
    }

    return NULL;
}
void HashTable::List() const
{
    for (size_t i = 0; i < this->TABLE_SIZE; i++)
    {
        if (table[i] != nullptr)
        {
            table[i]->user->Introduce();
        }
    };
};