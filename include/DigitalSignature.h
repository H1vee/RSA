//
// Created by shingesa on 31/03/25.
//

#ifndef DIGITALSIGNATURE_H
#define DIGITALSIGNATURE_H
#include "RSA.h"
#include "HashFunction.h"
#include <string>

class DigitalSignature {
    private:
    RSA rsa;
    HashFunction hash;


    public:
    DigitalSignature(const RSA& rsa_system, const HashFunction& hash_function);

    int sign(const std::string& message) const;

    bool verify(const std::string& message, int signature) const;
};
#endif //DIGITALSIGNATURE_H
