//
// Created by wikto on 12.05.2024.
//
#include <iostream>
#include <fstream>
#include <regex>
#include <map>
#include <string>

using namespace std;

// Function to convert words to their numerical equivalent
string wordToNum(const string& word) {
    static map<string, string> wordToNumMap = {
            {"one", "1"}, {"two", "2"}, {"three", "3"},
            {"four", "4"}, {"five", "5"}, {"six", "6"},
            {"seven", "7"}, {"eight", "8"}, {"nine", "9"}
    };

    auto it = wordToNumMap.find(word);
    if (it != wordToNumMap.end()) {
        return it->second;
    }
    return ""; // Return empty string if word not found
}

int main() {
    // Open input file
    ifstream inputFile("..\\Zajecia_7_C\\input.txt");
    if (!inputFile) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    // Process each row in the file
    string row;
    int sum=0;
    while (getline(inputFile, row)) {
        // Regular expression to find words representing numbers and digits
        regex wordPattern("(one|two|three|four|five|six|seven|eight|nine)|([0-9])");
        smatch match;

        string result;


        // Find and replace words and digits with their numerical equivalents
        auto textIterator = row.cbegin();
        while (regex_search(textIterator, row.cend(), match, wordPattern)) {
            if (match[1].matched) {
                result += wordToNum(match[1].str()); // Append numerical equivalent of word
            } else {
                result += match[2].str(); // Append the digit itself
            }
            textIterator = match.suffix().first; // Move iterator past the match
        }

        // Output result
        result = result.substr(0,1)+result.substr(result.length()-1,1);
        sum += stoi(result);

    }

    // Close input file
    inputFile.close();

    cout<<"sum: "<<sum<<endl;

    return 0;
}
