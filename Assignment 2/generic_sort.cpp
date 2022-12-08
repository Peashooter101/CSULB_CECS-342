#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

bool age(std::pair<std::string, int> &a, std::pair<std::string, int> &b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return !(a.second < b.second);
}
bool name(std::pair<std::string, int> &a, std::pair<std::string, int> &b) { return a.first < b.first; }

int main() {
    std::vector<double> numbers = {645.41, 37.59, 76.41, 5.31, -34.23, 1.11, 1.10, 23.46, 635.47, -876.32, 467.83, 62.25};
    std::vector<std::pair<std::string, int>> people = {
        {"Hal", 20}, {"Susann", 31}, {"Dwight", 19}, {"Kassandra", 21}, {"Lawrence", 25},
        {"Cindy", 22}, {"Cory", 27}, {"Mac", 19}, {"Romana", 27}, {"Doretha", 32},
        {"Danna", 20}, {"Zara", 23}, {"Rosalyn", 26}, {"Risa", 24}, {"Benny", 28},
        {"Juan", 33}, {"Natalie", 25}
    };

    std::cout << "Numbers:\n\t";
    for (auto number : numbers) {
        std::cout << number << ", ";
    }
    std::cout << "\n";

    std::cout << "People:\n\t";
    for (auto person : people) {
        std::cout << person.first << " (" << person.second << "), ";
    }
    std::cout << "\n";

    std::sort(numbers.begin(), numbers.end());
    std::cout << "Numbers Sorted:\n\t";
    for (auto number : numbers) {
        std::cout << number << ", ";
    }
    std::cout << "\n";

    std::sort(people.begin(), people.end(), name);
    std::cout << "People Sorted by Name:\n\t";
    for (auto person : people) {
        std::cout << person.first << " (" << person.second << "), ";
    }
    std::cout << "\n";

    std::sort(people.begin(), people.end(), age);
    std::cout << "People Sorted by Age (Descending):\n\t";
    for (auto person : people) {
        std::cout << person.first << " (" << person.second << "), ";
    }
    std::cout << "\n";
}