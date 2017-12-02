#include "GG.h"

void Gameover()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "GAME OVER");
 /////////////////////////////////////////////////sprites//////////////////////////////
    sf::Texture Texam;
    if(!Texam.loadFromFile("examen_jalado.jpg")){}
    sf::Sprite exam;
    exam.setTexture(Texam);
    exam.setScale(sf::Vector2f(0.4,0.75));
///////////////////////////////////////////////////////fonts////////////////////
    sf::Font font;
    if(!font.loadFromFile("Finition.ttf")){}
    sf::Text GG;
    GG.setFont(font);
    GG.setString("te fuiste en BIKA Boi!");
    GG.setCharacterSize(65);
    GG.setColor(sf::Color::Black);
    GG.setPosition(40,200);

    sf::Music gg;
    if (!gg.openFromFile("GameOver.wav")) {}
    gg.setLoop(true);
    gg.play();


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(exam);
        window.draw(GG);
        window.display();
    }

}
