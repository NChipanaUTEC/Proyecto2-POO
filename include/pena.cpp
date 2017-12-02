#include "pena.h"


void Pena()
{
    CPersona hppersona;
    CPena hpenemigo;
    int vidaoriginal = hppersona.get_vida();
    int vidapena = hpenemigo.get_vidae();
    ////////////////////////////declaraciones y pantalla//////////////////////////////
    int x = 60;
    int pos = x;
    RenderWindow window(VideoMode(1024, 600), "Alexander Peña: Divindidad de las Bicas");
    //Sprites: inicio//////////////////////////////////////////////////////////////
    Texture Ptexture;
    Sprite PikachuImage;
    if(!Ptexture.loadFromFile("backP.png")) {}
    PikachuImage.setTexture(Ptexture);
    PikachuImage.setPosition(30,180);
    PikachuImage.setScale(0.6,0.4);

    Texture Bk;
    if(!Bk.loadFromFile("battlePeña.png")) {}
    Sprite BkImage(Bk);
    BkImage.setScale(1.8,1.3);
    BkImage.setPosition(-20,0);

    Texture Boss;
    if(!Boss.loadFromFile("Peña1.png")){}
    Sprite BossPena(Boss);
    BossPena.setScale(0.25,0.2);
    BossPena.setPosition(600,15);

    Texture tTexture;
    RectangleShape rectangle(sf::Vector2f(120, 50));
    rectangle.setSize(sf::Vector2f(1024, 100));
    rectangle.setPosition(0,400);

    CircleShape triangulito (25,3);
    triangulito.rotate(90);
    triangulito.setPosition(x,525);

    RectangleShape vidaR (sf::Vector2f(120,50));
    vidaR.setFillColor(Color::Green);
    vidaR.setPosition(400,200);
    vidaR.setSize(sf::Vector2f(hppersona.get_vida(),20));


    RectangleShape vidaeR (sf::Vector2f(120,50));
    vidaeR.setFillColor(Color::Green);
    vidaeR.setPosition(100,80);
    vidaeR.setSize(sf::Vector2f(hpenemigo.get_vidae(),20));

    //Sprites: Final////////////////////////////////////////////////////////////

    //Musica: Inicio///////////////////////////////////////////////////////////
    sf::Music BM;
    if (!BM.openFromFile("Bicas.ogg")) {}
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
    log.setString("A la bica dile nica!");
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
                            cout << endl <<hppersona.get_atk() << endl << hpenemigo.get_dfse() << endl << random;
                            int poder = hppersona.get_atk() - hpenemigo.get_dfse() - random;
                            cout << "Tu poder es: "<<poder << endl;
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
                            log.setString("Peña te ataca!");
                            random = rand()% 10;
                            cout << endl <<random << endl;
                            poder = hpenemigo.get_atke() - hppersona.get_dfs() - random;
                            cout << "Su PODER es: " << poder << endl;
                            punch.play();
                            if (poder <= 0)
                                hppersona.setvida(hppersona.get_vida()-1);
                            else if (poder > 0)
                                hppersona.setvida(hppersona.get_vida()-poder);
                            vidaR.setSize(sf::Vector2f(hppersona.get_vida(),20));
                            cout << "TU VIDA ES: "<< hppersona.get_vida() << endl;
                            if (hppersona.get_vida()<=0)
                            {
                                vidaR.setPosition(10000,100000);
                                log.setString("GG");
                                BM.stop();
                                window.close();
                                Gameover();
                                break;
                            }
                            if (hpenemigo.get_vidae()< vidapena/0.6)
                            {
                                vidaeR.setFillColor(Color::Blue);
                                break;
                            }
                            if (hpenemigo.get_vidae() < vidapena/0.6 && hpenemigo.get_vidae()> 0)
                            {
                                vidaeR.setFillColor(Color::Red);
                                break;
                            }
                            if (hpenemigo.get_vidae()<=0)
                            {
                                vidaeR.setPosition(10000,100000);
                                log.setString("Ganaste !!");
                                sleep_until (system_clock::now()+2s);
                                BM.stop();
                                Congratulations();
                                window.close();
                                break;
                            }
                            break;
                        }
                        else if(pos == 460)
                        {
                            int random = rand()%10;
                            cout << endl <<random << endl;
                            int poder = hpenemigo.get_atke() - hppersona.get_dfs() - random;
                            cout << "El poder de Peña es: "<<poder << endl;
                            punch.play();
                            hppersona.setvida((hppersona.get_vida()-poder)/2);
                            vidaeR.setSize(sf::Vector2f(hpenemigo.get_vidae(),20));
                            vidaR.setSize(sf::Vector2f(hppersona.get_vida(),20));
                            if (hpenemigo.get_vidae()< vidapena/0.6)
                            {
                                vidaeR.setFillColor(Color::Blue);
                                break;
                            }
                            if (hpenemigo.get_vidae() < vidapena/0.6 && hpenemigo.get_vidae()> 0)
                            {
                                vidaeR.setFillColor(Color::Red);
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
                           Gameover();


                            break;}
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
                window.draw(BossPena);
                window.draw(vidaR);
                window.draw(vidaeR);
                window.display();
            }
        }

