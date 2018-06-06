#include <stdio.h>
#include <stdlib.h>

#define BUFF_SIZE 256
#define CELL_SIZE 256

int main(int argc, char **argv)
{
	if(argc != 2 && printf("Usgae: bf <.b file>\n")) return EXIT_FAILURE;

	unsigned int *ptr, *sta, *mem, i, s, pc = 0;
	char *cmd;

	FILE *fp = fopen(argv[1], "r");
	if(!fp && printf("The specified file does not exist.\n")) return EXIT_FAILURE;
	else {
		fseek(fp, 0, SEEK_END);
		s = ftell(fp);
		rewind(fp);

		cmd = calloc(s, sizeof(char));
		fread(cmd, 1, s, fp);
		fclose(fp);

		mem = calloc(BUFF_SIZE, sizeof(unsigned int));
		sta = ptr = mem;
	}

	while(pc < s) {
		switch(cmd[pc]) {
			case '>': ptr = ptr >= sta + BUFF_SIZE ? sta : ptr + 1; break;
			case '<': ptr = ptr <= sta ? sta + BUFF_SIZE : ptr - 1; break;
			case '+': *ptr = (*ptr + 1) % CELL_SIZE; break;
			case '-': *ptr = (*ptr - 1) % CELL_SIZE; break;
			case '.': putchar(*ptr); break;
			case ',': *ptr = getchar(); break;
			case '[':
				if(!*ptr) {
					i = 1;
					while(i) cmd[++pc] == ']' && i-- || cmd[pc] == '[' && i++;
				}
				break;
			case ']':
				if(*ptr) {
					i = 1;
					while(i) cmd[--pc] == '[' && i-- || cmd[pc] == ']' && i++;
				}
		}
		pc++;
	}

	free(cmd);
	free(mem);
	return EXIT_SUCCESS;
}
