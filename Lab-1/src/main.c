#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>

#include "../include/extralib.h"

#define MAX_SIZE 255

int main(int argc, char *argv[]){
  if (argc < 2){
    fprintf(stderr, "[ERROR] Not enough arguments!\n");
    exit(EXIT_FAILURE);
  }

  char input_file[MAX_SIZE];
  char input_stream[MAX_SIZE];

  if (!strcmp(argv[1], "-f")){
    if (argc < 3){
      fprintf(stderr, "[ERROR] No input file was found!\n");
      exit(EXIT_FAILURE);
    }
    read_file(argv[2], input_file);
  } else if (!strcmp(argv[1], "-s")){
    if (argc < 3){
      fprintf(stderr, "[ERROR] No input stream was detected!\n");
      exit(EXIT_FAILURE);
    }
    read_stream(argv[2], input_stream);
  } else {
    fprintf(stderr, "[ERROR] Unknow parameter!\n");
    exit(EXIT_FAILURE);
  }

  return EXIT_SUCCESS;
}
