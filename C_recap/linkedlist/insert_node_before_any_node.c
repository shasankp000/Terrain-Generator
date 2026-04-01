#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
  int *id = (int *) malloc(sizeof(int));
  bool node_not_found = false;


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
  

  printf("Enter id node before which new node is to be inserted: ");
  scanf("%d", id);
  printf("\n");

  // run an id check.
     
  printf("Running id check.....\n");

  if (*id - 1 == 0) {
    printf("Head node detected! \n");
    
    struct Node* temp = head;
    printf("Enter value of the new node: ");
    scanf("%d", element);
    printf("\n");

    struct Node* new_node = create_new_node(*element, temp);  

    if (!new_node) {
      printf("Error in memory allocation for new node!");
    }
    else {
     
    head = new_node; // set new head as the new node

    head->id = 0;

    
    // increase the ids of all subsequent nodes by 1.
    // reset ptr to head

    ptr = head;

    // Increment the IDs of all other nodes
    temp = head->next; // start with the old head
      while (temp != NULL) {
         temp->id += 1;
         temp = temp->next;
      }
   }

  }   
   
  else {
      
    
   if(*id < 1 || *id > *size) {
       printf("Error! Invalid id! Node not found! \n");
       printf("Printing out existing nodes... \n");
       node_not_found = true;
   } 


   if (!node_not_found) {
   
     
    // increase the ids of all subsequent nodes by 1.
    // reset ptr to head

    ptr = head;
    
    while (ptr!=NULL) {
      
      if (ptr->id == *id-2) { // found node just before insertion point
        printf("Enter value of the new node: ");
        scanf("%d", element);
        printf("\n");
        struct Node* new_node = create_new_node(*element, ptr->next);
        ptr->next = new_node;
        new_node->id = *id-1;
        // Shift .id for all subsequent nodes
        struct Node* temp = new_node->next;
        while (temp != NULL) {
            temp->id += 1;
            temp = temp->next;
         }
          break;
      }
      ptr = ptr->next;
    }
  }
 } 
  
  // traverse and print out the elements.
  // reset ptr to head

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
  free(id);
  return 0;
}
