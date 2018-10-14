#include "../include/extralib.h"
#include "../include/autolib.h"

int automatic_processing(char* data, int choice)
{
  int result = 0;
  switch (choice) {
    case 1:
      printf("First automatic was choosen\n");
      unsigned_automatic(data, 0, &result);
      break;
    case 2:
      printf("Second automatic was choosen\n");
      fiveletter_automatic(data, 0, &result);
      break;
    case 3:
      printf("Third automatic was choosen\n");
      ordered_automatic(data, 0, &result);
      break;
    case 4:
      printf("Fourth automatic was choosen\n");
      evenodd_automatic(data, 0, &result);
      break;
    case 5:
      printf("Fifth automatic was choosen\n");
      excludeSubstring_automatic(data, 0, &result);
      break;
    case 6:
      printf("Sixth automatic was choosen\n");
      excludeSubsequence_automatic(data, 0, &result);
      break;
  }
  return result;
}

void unsigned_automatic(char* data, int position, int* result)
{
  --*result;
}

void fiveletter_automatic(char* data, int position, int* result)
{
  --*result;
}

void ordered_automatic(char* data, int position, int* result)
{
  --*result;
}

void evenodd_automatic(char* data, int position, int* result)
{
  --*result;
}

void excludeSubstring_automatic(char* data, int position, int* result)
{
  --*result;
}

void excludeSubsequence_automatic(char* data, int position, int* result)
{
  --*result;
}
