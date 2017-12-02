#include "Intro.h"

void introduccion()
{
    int y = 220;
    RenderWindow window(VideoMode(600, 400), ":D");
 /////////////////////////////////////////////////sprites//////////////////////////////
    Texture Texam;
    if(!Texam.loadFromFile("BG-UTEC.jpg")){}
    Sprite bg;
    bg.setTexture(Texam);
    bg.setScale(Vector2f(0.4,0.75));
    bg.scale(sf::Vector2f(2.1f, 1.5f));
    CircleShape triangulito(10,3);
    triangulito.rotate(90);
    triangulito.setFillColor(Color::Black);
    triangulito.setPosition(230,y);

///////////////////////////////////////////////////////fonts////////////////////
    Font font;
    if(!font.loadFromFile("Finition.ttf")){}
    Text start;
    Text exit;
    start.setFont(font);
    start.setString("START");
    start.setCharacterSize(40);
    start.setColor(Color::White);
    start.setPosition(250,200);
    exit.setFont(font);
    exit.setString("EXIT");
    exit.setCharacterSize(40);
    exit.setColor(Color::White);
    exit.setPosition(250,300);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            switch(event.type)
                   {
                    case sf::Event::Closed:
                        window.close();
                        break;
                    case sf::Event::KeyPressed:
                        if(event.key.code == sf::Keyboard::Down)
                          {
                            if(y == 220){
                            y +=100;
                            triangulito.move(0,100);
                            break;}
                          }
                        else if (event.key.code == Keyboard::Up)
                        {
                            if (y == 320){
                            y -=100 ;
                            triangulito.move(0,-100);
                            break;}
                        }
                        else if(event.key.code == Keyboard::Z)
                        {
                            if(y==320)
                                window.close();
                            if(y==220)
                            {
                                window.close();
                                Entrada(20,100);
                            }
                            break;
                        }
                   }

        window.clear();
        window.draw(bg);
        window.draw(start);
        window.draw(exit);
        window.draw(triangulito);
        window.display();
      }
    }
}
