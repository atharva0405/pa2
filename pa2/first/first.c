#include <stdio.h>
#include <stdlib.h>


unsigned short get(unsigned short x, int n) {
  int result;
  result = (x >> n) & 1;
  printf("%d\n", result);
  return 0;
}

unsigned short comp(unsigned short x, int n) {
  int result;
  x ^= 1 << n;
  result = x;
  //result = (x >> n) ^ 1;
  //result = (result << n);
  printf("%d\n", result);
  return x;
}

unsigned short set(unsigned short x, int n, int v) {
  int result;
  //if ((1 >> n) != v) {
    //x = x | (1 << n);
  x ^= (-v ^ x) & (1 << n);
  result = x;
  printf("%d\n", result);
  //}
  return x;
}


int main(int argc, char *argv[]) {
  FILE *fptr;
  char *filename = argv[1];
  fptr = fopen(filename, "r");
  char str[5];

  unsigned short x, temp;
  int n, v;
  fscanf(fptr, "%hd", &x);
  while (!feof(fptr)) {
    fscanf(fptr, "%s\t%d\t%d\n", &str[0], &n, &v);
    //printf("%c %c\n", str[0], str[1]);
    //printf("%d %d\n", n, v);
    if (str[0] == 'g') {
      get(x, n);
    }
    if (str[0] == 'c') {
      temp = comp(x, n);
    }
    if (str[0] == 's') {
      temp = set(x, n, v);
    }
    x = temp;
  }
  return 0;
}
