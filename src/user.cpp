#include "../include/user.hpp"
#include "../utils/stringify.hpp"

User::User() : Schema(){};

User::User(const std::string &username) : Schema(username)
{
}

void User::SetID(size_t id)
{
    this->id = id;
};
unsigned long int User::GetID() const { return this->id; };

void User::Introduce() const
{

    std::cout << "      username  : " << this->GetName() << std::endl;
    std::cout << "      id        : " << this->id << std::endl;
    std::cout << "      createdAt : " << StringifyTime(this->createdAt) << std::endl;
}

const std::string User::GetName() const
{
    return this->name;
}

User::~User(){};
