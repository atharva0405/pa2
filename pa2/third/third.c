#include <stdio.h>
#include <stdlib.h>

unsigned short get(unsigned short x, int n) {
  int result;
  result = (x >> n) & 1;
  return result;
}

int main(int argc, char *argv[]) {
  unsigned short x;
  x = atoi(argv[1]);
  int left = 0;
  int right = 15;
  while (left < right) {
    int y = get(x, left);
    int z = get(x, right);
    if (y == z) {
      left++;
      right--;
    }
    else {
      printf("Not-Palindrome\n");
      break;
    }
  }
  if (left > right) {
    printf("Is-Palindrome\n");
  }
  return 0;
}
