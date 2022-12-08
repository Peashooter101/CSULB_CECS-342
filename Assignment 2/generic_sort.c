#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char* name;
    int age;
};

struct Person* getPerson(char* name_, int age_) {
    struct Person* person = malloc(sizeof(struct Person));
    person->age = age_;
    person->name = name_;
    return person;
}

int compareDoubles(const void* a_, const void* b_) {
    double a = *(double*) a_;
    double b = *(double*) b_;
    if (a > b) return 1;
    if (a < b) return -1;
    else return 0;
}

int compareNames(const void* a_, const void* b_) {
    struct Person** a = (struct Person**) a_;
    struct Person** b = (struct Person**) b_;
    return strcmp((*a)->name, (*b)->name);
}

int compareAges(const void* a_, const void* b_) {
    struct Person** a = (struct Person**) a_;
    struct Person** b = (struct Person**) b_;
    if ((*a)->age == (*b)->age) {
        return compareNames(a_, b_);
    }
    return (*b)->age - (*a)->age;
}

int main() {
    double numbers[] = {645.41, 37.59, 76.41, 5.31, -34.23, 1.11, 1.10, 23.46, 635.47, -876.32, 467.83, 62.25};
    struct Person* people[] = {
        getPerson("Hal", 20), getPerson("Susann", 31), getPerson("Dwight", 19), getPerson("Kassandra", 21), getPerson("Lawrence", 25),
        getPerson("Cindy", 22), getPerson("Cory", 27), getPerson("Mac", 19), getPerson("Romana", 27), getPerson("Doretha", 32),
        getPerson("Danna", 20), getPerson("Zara", 23), getPerson("Rosalyn", 26), getPerson("Risa", 24), getPerson("Benny", 28),
        getPerson("Juan", 33), getPerson("Natalie", 25)
    };

    int max_numbers = sizeof(numbers)/sizeof(numbers[0]);
    int max_people = sizeof(people)/sizeof(people[0]);
    
    printf("Numbers:\n\t");
    for (int i = 0; i < max_numbers; i++) {
        printf("%.2f, ", numbers[i]);
    }
    printf("\n");
    
    printf("People:\n\t");
    for (int i = 0; i < max_people; i++) {
        printf("%s (%d), ", people[i]->name, people[i]->age);
    }
    printf("\n");

    qsort(numbers, max_numbers, sizeof(numbers[0]), compareDoubles);
    printf("Numbers Sorted:\n\t");
    for (int i = 0; i < max_numbers; i++) {
        printf("%.2f, ", numbers[i]);
    }
    printf("\n");

    qsort(people, max_people, sizeof(struct Person*), compareNames);
    printf("People Sorted By Name:\n\t");
    for (int i = 0; i < max_people; i++) {
        printf("%s (%d), ", people[i]->name, people[i]->age);
    }
    printf("\n");

    qsort(people, max_people, sizeof(struct Person*), compareAges);
    printf("People Sorted By Age (Descending):\n\t");
    for (int i = 0; i < max_people; i++) {
        printf("%s (%d), ", people[i]->name, people[i]->age);
    }
    printf("\n");

    for (int i = 0; i < max_people; i++) {
        free(people[i]);
    }

    return 0;
}