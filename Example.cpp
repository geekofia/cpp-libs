/**
 * Author: chankruze (Chandan Kumar Mandal)
 * Mail: chankruze@geekofia.in
 *
 * Copyright (c) Geekofia 2020 and beyond
**/

#include <iostream>
#include "log.h"
#include "geekofia.h"

int main() {
	Log log;
	log.setLogLevel(Log::LevelError);

	log.Error("This is an error message");
	log.Warning("This is an warning message");
	log.Info("This is an info message");

	println
}