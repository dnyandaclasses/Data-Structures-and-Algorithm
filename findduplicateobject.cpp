#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

int main() {
    // Input data
    std::vector<std::map<std::string, std::string>> data = {
        {{"id", "1"}, {"name", "Deepika"}},
        {{"id", "2"}, {"last_name", "Walanjkar"}},
        {{"id", "3"}, {"name", "Deepika"}},
        {{"id", "4"}, {"last_name", "Walanjkar"}},
        {{"id", "5"}, {"name", "Vinod"}},
        {{"id", "6"}, {"name", "Vinod"}},
        {{"id", "7"}, {"color", "green"}},
        {{"id", "8"}, {"name", "Sachin"}},
        {{"id", "9"}, {"name", "kangude"}},
        {{"id", "10"}, {"color", "red"}},
        {{"id", "11"}, {"color", "red"}}
    };

    // Map to count occurrences of key-value pairs
    std::map<std::string, std::map<std::string, int>> keyValueCounts;

    // First pass: Count the occurrences of each key-value pair
    for (const auto& obj : data) {
        for (const auto& [key, value] : obj) {
            keyValueCounts[key][value]++;
        }
    }

    // Map to store the result: only duplicate key-value pairs
    std::map<std::string, std::vector<std::map<std::string, std::string>>> groupedDuplicates;

    // Second pass: Add only duplicate objects to the result
    for (const auto& obj : data) {
        for (const auto& [key, value] : obj) {
            if (keyValueCounts[key][value] > 1) {
                groupedDuplicates[key].push_back(obj);
                break; // Add the object once for each key
            }
        }
    }

    // Output the grouped data
    std::cout << "[\n{\n";
    for (const auto& [key, objects] : groupedDuplicates) {
        std::cout << "  \"" << key << "\": [\n";
        for (const auto& obj : objects) {
            std::cout << "    { ";
            for (const auto& [k, v] : obj) {
                std::cout << "\"" << k << "\": \"" << v << "\", ";
            }
            std::cout << "},\n";
        }
        std::cout << "  ],\n";
    }
    std::cout << "}\n]\n";

    return 0;
}
