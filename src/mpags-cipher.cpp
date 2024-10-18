#include <cctype>
#include <iostream>
#include <string>
#include <vector>

std::string transformChar(const char in_char){

    /*Takes an input character. If it is a letter, capitalises it. If it is a number returns the number as a capitalised word.
    Any other character returns an empty sting "".
        
    const char in_char: The input character to be changed
    
    return: Either:
        - A capital letter as a string
        - A number in capitalised word form
        - An empty sting for any other character
    */

    if (std::isalpha(in_char)) {
            char upper = std::toupper(in_char);
            std::string char_string {upper};
            return char_string;
        }

        // Transliterate digits to English words
        switch (in_char) {
            case '0':
                return "ZERO";
            case '1':
                return "ONE";
            case '2':
                return "TWO";
            case '3':
                return "THREE";
            case '4':
                return "FOUR";
            case '5':
                return "FIVE";
            case '6':
                return "SIX";
            case '7':
                return "SEVEN";
            case '8':
                return "EIGHT";
            case '9':
                return "NINE";
        }

        // If the character isn't alphabetic or numeric, DONT add it
    return "";
    }

bool ProcessCommandLine(const std::vector<std::string>& args,
                        bool& helpRequested,
                        bool& versionRequested,
                        std::string& inputFileName,
                        std::string& outputFileName){

    /* Process command line arguments

    const std::vector<std::string>& args - A vector of strings of the command line inputs 
    bool& helpRequested - Reference argument specifying whether the --help command has been input
    bool& versionRequested - Reference argument specifying whether the --version command has been input
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

    // Handle help, if requested
    /*if (helpRequested) {
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
        // with 0 used to indicate success
        return 0;
    }

    // Handle version, if requested
    // Like help, requires no further action,
    // so return from main with zero to indicate success
    if (versionRequested) {
        std::cout << "0.1.0" << std::endl;
        return 0;
    }*/
    return 0;
    }

int main(int argc, char* argv[])
{
    // Convert the command-line arguments into a more easily usable form
    const std::vector<std::string> cmdLineArgs{argv, argv + argc};
    const std::size_t nCmdLineArgs{cmdLineArgs.size()};

    // Options that might be set by the command-line arguments
    bool helpRequested{false};
    bool versionRequested{false};
    std::string inputFile{""};
    std::string outputFile{""};

    const bool CommandLineArgs {ProcessCommandLine(cmdLineArgs, helpRequested, versionRequested, inputFile, outputFile)};

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
    }

    // loop over each character from user input
    while (std::cin >> inputChar) {
        // Uppercase alphabetic characters
        inputText += std::string {transformChar(inputChar)};
    }

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