#include <iostream>
#include <stdexcept>
#include "../include/Signer.h"
#include "../include/DigitalSignature.h"
#include "../include/Verifier.h"
#include "../include/RSA.h"
#include "../include/HashFunction.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.

int main() {
    std::string mode;

    std::cout << "Choose mode (-s for signing, -v for verification): ";
    std::cin >> mode;

    try {
        RSA rsa(3, 11, 7);
        HashFunction hash(33);
        DigitalSignature ds(rsa, hash);

        if (mode == "-s") {
            std::string input_file, output_file;
            std::cout << "Enter input file name (file to sign): ";
            std::cin >> input_file;
            std::cout << "Enter output file name (file to save signature): ";
            std::cin >> output_file;

            Signer signer(ds);
            signer.signFile(input_file, output_file);
        } else if (mode == "-v") {
            std::string signature_file;
            std::cout << "Enter file with signature: ";
            std::cin >> signature_file;

            Verifier verifier(ds);
            verifier.verifyFile(signature_file);
        } else {
            std::cout << "Invalid mode. Use -s for signing or -v for verification." << std::endl;
            return 1;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }


    return 0;
}
