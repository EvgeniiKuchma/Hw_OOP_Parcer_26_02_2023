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
                break;
            }
            else 
                std::cout << "\nFile opening error, please try again: ";
            
        }
        std::cin.ignore();
        getline(std::cin, name);
        std::cout << std::endl;
    }
    while (std::getline(input_file, line)) {
        // Remove leading and trailing whitespace
        line = std::regex_replace(line, std::regex("^\\s+|\\s+$|#.*|;.*|\\s+"), "");
        // Ignore comments and blank lines
        if (line.empty() || line[0] == ';' || line[0] == '#') {
            continue;
        }
        // Check for section header
        if (line[0] == '[' && line.back() == ']') {
            current_section = line.substr(1, line.length() - 2);
        }
        else {
            // Split the line into key-value pairs
            size_t equals_pos = line.find('=');
            if (equals_pos == std::string::npos || equals_pos == 0) {
                continue;// Skip lines without equals sign
            }
            std::string key = line.substr(0, equals_pos);
            std::string value = line.substr(equals_pos + 1);
            if (key.empty()) {
                std::string value = line.substr(equals_pos + 1);

            } if (value.empty()) {
                std::string key = line.substr(0, equals_pos);
            }
            // Add the key-value pair to the map
            data_[current_section][key] = value;
        }
    }
    input_file.close();
    if (!input_file.is_open()) {
        std::cout << "\nFile close!\n\n" << std::endl;
    }
}
std::map<std::string, std::map<std::string, std::string>>  ParcerIni::get_data() const {
   return data_;
}
void ParcerIni::print_file() const   {
    for (auto const& section : data_) {
        std::cout << "[" << section.first << "]" << std::endl;
        for (auto const& key_value : section.second) {
            if (key_value.second.empty())
            std::cout << key_value.first << " = " << std::endl;
            else
            std::cout << key_value.first << " = " << key_value.second << std::endl;
        }
        std::cout << std::endl;
   }
}  
void ParcerIni::KeyInHedear(std::string& key) const {
    for (auto const& section : data_) {
          std::cout << section.first.find(key) << "=" << section.second.find(key) << std::endl;   
               
            
       std::cout << std::endl;
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