#pragma once
#include "I_Parcer.h"

class ParcerIni : public I_Parcer
{
public:
	
	virtual void read() override;
	std::map<std::string, std::map<std::string, std::string>> get_data()const;
	void const PrintFile() ;
private:
	std::string line;
	std::string current_section;
	std::map<std::string, std::map<std::string, std::string>> data_;
};