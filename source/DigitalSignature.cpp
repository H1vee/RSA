//
// Created by shingesa on 31/03/25.
//
#include "../include/DigitalSignature.h"
DigitalSignature::DigitalSignature(const RSA& rsa_system, const HashFunction& hash_function)
    :rsa(rsa_system), hash(hash_function){}

int DigitalSignature::sign(const std::string& &message) const {
    int hash_value = hash.calculate(message);
    return rsa.encrypt(hash_value);
}

bool DigitalSignature::verify(const std::string& &message, int signature) const {
    int hash_value = hash.calculate(message);
    int decrypted_signature = rsa.decrypt(signature);

    return hash_value == decrypted_signature;
}
