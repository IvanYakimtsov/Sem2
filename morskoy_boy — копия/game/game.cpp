#include <iostream>
#include "game.h"

using namespace std;


void GameBust::gameSetUp()
{
    for(int i=0; i<2; i++)
    {
        if(!player_swap)
        {
            player1->setShip(helper->setLocation());
            player_swap=true;
        }
        else
        {
            player2->setShip(helper->setLocation());
            player_swap=false;
        }
    }

}
string GameBust::startCalc(int x, int y)
{
    string output,tmp;
    string userGuess;
    int X=0,Y=0;
    if(player_swap)
    {
        if(x>34 && x<415 && y>30 && y<410)
        {
            X = ceil((x-33)/38.0);
            X--;
            Y = ceil((y-31)/38.0);
            Y--;
            coord_X = (X+1)*38+33-21;
            coord_Y = (Y+1)*38+31-21;
            userGuess = char(X) + 48;
            tmp = char(Y) + 48;
            userGuess.insert(1,tmp);
        }
        else return "tryAgain";
    }
    else
    {
        if(x>498 && x<879 && y>30 && y<410)
        {
            X = ceil((x-498)/38.0);
            X--;
            Y = ceil((y-31)/38.0);
            Y--;
            coord_X = (X+1)*38+498-21;
            coord_Y = (Y+1)*38+31-21;
            userGuess = char(X) + 48;
            tmp = char(Y) + 48;
            userGuess.insert(1,tmp);
        } else return "tryAgain";
    }



    if(!player_swap)
    {
        output = player2->checkUserGuess(userGuess);
        player2_loose = player2->checkLoose();
        if(output == "miss") player_swap = true;
        if(player2_loose) output = "p1win";
    }
    else
    {
        output = player1->checkUserGuess(userGuess);
        player1_loose = player1->checkLoose();
        if(output == "miss")player_swap = false;
        if(player1_loose) output = "p2win";
    }

    return output;

}
int GameBust::get_X()
{
    return coord_X;
}
int GameBust::get_Y()
{
    return coord_Y;
}







vector< vector<string> > GameHelper::setLocation()
{
    vector< vector<string> > a(10);
    a[0].push_back("01");
    a[0].push_back("11");
    a[1].push_back("07");
    a[2].push_back("14");
    a[2].push_back("24");
    a[2].push_back("34");
    a[2].push_back("44");
    a[3].push_back("40");
    a[3].push_back("50");
    a[3].push_back("60");
    a[4].push_back("82");
    a[5].push_back("26");
    a[6].push_back("29");
    a[7].push_back("56");
    a[7].push_back("57");
    a[8].push_back("85");
    a[8].push_back("86");
    a[8].push_back("87");
    a[9].push_back("89");
    a[9].push_back("99");
    return a;
}




void Ship::setShip(vector<string> l)
{
    locationCells = l;
}
string Ship::checkYourself(string guess)
{
    if(locationCells.empty()) return "drawned";
    string result = "miss";
    for(int i=0; i<locationCells.size(); i++)
    {
        if(locationCells[i] == guess)
        {
            result = "hit";
            locationCells.erase(locationCells.begin()+i);
            break;
        }
    }
    if(locationCells.empty()) result = "drawned";
    return result;
}







void Player::setShip(vector< vector<string> > a)
{
    for(int i=0; i<10; i++)
    {
        Ship *s = new Ship();
        s->setShip(a[i]);
        ShipList.push_back(*s);
    }
}
string Player::checkUserGuess(string Guess)
{
    string result = "miss";
    for(int i=0; i<ShipList.size(); i++)
    {
        result = ShipList[i].checkYourself(Guess);
        if(result == "drawned")
        {
            ShipList.erase(ShipList.begin()+i);
            break;
        }
        if(result == "hit")
        {
            break;
        }
    }
    return result;
}



bool Player::checkLoose()
{
    if(ShipList.empty()) loose = true;
    return loose;
}
