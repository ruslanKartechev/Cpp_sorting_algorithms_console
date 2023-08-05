#pragma once
#include "Logger.h"
#include <string>
#include <iostream>
#include <windows.h>


Logger* Logger::mInstance = nullptr;


Logger::Logger()
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

// Public Static
	void Logger::Init()
	{
		if (mInstance == nullptr)
			mInstance = new Logger();
	}

	//void Logger::LoopColors()
	//{
	//	HANDLE hConsole{};
	//	std::string message = "Color looping";
	//	for (int k = 1; k < 10; k++)
	//	{
	//		SetConsoleTextAttribute(hConsole, k);
	//		std::cout << k << message << std::endl;
	//	}
	//}

	void Logger::Log(std::string message) 
	{ 
		Logger::mInstance->PrintMessage(message);
	}

	void Logger::Log(std::wstring message)
	{
		Logger::mInstance->PrintMessage(message);
	}
	
	void Logger::LogRed(std::string message) 
	{ 
		SetConsoleTextAttribute(mInstance->hConsole, int(4));
		mInstance->Log(message);
		mInstance->ResetColor();

	}
	void Logger::LogBlue(std::string message) 
	{ 
		SetConsoleTextAttribute(mInstance->hConsole, 1);
		mInstance->Log(message);
		mInstance->ResetColor();
	}

	void Logger::LogCyan(std::string message) 
	{ 
		SetConsoleTextAttribute(mInstance->hConsole, 3);
		mInstance->Log(message);
		mInstance->ResetColor();
	}

	void Logger::LogYellow(std::string message) 
	{ 
		SetConsoleTextAttribute(mInstance->hConsole, 6);
		mInstance->Log(message);
		mInstance->ResetColor();
	}

	void Logger::LogPurple(std::string message) 
	{ 
		SetConsoleTextAttribute(mInstance->hConsole, 5);
		mInstance->Log(message);
		mInstance->ResetColor();
	}

	void Logger::LogGreen(std::string message)
	{
		SetConsoleTextAttribute(mInstance->hConsole, 2);
		mInstance->Log(message);
		mInstance->ResetColor();
	}
	

	// Protected	
	void Logger::PrintMessage(std::string message)
	{
		std::cout << message << std::endl;
	}

	void Logger::PrintMessage(std::wstring message)
	{
		std::wcout << message << std::endl;
	}

	void Logger::ResetColor()
	{
		SetConsoleTextAttribute(hConsole, 7);
	}

	

// 1 blue
// 2 green
// 3 cyan 
// 4 red
// 5 purple
// 6 yellow
// 7 white
// 8 gray
// 9 light blue


