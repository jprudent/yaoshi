#ifndef ALPHABET_NAVIGATOR_H
#define ALPHABET_NAVIGATOR_H

#include <stdlib.h>

class Keys {
  public:
    Keys(const char * symbols, size_t len);
    char letterAt(size_t index);
    size_t maxIndex();
  //private:
    const char* symbols;
    int len;
};

class AlphabetNavigator {
  public:

    AlphabetNavigator(Keys ** keyboards, size_t nbKeys);
    ~AlphabetNavigator();
    Keys* switchKeyboard();
    char left();
    char right();
    char currentLetter();
    void reset();

  //private:

    size_t position;
    Keys ** keys;
    size_t currentKeysIndex;
    size_t nbKeys;
    Keys * currentKeys();

};

#endif
