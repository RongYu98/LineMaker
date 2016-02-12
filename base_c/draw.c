#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//500x500


//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {

  /*
  screen s;
  color c;
  c.red = 30;
  c.green = 144;
  c.blue = 255;
  */

  int x,y;
  // Octent 1 or 5?
  if ( x0 > x1 && y0 > y1 ){ //swap the two so its up and right
    x = x0;
    x0 = x1;
    x1 = x;
    y = y0;
    y0 = y1;
    y1 = y;
  }


  //check to see of octent 1:
  if ( (x1 - x0) >= (y1 - y1) ){
    x = x0;
    y = y0;
    int A = y1 - y0;
    int B = -(x1 - x0);
    int d = 2*A + B;
    while ( x <= x1 ){
      //display.plot( screen s, color c, int x, int y);
      plot(s, c, x,y);
      if ( d>0 ){
	y += 1;
	d += 2*B;
      }
      x += 1;
      d += 2*A;
    }
  }
  //save_ppm( s, "stuff.ppm" ); 


}

