#include <stdio.h>
// signed integers
int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div(int a,int b, int *remainder);

int main() {
  int operation = 0;

  while (1==1) {

    printf("ASM Calculator from Group 7\n");
    printf("Menu:");
    printf("\n[1]\tAddition");
    printf("\n[2]\tSubtraction");
    printf("\n[3]\tMultiplication");
    printf("\n[4]\tDivision");
    printf("\n[0]\tExit\n");

    printf("Select an operation: ");
    scanf("\n\n\t%d", &operation);

    if(operation == 0){
        printf("Good bye!\n");
        break;
    }

    int val1, val2,result;
    int remainder=-1;
    printf("\nEnter the first number: ");
    scanf("\t%d", &val1);
    printf("\nEnter the second number: ");
    scanf("\t%d", &val2);

    switch (operation) {
    case 1:
      printf("\n\t%d + %d = %d\n\n", val1, val2, add(val1,val2));
      break;
    case 2:
      printf("\n%d - %d = %d\n\n", val1, val2, sub(val1,val2));
      break;
    case 3:
      printf("\n%d * %d = %d\n\n", val1, val2, mul(val1,val2));
      break;
    case 4:
      result = div(val1,val2,&remainder);
      printf("\n%d / %d = %d R %d \n\n", val1, val2, result, remainder);
      break;
    }
  }
}
