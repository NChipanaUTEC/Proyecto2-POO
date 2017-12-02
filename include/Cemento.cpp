#include "Cemento.h"

void Entrada(int pos_x, int pos_y)
{
    CPersona per;
    int x;
    string vidaarr[13]= {"NIVEL:0","NIVEL:1","NIVEL:2","NIVEL:3","NIVEL:4","NIVEL:5","NIVEL:6","NIVEL:7","NIVEL:8","NIVEL:9","NIVEL:10","NIVEL:11","NIVEL:12"};
    ///////////////////////////////////Dibujo de los Sprites///////////////////////////////////////////////////////////////
    sf::RenderWindow window(sf::VideoMode(1024, 600), "Bienvenido a tu último día en la UTEC!");
    sf::Texture Pt;
    Pt.loadFromFile("pSprite.png");
    sf::IntRect SpriteBx(0,0,64,64);
    sf::Sprite Psprite(Pt,SpriteBx);
    Psprite.setPosition(pos_x,pos_y);
    sf::Texture MapT1;
    sf::Sprite Map1;
    if(!MapT1.loadFromFile("BG.png")) {}
    Map1.setScale(sf::Vector2f(0.5,0.6));
    Map1.setTexture(MapT1);
    //////////////////////////////musica///////////////////////////////////////////////////////////////////////////////
    sf::Music mii;
    if (!mii.openFromFile("mii_trap.wav")) {}
    mii.play();

////////////////////////////////////TEXTO/////////////////////////////////////////////////////////////////////////////////
    Font font;
    if (!font.loadFromFile("Pixel_font.ttf")) {}

    Text nivellog;
    nivellog.setFont(font);
    nivellog.setString(vidaarr[per.get_nivel()]);
    nivellog.setCharacterSize(75);
    nivellog.setColor(Color::Yellow);
    nivellog.setPosition(800,-20);
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
            {
                window.close();
                break;
            }
            case sf::Event::KeyPressed:
                if(Event.key.code == sf::Keyboard::Down)
                {
                    if(pos_y<500){

                    Psprite.move(0,7);
                    pos_y+=7;
                    x = rand()%10000;
                    if (x>9700)
                    {
                        int posx = Psprite.getPosition().x;
                        int posy = Psprite.getPosition().y;
                        per.setx(posx);
                        per.sety(posy);
                        mii.stop();
                        FightScreen();
                        mii.play();
                    }
                    if (clock.getElapsedTime().asMilliseconds()>32)
                    {
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
                }
                if(Event.key.code == sf::Keyboard::Right)
                {
                    if(pos_x<920){
                    Psprite.move(7,0);
                    pos_x+=7;
                    x = rand()%10000;
                    if (x>9800)
                    {
                        int posx = Psprite.getPosition().x;
                        int posy = Psprite.getPosition().y;
                        per.setx(posx);
                        per.sety(posy);
                        mii.stop();
                        FightScreen();
                        mii.play();
                    }
                    if (clock.getElapsedTime().asMilliseconds()>32)
                    {
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
                }
                if(Event.key.code == sf::Keyboard::Left)
                {
                    if(pos_x>40)
                    {
                        Psprite.move(-7,0);
                        pos_x-=7;
                        x = rand()%10000;
                        if (x>9800)
                        {
                            int posx = Psprite.getPosition().x;
                            int posy = Psprite.getPosition().y;
                            per.setx(posx);
                            per.sety(posy);
                            mii.stop();
                            FightScreen();
                            mii.play();
                        }
                        if (clock.getElapsedTime().asMilliseconds()>32)
                        {
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
                    }
                }
                if(Event.key.code == sf::Keyboard::Up)
                {
                    if(pos_y>80)
                    {
                        pos_y-=7;
                        Psprite.move(0,-7);
                        x = rand()%10000;
                        if (x>9800)
                        {
                            int posx = Psprite.getPosition().x;
                            int posy = Psprite.getPosition().y;
                            per.setx(posx);
                            per.sety(posy);
                            mii.stop();
                            FightScreen();
                            mii.play();
                        }
                        if (clock.getElapsedTime().asMilliseconds()>32)
                        {
                            SpriteBx.top = 192;
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
                        if(pos_y<80 && pos_x>700&&pos_x<900)
                        {
                            mii.stop();
                            window.close();
                            Auditorio(100,150);
                        }
                    }
                }
                window.clear();
                window.draw(Map1);
                window.draw(Psprite);
                window.draw(nivellog);
                window.display();
            }
        }
    }
}

