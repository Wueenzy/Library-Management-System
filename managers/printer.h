#include "book.h"
using namespace std;

class Printer{
    int tab;
    string tabS = "\t";
public:
    Printer();
    void print(string);
    void input(string);
    void error(string);
    void tabPlus();
    void tabMinus();
    void displayBook(Book);
};

Printer::Printer() {

}

void Printer::print(string str) {
    string first = "[+] ";
    string sonuc = first + str;
    if(tab != 0){
        for(int i = 0; i < tab; i++){
            sonuc = tabS + sonuc;
        }
    }
    cout << sonuc << endl;
}

void Printer::input(string str) {
    string first = "[*] ";
    string sonuc = first + str;
    if(tab != 0) {
        for (int i = 0; i < tab; i++) {
            sonuc = tabS + sonuc;
        }
    }
    cout << sonuc;
}

void Printer::error(string str) {
    string first = "[-] ";
    string sonuc = first + str;
    if(tab != 0){
        for(int i = 0; i < tab; i++){
            sonuc = tabS + sonuc;
        }
    }
    cout << sonuc << endl;
}

void Printer::tabPlus() {
    tab++;
}

void Printer::tabMinus() {
    tab--;
}

void Printer::displayBook(Book book) {
    string numberOfReadings = to_string(book.getNumberOfReadings());
    print("UUID: " + book.getUUID());
    print("Name: " + book.getName());
    print("Author: " + book.getAuthor());
    if(book.getAvailable() == true){
        print("Available: true");
    }else{
        print("Available: false");
    }
    print("Issue Data: " + book.getIssueDate());
    print("Expire Date: " + book.getExpireDate());
    print("Number Of Readings: " + numberOfReadings);
    cout << endl;
    cout << "-----------------------------" << endl;
    cout << endl;
}