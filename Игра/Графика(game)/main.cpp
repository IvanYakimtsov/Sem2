
#include"Map.h";
using namespace sf;
int ground=680,time_gost_dont_touch=0;
float offsetX=0,offsetY=0;

class PLAYER
{
public:
    float dx,dy;
    FloatRect rect;
    bool onGround,check=true,life=true,d_enem=0;
    Sprite sprite;
    float currentFrame;
    PLAYER(Texture &image)
    {
        sprite.setTexture(image);
        sprite.setTextureRect(IntRect(18,252,70,112));
        rect = FloatRect(1000,400,70,112);
        dx=dy=0;
        currentFrame = 0;
    }
    void update(float time)
    {
        rect.left+=dx*time;
        Collision(0);
        if(!onGround)
        {
            dy=dy+0.0005*time;
        }
        rect.top+=dy*time;
        onGround=false;
        Collision(1);
        if(dy!=0)
        {
            sprite.setTextureRect(IntRect(102,3,60,120));
        }
        if(onGround)
        {
            if(check) sprite.setTextureRect(IntRect(18,255,82,120));
            else sprite.setTextureRect(IntRect(107,255,82,120));
        }
        if (rect.top>ground)
        {
            rect.top = ground;
            dy=0;
            onGround = true;
        }
        currentFrame+=0.005*time;
        if(currentFrame > 6) currentFrame -=6;
        if(dx>0)
        {
            sprite.setTextureRect(IntRect(83*int(currentFrame),0,82,120)),check=1;;
        }
        if(dx<0)
        {
            sprite.setTextureRect(IntRect(83*int(currentFrame)+83,0,-82,120)),check=0;;
        }

        sprite.setPosition(rect.left-offsetX,rect.top-offsetY);
        dx=0;
        if(d_enem){time_gost_dont_touch+=0.25*time;}
        if(time_gost_dont_touch>7) {time_gost_dont_touch=0;d_enem=0;}
    }
    void Collision(int dir)
    {
        for(int i=rect.top/32; i<(rect.top+rect.height)/32; i++)
            for(int j= (rect.left)/32; j<(rect.left+rect.width)/32; j++)
            {
                if (TileMap[i][j]=='B' || TileMap[i][j]=='b' || TileMap[i][j]=='E')
                {
                    if (dx>0 && dir ==0) rect.left = j*32 - rect.width;
                    if (dx<0 && dir ==0) rect.left = j*32 + 32;
                    if (dy>0 && dir ==1)
                    {
                        rect.top = i*32 - rect.height;
                        dy=0;
                        onGround=true;
                    }
                    if (dy<0 && dir ==1)
                    {
                        rect.top = i*32 + 32;
                        dy=0;
                    }

                }
               if (TileMap[i][j]=='g') d_enem=true;
               if (TileMap[i][j]=='c') TileMap[i][j]=' ';



            }
    }


};









class ENEMY
{

public:
    float dx,dy;
    FloatRect rect;
    Sprite sprite;
    float currentFrame;
    bool life,check=false;


    void set(Texture &image, int x, int y)
    {
        sprite.setTexture(image);
        sprite.setTextureRect(IntRect(15,14,100,160));
        rect = FloatRect(x,y,10,100);

        dx=0.05;  //**
        dy=0.05;
        currentFrame = 0;
        life=true;
    }

    void update(float time,int kx, int ky,bool l,bool l_g)
    {   if(l_g) life=0;
        if(!l_g) life=true;
        if(l && life)
        {if(rect.left<kx)
        {
            rect.left += dx * time;
        }
        else
        {
            rect.left -= dx * time;
        }
        if(rect.top<ky)
        {
            rect.top += dy * time;
        }
        else
        {
            rect.top -= dy * time;
        }
        }
        else
        {  if(!l && !check) {rect.top=ky-15;rect.left=kx+20; check=true;}
            if(abs(rect.left-kx)<1000 || abs(rect.top-ky)<1000) //смерть персанажа или призрака
        {
        {if(rect.left<kx)
        {
            rect.left -= dx * time;
        }
        else
        {
            rect.left += dx * time;
        }
        if(rect.top<ky)
        {
            rect.top -= dy * time;
        }
        else
        {
            rect.top += dy * time;
        }}}}


        //анимация

        currentFrame += time * 0.005;
          if(rect.left>kx )
        {
        switch (int(currentFrame))
            {
               case 0:{sprite.setTextureRect(IntRect(17, 13, 100,160));sprite.setScale(1, 1);break;}
               case 1:{sprite.setTextureRect(IntRect(162, 13, 100,160));sprite.setScale(1, 1);break;}
               case 2:{sprite.setTextureRect(IntRect(17, 205, 100,160));sprite.setScale(1, 1);break;}
               case 3:{sprite.setTextureRect(IntRect(162, 205, 100,160));sprite.setScale(1, 1);break;}
               case 4:{sprite.setTextureRect(IntRect(17, 400, 100,160));sprite.setScale(1, 1);break;}
               case 5:{sprite.setTextureRect(IntRect(162, 400, 100,160));sprite.setScale(1, 1);break;}
               default: currentFrame=0;
            }}
          if(rect.left<kx )
        {
                  switch (int(currentFrame))
            {
               case 0:{sprite.setTextureRect(IntRect(17, 13, 100,160));sprite.setScale(-1, 1);break;}
               case 1:{sprite.setTextureRect(IntRect(162, 13, 100,160));sprite.setScale(-1, 1);break;}
               case 2:{sprite.setTextureRect(IntRect(17, 205, 100,160));sprite.setScale(-1, 1);break;}
               case 3:{sprite.setTextureRect(IntRect(162, 205, 100,160));sprite.setScale(-1, 1);break;}
               case 4:{sprite.setTextureRect(IntRect(17, 400, 100,160));sprite.setScale(-1, 1);break;}
               case 5:{sprite.setTextureRect(IntRect(162, 400, 100,160));sprite.setScale(-1, 1);break;}
               default: currentFrame=0;
            }
        }
            sprite.setPosition(rect.left - offsetX, rect.top - offsetY);

        }

    };




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
