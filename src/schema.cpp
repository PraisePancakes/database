#include "../include/schema.hpp"
#include "../utils/stringify.hpp"

Schema::Schema()
{
    this->name = "";
    this->createdAt = time(NULL);
    this->updatedAt = time(NULL);
};

Schema::Schema(const std::string &name)
{
    this->name = name;
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