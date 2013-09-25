#ifndef __LIST_H__
#define __LIST_H__

/* your list data structure declarations */
struct node {
  int value;
  struct node * next;
};

//void list(void);
/* your function declarations associated with the list */
struct node* add_node(struct node* head, int val);
char* remove_newline(char *s);
int isint (char * str);


#endif // __LIST_H__
