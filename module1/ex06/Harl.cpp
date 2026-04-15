#include "Harl.hpp"

void Harl::debug(void) {
    std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n" 
			  << std::endl;
}

void Harl::info(void) {
    std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n"
			  << std::endl;
}

void Harl::warning(void) {
    std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n" 
			  << std::endl;
}

void Harl::error(void) {
    std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n" 
			  << std::endl;
}

void Harl::complain(std::string level) 
{
    std::string names[] = { "DEBUG", "INFO", "WARNING", "ERROR"};

    int level_index = 4;
    for (int i = 0; i < 4; i++) {
        if (names[i] == level) {
            level_index = i;
            break;
        }
    }
    switch (level_index) {
        case 0:
            this->debug();
			this->info();
			this->warning();
			this->error();
            break;
        case 1:
            this->info();
			this->warning();
			this->error();
            break;
        case 2:
            this->warning();
            this->error();
            break;
        case 3:
            this->error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]\n";
    }
}