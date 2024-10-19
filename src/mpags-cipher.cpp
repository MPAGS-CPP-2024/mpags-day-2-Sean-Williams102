#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

//Our project headers
#include "TransformChar.hpp"
#include "ProcessCommandLine.hpp"
#include "runCaesarCipher.hpp"

//! Transliterate char to string
std::string transformChar(const char in);

//Process the command line arguments
bool ProcessCommandLine(const std::vector<std::string>& args,
                        bool& helpRequested,
                        bool& versionRequested,
                        bool& encrypt,
                        size_t& key,
                        std::string& inputFileName,
                        std::string& outputFileName);

// Execute the Caesar Cipher
std::string runCaesarCipher(const std::string& inputText, const size_t key, const bool encrypt);

int main(int argc, char* argv[])
{
    // Convert the command-line arguments into a more easily usable form
    const std::vector<std::string> cmdLineArgs{argv, argv + argc};

    // Options that might be set by the command-line arguments
    bool helpRequested{false};
    bool versionRequested{false};
    bool encrypt{true}; //Default is set to encrypt rather than decrypt
    size_t key = 0; //Defualt set to no encryption
    std::string inputFile{""};
    std::string outputFile{""};

    const bool CommandLineArgs {ProcessCommandLine(cmdLineArgs, helpRequested, versionRequested, encrypt, key, inputFile, outputFile)};

    if (CommandLineArgs == 1) {
        std::cout << "ERROR" << std::endl;
        return 1;
    }

    if (helpRequested) {
        // Line splitting for readability
        std::cout
            << "Usage: mpags-cipher [-h/--help] [--version] [-i <file>] [-o <file>]\n\n"
            << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
            << "Available options:\n\n"
            << "  -h|--help        Print this help message and exit\n\n"
            << "  --version        Print version information\n\n"
            << "  --encrypt        Set the Caesar Cipher to encrypt\n\n"
            << "  --decrypt        Set the Caesar Cipher to decrypt\n\n"
            << "  --key INTEGER    Value of the key to be used for the Caesar Cipher\n\n"
            << "  -i FILE          Read text to be processed from FILE\n"
            << "                   Stdin will be used if not supplied\n\n"
            << "  -o FILE          Write processed text to FILE\n"
            << "                   Stdout will be used if not supplied\n\n"
            << std::endl;
        // Help requires no further action, so return from main
        // with 0 used to indicate success;
    return 0;
    }

    // Handle version, if requested
    // Like help, requires no further action,
    // so return from main with zero to indicate success
    if (versionRequested) {
        std::cout << "0.1.0" << std::endl;
        return 0;
    }

    // Process command line arguments - ignore zeroth element, as we know this
    // to be the program name and don't need to worry about it

    // Initialise variables
    char inputChar{'x'};
    std::string inputText;

    // Read in user input from stdin/file
    // Warn that input file option not yet implemented

    if (!inputFile.empty()) {
        //Open the file and check that you are able to read from it
        std::ifstream inputStream{inputFile};
        // If the input file is not able to be read from, give warning message and return error code (1)
        if (!inputStream.good()) {
            std::cerr << "[error] failed to create istream on file '" << inputFile
                  << "'" << std::endl;
            return 1;
        }
        // If the input file is good, loop over each character from the file
        while (inputStream >> inputChar) {
            // Uppercase alphabetic characters
            inputText += std::string {transformChar(inputChar)};
        }

    }
    //If no input file is given, loop over the user input as before
    else{
        while (std::cin >> inputChar) {
            // Uppercase alphabetic characters
            inputText += std::string {transformChar(inputChar)};
            }
        }

    std::string Caesar_text {runCaesarCipher(inputText, key,  encrypt)};
    

    //Output the capitalised text to an stdout/file
    if (!outputFile.empty()) {
        //Open the file and check that you are able to write to it
        std::ofstream outputStream{outputFile};
        if (!outputStream.good()) {
            std::cerr << "[error] failed to create ostream on file '" << outputFile
                  << "'" << std::endl;
            return 1;
        }
        //If able to write, print the generated text to the file
        outputStream << inputText << std::endl;
    }
    //If no output file, print the text to the screen instead
    else {
        std::cout << inputText << std::endl;
    }

    // No requirement to return from main, but we do so for clarity
    // and for consistency with other functions
    return 0;
}
