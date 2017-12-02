#include "Congratulations.h"

void Congratulations () {
    RenderWindow window(VideoMode(600, 400), ":D");

    Font font;
    if (!font.loadFromFile("Pixel_font.ttf")) {}
    Text Cong;
    Cong.setFont(font);
    Cong.setString("EL CACHIMBO SUPERÓ LO INSUPERABLE Y LOGRÓ LO INIMAGINABLE!");
    Cong.setCharacterSize(75);
    Cong.setColor(Color::Yellow);
    Cong.setPosition(300,200);

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
                        }

            window.clear();
            window.display();
            window.draw(Cong);
          }
        }
}
