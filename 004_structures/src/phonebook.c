#include <stdio.h>
#include <string.h>
#define MAXABONENTS 100
#define MAXMEMBERLEN 10

struct abonent {
  char name[MAXMEMBERLEN];
  char second_name[MAXMEMBERLEN];
  char tel[MAXMEMBERLEN];
};

int main() {
  struct abonent PhoneBook[MAXABONENTS];
  int numOfAbonents = 0;
  while (1) {
    printf("1) Добавить абонента\n");
    printf("2) Удалить абонента\n");
    printf("3) Поиск абонентов по имени\n");
    printf("4) Вывод всех записей\n");
    printf("5) Выход\n");
    int command;
    scanf("%d", &command);
    switch (command) {
    case 1:
      printf("Добавление абонента\n");
      if (numOfAbonents >= MAXABONENTS) {
        printf("Дальнейшее добавление невозможно, число абонентов не может "
               "превышать MAXABONENTS\n");
        break;
      }
      printf("Имя: ");
      scanf("%9s", PhoneBook[numOfAbonents].name);
      printf("Фамилия: ");
      scanf("%9s", PhoneBook[numOfAbonents].second_name);
      printf("Номер телефона: ");
      scanf("%9s", PhoneBook[numOfAbonents].tel);
      printf("Абонент добавлен\n");
      numOfAbonents++;
      break;

    case 2:
      printf("Удаление абонента\n");
      if (numOfAbonents < 1) {
        printf("Телефонная книга пуста, удаление невозможно\n");
        break;
      }
      printf("Порядковый номер абонента для удаления: ");
      int deletedNumber = 0;
      scanf("%d", &deletedNumber);
      if ((deletedNumber < 0) || (deletedNumber > numOfAbonents)) {
        printf("Неверный порядковый номер абонента\n");
        break;
      }
      // я выбрала самую простую реализацию удаления - поменять местами
      // удаляемую и последнюю записи, последнюю заполнить нулями и уменьшить
      // счётчик записей
      if (numOfAbonents == 1) {
        memset(PhoneBook[deletedNumber].name, '\0',
               sizeof(PhoneBook[deletedNumber].name));
        memset(PhoneBook[deletedNumber].second_name, '\0',
               sizeof(PhoneBook[deletedNumber].second_name));
        memset(PhoneBook[deletedNumber].tel, '\0',
               sizeof(PhoneBook[deletedNumber].tel));
        numOfAbonents--;
        printf("Абонент удалён\n");
        break;
      }
      strcpy(PhoneBook[deletedNumber].name, PhoneBook[numOfAbonents - 1].name);
      strcpy(PhoneBook[deletedNumber].second_name,
             PhoneBook[numOfAbonents - 1].second_name);
      strcpy(PhoneBook[deletedNumber].tel, PhoneBook[numOfAbonents - 1].tel);

      memset(PhoneBook[numOfAbonents - 1].name, '\0',
             sizeof(PhoneBook[numOfAbonents - 1].name));
      memset(PhoneBook[numOfAbonents - 1].second_name, '\0',
             sizeof(PhoneBook[numOfAbonents - 1].second_name));
      memset(PhoneBook[numOfAbonents - 1].tel, '\0',
             sizeof(PhoneBook[numOfAbonents - 1].tel));
      numOfAbonents--;
      printf("Абонент удалён\n");
      break;
    case 3:
      printf("Поиск абонентов по имени\n");
      printf("Имя: ");
      char name[MAXMEMBERLEN];
      scanf("%9s", name);
      int totalFound = 0;
      for (int i = 0; i < numOfAbonents; i++) {
        if (!strcmp(PhoneBook[i].name, name)) {
          totalFound++;
          printf("%9s - %9s - %9s\n", PhoneBook[i].name,
                 PhoneBook[i].second_name, PhoneBook[i].tel);
        }
      }
      if (!totalFound) {
        printf("Абонента с данным именем нет\n");
      }
      break;
    case 4:
      printf("Абоненты - %d записей:\n", numOfAbonents);
      for (int i = 0; i < numOfAbonents; i++) {
        printf("%9s - %9s - %9s\n", PhoneBook[i].name, PhoneBook[i].second_name,
               PhoneBook[i].tel);
      }
      break;
    case 5:
      return 0;
    default:
      break;
    }
  }
  return 0;
}
