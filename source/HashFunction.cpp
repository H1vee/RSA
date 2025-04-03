#include "../include/HashFunction.h"
#include <vector>
#include <map>
#include <cctype>  // Для tolower
#include <string>

HashFunction::HashFunction(int mod): modulus(mod) {
  initializeEnglishAlphabet();
}

void HashFunction::initializeEnglishAlphabet() {
  std::vector<char> englishAlphabet = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
    'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd',
    'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
    't', 'u', 'v', 'w', 'x', 'y', 'z', ' '
};

  for (size_t i = 0; i < englishAlphabet.size(); i++) {
    charMap[englishAlphabet[i]] = i;
  }
}

int HashFunction::calculate(const std::string &message) const {
  int hash_value = 0;

  for (char c : message) {
    auto it = charMap.find(tolower(c)); // Перетворюємо в нижній регістр для однакової обробки
    if (it != charMap.end()) {
      hash_value = (hash_value + it->second) % modulus;
    }
  }
  return hash_value;
}
