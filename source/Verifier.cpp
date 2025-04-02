//
// Created by shingesa on 02/04/25.
//
#include "../include/Verifier.h"
#include "../include/FileHandler.h"
#include <iostream>
#include<stdexcept>

Verifier::Verifier(const DigitalSignature &ds):digitalSignature(ds) {
}

void Verifier::verifyFile(const std::string &filePath) {
    try {
        auto [message,signature]= FileHandler::readSignedMessageFromFile(filePath);

        bool isValid = digitalSignature.verify(message,signature);

        std::cout<<"Message: "<<message<<std::endl;
        std::cout<<"Signature: "<<signature<<std::endl;

        if (isValid) {
            std::cout<<"Verification successful!"<<std::endl;
        }else {
            std::cout<<"Verification failed!"<<std::endl;
        }
    }catch (std::exception &e) {
        std::cout<<"Error verifying the signature: "<<e.what()<<std::endl;
    }
}

