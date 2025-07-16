#include <iostream>
#include <string>

using namespace std;

string Parser(string& source, const char DELIMITER);

int main() {
    string input;
    cout << "Enter text (<name>|<date of birth>|<phone>): ";
    getline(cin, input);

    const char DELIMITER_TOTAL = '|';
    const char DELIMITER_DATE = '.';

    auto name = Parser(input, DELIMITER_TOTAL);
    auto date_of_birth = Parser(input, DELIMITER_TOTAL);
    auto phone = input;

    cout << "name: " << "\t\t" << name << endl;
    cout << "date of birth: " << "\t\t" << date_of_birth << endl;
    cout << "phone: " << "\t\t" << phone << endl;

    return 0;
}

string Parser(string& source, const char DELIMITER) {
    auto position = source.find(DELIMITER);
    auto result = source.substr(0, position);
    source = source.substr(position + 1);

    return result;
}