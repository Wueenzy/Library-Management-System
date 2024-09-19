#include "loaders.h"
#include "printer.h"
#include "uuidGenerator.h"
using namespace std;

class Library{
    BootLoader loader;
    UUIDG generator;
    vector<Book> _book;
public:
    Library();
    vector<Book> getLibrary() const;
    Book addBook(string name, string author);
};

Library::Library() {
    auto jsonData = loader.parseSimpleJSON("C:\\Users\\wueen\\CLionProjects\\jsonParser\\resource\\books.json");

    for(const auto& obj : jsonData) {
        Book book;
        for (const auto &pair: obj) {
            if(pair.first == "uuid"){
                book.setUUID(pair.second);
            }else if(pair.first == "name"){
                book.setName(pair.second);
            }else if(pair.first == "author"){
                book.setAuthor(pair.second);
            }else if(pair.first == "available"){
                if(pair.second == "true"){
                    book.setAvailable(true);
                }else{
                    book.setAvailable(false);
                }
            }else if(pair.first == "issue_date"){
                book.setIssueDate(pair.second);
            }else if(pair.first == "expire_date"){
                book.setExpireDate(pair.second);
            }else if(pair.first == "number_of_readings"){
                string str = pair.second;
                int num = stoi(str);
                book.setNumbersOfReadings(num);
            }
        }
        _book.push_back(book);
    }
}

vector<Book> Library::getLibrary() const {
    return _book;
}

Book Library::addBook(string name, string author) {
    Book book;
    book.setUUID(generator.getUUID());
    book.setName(name);
    book.setAuthor(author);
    book.setAvailable(true);
    book.setIssueDate("Alinmadi");
    book.setExpireDate("Alinmadi");
    book.setNumbersOfReadings(0);
    return book;
}
