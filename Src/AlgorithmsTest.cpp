#pragma once
#include <iostream>
#include <string>
#include "Logger.h"
#include "Utils.h"
#include "SortingTester.cpp"
#include "PrintTable.h"

int main()
{
    Logger::Init();
    SortingTester* sortingTester = new SortingTester();
    sortingTester->Begin();
    char key;
    std::cin >> key;
    delete sortingTester;
}


