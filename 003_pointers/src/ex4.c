#include <stdio.h>
#define MAX_LENGTH 100

char *findSubString(const char *mainString, const char *subString) {
  while (*mainString) {
    const char *mainPtr = mainString;
    const char *subPtr = subString;

    while ((*subPtr && *mainPtr == *subPtr) && (*subString)) {
      mainPtr++;
      subPtr++;
    }

    if (!*subPtr) {
      return (char *)mainString; // Подстрока найдена
    }

    mainString++;
  }

  return NULL; // Подстрока не найдена
}

int main() {
  char mainString[MAX_LENGTH];
  char subString[MAX_LENGTH];

  printf("Enter the main string: ");
  scanf("%99[^\n]", mainString);

  printf("Enter the substring to search for: ");
  scanf(" %99[^\n]", subString);

  char *result = findSubString(mainString, subString);

  if (result != NULL) {
    printf("Substring found at position: %ld\n", result - mainString);
  } else {
    printf("Substring not found.\n");
  }
  return 0;
}

/*Напишите программу, которая ищет во введенной строке (с клавиатуры)
введенную подстроку (с клавиатуры) и возвращает указатель на начало
подстроки, если подстрока не найдена в указатель записывается NULL.
В качестве строк использовать статические массивы.*/
