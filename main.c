
/*
// stack_allocation/main.c
// 
// (Bad) stack allocation example.
// 
// Nitsan Shai
// nshai@google.com

#include <stdio.h>

struct tree {
  int value;
  struct tree *left_child;
  struct tree *right_child;
};

typedef struct tree tree_t;

tree_t *make_tree(int value) {
  tree_t t;
  t.value = value;
  tree_t *t_pointer = &t;
  return t_pointer;
}

void make_other_things() {
  int fun_array[7] = {1,2,3,4,5,6,7};
  fun_array[5] = 20;
  char fun_string[25] = "I love programming in C!";
  char some_character = fun_string[6];
  int magic_number = some_character + 50;
}

int main() {
  tree_t *t1 = make_tree(3);
  printf("The value of t1 is %d\n", t1->value);

  tree_t *t2 = make_tree(4);
  printf("The value of t2 is %d, not surprising\n", t2->value);
  printf("But the value of t1 is now %d!\n", t1->value);

  printf("Making other things...\n");
  make_other_things();

  printf("Even worse, the value of t1 is now %d\n", t1->value);
  printf("And the value of t2 is %d\n", t2->value);
  return 0;
}
*/

#include <stdio.h>

#include "list.h"

int main()
{  
  list_t *my_list = list_alloc();
  
  //  Testing add
  list_add_to_back(my_list, 3);        
  list_add_to_back(my_list, 4);        
  list_add_to_back(my_list, 5);   
  list_print(my_list); //3 4 5 
  printf("List is %d", list_length(my_list)); //3
  printf(" items long \n");
  list_add_to_front(my_list, 2);       
  list_add_to_front(my_list, 1);       
  list_add_to_front(my_list, 0); 
  list_print(my_list); //0 1 2 3 4 5 
  printf("List is %d", list_length(my_list)); //6
  printf(" items long \n");
  list_add_at_index(my_list, 99, 4);   
  list_print(my_list); //0 1 2 3 99 4 5
  printf("List is %d", list_length(my_list)); //7
  printf(" items long \n");
  
 
  //  Testing remove
  list_remove_from_back(my_list); //0 1 2 3 99 4
  list_print(my_list);
  printf("List is %d", list_length(my_list)); //6
  printf(" items long \n");
  list_remove_from_front(my_list);//1 2 3 99 4
  list_print(my_list);
  printf("List is %d", list_length(my_list)); //5
  printf(" items long \n");
  list_remove_at_index(my_list, 1);    //1 2 99 4
  printf("List is %d", list_length(my_list)); //4
  printf(" items long \n");
  
  
  //  Testing Seach
  printf("Searching for 99. %d\n", list_is_in(my_list, 99));
  printf("Index 3 is: %d\n", list_get_elem_at(my_list, 3));                
  
  list_free(my_list);

  return 0;
}