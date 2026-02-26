#include <iostream>
#include <vector>
#include "User.h"
#include "UserStore.h"

int main() {
    UserStore store;

    // Add some users
    store.addUser(User("Alice Johnson", 30, "123 Maple St, Springfield"));
    store.addUser(User("Bob Smith", 25, "456 Oak Ave, Shelbyville"));
    store.addUser(User("Charlie Lee", 35, "789 Pine Rd, Capital City"))

    std::cout << "All users:" << std::endl;
    store.printAll();

    // Look up a user by name
    std::cout << "\nSearching for 'Bob Smith'..." << std::endl;
    User* found = store.findByName("Bob Smith");
    if (found) {
        found->printInfo();
    } else {
        std::cout << "User not found." << std::endl;
    }

    // Update a user's address
    std::cout << "\nUpdating Alice's address..." << std::endl;
    User* alice = store.findByName("Alice Johnson");
    if (alice) {
        alice->setAddress("999 Elm Blvd, New Springfield");
        alice->printInfo();
    }

    std::cout << "\nTotal users: " << store.count() << std::endl;

    return 0;
}
