#include <stdio.h>

int main() {
  int num_to_be_changed = 0;
  printf("Enter a number to be changed: ");
  scanf("%d", &num_to_be_changed);

  int third_byte = -1;
  while (third_byte > 255 || third_byte < 0) {
    printf("Enter value for third byte [0;255]: ");
    scanf("%d", &third_byte);
  }

  unsigned char *pointer_to_num = (unsigned char *)&num_to_be_changed;

  *(pointer_to_num + 2) = third_byte;

  printf("Changed number: %d\n", num_to_be_changed);
  return 0;
}

/*Поменять в целом положительном числе (типа int) значение третьего
байта на введенное пользователем число (изначальное число также
вводится с клавиатуры) через указатель (не применяя битовые
операции).*/