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
}

/*
int main() {

  screen s;
  struct matrix *edges;

  edges = new_matrix(4, 4);

  free_matrix( edges );
}
*/
