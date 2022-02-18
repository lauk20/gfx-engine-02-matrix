#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main(){
  screen s;
  clear_screen(s);

  color c;
  c.red = 255;
  c.green = 255;
  c.blue = 255;

  struct matrix * edge;
  edge = new_matrix(4,4);

  struct matrix * transformation;
  transformation = new_matrix(4,4);

  int i;
  for (i = 0; i < 1000; i++){
    int y = (i - 100) * (i - 100);
    int y2 = (i + 1 - 6) * (i + 1 - 3);
    add_edge(edge, i, y, 0, i + 1, y2, 0);
  }

  draw_lines(edge, s, c);
  display(s);
}
