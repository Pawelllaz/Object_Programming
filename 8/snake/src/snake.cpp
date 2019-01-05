#include "snake.h"
CSnake::CSnake(CRect r, char _c /*=' '*/):
  CFramedWindow(r, _c)
{
  score = 0;
  err_count = 0;
  game_on = 0;
  wall = 0;
  snake.reserve(40);
  snake.push_back({5,3});
  snake.push_back({4,3});
  snake.push_back({3,3});
  int snakesize = snake.size();
}
/////////////////////////////////////////////////////////
bool CSnake::handleEvent(int key)
{
  if(!game_on) 
    if(CFramedWindow::handleEvent(key))
      return true;
  switch (key)
    {
    case 'p':
      gotoyx(geom.topleft.y+1,geom.topleft.x+1);
      game_on = !game_on;
      if(!game_on)
        if(CFramedWindow::handleEvent(key))
          return true;
    case ERR:
      if(game_on)
      {
	err_count++;
        if(err_count == 10 - score/3 || score > 30)
        {
	  move_snake();
	  err_count = 0;
        }
      }
      return true;
    };
  return false;
}
/////////////////////////////////////////////////////////
void CSnake::paint()
{
  CFramedWindow::paint();
  if(game_on)
    show_snake();
  else
  {
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
  /*for(int i = snake.size() - 1; i > 0; i--)
  {
    snake.at(i) = snake.at(i-1);
  }*/
  if(y == 0)
  {
    for(int i = snake.size() - 1; i > 0; i--)
    {
      snake.at(i) = snake.at(i-1);
    }
    if(x>0)
    {  
      head.x++;
      if(head.x + 1 >= geom.size.x) 
      {
	head.x -= geom.size.x;
	head.x += 2;
	wall++;
      }
      snake[0] = head;
    }
    else
    {
      if(wall)
      {
        head.x++;
        if(head.x + 1 >= geom.size.x) 
        {
	  head.x -= geom.size.x;
	  head.x += 2;
	  wall++;
        }
        wall = 0;
      }
      else
      {
        snake[0] = head;
        head.x--;
        snake[0] = head;
      }
    }
  }
  else
  {
    for(int i = snake.size() - 1; i > 0; i--)
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
