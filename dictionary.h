#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <unordered_set>

class Dictionary {
public:
    Dictionary(const std::string& filename);
    bool isValidWord(const std::string& word) const;

private:
    std::unordered_set<std::string> words;
    void loadFromFile(const std::string& filename);
};

#endif
