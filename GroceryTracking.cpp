#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <limits>

using namespace std;

// Function to search for an item's frequency
void searchFrequency(const map<string, int>& itemFrequencyMap) {
    string item;
    cout << "Enter the item to search for: ";
    cin >> item;

    auto it = itemFrequencyMap.find(item);
    if (it != itemFrequencyMap.end()) {
        cout << "The item " << item << " has been purchased " << it->second << " times." << endl;
    } else {
        cout << "The item " << item << " was not found." << endl;
    }
}

// Function to display all items and their frequencies
void displayAllItems(const map<string, int>& itemFrequencyMap) {
    cout << "All items and their frequencies:" << endl;
    for (const auto& pair : itemFrequencyMap) {
        cout << pair.first << " " << pair.second << endl;
    }
}

// Function to display histogram of items
void displayHistogram(const map<string, int>& itemFrequencyMap) {
    cout << "Displaying histogram of items:" << endl;
    for (const auto& pair : itemFrequencyMap) {
        cout << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            cout << "*";
        }
        cout << endl;
    }
}

// Function to write the frequency data to a file
void writeFrequencyToFile(const map<string, int>& itemFrequencyMap) {
    ofstream outputFile("frequency.dat");
    if (outputFile) {
        for (const auto& pair : itemFrequencyMap) {
            outputFile << pair.first << " " << pair.second << endl;
        }
        cout << "Frequency data has been written to frequency.dat." << endl;
    } else {
        cerr << "Error writing to frequency.dat" << endl;
    }
}

int main() {
    map<string, int> itemFrequencyMap;
    ifstream inputFile("CS210_Project_Three_Input_File.txt");

    // Check if the input file opened successfully
    if (!inputFile) {
        cerr << "Error opening input file!" << endl;
        return 1;
    }

    string item;
    cout << "Reading items from file:\n";  // Debugging message
    // Read items from the input file and store their frequencies
    while (getline(inputFile, item)) {
        cout << "Read item: " << item << endl;  // Print each item as it is read
        itemFrequencyMap[item]++;
    }

    // Close input file after reading
    inputFile.close();

    // Write frequency data to frequency.dat
    writeFrequencyToFile(itemFrequencyMap);

    // Menu loop
    int choice;
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Search for an item's frequency" << endl;
        cout << "2. Display all items and their frequencies" << endl;
        cout << "3. Display histogram of items" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                searchFrequency(itemFrequencyMap);
                break;
            case 2:
                displayAllItems(itemFrequencyMap);
                break;
            case 3:
                displayHistogram(itemFrequencyMap);
                break;
            case 4:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}