#include <SFML/Window.hpp>
#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include </home/alex/Desktop/Pepper/Player.hpp>
using namespace sf;

int main()
{
    
    Player p(220.0f, 140.0f, 192.0f, 192.0f);
    RenderWindow window(VideoMode(640, 480), "SpaceCat");
    
    //hero.setColor(Color::Transparent);
    float CurrentFrame = 0;
    /*hero.setTextureRect(IntRect(0, 100, 50, 50));*/
    
    while (window.isOpen())
    {
        Event event;
        // Блок времени 
        Clock clock;
        float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
        clock.restart(); //перезагружает время
        time = time/1000;
        /*bool shift = false;*/
        // Блок окна
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed){
                window.close();
                Window(); 
            }
        }
        // Блок анимации 
        CurrentFrame += 60*time;
        /*std::cout << CurrentFrame << '\n';*/
		if (CurrentFrame > 3) CurrentFrame -= 3; 
		p.sprite.setTextureRect(IntRect(192 * int(CurrentFrame), 0, 192, 192)); 

        // Блок движения 
        if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) {
            p.xspeed = -2250.0f;
            p.sprite.setScale(-1.0f, 1.0f);
            //p.yspeed = 0.0f;
        }
        if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
            p.xspeed = 2250.0f;
            p.sprite.setScale(1.0f, 1.0f);
            //p.yspeed = 0.0f;
        }
        if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
            //p.xspeed = 0.0f;
            p.yspeed = -2250.0f;
        }
        if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) {
            //p.xspeed = 0.0f;
            p.yspeed = 2250.0f;
        }

        p.update(time);
        window.clear(Color::White);
        window.draw(p.sprite);
        window.display();
    }
    return 0;
}