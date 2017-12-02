#include "Auditorio.h"


void Auditorio(int pos_x, int pos_y)
{
    CPersona hppersona;
        ///////////////////////////////////Dibujo de los Sprites///////////////////////////////////////////////////////////////
        RenderWindow window(sf::VideoMode(1024, 600), "Bienvenido al Quiz de Física");
        Texture Pt;
        Pt.loadFromFile("pSprite.png");
        IntRect SpriteBx(0,0,64,64);
        Sprite Psprite(Pt,SpriteBx);
        Psprite.setPosition(pos_x,pos_y);

        sf::Texture PixelPenaT;
        if(!PixelPenaT.loadFromFile("PixelPeña.png")){}
        sf::Sprite PixelPena;
        PixelPena.setTexture(PixelPenaT);
        PixelPena.setPosition(600,-20);
        PixelPena.setScale(sf::Vector2f(0.4,0.4));

        sf::Texture MapT1;
        sf::Sprite Map1;
        if(!MapT1.loadFromFile("auditorio.png")){}
        Map1.setScale(sf::Vector2f(0.6,0.6));
        Map1.setTexture(MapT1);
         //////////////////////////////musica///////////////////////////////////////////////////////////////////////////////
    Music mii;
    if (!mii.openFromFile("mii_trap.wav")){}
    mii.play();
    mii.setLoop(true);
    /////////////////////////////////Procesos//////////////////////////////////////////////////////////////////////////////
        sf::Clock clock;

        while (window.isOpen())
        {
            sf::Event Event;

                    while (window.pollEvent(Event))
                        {
                         switch(Event.type)
                       {
                        case sf::Event::Closed:
                            window.close();
                            break;
                        case sf::Event::KeyPressed:
                            if(Event.key.code == sf::Keyboard::Down){
                                Psprite.move(0,7);
                                pos_y +=7;
                                if (clock.getElapsedTime().asMilliseconds()>32){
                                SpriteBx.top = 0;
                                if (SpriteBx.left == 192)
                                    SpriteBx.left = 0;
                                else if (SpriteBx.left==64)
                                    SpriteBx.left= 128;
                                else if (SpriteBx.left== 128)
                                    SpriteBx.left= 192;
                                else
                                    SpriteBx.left=64;


                                Psprite.setTextureRect(SpriteBx);
                                clock.restart();
                                }
                                }
                            if(Event.key.code == sf::Keyboard::Right){
                                Psprite.move(7,0);
                                pos_x+=7;
                                if (clock.getElapsedTime().asMilliseconds()>32){
                                SpriteBx.top = 128;
                                if (SpriteBx.left == 192)
                                    SpriteBx.left = 0;
                                else if (SpriteBx.left==64)
                                    SpriteBx.left= 128;
                                else if (SpriteBx.left== 128)
                                    SpriteBx.left= 192;
                                else
                                    SpriteBx.left=64;


                                Psprite.setTextureRect(SpriteBx);
                                clock.restart();
                                }
                                }
                                if(Event.key.code == sf::Keyboard::Left){
                                Psprite.move(-7,0);
                                pos_x-=7;
                                if (clock.getElapsedTime().asMilliseconds()>32){
                                SpriteBx.top = 64;
                                if (SpriteBx.left == 192)
                                    SpriteBx.left = 0;
                                else if (SpriteBx.left==64)
                                    SpriteBx.left= 128;
                                else if (SpriteBx.left== 128)
                                    SpriteBx.left= 192;
                                else
                                    SpriteBx.left=64;


                                Psprite.setTextureRect(SpriteBx);
                                clock.restart();
                                }

                                if(pos_x <5 && pos_y<190&&pos_y>90)
                                {
                                  Entrada(800,100);
                                  mii.stop();
                                }
                                }

                                if(Event.key.code == sf::Keyboard::Up){
                                Psprite.move(0,-7);
                                pos_y-=7;
                                if (clock.getElapsedTime().asMilliseconds()>32)
                                {
                                SpriteBx.top = 195;
                                if (SpriteBx.left == 192)
                                    SpriteBx.left = 0;
                                else if (SpriteBx.left==64)
                                    SpriteBx.left= 128;
                                else if (SpriteBx.left== 128)
                                    SpriteBx.left= 192;
                                else
                                    SpriteBx.left=64;


                                Psprite.setTextureRect(SpriteBx);
                                clock.restart();
                                }
                            }
                            if(Event.key.code == sf::Keyboard::Z){
                                if (pos_x>580 && pos_x<630&& pos_y>20 && pos_y<50){
                                    mii.stop();
                                    window.close();
                                    Pena();}


                            }
                       }
                        window.clear();
                        window.draw(Map1);
                        window.draw(PixelPena);
                        window.draw(Psprite);
                        window.display();
                    }
        }
}
