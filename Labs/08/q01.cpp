#include <iostream>
using namespace std;

class Book {
    string title, author, publisher;
    
    public : 
        Book(string title, string author, string publisher) : title(title), author(author), publisher(publisher) {}
        
        void display() {
            cout << "Title : " << title << endl << "Author : " << author << endl << "Publisher : " << publisher << endl;
        }
};

class FictionBook : public Book {
    string genre, protagonist;
    
    public : 
        FictionBook(string title, string author, string publisher, string genre, string protagonist) : Book(title, author, publisher), genre(genre), protagonist(protagonist) {}
        
        void display() {
            Book::display();
            cout << "Genre : " << genre << endl << "Protagonist : " << protagonist << endl;
        }
};

int main() {
    FictionBook fb("Book1", "Author1", "Umar", "Fiction", "Umar");
    fb.display();
    
    return 0;
}
