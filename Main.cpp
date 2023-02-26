#include "ParcerIni.h"
#include "I_Parcer.h"
#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <map>

// IDEAL STRONG FUCKIN SINOR INIFILES PARCER PUNCH BICH, YAEEHHH -> GO A HEAD//(HuMor)

int main() {
    try {
        setlocale(LC_ALL, "Russia");//Понимаю что, Bad practic и все дела, но во имя своего понимания и лишь во учения своего, блага для)))
        std::shared_ptr<I_Parcer> parc = std::make_shared<ParcerIni>();
        std::shared_ptr<ParcerIni> parc_Ini = std::dynamic_pointer_cast<ParcerIni>(parc);  
        parc_Ini->read();
        parc_Ini->get_data();
        parc_Ini->print_file();
    }
    catch (std::bad_cast& e) {
        std::cerr << e.what() << std::endl;
    };
    return 0;
}