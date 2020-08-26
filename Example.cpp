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
}