#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	char **pyargv = malloc(sizeof *pyargv * (argc + 2));
	if (!pyargv)
	{
		return (1);
	}
	// Ref: Invoking python from C
	// https://stackoverflow.com/a/69813221/9160572
	pyargv[0] = "/usr/bin/python3";
	// pyargv[1] = "/Users/louis/Desktop/42school/42-push_swap/push_swap.py";
	// pyargv[1] = "/Users/lxu/Desktop/42school/42-push_swap/push_swap.py";
	pyargv[1] = "/home/louis/Desktop/42school/42-push_swap/push_swap.py";
	int i = 1;
	while (i < argc) {
		pyargv[i + 1] = argv[i];
		i++;
	}
	pyargv[i + 1] = NULL;
	execv(pyargv[0], pyargv);

	// char **tmp = argv;
	// while (*tmp){
	// 	printf("The input args are %s\n", *tmp);
	// 	tmp++;
	// }
	// printf("What is your name? ");
	// char name[20];
	// int a = scanf("%19s", name);
	// printf("Your inputed name was: %s\n", name);

	// argc++;
	// a++;

	// // int status;
	// char *paramsList[] = {
	// 	"/usr/bin/python3",
	// 	"test2.py",
	// 	(char *)NULL
	// 	};
	// execv(paramsList[0], paramsList);
	// printf("Done");
}