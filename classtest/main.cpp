//
//  main.cpp
//  classtest
//
//  Created by Magnus Romedahl on 2024-01-01.
//

#include <iostream>
#include <string>

using namespace std;

class Dog {
//private:
    static int totaldogs;
    string name;
    string breed;
    string age;
    string maxSpeed;

public:
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Breed: " << breed << endl;
        cout << "Age: " << age << endl;
    }
    static void display_total_dogs()
    {
        cout << "Total dogs: " << Dog::totaldogs << endl;
    }

    Dog(string dogName = "Unknown", string dogBreed = "Unknown", string dogAge = "Unknown")
    {
        name = dogName; breed = dogBreed; age = dogAge;
        totaldogs++;
    }

    ~Dog()
    {
        totaldogs--;
    }
};

class Car {
public:
    string brand;
    int year;
    int miles;
    
    void print()
    {
        cout << "Miles: " << miles << endl;
    }
    
    void increment_miles()
    {
        miles++;
    }
};

void long_drive(Car &c)
{
    c.increment_miles();
    c.increment_miles();
    c.increment_miles();
}

int Dog::totaldogs = 0;

int main()
{

    Dog* dog1 = new Dog("Buster", "Altesian", "5");
    dog1->display();
    Dog::display_total_dogs();
    delete dog1;
    Dog::display_total_dogs();

    int num_dogs = 10;
    std::vector<Dog*> dogs( num_dogs );
    for ( int i = 0; i < num_dogs; i++ ) {
        string dogstring = "Dog" + to_string(i);
        dogs[i] = new Dog(dogstring, "Pug", "10");
    }
    Dog::display_total_dogs();

    for ( int i = 0; i < num_dogs; i++ ) {
        dogs[i]->display();
    }
    for ( int i = 0; i < num_dogs; i++ ) {
        delete dogs[i];
    }
    Dog::display_total_dogs();
    
    cout << "NÄMEN" << endl;
    
    Car car1;
    
    car1.print();
    
    long_drive(car1);
    
    car1.print();
    
    return 0;
}


