#include <stdio.h>
#include <string.h>
#include <strings.h>
#define MAX 18

typedef struct Node {
  char ch[MAX];
  int index;
} stack;

int main() {
  char ch[MAX], choice;
  stack temp;
  printf("PENGECEKKAN PALINDROM\n");
  do {
    printf("masukkan kata yang mau di cek: ");
    fgets(ch, MAX, stdin);
    ch[strcspn(ch, "\n")] = '\0';
    temp.index = 0;

    int i = strlen(ch) - 1;
    while (i >= 0)
      temp.ch[temp.index++] = ch[i--];

    temp.ch[temp.index] = '\0';
    printf("kata \"%s\" ", ch);

    if (strcasecmp(ch, temp.ch))
      printf("tidak");

    printf(" palindrom");
    printf("\n\nlagi (Y/n) : ");
    scanf(" %c", &choice);
    getchar();
  } while (choice == 'y' || choice == 'Y');
}
