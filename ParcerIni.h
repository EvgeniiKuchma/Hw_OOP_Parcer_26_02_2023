#pragma once
#include "I_Parcer.h"

class ParcerIni : public I_Parcer
{
public:
	virtual void read() override;
	void const print_file() ;
	std::map<std::string, std::map<std::string, std::string>> get_data()const;
private:
	std::string line;
	std::string current_section;
	std::map<std::string, std::map<std::string, std::string>> data_;
};