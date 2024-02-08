#include <iostream>
using namespace std;

struct Book {
    string title, author, genre;
    int year;
    
    void inputDetails() {
        cout << "Enter book title : ";
        cin >> title;
        
        cout << "Enter book author : ";
        cin >> author;
        
        cout << "Enter book genre : ";
        cin >> genre;
        
        cout << "Enter year of publication : ";
        cin >> year;
    }
    
    void outputDetails() {
        cout << "Title :\t" << title << endl << "Author : " << author << endl << "Genre : " << genre << endl << "Year of Publication : " << year << endl;
    }
};

void menu(int totalBooks) {
    cout << "Choose any option from following" << endl << "\t1. Add book or books" << endl << "\t2. Update any book" << endl << "\t3. Display all books" << endl << "\t4. Exit" << endl;
}

int addBooks(Book books[1000], int totalBooks) {
    int morebooks;
    cout << endl << "Enter number of books : ";
    cin >> morebooks;
    
    for(int i = totalBooks; i < totalBooks+morebooks; i++) {
        cout << endl << "Enter details of book " << i+1 << endl;
        books[i].inputDetails();
    }
    
    return totalBooks+morebooks;
}

void displayBooks(Book books[1000], int totalBooks) {
    for(int i = 0; i < totalBooks; i++) {
        cout << endl << "Details of book " << i+1 << endl;
        books[i].outputDetails();
    }
}

void findAndUpdateBook(Book books[1000], int totalBooks) {
    
    string titleOrAuthor;
    cout << endl << "Enter the title or author of the book : ";
    cin >> titleOrAuthor;
    
    for(int i = 0; i < totalBooks; i++) {
        if(books[i].title == titleOrAuthor || books[i].author == titleOrAuthor) {
            cout << endl << "Enter new details of this book" << endl;
            books[i].inputDetails();
            return;
        }
    }
    
    cout << endl << "Book with such title or author not found" << endl;
}

int main(){
    
    Book books[1000];
    
    int totalBooks = 0;
    
    while(true) {
        menu(totalBooks);
        int choice;
        cout << "Choice : ";
        cin >> choice;
        
        switch(choice) {
            case 1 :
                totalBooks = addBooks(books, totalBooks);
                break;
            case 2 : 
                findAndUpdateBook(books, totalBooks);
                break;
            case 3 : 
                displayBooks(books, totalBooks);
                break;
            case 4 : 
            default : 
                return 0;
        }
        cout << endl;
    }
}
