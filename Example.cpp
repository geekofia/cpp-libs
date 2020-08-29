/**
 * Author: chankruze (Chandan Kumar Mandal)
 * Mail: chankruze@geekofia.in
 *
 * Copyright (c) Geekofia 2020 and beyond
**/

#include <iostream>

#include "geekofia.h"
#include "log.h"

int main() {
    Log log;
    log.setLogLevel(Log::LevelError);

    log.Error("This is an error message");
    log.Warning("This is an warning message");
    log.Info("This is an info message");

    int num = 231;
    // decimal to hex
    println("#" + toHex(num));
    // decimal to bin
    println(toBin(num));
    // isogram check
    println(isIsogram("test"));

    // split string with multiple delims
    std::vector<std::string> res = split("(*Nove*mber 19, 2019)", " ,()*");

    println("\n-- String Split --");
    for (std::string elem : res) {
        println(elem);
    }
    println("------------------");

    // find the day of the week form a date
    println("\n-- Day of Week --");
    print("2nd February 2016 is ");
    println(calcDay(2, 2, 2016));
    print("29th August 2020 is ");
    println(calcDay(29, 8, 2020));
    println("-------------------");
}