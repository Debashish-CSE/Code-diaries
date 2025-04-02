#include <iostream>

using namespace std;

class Car{
public:
    int max_speed;
    int price;
    string model_name;
    string color;
    int current_speed = 0;
    int acceleration;
    void accelerate(){
        current_speed += acceleration;
        cout<<"The car is accelerating..."<<endl; 
    }
    void horn(){
        cout<<"Beep Beep"<<endl;
    }
    void break_car(){
        current_speed = 0;
        cout<<"The car has stopped."<<endl;
    }
    int show_speed(){
        cout<<"The speed of the car is: "<<current_speed<<endl;
        return current_speed;
    }
};

int main(){
    Car toyota; // Car=>class and toyota=>object
    toyota.current_speed = 0;
    toyota.color = "Red";
    toyota.max_speed = 240;
    toyota.acceleration = 1;
    toyota.model_name = "Corolla";
    toyota.accelerate();
    toyota.accelerate();
    toyota.accelerate();
    cout<<"Current speed is "<<toyota.current_speed<<endl;
    toyota.horn();

}