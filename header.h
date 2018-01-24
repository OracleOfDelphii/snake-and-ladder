#ifndef GAME_H
#define GAME_H
#endif // GAME_H
extern "C"
{
#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"
}
#include <iostream>
#include <string>
#include <limits.h>
#include <random>
#include <ctime>
#include <map>
#include <unistd.h>
#include <ctime>
#include <climits>
#include <fstream>
#include <cstring>
#include <vector>
#include "algorithm.h"
#include <queue>
#include <QDir>
#include <QString>
struct data{
struct board{
    int holder[10000];
};

struct player{
std::string name[15000];
int cell[15000];
bool Play_Permit[15000];

}
;
}
;

int digit_count(int n);
void nsleep(int n);
void PUSH_FORWARD(int nrows);
void make_ladder_snake(int nrows , data::board &board , std::map<int , std::string> &graphical , int snake_count , int ladder_count);
bool save_game( data::player &player , data::board &board, std::map< int , std::string> &graphical , std::vector <int> &dist ,  int &num_player , int &nrows , int &snake_count , int &ladder_count);
bool load_game( data::player& player , data::board &board , std::map <int , std::string> &graphical , std::vector <int> &dist , int &num_player , int &nrows , int &snake_count , int &ladder_count);
void initialize_table(int player_id  , int nrows , std::map<int , std::string> &graphical , data::board &board , data::player player , int sleep , int from , int to);
bool make_table(int n);
