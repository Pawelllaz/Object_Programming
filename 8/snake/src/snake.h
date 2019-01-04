#ifndef __SNAKE_H__
#define __SNAKE_H__

#include "winsys.h"
#include "cpoint.h"
#include "screen.h"
#include <vector>

class CSnake:public CFramedWindow
{
private:
  std::vector <int> snake;  
public:
  CSnake(CRect r, char _c = ' ');
  void paint();
  void game();
  int initsnake();
  void showsnake();
  
};

#endif
