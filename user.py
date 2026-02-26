class User:
    def __init__(self, name: str = "", age: int = 0, address: str = ""):
        self.name = name
        self.age = age
        self.address = address

    def get_name(self) -> str:
        return self.name

    def get_age(self) -> int:
        return self.age

    def get_address(self) -> str:
        return self.address

    def set_name(self, name: str):
        self.name = name

    def set_age(self, age: int):
        self.age = age

    def set_address(self, address: str):
        self.address = address

    def print_info(self):
        print("=== User Record ===")
        print(f"Name   : {self.name}")
        print(f"Age    : {self.age}")
        print(f"Address: {self.address}")
        print("===================")

    def serialize(self) -> str:
        return f"{self.name}|{self.age}|{self.address}"
