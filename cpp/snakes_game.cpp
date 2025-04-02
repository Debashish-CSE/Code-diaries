#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class Player{
public:
    int id;
    int current_position;

    Player(int Id){
        id = Id;
        current_position = 0;
    }

    int throw_dice(){
        time_t t;
        srand((unsigned) time(&t));
        int random = rand()%6 +1;
        cout <<"Player "<<id<<" has throw: "<<random<<endl;
        return random;
    }
    void move_position(int threw){
        current_position += threw;
        if (current_position > 100){
            current_position -= threw;
            cout <<"Cannot move"<<endl;
        }
    }
    void show_position(){
        cout<<"Current position of Player "<<id<<" is: "<<current_position<<endl;
    }

    bool win(){
        if(current_position == 100){
            cout<<"Player "<<id<<" has won"<<endl;
            return true;
        }
        return false;
    }

};

int main(){
    Player a1 = Player(1);
    Player a2(2), a3(3), a4(4);
    
    bool game_on = true;
    while(1){
        if(game_on == false) break;
        for (int i=1; i<=4; i++){
            if(i == 1){
                int number = a1.throw_dice();
                a1.move_position(number);
                a1.show_position();
                if(a1.win()) game_on = false;
            }
            if(i == 2){
                int number = a2.throw_dice();
                a2.move_position(number);
                a2.show_position();
                if(a2.win()) game_on = false;
            }
            if(i == 3){
                int number = a3.throw_dice();
                a3.move_position(number);
                a3.show_position();
                if(a3.win()) game_on = false;
            }
            if(i == 4){
                int number = a4.throw_dice();
                a4.move_position(number);
                a4.show_position();
                if(a4.win()) game_on = false;
            }
            
        }
    }


    
}