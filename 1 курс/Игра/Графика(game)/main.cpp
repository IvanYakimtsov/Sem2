#include"player.h";
#include"enemy.h"

    int main()
    {

        bool game_over=false;
        RenderWindow window(VideoMode(1280, 680), "Game!");

        Texture t,tileSet,backgr,enem1,g_over,tileSet1,tileSet2;

        backgr.loadFromFile("Background01.png");
        Sprite background(backgr);
        background.setTextureRect(IntRect(0,0,1280,680));

        tileSet.loadFromFile("Tiles.png");
        Sprite tile(tileSet);

        tileSet1.loadFromFile("View.png");
        Sprite tile1(tileSet1);


        g_over.loadFromFile("GameOver.png");
        Sprite GameOver(g_over);
        GameOver.setTextureRect(IntRect(0,0,1280,680));
        GameOver.setPosition(170,100);

        t.loadFromFile("sprite.png");
        PLAYER p(t);

        ENEMY  enemy1;
        enem1.loadFromFile("Ghost_Standby2.png");
        enemy1.set(enem1,40,400);


        Music music;
        music.openFromFile("1.ogg");
        music.play();

        Clock clock;


        while (window.isOpen())
        {
            float time=clock.getElapsedTime().asMicroseconds();
            clock.restart();
            time=time/400;
            Event event;
            while (window.pollEvent(event))
            {
                if(event.type == Event::Closed)
                    window.close();
            }
            if(p.life)
            {if (Keyboard::isKeyPressed(Keyboard::Left))
            {
                p.dx = -0.07;

            }
            if (Keyboard::isKeyPressed(Keyboard::Right))
            {
                p.dx = 0.07;

            }
            if (Keyboard::isKeyPressed(Keyboard::Up))
            {
                if(p.onGround)
                {
                    p.dy=-0.4;
                    p.onGround=false;
                }
            }
            }
            if (Keyboard::isKeyPressed(Keyboard::R) && !p.life)
            {
              game_over=false;
              enemy1.check=false;
              p.d_enem=0;
              enemy1.life=true;
              enemy1.rect.left=40;
              enemy1.rect.top=400;
              p.rect.left=1000;
              p.rect.top=380;
              p.life=true;
              p.sprite.setColor(Color::White);
            }
            p.update(time);
            enemy1.update(time,p.rect.left,p.rect.top,p.life,p.d_enem);

            if(p.rect.intersects(enemy1.rect) && enemy1.life)
            {
              p.life=0;
              p.sprite.setColor(Color::Red);
              game_over=true;

            }

            if(p.rect.left>1280/2)offsetX=p.rect.left-1280/2;
            if(p.rect.top>680/1.5)offsetY=p.rect.top-680/1.25;

            window.clear();

            if(!game_over) window.draw(background);
            for(int i=0; i<H; i++)
                for(int j=0; j<W; j++)
                {
                    if (TileMap[i][j]=='B') tile.setTextureRect(IntRect(704,1714,32,32));
                    if (TileMap[i][j]=='0') tile.setTextureRect(IntRect(710,1170,123,110));
                    if (TileMap[i][j]=='1') tile.setTextureRect(IntRect(578,1159,123,110));
                    if (TileMap[i][j]=='E') tile.setTextureRect(IntRect(704,1714,32,32));
                    if (TileMap[i][j]=='h') tile.setTextureRect(IntRect(590,0,186,256));
                    if (TileMap[i][j]==' ') continue;
                    if (TileMap[i][j]=='g') continue;
                    if (TileMap[i][j]=='b') continue;
                    tile.setPosition(j*32-offsetX,i*32-offsetY);
                    if(!game_over) window.draw(tile);
                }
            for(int i=0; i<H; i++)
                for(int j=0; j<W; j++)
                {
                    if (TileMap[i][j]=='c') tile1.setTextureRect(IntRect(203,203,50,50));
                    if (TileMap[i][j]=='B') continue;
                    if (TileMap[i][j]=='0') continue;
                    if (TileMap[i][j]=='1') continue;
                    if (TileMap[i][j]=='E') continue;
                    if (TileMap[i][j]=='h') continue;
                    if (TileMap[i][j]==' ') continue;
                    if (TileMap[i][j]=='g') continue;
                    if (TileMap[i][j]=='b') continue;
                    tile1.setPosition(j*32-offsetX,i*32-offsetY);
                    if(!game_over)  window.draw(tile1);
                }


            if(!game_over) window.draw(p.sprite);

            if(game_over) window.draw(GameOver);

            window.draw(enemy1.sprite);
            window.display();
        }

        return 0;
    }
