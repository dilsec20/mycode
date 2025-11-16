#include <iostream>
#include <string>
#include <algorithm> // For std::count_if
#include <cctype>    // For std::tolower

int countVowelsSTL(const std::string& str) {
    
    return std::count_if(str.begin(), str.end(), [](unsigned char c) {
        char lower_c = std::tolower(c);
        return lower_c == 'a' || lower_c == 'e' || lower_c == 'i' || lower_c == 'o' || lower_c == 'u';
    });
}

int main() {
    std::string userInput;


    std::cout << "Enter a string: ";


    std::getline(std::cin, userInput);

    
    int vowels = countVowelsSTL(userInput);

    // Print the result
    std::cout << "The number of vowels is: " << vowels << std::endl;

    return 0;
}
