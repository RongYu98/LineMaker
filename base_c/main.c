#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int xer(int x) {
  // f(x) = ( 2x^2 - 5x + 5) / (x - 2)
  int a = (int)( 2*x*x*x - 5*x + 5 ) / (x + 2 );
  return a;
}
int yer(int y){
  // 4 cos2x siny = 1
  //siny = 1/4cos2x
  double a = (.25 * cos(y*3 * 180 / 3.141592653589 ) );
  int z = (int) asin(a);
  return (y+z);
}

int main() {

  screen s;
  color c;
 
  
  c.red = 0;
  c.green = MAX_COLOR;
  c.blue = 0;
  
  clear_screen(s);


  //octant 1
  printf("Is this octent 1?\n");
  draw_line( 0, 0, XRES-1, YRES - 75, s, c);
  //octant 2
  printf("Is this octent 2\n");
  draw_line( 0, 0, XRES - 75, YRES-1, s, c);
  
  //octant 8
  printf("Is this octent 8?\n");
  draw_line( 0, YRES-1, XRES-1, 75, s, c);
  //octant 7
  printf("Is this octent 7?\n");
  draw_line( 0, YRES-1, XRES - 75, 0, s, c);

  
  
  c.green = 0;
  c.blue = MAX_COLOR;
  //octant 5
  printf("%d\n",1);
  draw_line( XRES - 1, YRES - 1, 0, 75, s, c);
  //octant 6
  printf("6\n");
  draw_line( XRES - 1, YRES -1, 75, 0, s, c);
  //octant 4
  printf("4\n");
  draw_line( XRES - 1, 0, 0, YRES - 75, s, c);
  //octant 3
  printf("3\n");
  draw_line( XRES - 1, 0, 75, YRES - 1, s, c);
  
  c.blue = 0;
  c.red = MAX_COLOR;
  //y = x, y = -x
  draw_line( 0, 0, XRES - 1, YRES - 1, s, c);
  draw_line( 0, YRES - 1, XRES - 1, 0, s, c);

  //horizontal, vertical line
  draw_line( 0, YRES / 2, XRES - 1, YRES / 2, s, c);
  draw_line( XRES / 2, 0, XRES / 2, YRES - 1, s, c);

  //display(s);
  save_extension(s, "lines.png");
  c.red = 0;
  c.green = 0;
  c.blue = 205;

  clear_screen(s);
  
  int z = 0;
  int x,y;
  int xcor = 0;
  int ycor = 0;
  while (xcor < XRES){
    while (ycor < YRES){
      
      x = xer(z) % XRES;
      y = yer(z) % YRES;
      c.red = (x+y) % 255;
      draw_line(xcor, ycor, x,y,s,c);
      ycor+=10;
      z++;
    }
    xcor+=10;
    c.green = (x+y) % 255;
  }
  save_extension(s, "cool.png");
}  
