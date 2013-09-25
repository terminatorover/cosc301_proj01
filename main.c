/*
 *
 * Anna Miettinen and Robera Geleta 
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/resource.h>
#include "list.h"
#include <ctype.h>
#include <sys/time.h>



void usage(char *program) {
    fprintf(stderr, "usage: %s [<datafile>]\n", program);
    exit(1);
}


int main(int argc, char **argv) {
    FILE *datafile = NULL;
    /* find out how we got invoked and deal with it */
    switch (argc) {
        case 1:
            /* only one program argument (the program name) */ 
            /* just equate stdin with our datafile */
            datafile = stdin;        
            break;

        case 2:
            /* two arguments: program name and input file */
            /* open the file, assign to datafile */
            datafile = fopen(argv[1], "r");

            if (datafile == NULL) {
                printf("Unable to open file %s: %s\n", argv[1], strerror(errno));
                exit(-1);
            }
            break;

        default:
            /* more than two arguments?  throw hands up in resignation */

            usage(argv[0]);
    }

    /* 
     * you should be able to just read from datafile regardless 
     * whether it's stdin or a "real" file.
     *
     */
    int who = RUSAGE_SELF;
    struct rusage use;
    int ret;
    ret = getrusage(who, &use);
    
    
    


   struct node * head = NULL;
   const char* delim = "\n\t ";
    
   char* new_line = (char * ) malloc(sizeof(char)*1024);
   new_line =  fgets( new_line, 1024 ,  datafile);

   while(new_line != NULL)
      { 
	char * tmp= NULL;
	char * new_parse = strtok_r( new_line, delim, &tmp);

	      
   	while(new_parse!= NULL)
	{     	
	  if ( new_parse[0] == '#')
	    { break;}
	  else{
	  

      	  if( isint(new_parse)==0){
	    new_parse = NULL;
	  }
	  if (new_parse == NULL)
	    {
	      new_parse =strtok_r(NULL, delim, &tmp);
	      continue;
	    }
	  else {
	    int new_value = atoi(new_parse);
	    head = add_node(head, new_value);
	  } 
	  new_parse =strtok_r(NULL,delim, &tmp);
	  }}
	

      new_line =  fgets( new_line, 1024 ,  datafile);


}
   printf("\n*** List Contents Begin *** \n");

    while(head != NULL)
      {
	printf("%d \n", head->value);
	head = head -> next;
      }

    fclose(datafile);
       printf("\n*** List Contents End *** \n");
       
    
    printf("User time is : %ld.%06ld\n", use.ru_utime.tv_sec, use.ru_utime.tv_usec);
    printf("System Time is : %ld.%06ld\n", use.ru_stime.tv_sec, use.ru_stime.tv_usec);
  

  return 0;
}

