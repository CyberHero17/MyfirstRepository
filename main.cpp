#include <SFML/Window.hpp>
#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include </home/alex/Desktop/Pepper/Player.hpp>
//#include </home/alex/Desktop/Pepper/map.hpp>
using namespace sf;

int main()
{
    
    Player p(360.0f, 360.0f, 82.0f, 82.0f);
    RenderWindow window(VideoMode(640, 480), "SpaceCat");
    view.reset(FloatRect(0, 0, 640, 480));
    
    float CurrentFrame = 0;

    Image map_img;
    map_img.loadFromFile("/home/alex/Desktop/stuff/tilemap.png");
    Texture map;
    map.loadFromImage(map_img);
    Sprite map_sprite;
    map_sprite.setTexture(map);

    while (window.isOpen())
    {
        Event event;
        // Блок времени 
        Clock clock;
        float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
        clock.restart(); //перезагружает время
        time = time/800;
        /*bool shift = false;*/
        // Блок окна
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed){
                window.close();
            }
        }
        // Блок анимации 
        CurrentFrame += 200*time;
        /*std::cout << CurrentFrame << '\n'; */
		if (CurrentFrame > 3) CurrentFrame -= 3;
		p.sprite.setTextureRect(IntRect(0, 0, p.W, p.H)); 
        // Блок движения 
        if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) {
            p.xspeed = -2500.0f;
            // p.sprite.setScale(-0.64f, 0.64f);
            if (CurrentFrame > 3) CurrentFrame -= 3; 
		    p.sprite.setTextureRect(IntRect(p.W * int(CurrentFrame), 3.0f*p.H + 2.0f, p.W, p.H+2.0f));
            getCordsForView(p.getX(), p.getY());
        }
        if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
            p.xspeed = 2500.0f;
            // p.sprite.setScale(0.64f, 0.64f);
            if (CurrentFrame > 3) CurrentFrame -= 3; 
		    p.sprite.setTextureRect(IntRect(p.W * int(CurrentFrame), p.H, p.W, p.H)); 
            getCordsForView(p.getX(), p.getY());
        }

        if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
            //p.xspeed = 0.0f;
            p.yspeed = -2500.0f;
            if (CurrentFrame > 3) CurrentFrame -= 3; 
		        p.sprite.setTextureRect(IntRect(p.W * int(CurrentFrame), 2.0f*p.H, p.W, p.H)); 
            getCordsForView(p.getX(), p.getY());

        }
        if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) {
            //p.xspeed = 0.0f;
            p.yspeed = 2500.0f;
            if (CurrentFrame > 3) CurrentFrame -= 3; 
		        p.sprite.setTextureRect(IntRect(p.W * int(CurrentFrame), 0.0f, p.W, p.H));
            getCordsForView(p.getX(), p.getY());
        }
        p.update(time);
        window.setView(view);
        window.clear(/*Color::Green*/);
        // Рисовка карты 
        for (int i = 0; i < HEIGHT_MAP; i++)
            for (int j = 0; j < WIDTH_MAP; j++)
            {
                if (TileMap[i][j] == ' ')  map_sprite.setTextureRect(IntRect(512, 0, 256, 256)); 
                if ((TileMap[i][j] == '0')) map_sprite.setTextureRect(IntRect(0, 0, 256, 256));

                if (TileMap[i][j] == '1')  map_sprite.setTextureRect(IntRect(256, 0, 256, 256)); 
                if ((TileMap[i][j] == '2')) map_sprite.setTextureRect(IntRect(768, 0, 256, 256));

                if (TileMap[i][j] == '3')  map_sprite.setTextureRect(IntRect(1024, 0, 256, 256)); 
                if ((TileMap[i][j] == '4')) map_sprite.setTextureRect(IntRect(1280, 0, 256, 256));
                
                if (TileMap[i][j] == '5')  map_sprite.setTextureRect(IntRect(1536, 0, 256, 256)); 
                if ((TileMap[i][j] == '6')) map_sprite.setTextureRect(IntRect(1792, 0, 256, 256));
                
                if (TileMap[i][j] == '7')  map_sprite.setTextureRect(IntRect(2048, 0, 256, 256)); 
                if ((TileMap[i][j] == '8')) map_sprite.setTextureRect(IntRect(2304, 0, 256, 256));
                
                if (TileMap[i][j] == '9')  map_sprite.setTextureRect(IntRect(2560, 0, 256, 256)); 
                if ((TileMap[i][j] == 'A')) map_sprite.setTextureRect(IntRect(2816, 0, 256, 256));
                
                if (TileMap[i][j] == 'B')  map_sprite.setTextureRect(IntRect(3072, 0, 256, 256)); 
                if ((TileMap[i][j] == 'C')) map_sprite.setTextureRect(IntRect(3328, 0, 256, 256));
                
                if (TileMap[i][j] == 'D')  map_sprite.setTextureRect(IntRect(3584, 0, 256, 256)); 
                if ((TileMap[i][j] == 'E')) map_sprite.setTextureRect(IntRect(3840, 0, 256, 256));

                map_sprite.setPosition(j * 256, i * 256);
                window.draw(map_sprite);
            }
        window.draw(p.sprite);

        window.display();
    }    
    return 0;
}