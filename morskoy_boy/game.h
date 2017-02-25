#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <vector>
#include <string>

using namespace std;
///----------------------------------------------------------------------------

class GameHelper
{
public:
    string input;
    vector< vector<string> > setLocation();
    string getUserInput(bool p_swap);
    void playerOutput(string o,bool p_swap);
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
    bool player_swap=false;
    void finishGame (bool,bool);
public:
    void startPlaying();
    void gameSetUp();
};




#endif // GAME_H_INCLUDED
