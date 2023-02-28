#pragma once
#pragma once
#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>
#include <regex> //библиотека для работы сраного regexa
#include <map>

class I_Parcer
{
public:
	virtual	~I_Parcer() {}
	virtual void read() = 0;
	virtual void print_file() const = 0;
};