from user import User
from user_store import UserStore


def main():
    store = UserStore()

    # Add some users
    store.add_user(User("Alice Johnson", 30, "123 Maple St, Springfield"))
    store.add_user(User("Bob Smith", 25, "456 Oak Ave, Shelbyville"))
    store.add_user(User("Charlie Lee", 35, "789 Pine Rd, Capital City"))

    print("All users:")
    store.print_all()

    # Look up a user by name
    print("\nSearching for 'Bob Smith'...")
    found = store.find_by_name("Bob Smith")
    if found:
        found.print_info()
    else:
        print("User not found.")

    # Update a user's address
    print("\nUpdating Alice's address...")
    alice = store.find_by_name("Alice Johnson")
    if alice:
        alice.set_address("999 Elm Blvd, New Springfield")
        alice.print_info()

    print(f"\nTotal users: {store.count()}")


if __name__ == "__main__":
    main()
