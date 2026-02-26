#include "User.h"
#include <sstream>

User::User() : name(""), age(0), address("") {}

User::User(const std::string& name, int age, const std::string& address)
    : name(name), age(age), address(address) {}

std::string User::getName() const { return name; }
int User::getAge() const { return age; }
std::string User::getAddress() const { return address; }

void User::setName(const std::string& name) { this->name = name; }
void User::setAge(int age) { this->age = age; }
void User::setAddress(const std::string& address) { this->address = address; }

void User::printInfo() const {
    std::cout << "=== User Record ===" << std::endl;
    std::cout << "Name   : " << name << std::endl;
    std::cout << "Age    : " << age << std::endl;
    std::cout << "Address: " << address << std::endl;
    std::cout << "===================" << std::endl;
}

std::string User::serialize() const {
    std::ostringstream oss;
    oss << name << "|" << age << "|" << address;
    return oss.str();
}
