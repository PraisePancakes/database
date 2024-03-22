#pragma once
#include <ctime>
#include <iostream>

class Schema
{
protected:
    std::string name;
    unsigned long int id;
    time_t createdAt;
    time_t updatedAt;

public:
    Schema();
    Schema(const std::string &name);
    virtual const std::string GetName() const = 0;
    virtual unsigned long int GetID() const = 0;
    const std::string &StringifyTime(time_t time) const;
    virtual void Introduce() const = 0;
    const time_t GetCreatedAt() const;
    const time_t GetUpdatedAt() const;

    ~Schema();
};