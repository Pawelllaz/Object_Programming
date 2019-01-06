#include "snake.h"

CSnake::CSnake(CRect r, char _c /*=' '*/):
  CFramedWindow(r, _c)
{
  srand(time(NULL));
  dimensions = r.size;
  score = 0;
  err_count = 0;
  game_on = 0;
  wall = 0;
  food_flag = 0;

  snake.reserve(40);
  snake.push_back({5,3});
  snake.push_back({4,3});
  snake.push_back({3,3});
  create_food();
  
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
    case KEY_UP:
      if(!moving_up_down()) move_up();
      return true;
    case KEY_DOWN:
      if(!moving_up_down()) move_down();
      return true;
    case KEY_RIGHT:
      if(!moving_l_r()) move_right();
      return true;
    case KEY_LEFT:
      if(!moving_l_r()) move_left();
      return true;
    };
  return false;
}
// >>> PAINTING <<<
/////////////////////////////////////////////////////////
void CSnake::paint()
{
  CFramedWindow::paint();
  if(game_on)
  {
    show_snake();
    print_food();
  }
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
void CSnake::print_food()
{
  gotoyx(geom.topleft.y+food.y, geom.topleft.x+food.x);
  printc('+');
}
///////////////////////////////////////////////////////
//		>> MOVING SNAKE <<<
///////////////////////////////////////////////////////
void CSnake::move_snake()
{
  int x = snake[0].x - snake[1].x;
  int y = snake[0].y - snake[1].y;
  
  if(y > 0) 
  {
    if(wall)
    {
      wall=0;
      move_up();
    }
    else move_down();
  }
  if(y < 0)
  {
    if(wall)
    {
      wall=0;
      move_down();
    }
    else move_up();
  }
  if(x > 0) 
  {
    if(wall)
    {
      wall = 0;
      move_left();
    }
    else move_right();
  }
  if(x < 0) 
  {
    if(wall)
    {
      wall = 0;
      move_right();
    }
    else move_left();
  }
}
//////////////////////////////////////////////////////////////////////////
void CSnake::move_up()
{
  CPoint head = snake[0];
  for(int i = snake.size() - 1; i > 0; i--)
  {
    snake.at(i) = snake.at(i-1);
  }
  head.y--;
  if(head.y <= geom.size.y - dimensions.y) 
  {
    head.y += geom.size.y;
    head.y -= 2;
    wall++;
  }
    snake[0] = head;
}
//////////////////////////////////////////////////////////////////////////
void CSnake::move_down()
{
  CPoint head = snake[0];
  for(int i = snake.size() - 1; i > 0; i--)
  {
    snake.at(i) = snake.at(i-1);
  }
  head.y++;
  if(head.y + 1 >= geom.size.y) 
  {
    head.y -= geom.size.y;
    head.y += 2;
    wall++;
  }
    snake[0] = head;
}
////////////////////////////////////////////////////////////////////////////
void CSnake::move_left()
{
  CPoint head = snake[0];
  for(int i = snake.size() - 1; i > 0; i--)
  {
    snake.at(i) = snake.at(i-1);
  }
  head.x--;
  if(head.x <= geom.size.x - dimensions.x) 
  {
    head.x += geom.size.x;
    head.x -= 2;
    wall++;
  }
    snake[0] = head;
}
//////////////////////////////////////////////////////////////////////////////
void CSnake::move_right()
{
  CPoint head = snake[0];
  for(int i = snake.size() - 1; i > 0; i--)
  {
    snake.at(i) = snake.at(i-1);
  }
  head.x++;
  if(head.x + 1 >= geom.size.x) 
  {
    head.x -= geom.size.x;
    head.x += 2;
    wall++;
  }
    snake[0] = head;
}
////////////////////////////////////////////////////////////////////////////
bool CSnake::moving_up_down()
{
  int x = snake[0].x - snake[1].x;
  if(x == 0) return true;
  return false;
}
/////////////////////////////////////////////////////////////////////////
bool CSnake::moving_l_r()
{
  int y = snake[0].y - snake[1].y;
  if(y == 0) return true;
  return false;
}
//	>>> FOOD <<<
///////////////////////////////////////////////////////////////////////
void CSnake::create_food()
{
  int flag;
  while(1)
  {
    flag = 0;
    int y = rand() % (geom.size.y - 3) + 1;		// trzeba uwzglednic sciany
    int x = rand() % (geom.size.x - 3) + 1;
    food.x = x;
    food.y = y;
    /*for(int i = 0; i < snake.size(); i++)
    {
      CPoint p = snake[i];
      if(p.x == food.x and p.y == food.y) flag++;
    }*/
    if(flag == 0) break;
  }
}
