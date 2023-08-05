#pragma once
#include <iostream>
#include <string>
#include "Logger.h"
#include "Utils.h"
#include "SortingTester.cpp"
#include "PrintTable.h"


class SimpleClass {
public:
    SimpleClass()
    {
        Logger::LogBlue("Created");
        number = 5;
        refNumber = new int(10);
    }

    ~SimpleClass()
    {
        delete refNumber;
        Logger::LogBlue("Destroyed");
    }

private:
    int number;
    int* refNumber;
};


void TestTable()
{
    PrintTable* table = new PrintTable();
    table->AddColon(L"Colon 1");
    table->AddColon(L"Colon 2");
    table->AddColon(L"Colon 3");

    table->AddLineToColon(L"val 11", 0);
    table->AddLineToColon(L"val 21", 1);
    table->AddLineToColon(L"val 31", L"Colon 3");
    table->AddLineToColon(L"val 32", L"Colon 3");
    table->AddLineToColon(L"val 33", L"Colon 3");
    table->AddLineToColon(L"val 34", L"Colon 3");

    table->Print();
}


int main()
{
    Logger::Init();

    //TestTable();

    //SimpleClass* simpleClass = new SimpleClass();
    //delete simpleClass;

    SortingTester* sortingTester = new SortingTester();
    sortingTester->Begin();
    char key;
    Logger::LogBlue("Programm end, enter a key to clear");
    std::cin >> key;
    delete sortingTester;

}

