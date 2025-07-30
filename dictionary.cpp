#include "dictionary.h"
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

Dictionary::Dictionary(const string& filename) {
    loadFromFile(filename);
}

void Dictionary::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open dictionary file: " << filename << endl;
        return;
    }

    string word;
    while (getline(file, word)) {
        // Chuyển thành chữ thường
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        words.insert(word);
    }

    file.close();
}

bool Dictionary::isValidWord(const string& word) const {
    string lower = word;
    transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    return words.find(lower) != words.end();
}
