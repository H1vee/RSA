#include <iostream>
#include<stdexcept>
#include "../include/Signer.h"
#include "../include/DigitalSignature.h"
#include "../include/Verifier.h"
#include "../include/RSA.h"
#include "../include/HashFunction.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main(int argc, char *argv[]) {
    if (argc<3) {
        std::cout << "Usage: " << std::endl;
        std::cout << "  For signing: " << argv[0] << " -s input_file output_file" << std::endl;
        std::cout << "  For verification: " << argv[0] << " -v file_with_signature" << std::endl;
        return 1;
    }
    std::string mode = argv[1];

    try {
        RSA rsa(3,11,7);

        HashFunction hash(33);

        DigitalSignature ds(rsa,hash);

        if (mode == "-s" && argc>=4) {
            Signer signer(ds);
            signer.signFile(argv[2],argv[3]);
        }else if (mode == "-v" && argc>=3) {
            Verifier verifier(ds);
            verifier.verifyFile(argv[2]);
        }else {
            std::cout << "Invalid arguments." << std::endl;
            std::cout << "Usage: " << std::endl;
            std::cout << "  For signing: " << argv[0] << " -s input_file output_file" << std::endl;
            std::cout << "  For verification: " << argv[0] << " -v file_with_signature" << std::endl;
            return 1;
        }
    }catch(const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.