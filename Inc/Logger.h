#pragma once
#include <string>
#include <iostream>
#include <windows.h>


class Logger
{
public:
	Logger();
	
	static void Init();
	static void Log(std::string message);
	static void Log(std::wstring message);
	static void LogRed(std::string message);
	static void LogBlue(std::string message);
	static void LogCyan(std::string message);
	static void LogGreen(std::string message);
	static void LogYellow(std::string message);
	static void LogPurple(std::string message);

protected:
	static Logger* mInstance;
	HANDLE hConsole;
	void PrintMessage(std::wstring message);
	void PrintMessage(std::string message);

	void ResetColor();
};
