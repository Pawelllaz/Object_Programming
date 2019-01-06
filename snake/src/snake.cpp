#include "snake.h"

CSnake::CSnake(CRect r, char _c /*=' '*/):
  CFramedWindow(r, _c)
{
  srand(time(NULL));
  score = 0;
  err_count = 0;
  game_on = 0;
  wall = 0;
  food_flag = 0;
  help_window = 1;
  over = 0;

  snake.push_back({5,3});
  snake.push_back({4,3});
  snake.push_back({3,3});
  create_food();
  
}
///////////////////////////////////////////////////////
// >> GAME SUPPORT
/////////////////////////////////////////////////////////
bool CSnake::handleEvent(int key)
{
  if(!game_on) 
    if(CFramedWindow::handleEvent(key))
      return true;
  if(key == 'r')
  {
    score = 0;
    err_count = 0;
    game_on = 0;
    wall = 0;
    food_flag = 0;
    help_window = 1;
    over = 0;

    snake.clear();
    snake.push_back({5,3});
    snake.push_back({4,3});
    snake.push_back({3,3});
    create_food();
    return true;
  }
  if(!over)
  {
    switch (key)
      {
      case 'p':
        if(help_window) help_window = !help_window;
        game_on = !game_on;
        if(!game_on)
          CFramedWindow::handleEvent(key);
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
      case 'h':
        if(game_on) game_on = !game_on;
        help_window = !help_window;
        if(!game_on)
          CFramedWindow::handleEvent(key);
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
  }
  return false;
}
//////////////////////////////////////////////////////////
void CSnake::add_segm()
{
  if(food_flag)
  {
    food_flag = 0;
    snake.push_back(add);
  }
}
/////////////////////////////////////////////////////////
void CSnake::crash()
{
  if(snake.size() > 4)
  {
    for(unsigned int i = 4; i < snake.size(); i++)
    {
      if(snake[0].x == snake[i].x and snake[0].y == snake[i].y)
        return game_over();
    }
  }
}
///////////////////////////////////////////////////////////
void CSnake::game_over()
{
  game_on = 0;
  over++;
}
///////////////////////////////////////////////////////////
// >>> PAINTING <<<
/////////////////////////////////////////////////////////
void CSnake::paint()
{
  CFramedWindow::paint();
  if(help_window)
  {
    int i=3;
    gotoyx(geom.topleft.y+i++,geom.topleft.x+3);
    printl("h - toogle help information");
    gotoyx(geom.topleft.y+i++,geom.topleft.x+3);
    printl("p - toogle play/pause mode");
    gotoyx(geom.topleft.y+i++,geom.topleft.x+3);
    printl("r - restart game");
    gotoyx(geom.topleft.y+i++,geom.topleft.x+3);
    printl("q - quit game");
    gotoyx(geom.topleft.y+i++,geom.topleft.x+3);
    printl("arrows - move snake (in play mode) or");
    gotoyx(geom.topleft.y+i++,geom.topleft.x+3);
    printl("       - move window (in pause mode)");
    if(!over) print_lvl();
  }
  else if(!over)
  {
    print_food();
    print_snake();
    print_lvl();
    if(!game_on)
    {
      gotoyx(geom.topleft.y - 1, geom.topleft.x+16);
      printl("| game paused |");
    }
  }
  else
  {
    gotoyx(geom.topleft.y+1,geom.topleft.x+4);
    printl("GAME OVER, your score: %d", score);
    gotoyx(geom.topleft.y+2,geom.topleft.x+1);
    printl("press 'r' to reset the game or 'q' to quit");
  }
}
/////////////////////////////////////////////////////////
void CSnake::print_lvl()
{
  gotoyx(geom.topleft.y - 1, geom.topleft.x);
  printl("| LEVEL %d |", score);
}
///////////////////////////////////////////////////////
void CSnake::print_snake()
{
  gotoyx(geom.topleft.y+snake[0].y, geom.topleft.x+snake[0].x);
  printc('0');
  for(unsigned int i = 1; i < snake.size(); i++)
  {
    gotoyx(geom.topleft.y+snake[i].y, geom.topleft.x+snake[i].x);
    printc('O');
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
  eat();
  CPoint head = snake[0];
  for(unsigned int i = snake.size() - 1; i > 0; i--)
  {
    snake.at(i) = snake.at(i-1);
  }
  head.y--;
  if(head.y <= 0) 
  {
    head.y += geom.size.y;
    head.y -= 2;
    wall++;
  }
  add_segm();
  get_food();
  crash();
  snake[0] = head;
}
//////////////////////////////////////////////////////////////////////////
void CSnake::move_down()
{
  eat();
  CPoint head = snake[0];
  for(unsigned int i = snake.size() - 1; i > 0; i--)
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
  add_segm();
  get_food();
  crash();
  snake[0] = head;
}
////////////////////////////////////////////////////////////////////////////
void CSnake::move_left()
{
  eat();
  CPoint head = snake[0];
  for(unsigned int i = snake.size() - 1; i > 0; i--)
  {
    snake.at(i) = snake.at(i-1);
  }
  head.x--;
  if(head.x <= 0) 
  {
    head.x += geom.size.x;
    head.x -= 2;
    wall++;
  }
  add_segm();
  get_food();
  crash();
  snake[0] = head;
}
//////////////////////////////////////////////////////////////////////////////
void CSnake::move_right()
{
  eat();
  CPoint head = snake[0];
  for(unsigned int i = snake.size() - 1; i > 0; i--)
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
  add_segm();
  get_food();
  crash();
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
    for(unsigned int i = 0; i < snake.size(); i++)
    {
      CPoint p = snake[i];
      if(p.x == food.x and p.y == food.y) flag++;
    }
    if(flag == 0) break;
  }
}
///////////////////////////////////////////////////////////////////////////////
void CSnake::get_food()
{
  if(snake[0].x == food.x and snake[0].y == food.y)
  {
    food_flag++;
    score++;
  }  
}
////////////////////////////////////////////////////////////////////////////////
void CSnake::eat()
{
  if(food_flag)
  {
    create_food();
    add = snake.at(snake.size()-1);
  }
}
