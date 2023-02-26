#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <map>
#include "I_Parcer.h"
#include "ParcerIni.h"

int main() {
    try {
        std::shared_ptr<I_Parcer> parc = std::make_shared<ParcerIni>();
        parc->read();

        std::shared_ptr<ParcerIni> parc_Ini = std::dynamic_pointer_cast<ParcerIni>(parc);
        std::cout << "Value of 'key1' in section 'section1': " << parc_Ini->get_value("section1", "key1") << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

   

	return 0;
}