using System;
using System.Collections.Generic;
using System.Linq;

class generic_sort {

    public static void Main(string[] args) {
        List<double> numbers = new List<double>(new double[] {645.41, 37.59, 76.41, 5.31, -34.23, 1.11, 1.10, 23.46, 635.47, -876.32, 467.83, 62.25});
        List<Person> people = new List<Person>(
            new Person[] {
                new Person("Hal", 20), new Person("Susann", 31), new Person("Dwight", 19), new Person("Kassandra", 21), new Person("Lawrence", 25),
                new Person("Cindy", 22), new Person("Cory", 27), new Person("Mac", 19), new Person("Romana", 27), new Person("Doretha", 32),
                new Person("Danna", 20), new Person("Zara", 23), new Person("Rosalyn", 26), new Person("Risa", 24), new Person("Benny", 28),
                new Person("Juan", 33), new Person("Natalie", 25)
            }
        );

        Console.Write("Numbers:\n\t");
        for (int i = 0; i < numbers.Count; i++) {
            Console.Write(numbers[i] + ", ");
        }
        Console.Write("\n");

        Console.Write("People:\n\t");
        for (int i = 0; i < people.Count; i++) {
            Console.Write(people[i] + ", ");
        }
        Console.Write("\n");

        numbers.Sort();
        Console.Write("Numbers Sorted:\n\t");
        for (int i = 0; i < numbers.Count; i++) {
            Console.Write(numbers[i] + ", ");
        }
        Console.Write("\n");

        people.Sort(delegate(Person x, Person y) { return x.CompareByName(y); });
        Console.Write("People Sorted By Name:\n\t");
        for (int i = 0; i < people.Count; i++) {
            Console.Write(people[i] + ", ");
        }
        Console.Write("\n");

        people.Sort(delegate(Person x, Person y) { return x.CompareByAge(y); });
        Console.Write("People Sorted By Age (Descending):\n\t");
        for (int i = 0; i < people.Count; i++) {
            Console.Write(people[i] + ", ");
        }
        Console.Write("\n");

    }

    class Person {
        public string name;
        public double age;
        
        public Person(string name, double age) {
            this.name = name;
            this.age = age;
        }

        public override string ToString()
        {
            return name + " (" + age.ToString() + ")";
        }

        public int CompareByName(Person p) {
            return this.name.CompareTo(p.name);
        }

        public int CompareByAge(Person p) {
            if (this.age == p.age) return this.CompareByName(p);
            return -1*this.age.CompareTo(p.age);
        }

    }

}