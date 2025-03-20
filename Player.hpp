#include <SFML/Graphics.hpp>
#include <iostream>
#include </home/alex/Desktop/Pepper/View.hpp>
#include </home/alex/Desktop/Pepper/map.hpp>
using namespace sf;
class Player{
private: 
    float  X, Y;

public: 
    float xspeed, yspeed, W, H;
    int dx, dy;
    Texture texture;
    Sprite sprite;
    Image image;

    Player(float x, float y, float w, float h){

        X = x; // Пересобрали координаты
        Y = y;
        W = w;
        H = h;
        xspeed = 0.0f;
        yspeed = 0.0f;
        image.loadFromFile("/home/alex/Desktop/stuff/dogtile.png");
        image.createMaskFromColor(Color::White);
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.setPosition(x, y);
        sprite.setTextureRect(IntRect(0, 0, w, h));
        sprite.setScale(0.64,0.64);
    }

    void update(float time){ // Тут будет движение - изменение кординат с нажатием клавиш
        if(time < 0.002f){
        X = X + xspeed*time;
		Y = Y + yspeed*time;
    }
        //td::cout << X << '\n' << Y;

		sprite.setPosition(X, Y);
        xspeed = 0.0f;
        yspeed = 0.0f;
        interactionWithMap();//вызываем функцию, отвечающую за взаимодействие с картой
    }
    float getX(){
        return X;
    }
    float getY(){
        return Y;
    }
    void interactionWithMap()
	{

	}
};