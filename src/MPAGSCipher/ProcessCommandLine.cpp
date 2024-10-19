#include <cctype>
#include <iostream>
#include <string>
#include <vector>

//Process the command line arguments
bool ProcessCommandLine(const std::vector<std::string>& args,
                        bool& helpRequested,
                        bool& versionRequested,
                        bool& encrypt,
                        size_t& key,
                        std::string& inputFileName,
                        std::string& outputFileName){

    /* Process command line arguments

    const std::vector<std::string>& args - A vector of strings of the command line inputs 
    bool& helpRequested - Reference argument specifying whether the --help command has been input
    bool& versionRequested - Reference argument specifying whether the --version command has been input
    bool& encrypt - Specifies whether to use the Caesar Cipher to encrypt or decrypt the message
    size_t& key - The key for the Caesar Cipher
    std::string& inputFileName - Reference argument containing the name of the input file name
    std::string& outputFileName - Reference argument containing the name of the output file name

    Returns True (1) for an error and False (0) if everything occurs as expected. If certain inputs are specified the 
    function also prints the relevant message.
    */

    const std::size_t nCmdLineArgs{args.size()};

    for (std::size_t i{1}; i < nCmdLineArgs; ++i) {
        if (args[i] == "-h" || args[i] == "--help") {
            helpRequested = true;
        } else if (args[i] == "--version") {
            versionRequested = true;
        } else if (args[i] == "--encrypt") {
            continue; //default is already set to encrypt so can just continue
        } else if (args[i] == "--decrypt") {
            encrypt = false;
        } else if (args[i] == "--key") {
            // Next element is value of key unless "-key" is the last argument
            if (i == nCmdLineArgs - 1) {
                std::cerr << "[error] -key requires a value argument"
                          << std::endl;
                // exit main with non-zero return to indicate failure
                return 1;
            } else {
                // Got key value, so assign value and advance past it
                key = stol(args[i + 1]);
                ++i;
            }
        } else if (args[i] == "-i") {
            // Handle input file option
            // Next element is filename unless "-i" is the last argument
            if (i == nCmdLineArgs - 1) {
                std::cerr << "[error] -i requires a filename argument"
                          << std::endl;
                // exit main with non-zero return to indicate failure
                return 1;
            } else {
                // Got filename, so assign value and advance past it
                inputFileName = args[i + 1];
                ++i;
            }
        } else if (args[i] == "-o") {
            // Handle output file option
            // Next element is filename unless "-o" is the last argument
            if (i == nCmdLineArgs - 1) {
                std::cerr << "[error] -o requires a filename argument"
                          << std::endl;
                // exit main with non-zero return to indicate failure
                return 1;
            } else {
                // Got filename, so assign value and advance past it
                outputFileName = args[i + 1];
                ++i;
            }
        } else {
            // Have an unknown flag to output error message and return non-zero
            // exit status to indicate failure
            std::cerr << "[error] unknown argument '" << args[i]
                      << "'\n";
            return 1;
        }
    }
    return 0;
    }