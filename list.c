#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <string.h>

/* your list function definitions */
struct node* add_node(struct node* head, int val)
{
    struct node* new = (struct node *)malloc(sizeof(struct node));
    new -> value = val;
    if (head == NULL ){
      new -> next = NULL;
      return new;
    }
    else if (val < head->value)
      {
	new -> next = head;
	return new;
      }
    else if ( head ->next ==NULL   ){
      new->next = head -> next ;
      head -> next = new;
      return head;
    }
    else {
      struct node* curnode = head;
      while(val > curnode->next->value )
	{
	  curnode = curnode ->next ;
	  if (curnode ->next ==NULL ){
	    break;
	  }
	}
      // Now we are at the node whose value is greater than our new int.
      new -> next=curnode -> next; //will set to NULL if on the end of list
      curnode -> next = new;
      return head;
    }
}


char *remove_newline(char *s)
  {
    int len = strlen(s);
    if (len > 0 && s[len-1] == '\n')  // if there's a newline
      s[len-1] = '\0';          // truncate the string
    return s;
  }

int isint (char * str)
{
  char * nums = "0123456789";
  if( strlen(str) == 1 )
    {
      if(strchr( nums, str[0])!= NULL)
        {
	  return 1;
        }
      return 0;
    }
  if(  (   strchr(nums,str[0]) == NULL) && str[0]!= '-'){
    return 0;
  }
  int i = 1;
  int length =  strlen(str);
  for ( ; i < length ; i++)
    { if ( strchr(nums, str[i])== NULL){
	return 0;
      };
    }
  return 1;
}
