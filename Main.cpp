#include "ParcerIni.h"
#include "I_Parcer.h"
#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <map>

// IDEAL STRONG FUCKIN SINOR INIFILES PARCER PUNCH BICH, YAEEHHH -> GO A HEAD//(HuMor)//

int main() {
    try {
        setlocale(LC_ALL, "Russia");//������� ���, Bad practic � ��� ����, �� �� ��� ������ ��������� � ���� �� ������ ������, ����� ���)))
        std::shared_ptr<I_Parcer> parc = std::make_shared<ParcerIni>();
        std::shared_ptr<ParcerIni> parc_ini = std::dynamic_pointer_cast<ParcerIni>(parc);  
        parc->read();
        parc_ini->get_data();
        parc_ini->print_file();
        parc_ini->KeyInHedear("mode");
        std::cout <<  parc_ini->hasKey(";", "Test.ini");
        parc_ini->HedearSearch("Difficulty");
        parc_ini->ValueInFile("easy");
        parc_ini->ValueInKey("ColorSpace");
        parc_ini->ValueInKey("........");
        parc_ini->ChangeValue("Controls", "Button", "Key_num");
        parc_ini->ChangeValue("MySection", "MyValue", "MayKey");
    }
    catch (std::bad_cast& e) {
        std::cerr << e.what() << std::endl;
    };
    return 0;
}
//mutex - ��� �������� �������������