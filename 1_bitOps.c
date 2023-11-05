#include <stdio.h>

int main() {

  // ex1 + ex2
  int num1 = 0;
  printf("enter number to get binary form: ");
  scanf("%d", &num1);
  printf("binary form: ");
  for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
    printf("%d", (num1 >> i) & 1);
  }
  printf("\n");

  // ex3
  int num3 = 0;
  int count = 0;
  printf("enter number to get number of '1' in binary form: ");
  scanf(" %d", &num3);
  for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
    count += (((num3 >> i) & 1) == 1) ? 1 : 0;
  }
  printf("'1': %d\n", count);

  // ex4
  int num4 = 0;
  int bit = 2;
  printf("enter number to change: ");
  scanf("%d", &num4);
  while ((bit != 0) && (bit != 1)) {
    printf("enter '1' or '0' for third bit: ");
    scanf("%d", &bit);
  }
  bit ? (num4 |= (1 << 3)) : (num4 &= ~(1 << 3));
  printf("changed number: %d\n", num4);

  return 0;
}
