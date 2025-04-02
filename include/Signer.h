//
// Created by shingesa on 02/04/25.
//

#ifndef SIGNER_H
#define SIGNER_H
#include "DigitalSignature.h"
#include <string>

class Signer {
    private:
    DigitalSignature digitalSignature;
    public:
    Signer(const DigitalSignature& ds);

    void signFile(const std::string& inputFile, const std::string& outputFile);
};
#endif //SIGNER_H
