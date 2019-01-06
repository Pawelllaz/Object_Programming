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
  CPoint dimensions;   			// wymiary gry
  int food_flag;
  CPoint food;

public:
  CSnake(CRect r, char _c = ' ');
  bool handleEvent(int);

  void paint();
  void show_snake();
  
  void move_snake();

  void move_up();
  void move_down();
  void move_left();
  void move_right();

  bool moving_up_down();
  bool moving_l_r();
  
  void create_food();
  void print_food();
};

#endif
