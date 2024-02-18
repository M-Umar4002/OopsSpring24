#include <iostream>
using namespace std;

class Book {
    string name, author;
    int isbnNumber, totalPages, pagesRead;

    public :
        Book() : totalPages(1000), pagesRead(0) {}
    
        void setName(string n) {
            name = n;
        }
        
        void setAuthor(string aut) {
            author = aut;
        }
        
        void setIsbnNum(int isbnNum) {
            isbnNumber = isbnNum;
        }

        void showBookInfo() {
            cout << "Book Name : " << name << endl << "Author name : " << author << endl << "ISBN number : " << isbnNumber << endl << "Total pages of book : " << totalPages << endl << "Pages readed : " << pagesRead << endl;
        }
};

int main() {

    Book b1;
    b1.setName("Book 1"), b1.setAuthor("Umar"), b1.setIsbnNum(23);
    
    cout << "Details of book" << endl;
    b1.showBookInfo();

    return 0;
}
