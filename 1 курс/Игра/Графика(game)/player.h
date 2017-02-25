#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include"Map.h";

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


#endif // PLAYER_H_INCLUDED
