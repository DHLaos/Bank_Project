#include <iostream>
#include <string>
#include <algorithm>
#include <conio.h>
#include "Password.h"
using namespace std;

Password::Password() : pwd(""), ch('\0') {}

void Password::createPWD() {
    cout << "Please create a 5 Digit password: ";

    while (true) {
        ch = _getch();  // Capture character without displaying it

        // Check if ENTER is pressed (ENTER has ASCII value 13)
        if (ch == 13) {
            if (pwd.length() == 5) {  // Allow confirming only if 5 digits have been entered
                std::cout << std::endl;  // Move to the next line
                break;  // Exit the loop when ENTER is pressed
            }
            else {
                std::cout << "\nPlease enter exactly 5 digits." << std::endl;
                pwd.clear();  // Clear the input if ENTER is pressed too early
                std::cout << "Please create a 5-digit password: ";
            }
        }
        else if (ch == '\b' && !pwd.empty()) {  // Handle backspace
            pwd.pop_back();
            std::cout << "\b \b";  // Erase the '*' on backspace
        }
        // Only allow digits, and limit the length to 5
        else if (isdigit(ch) && pwd.length() < 5) {
            pwd.push_back(ch);
            std::cout << "*";  // Show '*' for each input character
        }
    }

    if (pwd.length() == 5 && std::all_of(pwd.begin(), pwd.end(), ::isdigit)) {
        std::cout << "Password successfully created." << std::endl;
    }
    else {
        std::cout << "Invalid Password." << std::endl;
    }
}