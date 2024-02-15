#include <iostream>
using namespace std;

class Book {
    string name, author;
    int isbnNumber, totalPages, pagesRead;

    public :
        Book() {
            name = "Book 1", author = "Umar", isbnNumber = 23, totalPages = 350, pagesRead = 150;
        }

        Book(string n, string aut, int isbnNum, int totalPageCount, int totalPagesRead) {
            name = n, author = aut, isbnNumber = isbnNum, totalPages = totalPageCount, pagesRead = totalPagesRead;
        }

        void checkPagesRead() {
            if(pagesRead == totalPages) cout << "You have finished the book" << endl;
            else cout << totalPages-pagesRead << " pages are left" << endl;
        }
};

int main() {

    Book b1;
    b1.checkPagesRead();

    Book b2("Book 2", "Talha", 45, 300, 300);
    b2.checkPagesRead();

    return 0;
}
