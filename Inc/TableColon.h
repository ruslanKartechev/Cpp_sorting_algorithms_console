#pragma once
#define CenterAlign

#include <cstdlib>
#include <string>
#include <map>
#include "Logger.h"

class TableColon {
public:
	TableColon();
	~TableColon();

	int GetLinesCount();
	void Clear();
	void AddLine(const std::wstring& line);
	std::wstring GetLine(int index);
	int GetWidth();
	void SetWidth(int width);
	void SetLabel(const std::wstring& label);
	std::wstring GetLabel();

private:
	std::wstring* data;
	std::wstring m_label;
	int m_width;
	int m_size;
	int m_capacity;

	std::wstring CorrectLineWidth(std::wstring line);
};
