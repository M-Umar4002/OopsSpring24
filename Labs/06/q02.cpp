#include <iostream>
#include <cstdlib>
using namespace std;

class Image {
    int height, width;
    int** data;
    
    public :
        Image(int height, int width, int** data) : height(height), width(width) {
            this->data = new int*[height];
            
            for(int i = 0; i < height; i++) this->data[i] = new int[width];
            
            for(int i = 0; i < height; i++) for(int j = 0; j < width; j++) this->data[i][j] = data[i][j];
        }
        
        Image(Image &obj) {
            height = obj.height, width = obj.width;
            
            data = new int*[height];
            
            for(int i = 0; i < height; i++) data[i] = new int[width];
            
            for(int i = 0; i < height; i++) for(int j = 0; j < width; j++) this->data[i][j] = obj.data[i][j];
         
        }
        
        ~Image() {
            for(int i = 0; i < height; i++) delete [] data[i];
            
            delete [] data;
        }
        
        void display() {
            for(int i = 0; i < height; i++) {
                for(int j = 0; j < width; j++) cout << data[i][j] << " ";
                cout << endl;
            }
        }
        
        void updateData() {
            for(int i = 0; i < height; i++) for(int j = 0; j < width; j++) if(data[i][j] <= 0) data[i][j] = (rand() % 255) + 1;
        }
};

int main() {
    
    srand(time(NULL));
    
    int** sampleData = new int*[2];
    
    for(int i = 0; i < 2; i++) sampleData[i] = new int[3];
    
    sampleData[0][0] = 40, sampleData[0][1] = -3, sampleData[0][2] = -2, sampleData[1][0] = -1, sampleData[1][1] = 0, sampleData[1][2] = 155;
    
    Image image(2, 3, sampleData);
    
    Image imageCopy(image);
    
    cout << "Data of both images before updaing" << endl << endl << "Real Image" << endl;
    image.display();
    
    cout << endl << "Copied Image" << endl;
    imageCopy.display();
    
    image.updateData(), imageCopy.updateData();
    
    cout << endl << endl << "Data of both images after updaing" << endl << endl << "Real Image" << endl;
    image.display();
    
    cout << endl << "Copied Image" << endl;
    imageCopy.display();
    
    return 0;
}
