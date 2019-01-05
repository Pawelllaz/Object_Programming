#ifndef __SNAKE_H__
#define __SNAKE_H__

#include "winsys.h"
#include "cpoint.h"
#include "screen.h"
#include <vector>

class CSnake:public CFramedWindow
{
private:
  std::vector <CPoint> snake;  
  int score;
  int err_count;
  int game_on;
public:
  CSnake(CRect r, char _c = ' ');
  void paint();
  bool handleEvent(char);
  int initsnake();
  void show_snake();
  void move_snake
};

#endif
