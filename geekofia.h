#pragma once

/**
 * Author: chankruze (Chandan Kumar Mandal)
 * Mail: chankruze@geekofia.in
 *
 * Copyright (c) Geekofia 2020 and beyond
**/

#include <bits/stdc++.h>

#include <cmath>
#include <string>
#include <unordered_set>
#include <vector>

#define print(x) std::cout << x
#define println(x) std::cout << x << std::endl
#define input(x) std::cin >> x
#define inputln(x) getline(std::cin >> std::ws, x)

// Decimal to Hexadecimal
std::string toHex(int num) {
    std::string hexDigits = "0123456789abcdef";
    std::string hex = "";
    int len = std::to_string(num).length();

    if (num < 16) {
        return std::to_string(hexDigits[num]);
    } else {
        double numd = (double)num;
        while (numd > 15.0) {
            numd /= 16.0;
        }

        int digit_0 = floor(numd);
        hex += hexDigits.at(digit_0);
        double rem = numd - digit_0;

        while (rem != 0.0) {
            rem *= 16.0;
            hex += hexDigits[floor(rem)];
            rem -= floor(rem);
        }

        return hex;
    }
}

// Decimal to Binary
std::string toBin(int x) {
    std::string bin = "";

    while (x != 0) {
        bin += std::to_string(x % 2);
        x /= 2;
    }
    reverse(bin.begin(), bin.end());
    return bin;
}

// Vowel Check
bool isVowel(char c) {
    switch (tolower(c)) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
        default:
            return false;
    }
}

// Isogram Check for a Word
bool isIsogram(std::string word) {
    std::unordered_set<char> set;

    for (char c : word) {
        set.insert(c);
    }

    return (word.length() == set.size());
}

// split string
// std::vector<std::string> split(std::string str, std::string delim) {
//     std::vector<std::string> splittedArray;

//     while (str.find(delim) < str.length()) {
//         int index = str.find(delim);
//         splittedArray.emplace_back(str.substr(0, index));
//         str = str.substr(index + 1);
//     }

//     splittedArray.emplace_back(str);

//     return splittedArray;
// }

// split string
std::vector<std::string> split(std::string str, char *delim) {
    std::vector<std::string> splittedArray;
    char temp[str.length() + 1];
    strcpy(temp, str.c_str());

    char *arr = strtok(temp, delim);

    while (arr != NULL) {
        splittedArray.emplace_back(arr);
        arr = strtok(NULL, delim);
    }

    return splittedArray;
}
