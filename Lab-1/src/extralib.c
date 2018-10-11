#include "../include/extralib.h"

void read_file(char* input_filename, char* file)
{
  int cnt = 0;
  printf("Input file: %s\n", input_filename);
  FILE *fd_input;
	fd_input = fopen(input_filename, "r");

	if (fd_input == NULL) {
		fprintf(stderr, "[ERROR] Can't open the file <%s> for reading\n", input_filename);
		exit(EXIT_FAILURE);
  }
  while (fscanf(fd_input, "%c", &file[cnt]) != EOF) {
    printf("%c\n", file[cnt]);
    ++cnt;
  }
  fclose(fd_input);
}

void read_stream(char* input_stream, char* stream)
{
  int cnt = 0;
  printf("Input stream: %s\n", input_stream);
  while (input_stream[cnt] != '\0') {
    stream[cnt] = input_stream[cnt];
    printf("%c\n", stream[cnt]);
    ++cnt;
  }
}
