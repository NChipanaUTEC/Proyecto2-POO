#ifndef PENA_H_INCLUDED
#define PENA_H_INCLUDED
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

#include "CPersona.h"
#include "FIghtSis.h"
#include "CPena.h"
#include "GG.h"
#include "Congratulations.h"

using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;
using namespace sf;

void Pena();
#endif // PENA_H_INCLUDED

