#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


/*

typedef struct node {
  int data;
  struct node *next;
} Node;

typedef struct linkedList {
  Node* head;
} LinkedList;

void reorder(LinkedList *list);

int main(){
  LinkedList* list;
  Node first, second, third, fourth, fifth, sixth, seventh, eighth;
  list->head = first;
  first = second;
  second->next = third;
  Node* newNode = (Node*) malloc (sizeof(Node));
  if(newNode!=NULL){
    newNode -> data = value;
    newNode -> next = NULL;
  }
}

void reorder(LinkedList *list){ //linkedlist pointer with a head that's called list
  Node* current = list->head;
  while (current->next!=NULL && current->next->data==0){
    ;
  }
}
*/

// char*lastStringInString(char *S1, char *S2){
//   int i = 0, j = 0;
//   char* ptr = NULL;
//   while(S2[j]!='\0'){
//     if (S1[i]==S2[j]){
//       i++;
//       j++;
//     } else if (S1[i]!=S2[j]){
//       j++;
//       i = 0;
//     }
//     if (S1[i]=='\0'){
//       ptr = &S2[j-strlen(S1)];
//       i = 0;
//     }
//   }
//   return ptr;
// }

// int recursiveFindIndex(char* string, char c, int n){
//   if (*string==c){
//     return n;
//   } else if(*string=='\0'){
//     return -1;
//   } else {
//     return recursiveFindIndex(string+1, c, n+1);
//   }
// }

// int main(){
//   char* string = "balloon";
//   char c = 'l';
//   int index = recursiveFindIndex(string, c, 0);
//   printf("the index that 'l' appears in \"balloon\" is %d", index);
// }

// bool compareLines(const char *lineOne, const char *lineTwo){
//   if(*lineOne=='\0'||*lineTwo=='\0'){
//     if(*lineOne=='\0' && *lineTwo=='\0'){
//       return true;
//     } else if (*lineTwo!='\0'){ //lineOne=='\0'
//       return compareLines(lineOne,lineTwo+1);
//     } else if (*lineOne!='\0'){ //lineTwo=='\0'
//       return compareLines(lineOne+1, lineTwo);
//     }
//   }
//   if(*lineOne==' ' || *lineOne=='.'){
//     return compareLines(lineOne+1, lineTwo);
//   } 
//   if(*lineTwo==' '||*lineTwo=='.'){
//     return compareLines(lineOne, lineTwo+1);
//   }
//   if (*lineOne!=*lineTwo){
//     return false;
//   } else if (*lineOne==*lineTwo){
//     return compareLines(lineOne+1, lineTwo+1);
//   }
// }

// int main(){
//   char* lineOne = "Hello everyone";
//   char* lineTwo = "Hello! everyone";
//   bool isSame = compareLines(lineOne, lineTwo);

//   printf("it is %d that %s and %s are the same\n", isSame, lineOne, lineTwo);
// }

// typedef struct node {
//   int data;
//   struct node *next;
// } Node;

// typedef struct linkedList{
//   Node *head;
// } LinkedList;

// void printList (LinkedList *list){
//   Node* current = list->head;
//   while (current!=NULL){
//     printf("%d ", current->data);
//     current = current ->next;
//   }
// }

// void bubbleSortLinkedList(LinkedList *list){
//   int n = 0;
//   Node* countNode = list->head;
//   while(countNode!=NULL){
//     n++;
//     countNode = countNode->next;
//   }

//   for (int top = n; top>0; top--){
//     Node* current = list->head;
//     while (current!=NULL && current->next!=NULL){
//       if (current->data>current->next->data){
//         int temp = current->data;
//         current->data = current->next->data;
//       }
//       current = current->next;
//     }
//     printf("After iteration %d: ", n-top);
//     printList(list);
//     printf("\n");
//   }

// }

// int main(){
//   LinkedList list;

//   //creating nodes
//   list.head = (Node*) malloc (sizeof(Node));
//   list.head->data = 2;
//   list.head->next = (Node*) malloc (sizeof(Node));
//   list.head->next->data = 5;
//   list.head->next->next = (Node*) malloc (sizeof(Node));
//   list.head->next->next->data = 3;
//   list.head->next->next->next = (Node*) malloc (sizeof(Node));
//   list.head->next->next->next->data = 1;
//   list.head->next->next->next->next = NULL;

//   //using the function to sort it
//   bubbleSortLinkedList(&list);
// }

/*
int main(){
  int sum = 0;
  for (int i=1;i<=999;i++){
    if((((i%100)/10)!=7)&&i%9==0&&i%2==0){
      sum = sum+i;
    }
  }
  printf("%d", sum);
}
*/

/*
#include <stdio.h>
int main(void) {
int sum = 0;
for (int number = 1; number <= 999; number++) {
if (!(number % 9) && !(number % 2) && ((number / 10) % 10 != 7)) {
sum += number;
}
}
printf("%d\n", sum);
return 0;
}
*/

// int borderSum(int mat[][26], int n){
//   int sum = 0;

//   if (n==0){
//     return sum;
//   }
//   for (int i = 0; i<n;i++){
//     for (int j = 0; j<n;j++){
//       if (i==0||j==0||i==(n-1)||j==(n-1)){
//         sum = sum + mat[i][j];
//       }
//     }
//   }
//   return sum;
// }

// int main(){
//   int mat[][26] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
//   printf("the border sum of the array when n = 1 is: %d", borderSum(mat, 1));
// }

/*
int main(){
  int sum = 0;
  int arr[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
  for (int row = 0;row<4;row++){
    for (int col = 0;col<4;col++){
      if (row==col){
        sum+=arr[row][col];
      }
      if ((row+col)==3){
        sum+=arr[row][col];
      }
    }
  }
  printf("%d", sum);
}
*/

char* removeSpecialChars(char* str){
  int i = 0, j = 0;
  char *removed = (char*) malloc(sizeof(char)*30);

  while (str[i]!='\0'){
    if (str[i]<'a' || str[i]>'z'){
      i++;
    } else {
      removed[j] = str[i];
      j++;
      i++;
    }
  }
  removed[j] = '\0';
  return removed;
}

int main(){
  char str[30] = "3";
  printf("str without special characters %s\n", removeSpecialChars(str));
  return 0;
}