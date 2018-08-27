#include "AlphabetNavigator.h"
#include <Arduino.h>

void checkArgument(bool condition) {
  if(!condition) {
     // should throw an exception here
  }
}

Keys::Keys(const char * symbols, size_t len) {
  checkArgument(len > 0);
  this->symbols = symbols;
  this->len = len;
}

char Keys::letterAt(size_t index) {
  return this->symbols[index];
}

size_t Keys::maxIndex() {
  return this->len - 1;
}


Keys ** deepcopy(Keys ** copy, size_t nbKeys) {
  Keys** ret = new Keys*[nbKeys];
  for(size_t i=0; i<nbKeys; i++) {
    ret[i] = new Keys(*copy[i]);
  }
  return ret;
}

AlphabetNavigator::AlphabetNavigator(Keys** keyboards, size_t nbKeys) {
  checkArgument(nbKeys > 0);
  this->keys = deepcopy(keyboards, nbKeys);
  this->currentKeysIndex = 0;
  this->nbKeys = nbKeys;
  this->reset();
}

AlphabetNavigator::~AlphabetNavigator() {
  delete keys;
}

Keys* AlphabetNavigator::switchKeyboard() {
  this->currentKeysIndex = (this->currentKeysIndex + 1) % this->nbKeys;
  return this->keys[this->currentKeysIndex];
}

char AlphabetNavigator::left() {
  this->position = max(0, this->position - 1);
  return currentLetter();
}

char AlphabetNavigator::right() {
  this->position = min(this->nbKeys - 1, this->position + 1);
  return currentLetter();
}

char AlphabetNavigator::currentLetter() {
  return currentKeys()->letterAt(this->position);
}

void AlphabetNavigator::reset() {
  this->position = this->nbKeys / 2;
}

Keys * AlphabetNavigator::currentKeys() {
  return this->keys[this->currentKeysIndex];
}