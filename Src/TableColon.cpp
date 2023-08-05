#include <cstdlib>
#include <string>
#include <map>
#include "Logger.h"
#include "TableColon.h"


TableColon::TableColon() : m_label(L""), m_width(1), m_capacity(50), m_size(0)
{
	data = new std::wstring[m_capacity];
}

TableColon::~TableColon()
{
	delete[] data;
}

int TableColon::GetLinesCount()
{
	return m_size;
}

std::wstring TableColon::GetLine(int index)
{
	if (index >= m_size)
	{
		return CorrectLineWidth(L"");
	}
	std::wstring line = CorrectLineWidth(data[index]);
	return line;
}

#ifdef CenterAlign
std::wstring TableColon::CorrectLineWidth(std::wstring line)
{
	auto originalSize = line.size();
	auto sizeDifference = m_width - originalSize;
	if (originalSize < m_width)
	{
		auto halfSize = sizeDifference / 2;
		auto otherHalf = sizeDifference - halfSize;
		int it = 0;
		while (it < otherHalf)
		{
			line = L" " + line;
			it++;
		}
		it = 0;
		while (it < halfSize)
		{
			line += L" ";
			it++;
		}
	}
	else if (originalSize < m_width)
	{
		Logger::LogRed("[Table colon] !! originalSize < m_width");
	}
	return line;
}
#else

std::wstring TableColon::CorrectLineWidth(std::wstring line)
{
	auto originalSize = line.size();
	auto sizeDifference = m_width - originalSize;

	if (originalSize < m_width)
	{
		auto addCount = m_width - originalSize - 1;
		line = L" " + line;
		int it = 0;
		while (it < addCount)
		{
			line += L" ";
			it++;
		}
	}
	else if (originalSize < m_width)
	{
		Logger::LogRed("[Table colon] !! originalSize < m_width");
	}
	return line;
}
#endif

void TableColon::AddLine(const std::wstring& line)
{
	if (m_size >= m_capacity)
	{
		Logger::LogRed("Max capacity reached");
		return;
	}
	data[m_size] = line;
	m_size++;
}

void TableColon::Clear()
{
	data->clear();
}

inline int TableColon::GetWidth()
{
	return m_width;
}

void TableColon::SetWidth(int width)
{
	this->m_width = width;
}

void TableColon::SetLabel(const std::wstring& label)
{
	this->m_label = label;
}

std::wstring TableColon::GetLabel()
{
	return CorrectLineWidth(m_label);
}


