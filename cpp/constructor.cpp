#include <iostream>
#include <cmath>

using namespace std;

class student{
public:
    string name;
    int roll;
    double cgpa;

    //Non-parameterized constructor
    /*student(){
        name = "Debashish Chakraborty";
        roll = 23701034;
        cgpa = 3.5;
    }*/
    
    //parameterized constructor
    student(string NAME,int ROLL,double CGPA){
        name = NAME;
        roll = ROLL;
        cgpa = CGPA;
    }

    void Introduce_Yourself(){     //functions in class are methods
        cout<<"My name is: "<<name<<endl;
        cout<<"My roll is: "<<roll<<endl;
    }
    double show_result(){
        cout<<"My cgpa is: "<<cgpa<<endl;
        return cgpa;
    }
};

int main(){
    //declare objects without parameters
    /*student a,b;
    a.Introduce_Yourself();
    a.show_result();
    b.Introduce_Yourself();
    b.show_result();*/

    student a = student("Debashish", 23701034, 3.5); //declare objects with parameters
    a.Introduce_Yourself();
    a.show_result();
    student b = student("Miskat",23701053,3.8);
    b.Introduce_Yourself();
    b.show_result();
}