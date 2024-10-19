#ifndef MPAGSCIPHER_RUNCAESARCIPHER_HPP
#define MPAGSCIPHER_RUNCAESARCIPHER_HPP

#include <string>

//! Exectute Caesar Cipher on a string string
std::string runCaesarCipher(const std::string& inputText, const size_t key, const bool encrypt);

#endif //MPAGSCIPHER_RUNCAESARCIPHER_HPP