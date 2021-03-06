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
#include <unordered_map>
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
std::vector<std::string> str_split(std::string str, char *delim) {
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

bool isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return true;
            } else {
                return false;
            }
        } else {
            return true;
        }
    } else {
        return false;
    }
}

std::string calcDay(int day, int month, int year) {
    const char *dayCodes[] = {
        "Sunday",
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday"};

    const char *monthsArray[] = {"NULL", "jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"};

    std::unordered_map<std::string, int> monthCodes;
    monthCodes["jan"] = 0;
    monthCodes["feb"] = 3;
    monthCodes["mar"] = 3;
    monthCodes["apr"] = 6;
    monthCodes["may"] = 1;
    monthCodes["jun"] = 4;
    monthCodes["jul"] = 6;
    monthCodes["aug"] = 2;
    monthCodes["sep"] = 5;
    monthCodes["oct"] = 0;
    monthCodes["nov"] = 3;
    monthCodes["dec"] = 5;

    std::unordered_map<std::string, int> centuryCodes;
    centuryCodes["16"] = 6;
    centuryCodes["17"] = 4;
    centuryCodes["18"] = 2;
    centuryCodes["19"] = 0;
    centuryCodes["20"] = 6;

    // logic
    // day code = ((day + [month code] + [year's last 2 digit] + [year's last 2 digit / 4] + [century code]) % 7 ) - (if Leap Year)
    int monthCode = monthCodes[monthsArray[month]];
    int yearTail = year % 100;
    int yearHead = year / 100;
    int centuryCode = centuryCodes[std::to_string(yearHead)];

    int dayCode = (day + monthCode + yearTail + (yearTail / 4) + centuryCode) % 7;

    // if leap year -1 in feb calculation
    if (month <= 2 && isLeapYear(year)) {
        dayCode = ((day + monthCode + yearTail + (yearTail / 4) + centuryCode) - 1) % 7;
    }

    return dayCodes[dayCode];
}

// string substr (size_t pos, size_t len) const;
// Parameters:
// pos: Position of the first character to be copied.
// len: Length of the sub-string.
// size_t: It is an unsigned integral type.
// Return value : It returns a string object.

std::vector<std::string> str_split(const std::string &str, const int step) {
    std::vector<std::string> arr;

    const int STR_LEN = str.length();

    for (size_t i = 0; i < STR_LEN; i += step) {
        if (i + step < STR_LEN) {
            arr.emplace_back(str.substr(i, step));
        } else {
            arr.emplace_back(str.substr(i));
        }
    }

    return arr;
}

std::vector<std::string> str_split(const std::string &str, const bool splitMiddle) {
    std::vector<std::string> arr;

    const int STR_LEN = str.length();

    if (splitMiddle) {
        if (STR_LEN % 2 != 0) {
            arr.emplace_back(str.substr(0, STR_LEN / 2));
            arr.emplace_back(str.substr(STR_LEN / 2 + 1));
            return arr;
        } else {
            arr.emplace_back(str.substr(0, STR_LEN / 2));
            arr.emplace_back(str.substr(STR_LEN / 2));
        }
    }

    return arr;
}

std::map<char, int> char_frequency(std::string& str) {
    std::map<char, int> count;
    int l = str.length();

    for (int i = 0; i < l; i++) {
        if (str[i] != ' ') {
            count[str[i]]++;
        }
    }

    return count;
}

bool hasAllSameChars(std::string& str1, std::string& str2) {
    std::set<char> str1Set, str2Set;
    std::string longer, shorter;

    for (char ch : str1) {
        str1Set.insert(ch);
    }

    for (char ch : str2) {
        str2Set.insert(ch);
    }

    if (str1Set.size() < str2Set.size()) {
        for (char ch : str2Set) {
            if (str1Set.find(ch) == str1Set.end())
                return false;
        }
    } else {
        for (char ch : str1Set) {
            if (str2Set.find(ch) == str2Set.end())
                return false;
        }
    }

    return true;
}

template <typename Map>
bool isSameMap(Map const& map1, Map const& map2) {
    return map1.size() == map2.size() && std::equal(map1.begin(), map1.end(), map2.begin());
}
