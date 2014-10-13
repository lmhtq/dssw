#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aware.h"
#include "interact.h"
#include "comm.h"

int help_info()
{
	printf("How to use dssw.\n");
}

int handle_cmd(char *argv)
{
	if (strcmp(argv, "help") == 0 || strcmp(argv, "H") == 0) {
		help_info();
	}
	if (strcmp(argv, "init0") == 0 || strcmp(argv, "I0") == 0) {
		init_ac();
	}
	if (strcmp(argv, "init1") == 0 || strcmp(argv, "I1") == 0) {
		init_sap();
	}
}

int main(int argc, char **argv)
{
	/*strip off self*/
	argc--;
	char *argv0 = *++argv;
	
	if (argc <= 0) {
		help_info();
	}

	handle_cmd(argv0);

	return 0;
}