#pragma once
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <regex> 
#include <filesystem>


class I_Parcer
{
public:
	
	virtual	~I_Parcer() {}
	virtual void read() = 0;
	
};