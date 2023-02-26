#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <map>
#include "I_Parcer.h"
#include "ParcerIni.h"

int main() {

    std::shared_ptr<I_Parcer> parc = std::make_shared<ParcerIni>();
    std::shared_ptr<ParcerIni> parc_Ini = std::dynamic_pointer_cast<ParcerIni>(parc);
    parc_Ini->read();
    parc_Ini->get_data();
    parc_Ini->PrintFile();
    
    return 0;
}