#include <iostream>
#include <string>
using namespace std;

class Book{
    string _uuid, _name, _author, _issue_date, _expire_date;
    bool _available;
    int _number_of_readings;
public:
    Book();
    void setUUID(string uuid);
    void setName(string name);
    void setAuthor(string author);
    void setAvailable(bool available);
    void setIssueDate(string issue_date);
    void setExpireDate(string expire_date);
    void setNumbersOfReadings(int number_of_readings);
    string getUUID() const;
    string getName() const;
    string getAuthor() const;
    bool getAvailable() const;
    string getIssueDate() const;
    string getExpireDate() const;
    int getNumberOfReadings() const;
};

Book::Book(){

}

string Book::getUUID() const {
    return _uuid;
}

string Book::getName() const {
    return _name;
}

string Book::getAuthor() const {
    return _author;
}

bool Book::getAvailable() const {
    return _available;
}

string Book::getIssueDate() const {
    return _issue_date;
}

string Book::getExpireDate() const {
    return _expire_date;
}

int Book::getNumberOfReadings() const {
    return _number_of_readings;
}

void Book::setUUID(string uuid) {
    _uuid = uuid;
}

void Book::setName(string name) {
    _name = name;
}

void Book::setAuthor(string author) {
    _author = author;
}

void Book::setAvailable(bool available) {
    _available = available;

}

void Book::setIssueDate(string issue_date) {
    _issue_date = issue_date;
}

void Book::setExpireDate(string expire_date) {
    _expire_date = expire_date;
}

void Book::setNumbersOfReadings(int number_of_readings) {
    _number_of_readings = number_of_readings;
}

