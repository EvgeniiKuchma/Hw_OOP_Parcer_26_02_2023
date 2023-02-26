#include "ParcerIni.h"

void ParcerIni::read()  {
    
    std::cout << "Please enter name file : ";
    std::string name;
    getline(std::cin, name);
    std::ifstream input_file(name); 
 while(!input_file.is_open()){
	std::filesystem::path path(name);
    if (path.extension() != ".ini") {
        std::cout << "\nThe file entered is not an ini file, please try again;\n\n";	
	}
	    else{
            if (input_file.is_open()) {
			    std::cout << "\nFile opening!\n\n";
	
            }
			    else {
				     std::cout << "\nFile opening error, please try again\n\n";
                }
        }
	std::cin.ignore();
    getline(std::cin, name);			
}     
while (std::getline(input_file, line)) {
        // Remove leading and trailing whitespace
        line = std::regex_replace(line, std::regex("^\\s+|\\s+$"), "");

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
            if (equals_pos == std::string::npos || equals_pos ==  0 ) {
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
}
std::map<std::string, std::map<std::string, std::string>>  ParcerIni::get_data() const {
   return data_;
}
void const ParcerIni::PrintFile()  {
    for (auto const& section : data_) {
        std::cout << "[" << section.first << "]" << std::endl;
        for (auto const& key_value : section.second) {
            std::string value = key_value.second.empty() ? "" : " = " + key_value.second;
            std::cout << key_value.first << value << std::endl;
        }
        std::cout << std::endl;
   }
}