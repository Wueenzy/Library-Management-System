#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
using namespace std;

class Utils{
public:
    string trim(const string& str);
};

string Utils::trim(const string& str) {
    size_t first = str.find_first_not_of(' ');
    if(first == string::npos){
        return "Empty";
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first,(last - first + 1));
}