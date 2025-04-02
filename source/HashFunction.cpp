//
// Created by shingesa on 30/03/25.
//

#include "../include/HashFunction.h"
#include <vector>
HashFunction::HashFunction(int mod):modulus(mod){
  initializeUkrainianAlphabet();
}

void HashFunction::initializeUkrainianAlphabet() {
  std::vector<wchar_t> ukrAlphabet = {
    L'А', L'Б', L'В', L'Г', L'Ґ', L'Д', L'Е', L'Є', L'Ж', L'З', L'И', L'І', L'Ї', L'Й', L'К',
    L'Л', L'М', L'Н', L'О', L'П', L'Р', L'С', L'Т', L'У', L'Ф', L'Х', L'Ц', L'Ч', L'Ш', L'Щ',
    L'Ь', L'Ю', L'Я'
};

  for (size_t i = 0; i < ukrAlphabet.size(); i++) {
    charMap[ukrAlphabet[i]] = i;
    charMap[std::tolower(ukrAlphabet[i])] = i;
  }

  charMap[L' '] = 32;
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

