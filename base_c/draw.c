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

  if ( x0 > x1 ){ //swap the two so its up and right
    x = x0;
    x0 = x1;
    x1 = x;
    y = y0;
    y0 = y1;
    y1 = y;
  }

  int A = y1 - y0;
  int B = -(x1 - x0);
  int d = 0;

  x = x0;
  y = y0;
  
  //check to see of octent 1:
  if ( (x1 - x0) >= (y1 - y0) && (y1 - y0) > 0 ){
    printf("Octent 1\n");
    //x = x0;
    //y = y0;
    //int A = y1 - y0;
    //int B = -(x1 - x0);
    //int d = 2*A + B;
    d = 2*A + B;
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
  } else if ( (y1 - y0) > 0 ){ //octent 2
    
    printf("Octent 2\n");
    d = A + 2*B;

    while ( y <= y1 ) {
      plot(s, c, x, y);
      if ( d < 0 ){
	x += 1;
	d += 2*A;
      }
      y += 1;
      d += 2*B;
    }
    
  } else if ( (x1 - x0)  > ( (y1 - y0) *-1 ) ) {//octent 8

    printf("Ocetent 8 \n");
    d = 2*A - B;

    while ( x <= x1 ){
      plot( s,c,x,y );
      if ( d > 0 ){
	y -= 1;
	d += 2*B;
      }
      x += 1;
      d += 2*A;
    }
    
  } else { ////////////////////////////////////Octent 7

    printf("Octent 7\n");
    d = A - 2*B;
    
  }


    

}

