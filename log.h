#pragma once

/**
 * Author: chankruze (Chandan Kumar Mandal)
 * Mail: chankruze@geekofia.in
 *
 * Copyright (c) Geekofia 2020 and beyond
**/

class Log {
	// public variables
public:
	enum LogLevel
	{
		LevelError, LevelWarning, LevelInfo
	};

	// private variables
private:
	LogLevel m_LogLevel = LevelInfo;

	// public methods
public:
	void setLogLevel(LogLevel level) {
		m_LogLevel = level;
	}

	void Error(const char* msg) {
		if (m_LogLevel >= LevelError)
			std::cout << "[ERROR]: " << msg << std::endl;
	}

	void Warning(const char* msg) {
		if (m_LogLevel >= LevelWarning)
			std::cout << "[WARNING]: " << msg << std::endl;
	}

	void Info(const char* msg) {
		if (m_LogLevel >= LevelInfo)
			std::cout << "[INFO]: " << msg << std::endl;
	}
};