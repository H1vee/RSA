//
// Created by shingesa on 31/03/25.
//
#include "../include/DigitalSignature.h"

#include <iostream>

DigitalSignature::DigitalSignature(const RSA& rsa_system, const HashFunction& hash_function)
    :rsa(rsa_system), hash(hash_function){}

int DigitalSignature::sign(const std::string& message) const {
    int hash_value = hash.calculate(message);
    std::cout << "Hash value: " << hash_value << std::endl;
    int encrypted = rsa.encrypt(hash_value);
    std::cout << "Encrypted hash: " << encrypted << std::endl;
    return rsa.encrypt(hash_value);
}

bool DigitalSignature::verify(const std::string& message, int signature) const {
    int hash_value = hash.calculate(message);
    std::cout << "Calculated hash value: " << hash_value << std::endl;
    int decrypted_signature = rsa.decrypt(signature);
    std::cout << "Decrypted signature: " << decrypted_signature << std::endl;
    return hash_value == decrypted_signature;
}
