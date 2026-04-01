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
  bool list_cleared = false;

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


  printf("Enter id node before which new node is to be deleted: ");
  scanf("%d", id);
  printf("\n");

  // special case: if linkedlist has only 1 node.
  // typicall by following order of execution the head node case will always trigger in this event.
  // However, just to be on the safe side...

  if (head->next == NULL) {
    printf("Linked list has only 1 node! Freeing up the list...\n");
    free(head);
    list_cleared = true;
  }

  if (!list_cleared) {
    
  // run an id check.
    
   printf("Running id check.....\n");
  
  
   if (*id < 1 || *id > *size) {
       printf("Error! Invalid id! Node not found! \n");
       printf("Printing out existing nodes... \n");
       node_not_found = true;
   }

   if (!node_not_found) {
   // case: target is head node.
     if (*id - 1 == 0) {
      printf("Head node detected!\n");

      struct Node* temp = head;
      head = head->next;
      head->id = 0;

      free(temp);

      // decrease the id's of subsequent nodes by 1.

      struct Node* ptr = head->next; // start at the subsequent node
      while(ptr!=NULL) {
        ptr->id = ptr->id-1;
        ptr=ptr->next;
      }
    }
  
    // case: target is last node.
     else if (*size-*id == 0) {
       printf("Last node detected!\n");

       // just break the link, no need to shuffled ids.

      struct Node* ptr = head->next;
      while(ptr!=NULL) {
        if (ptr->next->next == NULL) {
          // printf("Arrived at second last node");
          // at second last node.
          struct Node* temp = ptr->next; // store the last node in a temp variable
          ptr->next = NULL;
          free(temp); // free up the last node.
          break;
        }
        ptr=ptr->next;
      }
    }
    // case: target is somewhere in-between
     else {
      struct Node* ptr = head->next;
      while(ptr!=NULL) {
        if(*id - ptr->id == 2) {
          // arrived at one node prior.
          struct Node* temp = ptr->next; // store the target node.
          struct Node* next_node = temp->next;
          ptr->next = next_node; // link prior node to the next node.

          temp->next = NULL; // link of the target to the next node is broken.
          free(temp); // free up the target node.

          // decrease the ids of the subsequent nodes by 1.
          while (next_node!=NULL) {
            next_node->id = next_node->id-1;
            next_node = next_node->next;
          }
         break;  
        }
        ptr=ptr->next;
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
        
    }
  
   else {
     
     // traverse and print out the elements.
     // reset ptr to head

     ptr = head;
    
     while (ptr!=NULL) {

       printf("Value for node %d = %d", ptr->id+1, ptr->data);
       printf("\n");

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
  }
  else {
    printf("Nothing to print, as the entire linked list has been cleared \n");  
  }

  printf("Performing memory cleanup and exiting....\n");
  
  free(size);
  free(element);
  free(id);
  
  return 0;
} 
