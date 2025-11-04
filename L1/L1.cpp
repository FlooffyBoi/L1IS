// Задание 7

#include <iostream>
#include <string>
#include <fstream>
static std::string rle(std::string input) {
    for (int i = 0; i < input.size(); i++)
    {
        if ((input[i] < 'A' || input[i]>'Z')
            && (input[i] < 'a' || input[i]>'z')) { // Not a latin letter
            throw std::invalid_argument("The string contains a character that is not a latin letter.");
        }
    }
    std::string output="";
    char charbuf=NULL;
    int bufcount = 0;
    int outIteration = 0;
    for (int i = 0; i < input.size();i++) {
        if (input[i] == charbuf)
            bufcount++;
        else if (charbuf != NULL) {
            if (bufcount > 1) {
                output+=std::to_string(bufcount)+charbuf;
            }
            else
                output += charbuf;
            charbuf = input[i];
            bufcount = 1;
        }
        else {
            bufcount = 1;
            charbuf = input[0];
        }
    }
    if (input.size() != 0) {
        if (bufcount > 1) {
            output += std::to_string(bufcount) + charbuf;
        }
        else
            output += charbuf;
    }
    return output;
}

int main()
{
    std::string input;
    std::ifstream inputStream("input.txt");
    inputStream >> input;
    inputStream.close();
    std::ofstream outputStream("output.txt");
    outputStream << rle(input);
    outputStream.close();
    return 0;
}