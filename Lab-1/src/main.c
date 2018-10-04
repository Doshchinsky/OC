#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>

int main(int argc, char const *argv[]){
  if (argc < 2){
    fprintf(stderr, "[ERROR] Not enough arguments!\n");
    exit(EXIT_FAILURE);
  }

  if (!strcmp(argv[1], "-f")){
    if (argc < 3){
      fprintf(stderr, "[ERROR] No input file was found!\n");
      exit(EXIT_FAILURE);
    }
  } else if (!strcmp(argv[1], "-s")){
    if (argc < 3){
      fprintf(stderr, "[ERROR] No input stream was detected!\n");
      exit(EXIT_FAILURE);
    }
  }else{
    fprintf(stderr, "[ERROR] Unknow parameter!\n");
    exit(EXIT_FAILURE);
  }

  return EXIT_SUCCESS;
}
