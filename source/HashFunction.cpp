//
// Created by shingesa on 30/03/25.
//

#include "../include/HashFunction.h"
#include <vector>
HashFunction::HashFunction(int mod):modulus(mod){
  initializeUkrainianAlphabet();
}

void HashFunction::initializeUkrainianAlphabet() {
  std::vector<char> ukrAlphabet = {
    'А', 'Б', 'В', 'Г', 'Ґ', 'Д', 'Е', 'Є', 'Ж', 'З', 'И', 'І', 'Ї', 'Й', 'К', 'Л', 'М',
    'Н', 'О', 'П', 'Р', 'С', 'Т', 'У', 'Ф', 'Х', 'Ц', 'Ч', 'Ш', 'Щ', 'Ь', 'Ю', 'Я'
};

  for (size_t i = 0; i < ukrAlphabet.size(); i++) {
    charMap[ukrAlphabet[i]] = i;
    charMap[std::tolower(ukrAlphabet[i])] = i;
  }

  charMap[' '] = 32;
}

int HashFunction::calculate(const std::string &message) const {
  int hash_value = 0;

  for (char c : message) {
    auto it = charMap.find(c);
    if (it != charMap.end()) {
      hash_value = (hash_value + it->second) % modulus;
    }
  }
  return hash_value;
}

