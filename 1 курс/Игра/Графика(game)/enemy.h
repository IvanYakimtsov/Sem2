#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include"Map.h";


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




#endif // ENEMY_H_INCLUDED
