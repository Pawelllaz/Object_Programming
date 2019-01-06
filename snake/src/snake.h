#ifndef __SNAKE_H__
#define __SNAKE_H__

#include "winsys.h"
#include "cpoint.h"
#include "screen.h"
#include <vector>
#include <time.h>
#include <stdlib.h>

class CSnake:public CFramedWindow
{
private:
  std::vector <CPoint> snake;  
  int score;
  int err_count;
  int game_on;
  int wall;
  int food_flag;
  CPoint food;
  CPoint add;
  int over;
  int help_window;

public:
  CSnake(CRect r, char _c = ' ');
  
  //	game support
  bool handleEvent(int);
  void add_segm();
  void crash();

  //	prints
  void paint();
  void print_snake();
  void print_food();
  void game_over();
  void print_lvl();

  //	move
  void move_snake();

  void move_up();
  void move_down();
  void move_left();
  void move_right();

  bool moving_up_down();
  bool moving_l_r();
 
  //	food
  void create_food();
  void get_food();
  void eat();
};

#endif
