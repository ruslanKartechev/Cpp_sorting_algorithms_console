#include <string>
#include <iostream>
#include <string>
#include <list>
#include "PrintTable.h"
#include "TableColon.h"
#include "Logger.h"

PrintTable::PrintTable() : linesCount(0)
{
	m_colons = new std::list<TableColon*>();
	m_colonsByLabel = new std::map<std::wstring, TableColon*>();
}

void PrintTable::AddColon(const std::wstring& label, int width)
{
	auto colon = new TableColon();
	colon->SetLabel(label);
	colon->SetWidth(width);
	m_colons->push_back(colon);
	(*m_colonsByLabel)[label] = colon;
}

void PrintTable::AddLineToColon(const std::wstring& line, const std::wstring& label)
{
	TableColon* ss = (*m_colonsByLabel)[label];
	ss->AddLine(line);
}

void PrintTable::AddLineToColon(const std::wstring& line, int colonIndex)
{
	if (colonIndex >= GetColonsCount())
	{
		Logger::LogRed("[Print table] Colon index >= colons count");
		return;
	}
	auto iterator = m_colons->begin();
	std::advance(iterator, colonIndex);
	(*iterator)->AddLine(line);
}

int PrintTable::GetColonsCount()
{
	return m_colons->size();
}

void PrintTable::Print()
{
	int lineIndex = 0;
	int maxCount = GetMaxLinesCount();
	std::wstring line;
	for (auto iterator = m_colons->begin(); iterator != m_colons->end(); ++iterator)
		line += (*iterator)->GetLabel() + GetDelimeter();
	std::wcout << line << std::endl;
	auto lineLength = line.length();
	line = L"";
	for (auto i = 0; i < lineLength; i++)
		line += L"=";
	std::wcout << line  << std::endl;

	while (lineIndex < maxCount)
	{
		line = L"";
		for (auto iterator = m_colons->begin(); iterator != m_colons->end(); ++iterator)
			line += (*iterator)->GetLine(lineIndex) + GetDelimeter();
		std::wcout << line << std::endl;
		lineIndex++;
	}
}

int PrintTable::GetMaxLinesCount()
{
	int maxCount = 0;
	for (auto iterator = m_colons->begin(); iterator != m_colons->end(); ++iterator)
	{
		int count = (*iterator)->GetLinesCount();
		if (count > maxCount)
			maxCount = count;
	}
	return maxCount;
}

std::wstring PrintTable::GetDelimeter()
{
	return m_delimiter;
}
