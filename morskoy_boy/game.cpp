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
void GameBust::startPlaying()
{
    string userGuess;
    string output;
    while(true)
    {
        if(!player_swap)
        {
            cout<<" ";
            userGuess = helper->getUserInput(player_swap);
            output = player2->checkUserGuess(userGuess);
            helper->playerOutput(output,player_swap);
            player2_loose = player2->checkLoose();
            if(player2_loose) break;
            if(output!="hit" && output!="drawned" && output!="-1") player_swap = true;
        }
        else
        {
            cout<<" ";
            userGuess = helper->getUserInput(player_swap);
            output = player1->checkUserGuess(userGuess);
            helper->playerOutput(output,player_swap);
            player1_loose = player1->checkLoose();
            if(player1_loose) break;
            if(output!="hit" && output!="drawned" && output!="-1")player_swap = false;
        }
    }
    finishGame(player1_loose, player2_loose);


}
void GameBust::finishGame (bool looser1, bool looser2)
{
    if(looser1) cout<<"player 2 win";
    if(looser2) cout<<"player 1 win";
}




vector< vector<string> > GameHelper::setLocation()
{
    vector< vector<string> > a(10);
    a[0].push_back("12");
    a[0].push_back("22");
    a[1].push_back("18");
    a[2].push_back("25");
    a[2].push_back("35");
    a[2].push_back("45");
    a[2].push_back("55");
    a[3].push_back("51");
    a[3].push_back("61");
    a[3].push_back("71");
    a[4].push_back("93");
    a[5].push_back("37");
    a[6].push_back("310");
    a[7].push_back("67");
    a[7].push_back("68");
    a[8].push_back("96");
    a[8].push_back("97");
    a[8].push_back("98");
    a[9].push_back("910");
    a[9].push_back("1010");
    return a;
}
string GameHelper::getUserInput(bool p_swap)
{
    cin>>input;
    return input;
}
void GameHelper::playerOutput(string o,bool p_swap)
{
}




void Ship::setShip(vector<string> l)
{
    locationCells = l;
}
string Ship::checkYourself(string guess)
{
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
    for(int i=0; i<10; i++)
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
    cout<<result;
    return result;
}



bool Player::checkLoose()
{
    if(ShipList.empty()) loose = true;
    return loose;
}
