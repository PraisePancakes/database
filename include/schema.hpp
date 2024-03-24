#pragma once
#include <ctime>
#include <iostream>

/*
    As I was developing this project, I noticed that the database and its items shared a lot of common attributes.
    They both have a name e.g a databases name will be tied to its collection while a user has a username,
    They both have timestamps, and they both also have ids tied to the instance itself, because of this there has been a common structure in this project.
    the structure goes like so.

          Schema (Base)
        /              \
       /                \
Db [item] (child)  \
                         User [item] (child)


    with this implementation flow, both the User class and the Db class are items created from a schema,
    The schema will have a virtual serializable method which
    the db can serialize itself with and the user item can serialize itself with.


*/

class Schema
{
protected:
    std::string name;
    size_t id;
    time_t createdAt;
    time_t updatedAt;

public:
    Schema();
    Schema(const std::string &name);
    virtual const std::string GetName() const = 0;
    virtual unsigned long int GetID() const = 0;
    const std::string &StringifyTime(time_t time) const;
    virtual void SetID(size_t id) = 0;
    virtual void Introduce() const = 0;
    // virtual void Serializable() const = 0;

    const time_t GetCreatedAt() const;
    const time_t GetUpdatedAt() const;

    ~Schema();
};