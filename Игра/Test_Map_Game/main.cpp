#include <SFML/Graphics.hpp>
using namespace sf;


const int H=12;
const int W=40;

String TileMap[H] = {

"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"B                                    B",
"B                                    B",
"B                                    B",
"B                                 BBBB",
"B              000               B   B",
"B                               B    B",
"B                              B     B",
"BBB                          BBBB    B",
"B                            B       B",
"B             B            B         B",
"BBBBBBBB  BBBBBBBBBBBBBBBBBBBBBBBBBBBB",

};



int main()
{
    RenderWindow window(VideoMode(1280, 680), "Game!");
    Clock clock;
    CircleShape shape(15.f);;
    //rectangle.setSize(sf::Vector2f(15, 15));


    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if(event.type == Event::Closed)
                window.close();
        }

        window.clear();

        for(int i=0; i<H;i++)
            for(int j=0; j<W;j++)
        {
            if (TileMap[i][j]=='B') shape.setFillColor(Color::Red);
            if (TileMap[i][j]=='0') shape.setFillColor(Color::Green);
            if (TileMap[i][j]==' ') continue;
            shape.setPosition(j*15,i*15);
            window.draw(shape);
        }
      //  for(int i=0; i<H;i++)
           /* for(int j=0; j<W;j++)
        {shape.setPosition(j*15,0);
        window.draw(shape);}*/
        window.display();
    }

    return 0;
}
