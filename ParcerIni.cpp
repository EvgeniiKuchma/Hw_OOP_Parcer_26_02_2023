#include "ParcerIni.h"

void ParcerIni::read() {
    std::cout << "Please enter name file: ";
    std::string name;
    getline(std::cin, name);
    std::cout << std::endl;
    std::ifstream input_file(name);
    while (!input_file.is_open()) {
        std::filesystem::path path(name);
        if (path.extension() != ".ini") {
            std::cout << "\nThe file entered is not an ini file, please try again: ";
        }
        else {
            if (input_file.is_open()) {
                std::cout << "\nFile opening!\n" << std::endl;
               return;
            }
            else 
                std::cout << "\nFile opening error, please try again: ";
            
        }
        std::cin.ignore();
        getline(std::cin, name);
        std::cout << std::endl;
    }
    while (std::getline(input_file, line_)) {
        // Remove leading and trailing whitespace
        line_ = std::regex_replace(line_, std::regex("^\\s+|\\s+$|#.*|;.*|\\s+"), "");
        // Ignore comments and blank lines
        if (line_.empty() || line_[0] == ';' || line_[0] == '#') {
            continue;
        }
        // Check for section header
        if (line_[0] == '[' && line_.back() == ']') {
            current_section_ = line_.substr(1, line_.length() - 2);
        }
        else {
            // Split the line into key-value pairs
            size_t equals_pos = line_.find('=');
            if (equals_pos == std::string::npos) {
                continue;// Skip lines without equals sign
            }
            key_ = line_.substr(0, equals_pos);
            value_ = line_.substr(equals_pos + 1);
            if (key_.empty()) {
                 value_ = line_.substr(equals_pos + 1);

            } if (value_.empty()) {
                 key_ = line_.substr(0, equals_pos);
            }
            // Add the key-value pair to the map
            data_[current_section_][key_] = value_;
        }
    }
    input_file.close();
    if (!input_file.is_open()) {
        std::cout << "\nFile close!\n\n" << std::endl;
    }
}

 const std::map<std::string, std::map<std::string, std::string>>&  ParcerIni::get_data() const {
   return data_;
}

void ParcerIni::print_file() const {
    for (auto const& section : data_) {
        std::cout << "[" << section.first << "]" << std::endl;
        for (auto const& key_value : section.second) {
            std::cout << key_value.first << " = " << key_value.second << std::endl;
        }
        std::cout << std::endl;
    }
}  

void ParcerIni::KeyInHedear(const std::string& key) const {
    auto it = data_.begin();
    while (it != data_.end()) {
        auto subMapIt = it->second.find(key);
        if (subMapIt != it->second.end()) {
            // Found key
            std::string header = it->first;
            std::cout << "Key " << key << " is in heder " << header << std::endl; 
            break;
        }
       it++;  
    }
    if (it == data_.end()) {
        // Key not found
        std::cout << "Key " << key << " not found in File" << std::endl;
    }
}

bool ParcerIni::hasKey( const std::string key,const std::string filename) const {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty() || line[0] == ';' || line[0] == '#') {
            continue;
        }
        std::string::size_type pos = line.find('=');
        if (pos != std::string::npos) {
            std::string current_key = line.substr(0, pos);
            if (current_key == key) {
                return true;
            }
        }
    }
    return false;
}
void ParcerIni::HedearSearch( const std::string& hedear) const {
    for (auto it = data_.begin(); it != data_.end(); it++)
        if(it->first.find == key) {
            std::cout << "\n\nHedear " << hedear << " found" << std::endl;
            return;
        }
    std::cout << "\n\nHedear " << hedear << " not found in File" << std::endl;
}

void ParcerIni::ValueInFile(const std::string& value) const {
    for (auto it = data_.begin(); it != data_.end(); it++) {
        for (auto it_subMap = it->second.begin(); it_subMap != it->second.end(); it_subMap) {
            if (it_subMap->second.find(value)) {
                std::cout << "\n\nValue " << value << " found in file" << std::endl;
                return;
            }
            std::cout << "\n\nValue " << value << " not found in file" << std::endl;
        }
    }
}

void ParcerIni::ValueInKey(const std::string& key) const {
    for (const auto& section : data_) {
        for (const auto& key_value : section.second) {
            if (key_value.first == key) {
                std::cout << "\n\nIn key " << key << " put on " << key_value.second << " value." << std::endl;
               return;
            }  
        }
    }
    std::cout << "\nKey not found!\n" << std::endl;
}

void ParcerIni::ChangeValue(const std::string& hedear,const std::string& value, const std::string& key) {
    for (const auto& section : data_){
        for (const auto& key_value : section.second) { 
             if(section.first==hedear){
                data_ [section.first][key_value.second] = value;
                std::cout << '[' << section.first << ']' << std::endl;
                std::cout << key_value.first << " = " << value << std::endl;
                return;
             }
             else {
                 current_section_ = hedear;
                 key_ = key;
                 data_[current_section_][key_] = value;
                 std::cout << '[' << current_section_ << ']' << std::endl;
                 std::cout << key_ << " = " << value << std::endl;
                 return;
             }
        }
    } 
    
}
           






// std::ifstream input_file(name); 


    //  std::filesystem::path - ��� ����� �� ���������� <filesystem>, ������� ������������ ����� ���� � ����� 
    //  ��� �������� � �������� �������.��� �������� ������� ����� ������ ���������� �������� ��� ������ � ������ 
    //  ����.��������, ����� ������� ������ path � ������ ����� "file.txt", ����� �������� ����� ��� :
    //  ����� path ��������� �������� � ������ � ������ � ���������, ������������ �������� �� �������������, ��������
    //  ��� ����� ��� ��������, ���������� ����� � �.�.


// if (path.extension() != ".ini")   


    //  ��� ������ ���������, ��� ���������� �����, ���������� �� path.extension(), �� ����� ".ini".���� ���������� 
    //  ����� �� ".ini", �� ��� ����� ��������, ��� ���� �� �������� INI - ������, � ������� �� ����� ���� ��������� 
    //  �������� INI.


// line = std::regex_replace(line, std::regex("^\\s+|\\s+$|#.*|;.*|\\s+"), "");


     //  ��� ������ ���������� ���������� ���������, 
     //  ����� ������� ���������� ������� � ������ � ����� ������ line.
     //  ^ \\s + ������������� ������ ��� ���������� ���������� �������� � ������ ������.
     //  \\s + $ ������������� ������ ��� ���������� ���������� �������� � ����� ������.
     //  ������� std::regex_replace �������� ��� ���������� � ����� ��������� �� ������ 
     //  ������, ��� � �������  ������� � ������ � ����� ������.
     //  ��������, ���� ������ line ���� " hello world ", �� ����� ���� ������ � �������� ������ "hello world".


//size_t equals_pos = line.find('=');
//if (equals_pos == std::string::npos || equals_pos == 0) {


    //  � ������ equals_pos = line.find('='); 
    //  �� ���� ������� ������� ��������� (=) � ������ line. ���� ������ �� ������, 
    //  �� ����� find ���������� std::string::npos, ��� �������� ����������, �������������� 
    //  ������������ �������� ��� ���� std::string::size_type.
    //  ���� equals_pos ����� std::string::npos, �� ��� ��������, ��� ������ ��������� �� 
    //  ��� ������ � ������ line, ��� � ���� ������� ��������, ��� � ���� ������ ��� �������� 
    //  ��� �����, � �������� ����� ������ ���� ����������� � ������ ������.������� � ���� ������ 
    //  �� ������������� equals_pos � 0, ����� ���� ��� ���������� �� ��� ������ line, � �������� 
    //  ���� ����������� � ������ ������.


//  data_[current_section][key] = value;

   
    //  data_ �������� �����, ��� ���� - ��� �������� ������, � �������� - ������ ����, ������� �������� ���� ���� - �������� ��� ������ ������.
    //  current_section - ��� �������� ������� ������, ������� �� ������������ � ������ ������
    //  key - ��� ����, ������� �� ����� �������� � ������� ������.
    //  value - ��� �������� �����, ������� �� ����� �������� � ������� ������.
    //  ������� ������ ������ ���� ��������� ����� ���� ���� - �������� � ���� ��� ������� ������.���� ����� ���� ��� ����, �� ��� �������� ����� 
    //  �������� �� �����.���� �� ����� ���, �� �� ����� �������� � ������� ������.
    //  ������ ��� ��������� �������� value ������ ����� key � ������� ������ current_section � std::map<std::string, std::map<std::string, std::string>> data_.
    //  �� ������ ���������� ���������� ������� ������ ���� std::map<std::string, std::map<std::string, std::string>>, ������� ������ ������ � ���� ��� ���� - ��������.
     /* ����� ��� �����������, �� ��������� �����������, ��� ����� �������� ����� �������� value � ���� key, ������� ��������� � ������� current_section.��� ����� 
        �� ���������� ��������[] ������.������ ��� �� ���������� � data_ � ������� ����� current_section, ����� �������� ��������� std::map.������ ��� �� ���������� 
        � ����� ���������� std::map � ������� ����� key, ����� ���������� �������� value.*/