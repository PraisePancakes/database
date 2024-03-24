#pragma once
#include <iostream>
#include <ctime>
#include "../include/database.hpp"
#include "../include/schema.hpp"

class DataBase;

class User : public Schema
{
public:
    User();
    User(const std::string &username);
    void SetID(size_t id) override;
    void Introduce() const override;
    unsigned long int GetID() const override;
    const std::string GetName() const override;

    ~User();
};