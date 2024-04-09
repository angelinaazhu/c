#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(){
  char labelName[5] = "R100";
  int labelNum = (int) (labelName-'0');
  printf("%d", labelNum);
}