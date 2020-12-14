#include <stdio.h>     /* for printf */
#include <stdlib.h>    /* for exit */
#include <string.h>
#include <unistd.h>

#define MAX_ARGS 10
#define MAX_C 100


int main(int argc, char **argv) {
  int c;
  char       cmd[MAX_C+1];

  int argc_i;
  char *argv_i[MAX_ARGS];
  
  
  while (1) {
    // Read string, for example: cmd -i -a
    fgets(cmd,MAX_C,stdin);
    cmd[strlen(cmd) - 1] = 0;
    if (strlen(cmd) <= 1) break;

    // Transform into argc_i, argv_i, to feed to getopt
    argc_i = 0;
    char *p2 = strtok(cmd, " ");
    while (p2 && argc_i < MAX_ARGS)
      {
	argv_i[(argc_i)++] = p2;
	p2 = strtok(NULL, " ");
      }
    argv_i[argc_i] = 0;


    // Reset getopt
    optind  = 1;
    int option_index = 0;

    
    while (1) {
      c = getopt(argc_i, argv_i, "ia");

      if (c == -1)
	break;

      switch (c) {
      case 'a':
	printf("  -- option a\n");
	break;

      case 'i':
	printf("  -- option i\n");
	break;

      case '?':
	printf("  -- option unknown\n");
	break;

      default:
	printf("?? getopt returned character code 0%o ??\n", c);
      }
    }

    printf("\n\n");

    if (optind < argc) {
      printf("non-option ARGV-elements: ");
      while (optind < argc)
	printf("%s ", argv[optind++]);
      printf("\n");
    }
  }

  exit(EXIT_SUCCESS);
}
