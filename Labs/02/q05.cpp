#include <iostream>
using namespace std;

struct Product {
    string name, id;
    float price;
    int quantity;
};

void menu() {
    cout << "Choose any option from following" << endl << "\t1. Add a product" << endl << "\t2. Update a product" << endl << "\t3. Display a product" << endl << "\t4. Exit" << endl;
}

Product inputProduct() {

    Product product;

    cout << "Enter product name : ";
    cin >> product.name;
    
    cout << "Enter product id : ";
    cin >> product.id;
    
    cout << "Enter product price : ";
    cin >> product.price;
    
    cout << "Enter product quantity : ";
    cin >> product.quantity;
    
    return product;
}

void updateProduct(Product products[100], int totalProducts) {
    string id;
    cout << endl << "Enter the id of the product for which you want to update its data : ";
    cin >> id;
    
    for(int i = 0; i < totalProducts; i++) {
        if(products[i].id == id) {
            cout << endl << "Enter new details of this product" << endl;
            products[i] = inputProduct();
            return;
        }    
    }
    
    cout << endl << "Product with such id not found" << endl;
}

void displayProduct(Product products[100], int totalProducts) {
    string id;
    cout << endl << "Enter the id of the product for which you want all details : ";
    cin >> id;
    
    for(int i = 0; i < totalProducts; i++) {
        if(products[i].id == id) {
            cout << endl << "Details of product " << endl << "Product Name : " << products[i].name << endl << "Product Id : " << products[i].id << endl << "Product Price : " << products[i].price << endl << "Total Quantity of Product : " << products[i].quantity << endl;
            return;
        }
    }
    
    cout << endl << "Product with such id not found" << endl;
}

int main(){
    Product products[100];
    
    int totalProducts = 0;
    
    while(true) {
        menu();
        int choice;
        cout << "Choice : ";
        cin >> choice;
        
        switch(choice) {
            case 1 : 
                cout << endl << "Enter details of product" << endl;
                products[totalProducts++] = inputProduct();
                break;
            case 2 : 
                updateProduct(products, totalProducts);
                break;
            case 3 : 
                displayProduct(products, totalProducts);
                break;
            case 4 : 
            default : 
                return 0;
        }
        cout << endl;
    }
}
