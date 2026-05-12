#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
  char str[MAX];
  int urut;
} stack;

int derajat(char);
void postfix(char[]);
void push(stack *, char);
void pop(stack *);
int isEmpty(stack *);

int main() {
  char choice, temp[MAX];
  printf("PENGUBAH NOTASI INFIX MENJADI POSTFIX\n"
         "DENGAN MEMANFAATKAN STRUKTUR STACK\n\n");
  do {
    printf("masukkan ekspresi dalam notasi infix : ");
    fgets(temp, MAX, stdin);
    printf("Notasi postfix : ");

    postfix(temp);

    printf("\n\nlagi (Y/n) : ");
    scanf(" %c", &choice);
    getchar();
  } while (choice == 'y' || choice == 'Y');
}

int derajat(char t) {
  if (t == '+' || t == '-')
    return 1;
  else if (t == '*' || t == '/')
    return 2;
  else if (t == '^')
    return 3;

  return 0; // jika dibaca '('
}

void postfix(char ch[]) {
  stack asal;
  asal.urut = 0;

  for (int i = 0; i < strlen(ch); i++) {

    char temp = ch[i];

    if (isalnum(temp))
      printf("%c", temp);
    else if (temp == '(')
      push(&asal, temp);
    else if (temp == ')') {
      while (!isEmpty(&asal) && asal.str[asal.urut - 1] != '(') {
        printf("%c", asal.str[asal.urut - 1]);
        pop(&asal);
      }
      pop(&asal);
    } else {
      while (!isEmpty(&asal) &&
             derajat(asal.str[asal.urut - 1]) >= derajat(temp)) {
        printf("%c", asal.str[asal.urut - 1]);
        pop(&asal);
      }
      push(&asal, temp);
    }
  }
}

void push(stack *tumpuk, char ch) {
  tumpuk->str[tumpuk->urut] = ch;
  tumpuk->urut++;
}

void pop(stack *tumpuk) { tumpuk->urut--; }

int isEmpty(stack *tumpuk) { return tumpuk->urut == 0; }
