#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main(){
  printf("\nTesting add_edge. Adding (1,2,3), (4,5,6) m2 =\n");

  struct matrix * test;
  test = new_matrix(4,10);
  add_edge(test, 1, 2, 3, 4, 5, 6);
  print_matrix(test);

  printf("\n");

  printf("Testing ident. m1 =\n");
  struct matrix * identm;
  identm = new_matrix(4,4);
  ident(identm);
  print_matrix(identm);

  printf("\n");

  printf("Testing Matrix mult. m1 * m2 =\n");
  matrix_mult(identm, test);
  print_matrix(test);

  struct matrix * m1;

  m1 = new_matrix(4, 10);
  add_edge(m1, 1, 2, 3, 4, 5, 6);
  add_edge(m1, 7, 8, 9, 10, 11, 12);
  printf("\nTesting Matrix mult. m1 =\n");
  print_matrix(m1);
  printf("\nTesting Matrix mult. m1 * m2 =\n");
  matrix_mult(m1, test);
  print_matrix(test);

  screen s;
  clear_screen(s);
  color c;
  c.red = 0;
  c.green = 255;
  c.blue = 255;
  struct matrix * edges;
  edges = new_matrix(4,4);
  add_edge(edges, 50, 450, 0, 100, 450, 0);
  add_edge(edges, 50, 450, 0, 50, 400, 0);
  add_edge(edges, 100, 450, 0, 100, 400, 0);
  add_edge(edges, 100, 400, 0, 50, 400, 0);

  add_edge(edges, 200, 450, 0, 250, 450, 0);
  add_edge(edges, 200, 450, 0, 200, 400, 0);
  add_edge(edges, 250, 450, 0, 250, 400, 0);
  add_edge(edges, 250, 400, 0, 200, 400, 0);

  add_edge(edges, 150, 400, 0, 130, 360, 0);
  add_edge(edges, 150, 400, 0, 170, 360, 0);
  add_edge(edges, 130, 360, 0, 170, 360, 0);

  add_edge(edges, 100, 340, 0, 200, 340, 0);
  add_edge(edges, 100, 320, 0, 200, 320, 0);
  add_edge(edges, 100, 340, 0, 100, 320, 0);
  add_edge(edges, 200, 340, 0, 200, 320, 0);

  draw_lines( edges, s, c );
  save_extension(s, "bob.png");
  display(s);
}

/*
int main() {

  screen s;
  struct matrix *edges;

  edges = new_matrix(4, 4);

  free_matrix( edges );
}
*/
