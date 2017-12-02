#include "FightScreen.h"

void FightScreen()
{
    srand(time(NULL));
    CPersona hppersona;
    CEnemigo hpenemigo;

    int vidaoriginal = hppersona.get_vida();
    int random;
    int Mrandom;
    int poder;
    ////////////////////////////declaraciones y pantalla//////////////////////////////
    int x = 60;
    int pos = x;
    random = rand()%3;
    Mrandom = rand()%1;
    RenderWindow window(VideoMode(1024, 600), "The Wheel of fate is turning!!");
    //Sprites: inicio//////////////////////////////////////////////////////////////
    Texture Ptexture;
    Sprite PikachuImage;
    if(!Ptexture.loadFromFile("backP.png")) {}
    PikachuImage.setTexture(Ptexture);
    PikachuImage.setPosition(30,180);
    PikachuImage.setScale(0.6,0.4);

    Texture Bk;
    if(!Bk.loadFromFile("battleB.png")) {}
    Sprite BkImage(Bk);
    BkImage.setScale(1.8,1.3);
    BkImage.setPosition(-20,0);


    Texture tTexture;
    Sprite TriSprite;

   if (random == 0)
    {
        if(!tTexture.loadFromFile("pingpong.png")) {}
        TriSprite.setTexture(tTexture);
        TriSprite.setPosition(600,40);
        TriSprite.setScale(sf::Vector2f(0.15,0.1));

    }
    if (random == 1)
    {
        if(!tTexture.loadFromFile("barcelo.png")) {}
        TriSprite.setTexture(tTexture);
        TriSprite.setPosition(650,40);
        TriSprite.setScale(sf::Vector2f(0.5,0.5));

    }
    if (random == 2)
    {
        if(!tTexture.loadFromFile("waifu.png")) {}
        TriSprite.setTexture(tTexture);
        TriSprite.setPosition(650,30);
        TriSprite.setScale(sf::Vector2f(0.7,0.5));

    }
    if (random == 3)
    {
        if(!tTexture.loadFromFile("dota_logo.png")) {}
        TriSprite.setTexture(tTexture);
        TriSprite.setPosition(600,40);
        TriSprite.setScale(sf::Vector2f(0.3,0.3));

    }


    RectangleShape rectangle(sf::Vector2f(120, 50));
    rectangle.setSize(sf::Vector2f(1024, 100));
    rectangle.setPosition(0,400);

    CircleShape triangulito (25,3);
    triangulito.rotate(90);
    triangulito.setPosition(x,525);

    RectangleShape vidaR (sf::Vector2f(120,50));
    vidaR.setFillColor(Color::Green);
    vidaR.setPosition(200,200);
    vidaR.setSize(sf::Vector2f(hppersona.get_vida(),20));


    RectangleShape vidaeR (sf::Vector2f(120,50));
    vidaeR.setFillColor(Color::Green);
    vidaeR.setPosition(500,80);
    vidaeR.setSize(sf::Vector2f(hpenemigo.get_vidae(),20));

    //Sprites: Final////////////////////////////////////////////////////////////

    //Musica: Inicio///////////////////////////////////////////////////////////
    srand(time(NULL));
    sf::Music BM;
    if(Mrandom == 0)
        if (!BM.openFromFile("PKm_trapp.wav")) {}
    if(Mrandom == 1)
        if(!BM.openFromFile("Bmusic.wav"))
    BM.setLoop(true);
    BM.play();

    SoundBuffer buffer;
    if (!buffer.loadFromFile("Punch.wav")){}
    Sound punch;
    punch.setBuffer(buffer);
    //Musica: FIN//////////////////////////////////////////////////////////////

    //Texto: Inicio////////////////////////////////////////////////////////////
    Font font;
    if (!font.loadFromFile("Pixel_font.ttf")) {}

    sf::Text log;
    sf::Text Fight;
    sf::Text Defend;
    sf::Text RUN;

    Fight.setFont(font);
    Fight.setString("FIGHT");
    Fight.setCharacterSize(75);
    Fight.setColor(Color::White);
    Fight.setPosition(75,485);

    Defend.setFont(font);
    Defend.setString("DEFEND");
    Defend.setCharacterSize(75);
    Defend.setColor(Color::White);
    Defend.setPosition(500,485);

    RUN.setFont(font);
    RUN.setString("RUN");
    RUN.setCharacterSize(75);
    RUN.setColor(Color::White);
    RUN.setPosition(900,485);

    log.setFont(font);
    log.setString("Una distracción apareció!");
    log.setCharacterSize(80);
    log.setColor(Color::Black);
    log.setPosition(15,375);
    //TEXTO: FINAL /////////////////////////////////////////////////////////////////////

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
                    if(Event.key.code == sf::Keyboard::Right)
                    {
                        if(pos < 600)
                        {
                            pos += 400;
                            triangulito.move(400,0);
                            break;
                        }
                    }
                    else if (Event.key.code == Keyboard::Left)
                    {
                        if (pos > 60)
                        {
                            pos -= 400;
                            triangulito.move(-400,0);
                            break;
                        }
                    }
                    else if (Event.key.code == Keyboard::Z)
                    {
                        if (pos == 60)
                        {
                            int random = rand()%10;
                            cout << endl <<random << endl;
                            poder = hppersona.get_atk() - hpenemigo.get_dfse() - random;
                            cout << "Tu poder es: " << poder << endl;
                            punch.play();
                            if (poder <= 0)
                                hpenemigo.setvidae(hpenemigo.get_vidae()-1);
                            else if (poder > 0)
                                hpenemigo.setvidae(hpenemigo.get_vidae()-poder);
                            vidaeR.setSize(sf::Vector2f(hpenemigo.get_vidae(),20));
                            sleep_until(system_clock::now() + 0.25s);
                            log.setString("Kchimbo realizo un ataque!");
                            vidaR.setSize(sf::Vector2f(hppersona.get_vida(),20));
                            sleep_until (system_clock::now()+0.5s);
                            log.setString("La distracción te ataca!");
                            random = rand()%10;
                            cout << endl <<random << endl;
                            poder = hpenemigo.get_atke() - hppersona.get_dfs() - random;
                            cout << "Tu enemigo tiene poder:  " << poder << endl;
                            punch.play();
                            hppersona.setvida(hppersona.get_vida()-poder);
                            vidaeR.setSize(sf::Vector2f(hppersona.get_vida(),20));
                            if (hpenemigo.get_vidae()>45)
                            {
                                vidaeR.setFillColor(Color::Blue);
                                break;
                            }
                            if (hpenemigo.get_vidae()<45 && hpenemigo.get_vidae() > 0)
                            {
                                vidaeR.setFillColor(Color::Red);
                                break;
                            }
                            if (hpenemigo.get_vidae()<=0)
                            {
                                vidaeR.setPosition(10000,100000);
                                log.setString("Ganaste !!");
                                sleep_until (system_clock::now()+2s);
                                int xp = experiencia(hpenemigo.get_atke(),hpenemigo.get_dfse());
                                hppersona.setxp(xp + hppersona.get_xp());
                                cout << endl << "XP: " << hppersona.get_xp();
                                hppersona.setvida(vidaoriginal);
                                if (hppersona.get_xp() >= hppersona.get_xpmax())
                                {
                                    log.setString("Subiste de nivel!");
                                    cout << endl << "Subiste de nivel!";
                                    hppersona.setvida(vidaoriginal+15);
                                    hppersona.aumento_nivel();
                                    cout << endl << "Tu nivel es: " << hppersona.get_nivel();
                                    hppersona.setatk(hppersona.get_atk()+ 10);
                                    hppersona.setdfs(hppersona.get_dfs()+10);
                                    hppersona.setxpmax(hppersona.get_xpmax()*1.5);
                                    cout << endl << "Tu XP maxima es: " << hppersona.get_xpmax();
                                    hppersona.setxp(0);
                                }
                                BM.stop();
                                window.close();
                                break;
                            }
                            if (hppersona.get_vida()<=0)
                            {
                                vidaR.setPosition(10000,100000);
                                log.setString("GG");
                                BM.stop();
                                Gameover();
                                break;
                            }
                            break;
                        }
                        else if(pos == 460)
                        {
                            log.setString("Te defiendes!");
                            random = rand()%10;
                            int poder = hpenemigo.get_atke() - hppersona.get_dfs() - random;
                            if (poder <= 0){}
                            else
                                hppersona.setvida((hppersona.get_vida()- (poder)/2));
                            vidaR.setSize(sf::Vector2f(hppersona.get_vida(),20));
                            if (hppersona.get_vida()>45)
                            {
                                vidaR.setFillColor(Color::Blue);
                                break;
                            }
                            if (hppersona.get_vida()<45 && hppersona.get_vida() > 0)
                            {
                                vidaR.setFillColor(Color::Red);

                                break;
                            }
                            if (hppersona.get_vida()<=0)
                            {
                                vidaR.setPosition(10000,100000);
                                log.setString("GG");
                                BM.stop();
                                Gameover();
                                break;
                            }
                            break;
                        }
                        else if (pos == 860)
                        {
                            BM.stop();
                            window.close();
                            break;
                        }
                    }
                    break;
                }
            }
            window.setSize(sf::Vector2u(700,600));
            window.clear();
            window.draw(BkImage);
            window.draw(PikachuImage);
            window.draw(rectangle);
            window.draw(log);
            window.draw(Fight);
            window.draw(Defend);
            window.draw(RUN);
            window.draw(triangulito);
            window.draw(vidaR);
            window.draw(vidaeR);
            window.draw(TriSprite);
            window.display();


    }
}
