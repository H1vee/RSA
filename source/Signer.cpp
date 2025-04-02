#include "../include/Signer.h"
#include "../include/FileHandler.h"
#include <iostream>
#include <stdexcept>
//
// Created by shingesa on 02/04/25.
//
Signer::Signer(const DigitalSignature &ds):digitalSignature(ds) {
}

void Signer::signFile(const std::string &inputFile, const std::string &outputFile) {
    try {
        std::string message = FileHandler::readMessageFromFile(inputFile);
        int signature = digitalSignature.sign(message);

        FileHandler::writeSignedMessage(outputFile,message,signature);
        std::cout<<"Message signed Successfully"<<std::endl;
        std::cout<<"Signature value: "<<signature<<std::endl;
    }catch(std::exception &e) {
        std::cerr<<"Error signing the message: "<<e.what()<<std::endl;
    }
}
