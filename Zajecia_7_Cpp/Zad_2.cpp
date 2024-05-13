//
// Created by wikto on 13.05.2024.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Open the input file
    ifstream inputFile("..//Zajecia_7_C//input2.txt");
    if (!inputFile) {
        cerr << "Failed to open input file." << endl;
        return 1;
    }

    string row;
    long long int sum=0;
    while (getline(inputFile, row)) {

        vector<int> list_n;
        vector<int> list_z;
        vector<int> list_c;

        // Process the text
        for (size_t i = 5; i < row.size(); ++i) {
            if (row[i] == 'b' || row[i] == 'g' || row[i] == 'r') {
                // Check if two iterations earlier was a digit
                if (isdigit(row[i - 2])) {
                    int num = int(row[i - 2] - 48); // Convert char to int
                    if (row[i] == 'b')
                        list_n.push_back(num);
                    else if (row[i] == 'g')
                        list_z.push_back(num);
                    else if (row[i] == 'r')
                        list_c.push_back(num);
                }
            }
        }


        int max_valueZ = 0;
        int max_valueN = 0;
        int max_valueC = 0;
        // Find the iterator pointing to the maximum element in the list
        auto max_iterN = std::max_element(list_n.begin(), list_n.end());

        // Check if max_iter is valid before dereferencing
        if (max_iterN != list_n.end()) {
            max_valueN = *max_iterN; // Convert iterator to int

        } else {
            cout << "The list 'c' is empty." << endl;
        }



        // Find the iterator pointing to the maximum element in the list
        auto max_iterZ = std::max_element(list_z.begin(), list_z.end());

        // Check if max_iter is valid before dereferencing
        if (max_iterZ != list_z.end()) {
            max_valueZ = *max_iterZ; // Convert iterator to int

        } else {
            cout << "The list 'c' is empty." << endl;
        }

        // Find the iterator pointing to the maximum element in the list
        auto max_iterC = std::max_element(list_c.begin(), list_c.end());

        // Check if max_iter is valid before dereferencing
        if (max_iterC != list_c.end()) {
            max_valueC = *max_iterC; // Convert iterator to int

        } else {
            cout << "The list 'c' is empty." << endl;
        }

        sum += max_valueC * max_valueN * max_valueZ;


        // Close the input file
    }
    inputFile.close();
    cout << "The sum of the maximum values in the lists is (Suma mocy zestawow:D): " << sum << endl;

    return 0;
}
