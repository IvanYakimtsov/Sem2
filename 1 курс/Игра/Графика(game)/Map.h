#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
const int H=25;
const int W=150;
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
int ground=680,time_gost_dont_touch=0;
float offsetX=0,offsetY=0;
using namespace sf;
sf::String TileMap[H] = {

"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
"b                                                                                                                                                      b",
"b                                                                                                                                                      b",
"b                                                                                                                                                      b",
"b                                                                                                                                                      b",
"b                                                                                                                                                      b",
"b                                                                                                                                                      b",
"b                                                   EEEEE                                                                                              b",
"b                                                                                                                                                      b",
"b                                           EEEE                    EEEEE                                                                              b",
"b                                              E                                                                                                       b",
"b                                              E             EEEE          EEEEEEEE   EEEEEEEEEEEEEEEEEEEEEEE                                          b",
"b                                              EEEEEEE                                                                                                 b",
"b                                                                                                                                                      b",
"b                                                             c  c  c  c  c   c    c   c                                                               b",
"b                                                  c  c                                                                                                b",
"b                                                        EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE                  EEEEE                                  b",
"b                                   c c         EEEEEEEEE    E                                         EEEEEEEEEEE E                    h              b",
"b                                            EEE             E                                   EEEEEEEE          E                                   b",
"b                                         EEE                E                                                     E                                   b",
"b                             EEEEEEEEE                      E                                                     E                                   b",
"b         0    1   1          EEEEEEEEE                      E    0      0                                         E                          0        b",
"b                          EEEEEEEEEEEE                      E                                                     E                                   b",
"b                          EEEEEEEEEEEE                      E                                                     E                    ggg            b",
"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",

};


#endif // MAP_H_INCLUDED
