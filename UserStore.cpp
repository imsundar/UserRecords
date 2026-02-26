#include "UserStore.h"
#include <algorithm>

void UserStore::addUser(const User& user) {
    users.push_back(user);
}

User* UserStore::findByName(const std::string& name) {
    for (auto& u : users) {
        if (u.getName() == name) {
            return &u;
        }
    }
    return nullptr;
}

void UserStore::removeByName(const std::string& name) {
    users.erase(
        std::remove_if(users.begin(), users.end(),
            [&name](const User& u) { return u.getName() == name; }),
        users.end()
    );
}

void UserStore::printAll() const {
    for (const auto& u : users) {
        u.printInfo();
    }
}

int UserStore::count() const {
    return static_cast<int>(users.size());
}
