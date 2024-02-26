#include <iostream>
#include <algorithm>
using namespace std;

class ChessPiece {
    string name, color;
    char symbol;

    public:
        ChessPiece() {
            name = "Pawn", color = "white", symbol = 'p';
        }

        ChessPiece(string n, string col, char sym) {
            name = n, color = col, symbol = sym;
        }

        void setName(string n) {
            name = n;
        }

        void setColor(string col) {
            color = col;
        }

        void setSymbol(char sym) {
            symbol = sym;
        }

        string getName() {
            return name;
        }

        string getColor() {
            return color;
        }

        char getSymbol() {
            return symbol;
        }
};

class ChessBoard {
    ChessPiece pieces[8][8];
    
    public:
        ChessBoard(){
            
            // For black pieces
            pieces[0][0] = pieces[0][7] = ChessPiece("Rook", "black", 'R'), pieces[0][1] = pieces[0][6] = ChessPiece("Knight", "black", 'N'), pieces[0][2] = pieces[0][5] = ChessPiece("Bishop", "black", 'B'), pieces[0][3] = ChessPiece("Queen", "black", 'Q'), pieces[0][4] = ChessPiece("King", "black", 'K');
            
            for (int i = 0; i < 8; i++) pieces[1][i] = ChessPiece("Pawn", "black", 'P');
            
            // For white pieces
            pieces[7][0] = pieces[7][7] = ChessPiece("Rook", "white", 'r'), pieces[7][1] = pieces[7][6] = ChessPiece("Knight", "white", 'n'), pieces[7][2] = pieces[7][5] = ChessPiece("Bishop", "white", 'b'), pieces[7][3] = ChessPiece("Queen", "white", 'q'), pieces[7][4] = ChessPiece("King", "white", 'k');
            
            // For all remaining pieces
            for(int i = 2; i < 6; i++) for(int j = 0; j < 8; j++) pieces[i][j] = ChessPiece("", "", '.');
        }

        void display(){
            
            cout << endl << ' ';
            
            for(char i = 'a'; i <= 'h'; i++) cout << "   " << i;
            
            cout << endl << endl;
            
            for(int i = 0; i < 8; i++) {
                cout << 8 - i << "   ";
                for(int j = 0; j < 8; j++){
                    cout << pieces[i][j].getSymbol() << "   ";
                }
                cout << 8 - i << endl << endl;
            }
            
            cout << ' ';
            
            for(char i = 'a'; i <= 'h'; i++) cout << "   " << i;
            
            cout << endl << endl << endl;
        }
        
        bool movePiece(string source, string destination) {
            int sr = 8 - (source[1] - '0'), sc = source[0] - 97, dr = 8 - (destination[1] - '0'), dc = destination[0] - 97;
            
            if(pieces[dr][dc].getSymbol() == '.') {
                if(pieces[sr][sc].getName() == "Pawn") {
                    if(abs(dr-sr) <= 2 && abs(dr-sr) > 0 && dc == sc) {
                        swap(pieces[dr][dc], pieces[sr][sc]);
                        return true;
                    } else cout << "Your move is not valid" << endl;
                } else if(pieces[sr][sc].getName() == "Knight") {
                    if((abs(dr-sr) == 2 && abs(dc-sc) == 1) || (abs(dc-sc) == 2 && abs(dr-sr) == 1)) {
                        swap(pieces[dr][dc], pieces[sr][sc]);
                        return true;
                    } else cout << "Your move is not valid" << endl;
                } else cout << "You can only move pawn or knight" << endl;
            } else cout << "There is already another piece at that place" << endl;
            
            return false;;
        }

};

int main(){
    ChessBoard cb;
    cb.display();
    
    cout << "After valid move for Knight" << endl;
    if(cb.movePiece("b8", "a6")) cb.display();
    
    cout << "After invalid move for Knight" << endl << endl;
    if(cb.movePiece("g1", "f4")) cb.display();
    
    cout << endl << endl << "After valid move for Pawn" << endl;
    if(cb.movePiece("c2", "c4")) cb.display();
    
    cout << "After invalid move for Pawn" << endl << endl;
    if(cb.movePiece("h7", "f5")) cb.display();
    
    return 0;
}
