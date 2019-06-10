#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  unsigned short x;
  unsigned short x_copy;
  int parity = 1;
  x = atoi(argv[1]);
  x_copy = x;
  while (x != 0) {
    if (parity == 1) {
      parity = 0;
    }
    else if (parity == 0) {
      parity = 1;
    }
    x = x & (x - 1);
    //printf("%d\n", parity);
  }
  if (parity == 1) {
    printf("Even-Parity\t");
  }
  else {
    printf("Odd-Parity\t");
  }

  int temp1 = 0;
  int temp2 = 0;
  float counter = 0;
  while (x_copy != 0) {
    temp1 = x_copy & 1;
    //printf("%d\n", temp1);
    x_copy >>= 1;
    temp2 = x_copy & 1;
    //printf("%d\n", temp2);
    if (temp1 == 1 && temp2 == 1) {
      counter++;
      x_copy >>= 1;
    }
  }
  //printf("Counter = " );
  printf("%0.0f\n", counter);
  return 0;
}
