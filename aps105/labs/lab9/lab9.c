#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

// Implement these functions
void handleInsert(LinkedList*);
void handleRemove(LinkedList*);
void handleCurrentCal(LinkedList*, int);
void handleVoltage(LinkedList*, int);
void handlePrint(LinkedList*);
void handleQuit(LinkedList*);
Node* createNode(int resistance, char labelName[STRING_MAX]);

int main(void) {
  LinkedList circuit;
  initList(
      &circuit);  // initializes list with head originally pointing to nothing
  char command = '\0';
  printf("Welcome to our circuit simulator\n");
  // Enter the source voltage!
  printf("What is the source of the voltage?\n");
  int voltage;
  readInputNumber(&voltage);  // reads voltage input

  while (command != 'Q') {
    command = getCommand();  // prompt user for command they want to operate,
                             // function returns command (letter) user inputted

    switch (command) {
      case 'I':
        handleInsert(&circuit);
        break;
      case 'R':
        handleRemove(&circuit);
        break;
      case 'C':
        handleCurrentCal(&circuit, voltage);
        break;
      case 'V':
        handleVoltage(&circuit, voltage);
        break;
      case 'P':
        handlePrint(&circuit);
        break;
      case 'Q':
        handleQuit(&circuit);
        break;
    }
  }
  return 0;
}

void handleInsert(LinkedList* circuit) {
  int resistance = 0;
  printf("What's the value of the resistor: ");
  readInputNumber(&resistance);  // new resistor value stored in "resistance"
  printf("What's the label of the resistor: ");
  char labelName[STRING_MAX];  // new label stored in char array "labelName"
  readInputString(labelName,
                  STRING_MAX);  // resistor label name stored in "labelName"

  // TODO: Implement the insert into ordered list function

  // traverse list & compare
  Node* current = circuit->head;

  // special case: if linked list is empty insert at front
  if (current == NULL) {
    // implement insertAtFront to create and insert new node at front
    Node* firstNode = createNode(resistance, labelName);
    if (firstNode != NULL) {
      firstNode->next = NULL;     // nothing at end of list
      circuit->head = firstNode;  // first element in list is new node
      return;                     // return to main
    }
  }

  // if names are the same
  if (strncmp(current->name, labelName, STRING_MAX) == 0) {
    // send error message
    printf("A resistor with %s label already exists.\n", labelName);
    return;  // returns to main
  }

  // if linked list is not empty but still needs to be inserted at front
  // if very first name > labelName
  // if strncmp returns a positive number
  // PROBLEM: USING STRNCMP RETURNS R5>R10 :(
  // FIX: prof confirmed don't need to think about double digit issue
  if (strncmp(current->name, labelName, STRING_MAX) > 0) {
    // impolement insertAtFront
    Node* newFirstNode = createNode(resistance, labelName);
    if (newFirstNode != NULL) {
      newFirstNode->next =
          current;  // connect remainider of list to end of new first node
      circuit->head = newFirstNode;  // first element in list is new node
      return;                        // return to main
    }
  }
  // continues traversing as long as next node exists & name < labelName -->
  // WHAT IF IF NEEDS TO BE INSERTED AT FRONT?
  // SEGMENTATION FAULT -> FIX: return to main after finishing insert
  while (current->next != NULL &&
         strncmp(current->next->name, labelName, STRING_MAX) <= 0) {
    // current points to next node
    current = current->next;

    // checking if current name and labelName are the same
    if (strncmp(current->name, labelName, STRING_MAX) == 0) {
      // error message
      printf("A resistor with %s label already exists.\n", labelName);
      return;  // returns to main
    }
  }
  // exit loop when reached last node OR name > labelName

  // may be within the list or at the end of the list

  // create a node: if appropriate position is found (loop exited)
  Node* newNode = createNode(resistance, labelName);

  if (newNode != NULL) {
    newNode->next = current->next;  // linking rest of list to end of this node
    current->next = newNode;        // inserting
    return;
  }
}

void handleRemove(LinkedList* circuit) {
  // TODO: Implement the remove function
  // WORK ON THIS --> in example 2 it didn't remove R1.

  // prompting user input: specifying label of resistor to delete
  char toDelete[STRING_MAX];  // label to delete
  printf("What's the label of the resistor you want to remove: ");
  readInputString(toDelete, STRING_MAX);

  // list is empty
  if (circuit->head == NULL) {
    printf("The resistor with %s label does not exist.\n", toDelete);
    return;
  }

  // first node matches value
  if (strncmp(circuit->head->name, toDelete, STRING_MAX) == 0) {
    
    // implement deleteFront
    //save location of the node after head, so we don't lose rest of list
    Node* newHead = circuit->head->next;
    //free up memory used by current head
    free(circuit->head);
    //update current head to the saved location
    circuit->head = newHead;
    return;
  }

  // search for a node that matches the first value, but maintain a pointer to
  // the node just before it
  Node* current = circuit->head;
  // while next exists & labels don't match
  while (current->next != NULL &&
         strncmp(current->next->name, toDelete, STRING_MAX) != 0) {
    current = current->next;
  }

  // current now points to a node just before the node that matched
  // OR current points to the last node
  if (current->next != NULL) {
    // current does not point to last node
    Node* temp =
        current->next;  // temp or current->next is node we want to delete
    current->next = temp->next;  // current->next now points to the node after
                                 // the one we want to delete
    free(temp);
    // successful so returns to main
    return;
  }

  // if label not found
  printf("The resistor with %s label does not exist.\n", toDelete);
  return;
}

void handleCurrentCal(LinkedList* circuit, int voltage) {
  // TODO: Implement the function that prints the value of current in the
  // circuit

  double totalResistance = 0;

  // make current point to first node
  Node* current = circuit->head;

  // while node exists
  // is it possible for current to be NULL
  // but current->value exist?
  // i don't think so.
  // if current is NULL then the node doesn't exist
  while (current != NULL) {
    // tallying totalResistance
    totalResistance += current->value;
    // make current traverse
    current = current->next;
  }
  // find and print total current
  double totalCurrent = ((double)voltage) / (totalResistance);
  printf("The current in the circuit is %.6lfA\n", totalCurrent);
  return;
}

void handleVoltage(LinkedList* circuit, int voltage) {
  // TODO: Implement the function that prints the potential difference across a
  // resistor

  // prompting user input: specifying label of resistor to analyze
  char label[STRING_MAX];  // label we are looking for
  double resistance;       // resistance of label we are looking for
  printf(
      "What's the label of the resistor you want to find the voltage across: ");
  readInputString(label, STRING_MAX);

  // list is empty
  if (circuit->head == NULL) {
    printf("The resistor with %s label does not exist.\n", label);
    return;
  }

  // find a node with a specific resistor
  // currentResistor: current resistor the traversal is on
  Node* currentResistor = circuit->head;
  while (currentResistor != NULL) {
    // if currentResistor's "name" is the same as label of resistor
    if (strncmp(currentResistor->name, label, STRING_MAX) == 0) {
      // found the node
      resistance = (double)(currentResistor->value);
      currentResistor = NULL;
      // finding total resistance
      double totalResistance = 0;
      Node* current = circuit->head;  // current: current node we are on
      while (current != NULL) {
        totalResistance += current->value;
        current = current->next;
      }

      // find total current
      double totalCurrent = ((double)voltage) / (totalResistance);

      // find voltage across specified resistor
      double voltageOfSpecifiedResistor = totalCurrent * (resistance);
      printf("Voltage across resistor is %.6lfV\n", voltageOfSpecifiedResistor);
      return;
    }
    // did not find matching label, moving onto next node
    currentResistor = currentResistor->next;
  }

  // exits loop, meaning didn't find matching node
  printf("The resistor with %s label does not exist.\n", label);
}

void handlePrint(LinkedList* circuit) {
  // TODO: they can implement the print function
  // make current point to first node
  Node* current = circuit->head;
  while (current != NULL) {
    // print list
    printf("%s %d Ohms\n", current->name, current->value);
    // make current point to what current -> next is pointing ti
    current = current->next;
  }
  // exit loop when current == NULL, when we printed all nodes!
  return;
}

void handleQuit(LinkedList* circuit) {
  // TODO: Implement the quit function

  // initiating deleting process
  printf("Removing all resistors in the circuit...\n");

  // the list is empty, nothing to delete;
  if (circuit->head == NULL) {
    return;
  }

  // delete all nodes one by one from the front
  while (circuit->head != NULL) {
    // print node before deleting
    printf("%s %d Ohms\n", circuit->head->name, circuit->head->value);

    // delete node at the front...

    // save the location of the new node after head
    // to prevent memory leak & loss of rest of list
    //(it's okay if it's NULL)
    Node* newHead = circuit->head->next;

    // free up the memory used by the current head
    free(circuit->head);

    // update current head to the saved location
    circuit->head = newHead;
  }
}

Node* createNode(int resistance, char labelName[STRING_MAX]) {
  Node* nodeCreated =
      (Node*)malloc(sizeof(Node));  // NOTE: REMEMBER TO FREE THIS!
  if (nodeCreated != NULL) {
    nodeCreated->value = resistance;                    // integer
    strncpy(nodeCreated->name, labelName, STRING_MAX);  // copying string
    //+1 for null character
    // returns pointer to dest.
    nodeCreated->next = NULL;  // point to next list

    return nodeCreated;  // returns pointer to newNode;
  } else {
    return NULL;
  }
}
