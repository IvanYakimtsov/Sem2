#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.h"

using namespace sf;


int main()
{
    RenderWindow window(VideoMode(893, 443), "Navy Battleships ");

    Texture background;
    background.loadFromFile("15.png");
    Sprite background_s(background);
    background_s.setTextureRect(IntRect(0,0,900,500));
    GameBust *game = new GameBust();
    game->gameSetUp();
    string output;
    vector<CircleShape> Shapes;
    vector<RectangleShape> RShapes;

    while (window.isOpen())
    {
        Event Event;
        while (window.pollEvent(Event))
        {
            switch (Event.type)
            {
            case Event::Closed:
                window.close();
                break;
            case Event::MouseButtonPressed:
                if(Event.mouseButton.button == Mouse::Left)
                {
                    output=game->startCalc(Event.mouseButton.x,Event.mouseButton.y);
                    //   std::cout<<output<<endl;
                }
                break;
            }
        }
        if(output == "miss")
        {
            CircleShape shape(5.f);
            shape.setFillColor(Color::Red);
            shape.setPosition(game->get_X(),game->get_Y());
            Shapes.push_back(shape);
        }
        if(output == "hit" || output == "drawned")
        {
            RectangleShape Shape(sf::Vector2f(30,30));
            Shape.setFillColor(Color::Red);
            Shape.setPosition(game->get_X()-12,game->get_Y()-12);
            RShapes.push_back(Shape);
        }
        if(output == "p1win" || output == "p2win")
        {
            cout<<output;
            break;
        }
        window.clear();
        window.draw(background_s);
        for(int i=0; i<Shapes.size(); i++) window.draw(Shapes[i]);
        for(int i=0; i<RShapes.size(); i++) window.draw(RShapes[i]);
        window.display();
    }

    return 0;
}
