#include <SFML/Graphics.hpp>
using namespace sf;

Texture texture;
if (!texture.loadFromFile("/home/alex/Desktop/stuff/main_character.jpeg"))
    return -1;
Sprite sprite;
sprite.setTexture(texture);

