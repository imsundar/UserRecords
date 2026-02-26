#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>

class User {
private:
    std::string name;
    int age;
    std::string address;

public:
    // Constructors
    User();
    User(const std::string& name, int age, const std::string& address);

    // Getters
    std::string getName() const;
    int getAge() const;
    std::string getAddress() const;

    // Setters
    void setName(const std::string& name);
    void setAge(int age);
    void setAddress(const std::string& address);

    // Display
    void printInfo() const;

    // Serialize to a simple string format
    std::string serialize() const;
};

#endif // USER_H
