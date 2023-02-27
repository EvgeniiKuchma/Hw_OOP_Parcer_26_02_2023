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


    //  std::filesystem::path - это класс из библиотеки <filesystem>, который представляет собой путь к файлу 
    //  или каталогу в файловой системе.Для создания объекта этого класса необходимо передать ему строку с именем 
    //  пути.Например, чтобы создать объект path с именем файла "file.txt", можно написать такой код :
    //  Также path позволяет работать с путями к файлам и каталогам, осуществлять проверку на существование, получать
    //  имя файла или каталога, расширение файла и т.д.


// if (path.extension() != ".ini")   


    //  Эта строка проверяет, что расширение файла, полученное из path.extension(), не равно ".ini".Если расширение 
    //  файла не ".ini", то это может означать, что файл не является INI - файлом, и поэтому не может быть обработан 
    //  парсером INI.


// line = std::regex_replace(line, std::regex("^\\s+|\\s+$|#.*|;.*|\\s+"), "");


     //  Эта строка использует регулярное выражение, 
     //  чтобы удалить пробельные символы в начале и конце строки line.
     //  ^ \\s + соответствует одному или нескольким пробельным символам в начале строки.
     //  \\s + $ соответствует одному или нескольким пробельным символам в конце строки.
     //  Функция std::regex_replace заменяет все совпадения с этими шаблонами на пустую 
     //  строку, что и удаляет  пробелы в начале и конце строки.
     //  Например, если строка line была " hello world ", то после этой строки её значение станет "hello world".


//size_t equals_pos = line.find('=');
//if (equals_pos == std::string::npos || equals_pos == 0) {


    //  В строке equals_pos = line.find('='); 
    //  мы ищем позицию символа равенства (=) в строке line. Если символ не найден, 
    //  то метод find возвращает std::string::npos, что является константой, представляющей 
    //  максимальное значение для типа std::string::size_type.
    //  Если equals_pos равен std::string::npos, то это означает, что символ равенства не 
    //  был найден в строке line, что в свою очередь означает, что в этой строке нет значения 
    //  для ключа, и значение ключа должно быть установлено в пустую строку.Поэтому в этом случае 
    //  мы устанавливаем equals_pos в 0, чтобы ключ был установлен на всю строку line, а значение 
    //  было установлено в пустую строку.


//  data_[current_section][key] = value;

   
    //  data_ является мапой, где ключ - это название секции, а значение - другая мапа, которая содержит пары ключ - значение для данной секции.
    //  current_section - это название текущей секции, которую мы обрабатываем в данный момент
    //  key - это ключ, который мы хотим добавить в текущую секцию.
    //  value - это значение ключа, которое мы хотим добавить в текущую секцию.
    //  Поэтому данная строка кода добавляет новую пару ключ - значение в мапу для текущей секции.Если такой ключ уже есть, то его значение будет 
    //  заменено на новое.Если же ключа нет, то он будет добавлен в текущую секцию.
    //  Данный код добавляет значение value внутри ключа key в текущий раздел current_section в std::map<std::string, std::map<std::string, std::string>> data_.
    //  На уровне компиляции компилятор создает объект типа std::map<std::string, std::map<std::string, std::string>>, который хранит данные в виде пар ключ - значение.
     /* Когда код выполняется, мы указываем компилятору, что нужно добавить новое значение value в ключ key, который находится в разделе current_section.Для этого 
        мы используем оператор[] дважды.Первый раз мы обращаемся к data_ с помощью ключа current_section, чтобы получить вложенный std::map.Второй раз мы обращаемся 
        к этому вложенному std::map с помощью ключа key, чтобы установить значение value.*/