#ifndef USERSTORE_H
#define USERSTORE_H

#include <vector>
#include <string>
#include "User.h"

class UserStore {
private:
    std::vector<User> users;

public:
    void addUser(const User& user);
    User* findByName(const std::string& name);
    void removeByName(const std::string& name);
    void printAll() const;
    int count() const;
};

#endif // USERSTORE_H
