import functools


def main():
    print(Person("Natalie", 25))
    floatList = [645.41, 37.59, 76.41, 5.31, -34.23, 1.11, 1.10, 23.46, 635.47, -876.32, 467.83, 62.25]
    personList = [
        Person("Hal", 20), Person("Susann", 31), Person("Dwight", 19), Person("Kassandra", 21), Person("Lawrence", 25),
        Person("Cindy", 22), Person("Cory", 27), Person("Mac", 19), Person("Romana", 27), Person("Doretha", 32),
        Person("Danna", 20), Person("Zara", 23), Person("Rosalyn", 26), Person("Risa", 24), Person("Benny", 28),
        Person("Juan", 33), Person("Natalie", 25)
        ]
    
    print("Numbers:\n\t" + str(floatList))
    print("People:\n\t" + str(personList))

    floatList.sort()
    print("Numbers Sorted:\n\t" + str(floatList))
    personList.sort(key=Person.name)
    print("Sorted by Name:\n\t" + str(personList))
    personList.sort(key = functools.cmp_to_key(compareByAge))
    print("Sorted by Age (Descending):\n\t" + str(personList))


class Person:
    def __init__(self, name: str, age: int):
        self.name = name
        self.age = age
    
    def name(self):
        return self.name

    def age(self):
        return self.age

    def __str__(self):
        return "{name} ({age})".format(name=self.name, age=self.age)

    def __repr__(self):
        return self.__str__()


def compareByAge(self: Person, other: Person):
    if (self.age == other.age): return cmp(self.name, other.name)
    return cmp(other.age, self.age)


def cmp(self, other):
    return (self > other) - (self < other)


if __name__ == "__main__":
    main()
