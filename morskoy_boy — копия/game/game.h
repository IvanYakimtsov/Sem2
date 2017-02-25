#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <vector>
#include <string>
#include <math.h>

using namespace std;
///----------------------------------------------------------------------------

class GameHelper
{
public:
    vector< vector<string> > setLocation();
};

class Ship
{
private:
    vector<string> locationCells;
public:
    void setShip(vector<string>);
    string checkYourself(string);
};


class Player
{
private:
    vector<Ship> ShipList;
    bool loose=false;
public:
    void setShip(vector< vector<string> >);
    string checkUserGuess(string);
    bool checkLoose();
};






class GameBust
{
private:
    GameHelper *helper = new GameHelper();
    Player *player1 = new Player();
    Player *player2 = new Player();
    bool player1_loose = false;
    bool player2_loose = false;
    int coord_X,coord_Y;
    bool player_swap=false;
public:
    string startCalc(int,int);
    void gameSetUp();
    int get_X();
    int get_Y();
};




#endif // GAME_H_INCLUDED
