#include "snake.h"

CSnake::CSnake(CRect r, char _c /*=' '*/):
  CFramedWindow(r, _c)
{
  score = 0;
  err_count = 0;
  game_on = 0;

  if(initsnake())
  {
    gotoyx(geom.topleft.y+3, geom.topleft.x+3);
    printl("blad gry");
  }
}
/////////////////////////////////////////////////////////
bool CSnake::handleEvent(char key)
{
  switch (key)
    {
    case ERR:
      err_count++;
      if(err_count == 10 - score/3 || score > 30)
      {
	move_snake();
	err_count = 0;
      }
      return true;
    case 'p':
      gotoyx(geom.topleft.y+10,geom.topleft.x+5);
      printl("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
      game_on = !game_on;
      if(!game_on)
        if(CFramedWindow::handleEvent(key))
      return true;
    case 'r':
      CSnake(CRect (CPoint (5, 5), CPoint (45, 20)));
      return true;
    case KEY_UP:
      move (CPoint (0, -1));
      return true;
    case KEY_DOWN:
      move (CPoint (0, 1));
      return true;
    case KEY_RIGHT:
      move (CPoint (1, 0));
      return true;
    case KEY_LEFT:
      move (CPoint (-1, 0));
      return true;
    };
  return false;
}
/////////////////////////////////////////////////////////
void CSnake::paint()
{
  if(game_on)
    show_snake();
  else
  {
    CFramedWindow::paint();
    int i=3;
    gotoyx(geom.topleft.y+i++,geom.topleft.x+3);
    printl("h - toogle help information");
    gotoyx(geom.topleft.y+i++,geom.topleft.x+3);
    printl("p - toogle play/pause mode");
    gotoyx(geom.topleft.y+i++,geom.topleft.x+3);
    printl("r - restart game");
    gotoyx(geom.topleft.y+i++,geom.topleft.x+3);
    printl("arrows - move snake (in play mode) or");
    gotoyx(geom.topleft.y+i++,geom.topleft.x+3);
    printl("       - move window (in pause mode)");
  }
}
///////////////////////////////////////////////////////
int CSnake::initsnake()
{
  snake.clear();
  snake.push_back({18,10});
  snake.push_back({19,10});
  snake.push_back({20,10});
  if(snake.empty()) return 1;
  return 0;
}
/////////////////////////////////////////////////////
void CSnake::show_snake()
{
  for(int i = 0; i < snake.size(); i++)
  {
    CPoint p = snake[i];
    gotoyx(geom.topleft.y+p.y, geom.topleft.x+p.x);
    printc('0');
  }
}
///////////////////////////////////////////////////////
void CSnake::move_snake()
{
  CPoint head = snake[0];
  CPoint second_seg = snake[1];
  int x = head.x - second_seg.x;
  int y = head.y - second_seg.y;
  if(y == 0)
  {
    for(int i = snake.size() - 1; i > 0; i++)
    {
      snake.at(i) = snake.at(i-1);
    }
    if(x>0)
    {  
      head.x++;
      snake[0] = head;
    }
    else
    {
      head.x--;
      snake[0] = head;
    }
  }
  else
  {
    for(int i = snake.size() - 1; i > 0; i++)
    {
      snake.at(i) = snake.at(i-1);
    }
    if(y>0)
    {  
      head.y++;
      snake[0] = head;
    }
    else
    {
      head.y--;
      snake[0] = head;
    }
  } 
}
