#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

//Our project headers
#include "TransformChar.hpp"
#include "ProcessCommandLine.hpp"

//! Transliterate char to string
std::string transformChar(const char in);

//Process the command line arguments
bool ProcessCommandLine(const std::vector<std::string>& args,
                        bool& helpRequested,
                        bool& versionRequested,
                        std::string& inputFileName,
                        std::string& outputFileName);


int main(int argc, char* argv[])
{
    // Convert the command-line arguments into a more easily usable form
    const std::vector<std::string> cmdLineArgs{argv, argv + argc};

    // Options that might be set by the command-line arguments
    bool helpRequested{false};
    bool versionRequested{false};
    std::string inputFile{""};
    std::string outputFile{""};

    const bool CommandLineArgs {ProcessCommandLine(cmdLineArgs, helpRequested, versionRequested, inputFile, outputFile)};

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
        std::cerr << "[warning] input from file ('" << inputFile
                  << "') not implemented yet, using stdin\n";
        
        while (std::cin >> inputChar) {
            // Uppercase alphabetic characters
            inputText += std::string {transformChar(inputChar)};
        }

    }
    else {
        std::string name {inputFile};
        std::ifstream in_file {name};
        bool ok_to_read = in_file.good();
        if (ok_to_read){
            while (in_file >> inputChar) {
                // Uppercase alphabetic characters
                inputText += std::string {transformChar(inputChar)};
            }
        }
    }

    

    // loop over each character from user input

    /*if (ok_to_read) {
        while (in_file >> inputChar) {
            // Uppercase alphabetic characters
            inputText += std::string {transformChar(inputChar)};
        }
    }
    else {
        while (std::cin >> inputChar) {
            // Uppercase alphabetic characters
            inputText += std::string {transformChar(inputChar)};
        }
    }*/

    // Print out the transliterated text

    // Warn that output file option not yet implemented
    if (!outputFile.empty()) {
        std::cerr << "[warning] output to file ('" << outputFile
                  << "') not implemented yet, using stdout\n";
    }

    std::cout << inputText << std::endl;

    // No requirement to return from main, but we do so for clarity
    // and for consistency with other functions
    return 0;
}
