#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

//gcc -o gallery gallery.c draw.c display.c matrix.c -lm
//TO COMPILE

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
  ident(transformation);
  //transformation->m[0][3] = 100;
  //transformation->m[1][3] = 100;

  //3 vertical lines
  add_edge(edge, 0, 0, 0, 0, 10, 0);
  add_edge(edge, 8, -4, 0, 8, 6, 0);
  add_edge(edge, 16, 0, 0, 16, 10, 0);

  //point center top
  add_edge(edge, 0, 10, 0, 8, 6, 0);
  add_edge(edge, 16, 10, 0, 8, 6, 0);

  //point center bottom
  add_edge(edge, 0, 0, 0, 8, -4, 0);
  add_edge(edge, 16, 0, 0, 8, -4, 0);

  //point out top
  add_edge(edge, 0, 10, 0, 8, 13, 0);
  add_edge(edge, 16, 10, 0, 8, 13, 0);

  matrix_mult(transformation, edge);

  //DILATE
  ident(transformation);
  transformation->m[0][0] = 2;
  transformation->m[1][1] = 2;
  transformation->m[2][2] = 2;

  //print_matrix(transformation);
  //printf("row: %d col: %d lastcol: %d\n", edge->rows, edge->cols, edge->lastcol);
  matrix_mult(transformation, edge);
  //print_matrix(edge);
  //printf("row: %d col: %d lastcol: %d\n", edge->rows, edge->cols, edge->lastcol);

  ident(transformation);
  transformation->m[0][3] = -5;
  transformation->m[1][3] = 5;
  matrix_mult(transformation, edge);
  //printf("\n");
  //print_matrix(transformation);

  int i;
  int iTIMES = 0;
  for (i = 0; i < 500; i = i + 16){
    int v;
    int times = 0;
    for (v = 0; v < 500; v = v + 60){
      int angle = rand();
      //printf("%d\n", angle);
      draw_lines(edge, s, c);

      //BACK TO ORGIN
      ident(transformation);
      transformation->m[0][3] = -1 * (times) * 60 + 5 - 8;
      transformation->m[1][3] = -1 * (iTIMES) * 60 - 5;
      matrix_mult(transformation, edge);

      //print_matrix(edge);

      //ROTATE
      ident(transformation);
      transformation->m[0][0] = cos(angle);
      transformation->m[0][1] = sin(angle);
      transformation->m[1][0] = -1 * sin(angle);
      transformation->m[1][1] = cos(angle);
      matrix_mult(transformation, edge);

      //MOVE BACK
      ident(transformation);
      transformation->m[0][3] = (times) * 60 - 5 + 8;
      transformation->m[1][3] = (iTIMES) * 60 + 5;
      matrix_mult(transformation, edge);

      //TRANSLATE
      ident(transformation);
      transformation->m[0][3] = 60;
      matrix_mult(transformation, edge);

      times = times + 1;
    }

    //REVERT X TRANSLATION
    ident(transformation);
    transformation->m[0][3] = (times) * -60;
    matrix_mult(transformation, edge);

    /*
    for (v = 0; v < 500; v = v + 60){
      ident(transformation);
      transformation->m[0][3] = -60;
      //transformation->m[1][3] = i + 2;
      matrix_mult(transformation, edge);
    }
    */
    ident(transformation);
    transformation->m[1][3] = 60;
    //print_matrix(transformation);
    //printf("\n");
    matrix_mult(transformation, edge);

    iTIMES = iTIMES + 1;
  }

  //draw_lines(edge, s, c);

  /*
  PARABOLA
  int i;
  for (i = 0; i < 1000; i++){
    int y = (i - 100) * (i - 100);
    int y2 = (i + 1 - 100) * (i + 1 - 100);
    add_edge(edge, i, y, 0, i + 1, y2, 0);
  }
  */

  draw_lines(edge, s, c);
  save_extension(s, "gallery.png");
  display(s);
}
