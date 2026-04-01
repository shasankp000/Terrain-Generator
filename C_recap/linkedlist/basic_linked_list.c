#include <stdio.h>
#include <stdlib.h>

// Struct definition (note the semicolon at the end!)
struct Node {
    int id;
    int data;
    struct Node* next;
};


// Function implementation
struct Node* create_new_node(int value, struct Node* next_node) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    if (!new_node) {
        printf("Error in memory allocation for new node\n");
        return NULL; 
    }
    new_node->data = value;
    new_node->next = next_node;
    return new_node;
}


int main() {

  int *size = (int *) malloc(sizeof(int));
  int *element = (int *) malloc(sizeof(int));


  printf("Enter number of elements: ");
  scanf("%d", size);

  struct Node* head = create_new_node(-1, NULL);
  head->id = 0;
  struct Node* current_node = NULL; // container for storing the current node.


  for (int i=1; i<*size; i++) {
    struct Node* new_node = create_new_node(-1, NULL);
    new_node->id = i;


    if (!new_node) {
      printf("Error in memory allocation for new node \n");
      break;
    }
    if (i == 1) {head->next = new_node;} // if first iteration, link head to next node
    else {
      current_node->next = new_node; // link currently stored node to the new node
    }
    current_node = new_node;
  }

 // insertion while traversing one node at a time.

  struct Node* ptr = head;

  while (ptr!=NULL) {

    printf("Enter element for node %d:", ptr->id+1);
    scanf("%d", element);
    printf("\n");

    ptr->data = *element;
    ptr = ptr->next;    
   
  }

  // print out the entered elements.

  // reset ptr to head.

  ptr = head;

  while (ptr!=NULL) {

    printf("Value for node %d = %d", ptr->id+1, ptr->data);
    printf("\n");

    ptr = ptr->next;    
   
  }


  printf("Performing memory cleanup and exiting....\n");

  // free up all the nodes by traversing
  // reset ptr to head

  ptr = head;


  while (ptr!=NULL) {

    struct Node* temp = ptr;
    ptr = ptr->next;
    free(temp);
   
  }
  
  free(size);
  free(element);
  return 0;
}
