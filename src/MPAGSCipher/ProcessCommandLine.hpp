#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include <iostream>
#include <string>
#include <vector>

//! Process the command line arguments
bool ProcessCommandLine(const std::vector<std::string>& args,
                        bool& helpRequested,
                        bool& versionRequested,
                        bool& encrypt,
                        size_t& key,
                        std::string& inputFileName,
                        std::string& outputFileName);

#endif //MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

