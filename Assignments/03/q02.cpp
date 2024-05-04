#include <iostream>

using namespace std;

template <class T>
class Pet {
    T name;
    int age;
    
    public :
        Pet(T name, int age) : name(name), age(age) {}
        
        virtual void makeSound() = 0;
        
        void display() {
            cout << "Name : " << name << endl << "Age : " << age << endl;
        }
};

template <class T>
class Cat : public Pet<T> {
    public :
        Cat(T name, int age) : Pet<T>(name, age) {}
    
        void makeSound() {
            cout << "Sound : Meow" << endl;
        }
};

template <class T>
class Dog : public Pet<T> {
    public :
        Dog(T name, int age) : Pet<T>(name, age) {}
    
        void makeSound() {
            cout << "Sound : Woof" << endl;
        }
};

template <class T>
class Bird : public Pet<T> {
    public :
        Bird(T name, int age) : Pet<T>(name, age) {}
    
        void makeSound() {
            cout << "Sound : Chirp" << endl;
        }
};

int main() {
    Pet<string>* pet;
    
    Cat<string> cat("Cat", 7);
    Dog<string> dog("Dog", 4);
    Bird<string> bird("Bird", 3);
    
    pet = &cat;
    pet->display(), pet->makeSound();
    
    cout << endl;
    
    pet = &dog;
    pet->display(), pet->makeSound();
    
    cout << endl;
    
    pet = &bird;
    pet->display(), pet->makeSound();

    return 0;
}
