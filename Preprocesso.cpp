#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void task1() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output_task1.txt");
    string word;

    if (!inputFile || !outputFile) {
        cerr << "Error opening file!" << endl;
        return;
    }

    while (inputFile >> word) {
        if (word.length() >= 7) {
            outputFile << word << " ";
        }
    }

    inputFile.close();
    outputFile.close();
}

void task2() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output_task2.txt");
    string line;

    if (!inputFile || !outputFile) {
        cerr << "Error opening file!" << endl;
        return;
    }

    while (getline(inputFile, line)) {
        outputFile << line << endl;
    }

    inputFile.close();
    outputFile.close();
}

void task3() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output_task3.txt");
    vector<string> lines;
    string line;

    if (!inputFile || !outputFile) {
        cerr << "Error opening file!" << endl;
        return;
    }

    while (getline(inputFile, line)) {
        lines.push_back(line);
    }

    for (auto it = lines.rbegin(); it != lines.rend(); ++it) {
        outputFile << *it << endl;
    }

    inputFile.close();
    outputFile.close();
}

void task4() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output_task4.txt");
    vector<string> lines;
    string line;
    bool foundNonSpaceLine = false;

    if (!inputFile || !outputFile) {
        cerr << "Error opening file!" << endl;
        return;
    }

    while (getline(inputFile, line)) {
        lines.push_back(line);
        if (line.find(' ') == string::npos) {
            foundNonSpaceLine = true;
        }
    }

    if (foundNonSpaceLine) {
        for (size_t i = lines.size(); i > 0; --i) {
            if (lines[i - 1].find(' ') == string::npos) {
                lines.insert(lines.begin() + i, "------------");
                break;
            }
        }
    }
    else {
        lines.push_back("------------");
    }

    for (const auto& l : lines) {
        outputFile << l << endl;
    }

    inputFile.close();
    outputFile.close();
}

int main() {
    task1(); // Виконується тільки завдання 1
    // task2(); // Розкоментувати для виконання завдання 2
    // task3(); // Розкоментувати для виконання завдання 3
    // task4(); // Розкоментувати для виконання завдання 4

    return 0;
}
