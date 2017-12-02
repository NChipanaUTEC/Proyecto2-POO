#include "Congratulations.h"

void Congratulations () {
    RenderWindow window(VideoMode(1024, 600), ":D");

    Font font;
    if (!font.loadFromFile("Pixel_font.ttf")) {}
    Text Cong;
    Cong.setFont(font);
    Cong.setString("EL CACHIMBO SUPERÓ LO INSUPERABLE Y LOGRÓ LO INIMAGINABLE!");
    Cong.setCharacterSize(55);
    Cong.setColor(Color::Yellow);
    Cong.setPosition(100,250);


    sf::Music BM;
    if (!BM.openFromFile("PKm_trapp.wav")) {}
    BM.setLoop(true);
    BM.play();

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
            window.draw(Cong);
            window.display();
          }
        }
}
