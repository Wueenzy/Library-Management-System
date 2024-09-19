#include <iostream>
#include <iomanip>
#include <random>
#include <sstream>
using namespace std;

class UUIDG{
public:
    UUIDG();
    string getUUID() const;
};
UUIDG::UUIDG() {

}

string UUIDG::getUUID() const{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, 15);
    uniform_int_distribution<int> dist_variant(8, 11);

    stringstream ss;
    ss << hex << setfill('0');

    // İlk 8 karakter
    for (int i = 0; i < 8; ++i) {
        ss << dist(gen);
    }
    ss << '-';

    for (int i = 0; i < 4; ++i) {
        ss << dist(gen);
    }
    ss << '-';

    ss << '4';
    for (int i = 0; i < 3; ++i) {
        ss << dist(gen);
    }
    ss << '-';

    ss << dist_variant(gen);
    for (int i = 0; i < 3; ++i) {
        ss << dist(gen);
    }
    ss << '-';

    for (int i = 0; i < 12; ++i) {
        ss << dist(gen);
    }

    return ss.str();
}