#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
sf::View view;
sf::RenderWindow window;

sf::View getCordsForView(float x, float y){
    float viewX = x;
    float viewY = y;
    if(viewX < 320) viewX = 320;
    if(viewY < 243) viewY = 243;
    if(viewX > 700) viewX = 700;
    if(viewY > 770) viewY = 770;
    view.setCenter(viewX, viewY);
    view.setSize(640, 480);
    return view;
}
