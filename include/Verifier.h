//
// Created by shingesa on 02/04/25.
//

#ifndef VERIFIER_H
#define VERIFIER_H
#include "DigitalSignature.h"
#include <string>
class Verifier {

  private:
    DigitalSignature digitalSignature;

    public:
      Verifier(const DigitalSignature& ds);

      void verifyFile(const std::string& filePath);
};

#endif //VERIFIER_H
