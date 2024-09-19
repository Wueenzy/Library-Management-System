#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "utils.h"
using namespace std;

class BootLoader{
    Utils utils;
public:
    vector<unordered_map<string, string>> parseSimpleJSON(const string& filename);
};

vector<unordered_map<string, string>> BootLoader::parseSimpleJSON(const string &filename) {
    vector<unordered_map<string, string>> jsonData;
    ifstream file(filename, ios::in);
    string line;

    if(!file.is_open()){
        cerr << "Failed to open file!" << endl;
        return jsonData;
    }

    unordered_map<string, string> currentPerson;
    bool inArray = false;

    while(getline(file, line)){
        line = utils.trim(line);

        if(line.empty()){
            continue;
        }

        if(line == "["){
            inArray = true;
            continue;
        }

        if(line == "]"){
            inArray = false;
            continue;
        }

        if(inArray && line == "{" || line == "}" || line == "},"){
            if(line == "}," || line == "}"){
                jsonData.push_back(currentPerson);
                currentPerson.clear();
            }
            continue;
        }

        size_t delimiter = line.find(':');
        if(delimiter == string::npos){
            continue;
        }

        string key = line.substr(0, delimiter);
        string value = line.substr(delimiter + 1);

        key = utils.trim(key);
        value = utils.trim(value);

        if (key[0] == '"') {
            key = key.substr(1, key.size() - 2);
        }
        if (value[0] == '"') {
            value = value.substr(1, value.size() - 3);
        } else if (value.back() == ',') {
            value.pop_back();
        }

        currentPerson[key] = value;
    }

    return jsonData;
}