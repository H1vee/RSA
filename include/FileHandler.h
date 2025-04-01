//
// Created by shingesa on 01/04/25.
//

#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <string>
#include <utility>

class FileHandler {
    public:

    static std::string readMessageFromFile(const std::string& filePath);
    static void writeSignedMessage (const std::string& filePath, const std::string& message, int signature);

    static std::pair<std::string,int>readSignedMessageFromFile(const std::string& filePath);
};
#endif //FILEHANDLER_H
