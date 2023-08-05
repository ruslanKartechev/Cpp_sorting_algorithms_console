#pragma once
#include <string>
#include <iostream>
#include <string>
#include "Logger.h"
#include "Utils.h"
#include <list>
#include "TableColon.h"

class PrintTable
{

public:
	PrintTable();
	void AddColon(const std::wstring& label, int width = 16);
	void AddLineToColon(const std::wstring& line, const std::wstring& label);
	void AddLineToColon(const std::wstring& line, int colonIndex);
	int GetColonsCount();
	void Print();

private:
	std::map<std::wstring, TableColon*>* m_colonsByLabel;
	std::list<TableColon*>* m_colons;
	int linesCount;
	const std::wstring m_delimiter = L"||";
	int GetMaxLinesCount();
	std::wstring GetDelimeter();
};

