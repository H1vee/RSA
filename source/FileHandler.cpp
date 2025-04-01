//
// Created by shingesa on 01/04/25.
//
#include "../include/FileHandler.h"
#include <fstream>
#include <stdexcept>
#include <algorithm>

std::string FileHandler::readMessageFromFile(const std::string &filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file " + filePath);
    }
    std::string message;
    std::string line;
    while (std::getline(file, line)) {
        if (!message.empty()) {
            message += "\n";
        }
        message += line;
    }
    file.close();
    return message;
}

void FileHandler::writeSignedMessage(const std::string &filePath, const std::string &message, int signature) {
    std::ofstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file " + filePath);
    }
    file<<message<<"\n"<<signature;
    file.close();
}

std::pair<std::string, int> FileHandler::readSignedMessageFromFile(const std::string &filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file " + filePath);
    }
    std::string message;
    std::string line;

    while (std::getline(file, line)) {
        if (line.empty() && std::all_of(line.begin(), line.end(),[](char c) {
            return std::isdigit(c)||c == '-';
        })) {
            break;
        }
        if (!message.empty()) {
            message += "\n";
        }
        message += line;
    }
    int signature = std::stoi(line);
    file.close();

    return {message, signature};
}
