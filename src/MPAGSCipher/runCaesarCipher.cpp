#include <iostream>
#include <string>
#include <vector>
#include <algorithm> //to be able to use the std::find function to find the index in the alphabet.

std::string runCaesarCipher(const std::string& inputText, const size_t key, const bool encrypt) {

    /* Takes an input string and either encypts or decrypts it using the Caesar Cipher method

    const std::string& inputText - the input string to be decrypted
    const size_t key - The key for the cipher. This is the number of positions to translate each letter in the alphabet
    const bool encrypt - Optional argument set to true for encryption and false for decryption
    
    Returns an encrypted/decrypted string
    */


    std::vector<char> alphabet{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
                                'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    std::string CaesarText {""}; //Define an empty string that will contain the encrypted/decrypted text

    // When the encrypt optional is set to be true
        for (size_t i = 0; i < inputText.size(); i++){
            char letter = inputText[i];
            auto alphabet_character = std::find (alphabet.begin(), alphabet.end(), letter);
            int alphabet_index = std::distance (alphabet.begin(), alphabet_character);

            //When the encrypt optional is set to be true
            if (encrypt) {
                //Check to see if you need to loop around to the begining
                if ((alphabet_index + key) >= 26){
                    CaesarText += alphabet[alphabet_index + key - 26]; //if there is an overflow, loop back around to the beginning of the alphabet
                }
                else{
                    CaesarText += alphabet[alphabet_index + key];
                }
            }
            //if the decrypt option is specified
            else {
                //Check to see if you need to loop around to the begining
                if ((alphabet_index - key + 26) < 25){ // as some varables are unsigned ints, need to write condition like this, otherwise I get an error saying unsigned ints are never less than 0
                    CaesarText += alphabet[alphabet_index - key + 26]; //if there is an overflow, loop back around to the end of the alphabet
                }
                else{
                    CaesarText += alphabet[alphabet_index - key];
                }
            }
            }

    return CaesarText;
    }
