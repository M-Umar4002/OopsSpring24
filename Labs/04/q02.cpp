#include <iostream>
using namespace std;

class Book {
    string name, author;
    int isbnNumber, totalPages, pagesRead;

    public :
        Book() {
            name = "Book 1", author = "Umar", isbnNumber = 23, totalPages = 1000, pagesRead = 0;
        }

        Book(string n, string aut, int isbnNum, int totalPageCount, int totalPagesRead) {
            name = n, author = aut, isbnNumber = isbnNum, totalPages = totalPageCount, pagesRead = totalPagesRead;
        }

        void setName(string n) {
            name = n;
        }

        void setAuthor(string aut) {
            author = aut;
        }

        void setIsbnNumber(int isbnNum) {
            isbnNumber = isbnNum;
        }

        void setTotalPages(int totalPageCount) {
            totalPages = totalPageCount;
        }

        void setPagesRead(int totalPagesRead) {
            pagesRead = totalPagesRead;;
        }

        void showBookInfo() {

        }
};

int main() {

    Book b1;
    // b1.checkPagesRead();

    Book b2("Book 2", "Talha", 45, 300, 300);
    // b2.checkPagesRead();

    return 0;
}
