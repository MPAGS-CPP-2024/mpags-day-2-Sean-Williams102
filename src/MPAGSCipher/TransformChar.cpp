#include <cctype>
#include <iostream>
#include <string>
#include <vector>

//Our project headers
#include "TransformChar.hpp"

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