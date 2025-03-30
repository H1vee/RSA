//
// Created by shingesa on 30/03/25.
//

#ifndef HASHFUNCTION_H
#define HASHFUNCTION_H

#include <string>
#include <unordered_map>

class HashFunction {
private:
  std::unordered_map<char,int> charMap;
  int modulus;

  void initializeUkrainianAlphabet();

  public:

  HashFunction(int mod = 33);

  int calculate(const std::string& message) const;
};

#endif //HASHFUNCTION_H
