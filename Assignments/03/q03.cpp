#include <iostream>

using namespace std;

template <class T>
class Matrix {
    protected : 
        T** matrix;
        int rows, cols;
    
    public :
        Matrix(int rows, int cols) : rows(rows), cols(cols) {
            matrix = new T*[rows];
            
            for(int i = 0; i < rows; i++) {
                matrix[i] = new T[cols];
            }
        }
        
        void setElement(int row, int col, T value) {
            matrix[row][col] = value;
        }
        
        T getElement(int row, int col) {
            return matrix[row][col];
        }
        
        T** operator+(Matrix<T> &matrix2) {
            T** result = new T*[this->rows];
            
            for(int i = 0; i < this->rows; ++i) {
                result[i] = new T[this->cols];
                for(int j = 0; j < this->cols; ++j) {
                    result[i][j] = matrix[i][j] + matrix2.matrix[i][j];
                }
            }
            
            return result;
        }
        
        T** operator-(Matrix<T> &matrix2) {
            T** result = new T*[this->rows];
            
            for(int i = 0; i < this->rows; ++i) {
                result[i] = new T[this->cols];
                for(int j = 0; j < this->cols; ++j) {
                    result[i][j] = this->matrix[i][j] - matrix2.matrix[i][j];
                }
            }
            
            return result;
        }
        
        T** operator*(Matrix<T> &matrix2) {
            T** result = new T*[this->rows];
            
            for(int i = 0; i < this->rows; ++i) {
                result[i] = new T[matrix2.cols];
                for(int j = 0; j < matrix2.cols; ++j) {
                    for(int k = 0; k < this->cols; ++k) {
                        result[i][j] += this->matrix[i][k] * matrix2.matrix[k][j];
                    }
                }
            }
            
            return result;
        }
        
        virtual void display() const = 0;
        
        ~Matrix() {
            for(int i = 0; i < rows; i++) {
                delete [] matrix[i];
            }
            delete [] matrix;
        }
};

class IntMatrix : public Matrix<int> {
    public :
        IntMatrix(int rows, int cols) : Matrix<int>(rows, cols) {}
        
        void display() const {
            for(int i = 0; i < rows; i++) {
                for(int j = 0; j < cols; j++) {
                    cout << this->matrix[i][j] << " ";
                }
                cout << endl;
            }
        }
};

class DoubleMatrix : public Matrix<double> {
    public :
        DoubleMatrix(int rows, int cols) : Matrix<double>(rows, cols) {}
        
        void display() const {
            for(int i = 0; i < rows; i++) {
                for(int j = 0; j < cols; j++) {
                    cout << this->matrix[i][j] << " ";
                }
                cout << endl;
            }
        }
};

template <class T>
void display(T** matrix, int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

template <class T>
void dealloacteArray(T** matrix, int rows) {
    for(int i = 0; i < rows; i++) {
        delete [] matrix[i];
    }
    delete [] matrix;
}

int main() {
    IntMatrix intMatrix1(3, 3);
    IntMatrix intMatrix2(3, 3);

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            intMatrix1.setElement(i, j, i + j + 3);
            intMatrix2.setElement(i, j, i + j + 1);
        }
    }
    
    cout << "Integer Matrix 1 : " << endl;
    intMatrix1.display();
    
    cout << endl << "Integer Matrix 2 : " << endl;
    intMatrix2.display();
    
    int** intAddition = intMatrix1 + intMatrix2;
    int** intSubtraction = intMatrix1 - intMatrix2;
    int** intMultiplication = intMatrix1 * intMatrix2;
    
    cout << endl << "After adding integer matrices :" << endl;
    display(intAddition, 3, 3);
    
    cout << endl << "After subtracting integer matrices :" << endl;
    display(intSubtraction, 3, 3);
    
    cout << endl << "After multiplying integer matrices :" << endl;
    display(intMultiplication, 3, 3);
    
    DoubleMatrix doubleMatrix1(2, 2);
    DoubleMatrix doubleMatrix2(2, 2);

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            doubleMatrix1.setElement(i, j, i + j * 3.3);
            doubleMatrix2.setElement(i, j, i + j * 1.7);
        }
    }
    
    cout << endl << "Double Matrix 1 : " << endl;
    doubleMatrix1.display();
    
    cout << endl << "Double Matrix 2 : " << endl;
    doubleMatrix2.display();
    
    double** doubleAddition = doubleMatrix1 + doubleMatrix2;
    double** doubleSubtraction = doubleMatrix1 - doubleMatrix2;
    double** doubleMultiplication = doubleMatrix1 * doubleMatrix2;
    
    cout << endl << "After adding double matrices :" << endl;
    display(doubleAddition, 2, 2);
    
    cout << endl << "After subtracting double matrices :" << endl;
    display(doubleSubtraction, 2, 2);
    
    cout << endl << "After multiplying double matrices :" << endl;
    display(doubleMultiplication, 2, 2);
    
    dealloacteArray(intAddition, 3), dealloacteArray(intSubtraction, 3), dealloacteArray(intMultiplication, 3);
    dealloacteArray(doubleAddition, 2), dealloacteArray(doubleSubtraction, 2), dealloacteArray(doubleMultiplication, 2);

    return 0;
}
