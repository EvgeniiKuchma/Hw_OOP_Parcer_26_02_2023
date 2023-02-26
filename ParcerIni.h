#pragma once
#include "I_Parcer.h"

class ParcerIni : public I_Parcer
{
public:
	
	virtual void read() override;
	std::string get_value(const std::string& section, const std::string& key)const;
	std::map<std::string, std::map<std::string, std::string>> get_data()const;
	void const PrintFile(std::map<std::string, std::map<std::string, std::string>> &data_) ;
private:
	std::string line;
	std::string current_section;
	std::map<std::string, std::map<std::string, std::string>> data_;
};