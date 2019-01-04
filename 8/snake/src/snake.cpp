#include "snake.h"

CSnake::CSnake(CRect r, char _c /*=' '*/):
  CFramedWindow(r, _c)
{
}
/////////////////////////////////////////////////////////
void CSnake::game()
{

}
/////////////////////////////////////////////////////////
void CSnake::paint()
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
