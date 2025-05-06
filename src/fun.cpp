// Copyright 2022 UNN-IASR
#include "fun.h"
#include <iostream>
#include <string>
#include <cctype>
#include <cstring>

unsigned int faStr1(const char* str) {
    unsigned int result = 0; bool word = false, number = false;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && word == true) {
            if (isdigit(str[i])) number = true;
        }
        if (str[i] != ' ' && word == false) {
            word = true;
            if (isdigit(str[i])) number = true;
        }
        if ((str[i] == ' ' && word == true)
            || (i == strlen(str) && word == true)) {
            word = false;
            if (number == false) result++;
            number = false;
        }
    }
    return result;
}

unsigned int faStr2(const char* str) {
    unsigned int result = 0; bool word = false, letter = false;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && word == true) {
            if (!isdigit(str[i]) && !ispunct(str[i])) {
                letter = true;
            } else {
                letter = false;
            }
        }
        if (isupper(str[i]) && word == false) {
            word = true;
            letter = !isdigit(str[i]) && !ispunct(str[i]);
        }
        if ((str[i] == ' ' && word == true)
            || (str[i + 1] == '\0' && word == true)) {
            word = false;
            if (letter == true) result++;
            letter = false;
        }
    }
    return result;
}

unsigned int faStr3(const char* str) {
    unsigned int result = 0, length = 0, count_word = 0; bool word = false;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && word == true) {
            length++;
        }
        if (str[i] != ' ' && word == false) {
            word = true;
            length++;
        }
        if ((str[i] == ' ' && word == true)
            || (str[i + 1] == '\0' && word == true)) {
            word = false;
            count_word++;
            result += length;
            length = 0;
        }
    }
    return (result / count_word);
}
