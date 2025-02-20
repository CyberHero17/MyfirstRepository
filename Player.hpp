#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
class Player{
public: 

    float xspeed, yspeed, X, Y, W, H;
    int dx, dy;
    //int dir;
    Texture texture;
    Sprite sprite;

    Player(float x, float y, float w, float h){
        X = x; // Пересобрали координаты
        Y = y;
        W = w;
        H = h;
        xspeed = 0.0f;
        yspeed = 0.0f;
        texture.loadFromFile("/home/alex/Desktop/stuff/Defaultile.png");
        sprite.setTexture(texture);
        sprite.setPosition(x, y);
        sprite.setTextureRect(IntRect(0, 0, w, h));
    }

    void update(float time){ // Тут будет движение - изменение кординат с нажатием клавиш
        if(time < 0.002f){
        X = X + xspeed*time;
		Y = Y + yspeed*time;
    }
        //std::cout << X << '\n' << Y<< "-----" << time<< '\n';

		sprite.setPosition(X,Y); 
        xspeed = 0.0f;
        yspeed = 0.0f;
    }
};