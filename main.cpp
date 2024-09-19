#include "managers/library.h"
#include <ctime>
#include <cstdlib>
using namespace std;
Library library;
vector<Book> books = library.getLibrary();
Printer printer;

tm stringToTime(const string& timeStr){
    tm tm = {};
    istringstream ss(timeStr);
    ss >> get_time(&tm, "%Y-%m-%d %H:%M:%S");
    return tm;
}

void starterGUI(){
    int choice;
    int i = 0;
    bool _exit = true;
    bool _globalExit = true;
    bool _globalError = true;
    string input;
    string input2;
    time_t currentTime = time(nullptr);
    tm* localTime = localtime(&currentTime);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localTime);
    string timeString(buffer);
    tm tm1 = stringToTime(timeString);
    tm tm2;

    time_t time_t1 = mktime(&tm1);
    time_t time_t2;

    localTime->tm_mon += 1;

    if(localTime->tm_mon > 11){
        localTime->tm_mon = 0;
        localTime->tm_year += 1;
    }

    time_t newTime = mktime(localTime);

    char buffer2[80];
    strftime(buffer2, sizeof(buffer2), "%Y-%m-%d %H:%M:%S", localTime);

    string expireTimeString(buffer2);

    while(_exit){
        printer.print("1. Display Books");
        printer.print("2. Issue Book");
        printer.print("3. Return Book");
        printer.print("4. Add Book");
        printer.print("5. Search Book");
        printer.print("6. Remove Book");
        printer.print("7. Display Outdated Issued Books");
        printer.print("8. Clear console");
        printer.print("9. Exit");
        printer.input("Enter your choice: ");
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (choice) {
            case 1:
                printer.tabPlus();
                for(const Book& oth : books){
                    printer.displayBook(oth);
                }
                printer.tabMinus();
                break;
            case 2:
                printer.tabPlus();
                _globalExit = true;
                while(_globalExit) {
                    printer.input("Enter the Name of the book you want to issue: ");
                    getline(cin, input);
                    if(input == "exit"){
                        _globalExit = false;
                        break;
                    }
                    _globalError = true;
                    for(Book& oth : books){
                        if(oth.getName() == input){
                            if(oth.getAvailable()){
                                printer.print("Book issued successfully!");
                                _globalExit = false;
                                _globalError = false;
                                oth.setAvailable(false);
                                oth.setIssueDate(timeString);
                                oth.setExpireDate(expireTimeString);
                            }else{
                                printer.error("This book is already issued. Issue Date: " + oth.getIssueDate() + "; Expire Date: " + oth.getExpireDate());
                                _globalError = false;
                            }
                        }
                    }
                    if(_globalError){
                        printer.error("There is no such book here!");
                    }
                }
                printer.tabMinus();
                break;
            case 3:
                printer.tabPlus();
                _globalExit = true;
                while(_globalExit) {
                    printer.input("Enter the Name of the book you want to return: ");
                    getline(cin, input);
                    if(input == "exit"){
                        _globalExit = false;
                        break;
                    }
                    _globalError = true;
                    for(Book& oth : books){
                        if(oth.getName() == input){
                            if(!oth.getAvailable()){
                                printer.print("Book returned successfully!");
                                _globalExit = false;
                                _globalError = false;
                                oth.setAvailable(true);
                                oth.setIssueDate("Alinmadi");
                                oth.setExpireDate("Alinmadi");
                            }else{
                                printer.error("This book is not issue.");
                                _globalError = false;
                            }
                        }
                    }
                    if(_globalError){
                        printer.error("There is no such book here!");
                    }
                }
                printer.tabMinus();
                break;
            case 4:
                printer.tabPlus();
                _globalExit = true;
                while(_globalExit){
                    bool exit = false;
                    printer.input("Enter the title of the book: ");
                    getline(cin, input);
                    printer.input("Enter the author of the book: ");
                    getline(cin, input2);
                    if(sizeof(input) > 0 && sizeof(input2) > 0){
                        exit = true;
                        Book book = library.addBook(input, input2);
                        books.push_back(book);
                        printer.tabPlus();
                        printer.print("Book added successfully!");
                        printer.displayBook(book);
                        printer.tabMinus();
                    }
                    if(exit){
                        _globalExit = false;
                    }else{
                        printer.error("We are use string here!");
                    }
                }
                printer.tabMinus();
                break;
            case 5:
                printer.tabPlus();
                _globalExit = true;
                while(_globalExit){
                    printer.input("Enter the attribute to search by (e.g., name, author, available): ");
                    getline(cin, input);
                    if(input == "name"){
                        printer.input("Enter the value for name: ");
                        getline(cin, input);
                        for(const Book& oth : books){
                            if(input == oth.getName()){
                                printer.print("Book: ");
                                printer.tabPlus();
                                printer.displayBook(oth);
                                printer.tabMinus();
                            }
                        }
                    }else if(input == "author"){
                        printer.input("Enter the value for name: ");
                        getline(cin, input);
                        for(const Book& oth : books){
                            if(input == oth.getAuthor()){
                                printer.print("Book: ");
                                printer.tabPlus();
                                printer.displayBook(oth);
                                printer.tabMinus();
                            }
                        }
                    }else if(input == "available"){
                        printer.input("Enter the value for name: ");
                        getline(cin, input);
                        string available;
                        for(const Book& oth : books){
                            if(oth.getAvailable()){
                                available = "true";
                            }else{
                                available = "false";
                            }
                            if(input == available){
                                printer.print("Book: ");
                                printer.tabPlus();
                                printer.displayBook(oth);
                                printer.tabMinus();
                            }
                        }
                    }else if(input == "exit"){
                        _globalExit = false;
                        break;
                    }
                }
                printer.tabMinus();
                break;
            case 6:
                printer.tabMinus();
                printer.print("Enter the Name of the book you want to remove: ");
                getline(cin, input);
                i = 0;
                for(const Book& oth : books){
                    if(oth.getName() == input){
                        printer.tabPlus();
                        printer.displayBook(oth);
                        printer.tabMinus();
                        printer.input("Are you sure you want to remove this book? (y/n): ");
                        getline(cin, input2);
                        if(input2 == "y"){
                            books.erase(books.begin() + i);
                            printer.print("Book removed successfully!");
                        }else if(input2 == "n"){
                            printer.print("Book was not removed.");
                        }
                    }
                    i++;
                }
                printer.tabPlus();
                break;
            case 7:
                printer.tabPlus();
                for(const Book& oth : books){
                    if(oth.getExpireDate() != "null") {
                        tm2 = stringToTime(oth.getExpireDate());
                        time_t2 = mktime(&tm2);
                        if (time_t1 > time_t2) {
                            printer.displayBook(oth);
                        }
                    }
                }
                printer.tabMinus();
                break;
            case 8:
                system("cls");
                break;
            case 9:
                _exit = false;
                break;
            default:
                break;
        }
    }
}

int main() {
    starterGUI();

    return 0;
}
