#include "../include/extralib.h"
#include "../include/autolib.h"

void read_file(char* input_filename, char* file)
{
  int cnt = 0;
  FILE *fd_input;
	fd_input = fopen(input_filename, "r");

	if (fd_input == NULL) {
		fprintf(stderr, "[ERROR] Can't open the file <%s> for reading\n", input_filename);
		exit(EXIT_FAILURE);
  }
  while (fscanf(fd_input, "%c", &file[cnt]) != EOF) {
    ++cnt;
  }
  fclose(fd_input);
}

void read_stream(char* input_stream, char* stream)
{
  int cnt = 0;
  while (input_stream[cnt] != '\0') {
    stream[cnt] = input_stream[cnt];
    ++cnt;
  }
}
