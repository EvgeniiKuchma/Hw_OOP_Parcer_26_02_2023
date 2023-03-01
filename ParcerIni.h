#pragma once
#include "I_Parcer.h"

class ParcerIni : public I_Parcer
{
public:
	virtual void read() override;
	void print_file() const override;
	void KeyInHedear(const std::string& key) const;
	bool hasKey(const std::string key,const std::string filename) const;
	void HedearSearch(const std::string& hedear) const;
	void ValueInFile(const std::string& value) const;
	void ValueInKey(const std::string& key) const;
	void ChangeValue(const std::string& hedear,const std::string& value, const std::string& key);
	const std::map<std::string, std::map<std::string, std::string>>& get_data() const;

private:
	std::string key_;
	std::string value_;
	std::string line_;
	std::string current_section_;
	std::map<std::string, std::map<std::string, std::string>> data_;
};