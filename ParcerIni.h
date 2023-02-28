#pragma once
#include "I_Parcer.h"

class ParcerIni : public I_Parcer
{
public:
	virtual void read() override;
	void print_file() const override;
	void KeyInHedear(std::string& key) const;
	bool hasKey(std::string key, std::string filename);
	void HedearSearch( const std::string& hedear) const;
	std::map<std::string, std::map<std::string, std::string>> get_data()const;

private:
	std::string line;
	std::string current_section;
	std::map<std::string, std::map<std::string, std::string>> data_;
};