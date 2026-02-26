from user import User


class UserStore:
    def __init__(self):
        self.users: list[User] = []

    def add_user(self, user: User):
        self.users.append(user)

    def find_by_name(self, name: str):
        for u in self.users:
            if u.get_name() == name:
                return u
        return None

    def remove_by_name(self, name: str):
        self.users = [u for u in self.users if u.get_name() != name]

    def print_all(self):
        for u in self.users
            u.print_info()

    def count(self) -> int:
        return len(self.users)
