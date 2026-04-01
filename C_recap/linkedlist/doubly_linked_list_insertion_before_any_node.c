#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Struct definition (note the semicolon at the end!)
struct Node {
    int id;
    int data;
    struct Node* next;
    struct Node* prev;
};


// Function implementation
struct Node* create_new_node(int value, struct Node* next_node, struct Node* prev_node) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    if (!new_node) {
        printf("Error in memory allocation for new node\n");
        return NULL; 
    }
    new_node->data = value;
    new_node->next = next_node;
    new_node->prev = prev_node;
    return new_node;
}


int main() {

  int *size = (int *) malloc(sizeof(int));
  int *element = (int *) malloc(sizeof(int));
  int *id = (int *) malloc(sizeof(int));
  bool node_not_found = false;

  printf("Enter number of elements: ");
  scanf("%d", size);

  struct Node* head = create_new_node(-1, NULL, NULL);
  head->id = 0;
  struct Node* current_node = NULL; // container for storing the current node.


  for (int i=1; i<*size; i++) {
    struct Node* new_node = create_new_node(-1, NULL, NULL);
    new_node->id = i;


    if (!new_node) {
      printf("Error in memory allocation for new node \n");
      break;
    }
    if (i == 1) {
      head->next = new_node;
      new_node->prev = head;
    } // if first iteration, link head to next node
    else {
      current_node->next = new_node; // link currently stored node to the new node
      new_node->prev = current_node;
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

 // backward traversal
 // first we traverse from head to last node
 // reset ptr to head
 ptr = head;
 printf("Reverse traversal: \n");
 while (ptr!=NULL) {
   if (ptr->next == NULL) {
     // reached last node
     printf("Reached last node!\n"); 
     
     while(ptr!=NULL) {
       printf("Value for node %d = %d", ptr->id+1, ptr->data);
       printf("\n");

       ptr = ptr->prev;       
     }
     break;
   }
   ptr = ptr->next;
 }

 // request id of node.
 printf("Enter node before which new node is to be inserted:");
 scanf("%d", id);
 printf("\n");

// head case
if (*id - 1 == 0) {
  printf("Head node detected!\n");
  printf("Enter value for the new node:");
  scanf("%d", element);
  printf("\n");

  struct Node* new_node = create_new_node(*element, head, NULL);
  head->prev = new_node;
  head = new_node;
  head->id = 0;

  // shuffle all ids of the subsequent nodes, starting from ptr, forward by 1.
  ptr = head->next;
  while(ptr!=NULL) {
    ptr->id = ptr->id+1;
    ptr = ptr->next;
  }

  
  *size = *size + 1;
}
// tail node case
else if (*id == *size) {
  printf("Tail node detected!\n");

  ptr = head->next;

  while(ptr!=NULL) {
    if (ptr->next==NULL) {
       printf("Enter value for the new node:");
       scanf("%d", element);
       printf("\n");

       struct Node* new_node = create_new_node(*element, ptr, ptr->prev);
       new_node->id = ptr->id;
       ptr->prev->next = new_node;
       ptr->id = ptr->id+1; // increment id of last node by 1.
    }
    ptr = ptr->next;
  }   
  *size = *size + 1;
}
else if (*id>1 || *id<*size) {
  ptr = head->next;

  while(ptr!=NULL) {
    if(ptr->id+1 == *id) {
      // node found.
      printf("Enter value for new node:");
      scanf("%d", element);
      printf("\n");
      struct Node* new_node = create_new_node(*element, ptr, ptr->prev);
      new_node->id = ptr->id;

      // shuffle ids of all subsequent nodes starting from ptr, forward by 1
      while(ptr!=NULL) {
        ptr->id = ptr->id+1;
        ptr = ptr->next;
      }
      break; // important, once new node has been added and ids are shuffled exit parent loop.
    }
    ptr = ptr->next;
  }
  *size = *size + 1;
}
else {
  printf("Error! Invalid id! Node not found!\n");
  node_not_found = true;
}

if (!node_not_found) {
  printf("Linkedlist after insertion: \n");
  
  
  // forward traversal
  
  ptr = head;

  while (ptr!=NULL) {

    printf("Value for node %d = %d", ptr->id+1, ptr->data);
    printf("\n");

    ptr = ptr->next;    
   
  }

  
  // backward traversal
  // first we traverse from head to last node
  // reset ptr to head
  ptr = head;
  printf("Reverse traversal: \n");
  while (ptr!=NULL) {
    if (ptr->next == NULL) {
      // reached last node
      printf("Reached last node\n");
      while(ptr!=NULL) {
        printf("Value for node %d = %d", ptr->id+1, ptr->data);
        printf("\n");

        ptr = ptr->prev;       
      }
      break;
    }
    ptr = ptr->next;
  }
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
