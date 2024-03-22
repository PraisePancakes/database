#include "../include/schema.hpp"
#include "../utils/stringify.hpp"

Schema::Schema()
{
    static int id = 0;
    this->name = "";
    this->id = id++;
    this->createdAt = time(NULL);
    this->updatedAt = time(NULL);
};

Schema::Schema(const std::string &name)
{
    static int id = 0;
    this->name = name;
    this->id = id++;
    this->createdAt = time(NULL);
    this->updatedAt = time(NULL);
};

const std::string &Schema::StringifyTime(time_t time) const
{
    return utils::stringify::StringifyFormattedDate(time);
};

const time_t Schema::GetCreatedAt() const
{
    return this->createdAt;
};

const time_t Schema::GetUpdatedAt() const
{
    return this->updatedAt;
};

Schema::~Schema(){};