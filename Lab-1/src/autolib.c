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
  char *tokens[14] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "+", "-", ".", "E"};
  printf("Scanning %d position\n", position+1);

  if (position == 0) {
    if (data[position] == *tokens[position]) {
      printf(">   %c\n", *tokens[position]);
      if (data[position + 1] == *tokens[12]) {
        unsigned_automatic(data, ++position, result);
        return;
      } else {
        --*result;
        return;
      }
    }
    for (int i = 1; i < 10; ++i) {
      if (data[position] == *tokens[i]) {
        printf(">   %c\n", *tokens[i]);
        unsigned_automatic(data, ++position, result);
        return;
      }
    }
    --*result;
  }
  if (data[position] == '\n' || data[position] == '\0') {
    printf(">   EOF\n");
    return;
  }
  for (int i = 0; i < 14; ++i) {
    if (data[position] == *tokens[i]) {
      if ((i > 9) && (i < 12)) {
        printf(">   %c\n", *tokens[i]);
        if (data[position - 1] == *tokens[13]) {
          unsigned_automatic(data, ++position, result);
          return;
        } else {
          --*result;
          return;
        }
      } else if (i == 13) {
        printf(">   %c\n", *tokens[i]);
        for (int j = 0; j < 10; ++j) {
          if (data[position - 1] == *tokens[j]) {
            unsigned_automatic(data, ++position, result);
            return;
          }
        }
        --*result;
      } else if (i == 12) {
        printf(">   %c\n", *tokens[i]);
        if ((*result <= 0) && (data[position + 1] != '\n')) {
          ++*result;
          unsigned_automatic(data, ++position, result);
          --*result;
          return;
        } else {
          --*result;
          break;
        }
      } else {
        printf(">   %c\n", *tokens[i]);
        unsigned_automatic(data, ++position, result);
        return;
      }
    }
  }
  --*result;
}

void fiveletter_automatic(char* data, int position, int* result)
{
  char *tokens[5] = {"a", "e", "i", "o", "u"};
  int combo = 0;
  while (data[position] != '\n' && data[position] != '\0') {
    printf("Scanning %d position\n", position + 1);
    if (data[position] == *tokens[0]) {
      if (data[position + 1] == *tokens[1]) {
        if (data[position + 2] == *tokens[2]) {
          if (data[position + 3] == *tokens[3]) {
            if (data[position + 4] == *tokens[4]) {
              ++combo;
            }
          }
        }
      }
    }
    ++position;
  }
  if (combo < 1) {
    --*result;
  }
}

void ordered_automatic(char* data, int position, int* result)
{
  char *tokens[6] = {"a", "b", "c", "d", "e", "f"};
  int ordered = 0;
  while ((data[position] != '\n') && (data[position] != '\0')) {
    printf("Scanning %d position: %c\n", position + 1, data[position]);
    if (data[position] == *tokens[ordered]) {
      ++ordered;
    } else if ((ordered != 0) && (ordered < 6)) {
      --*result;
    }
    ++position;
  }
  if (ordered < 6) {
    --*result;
  }
}

void evenodd_automatic(char* data, int position, int* result)
{
  int a_counter = 0, b_counter = 0;
  while ((data[position] != '\0') && (data[position] != '\n')) {
    if (data[position] == 'a') {
      ++a_counter;
    } else if (data[position] == 'b') {
      ++b_counter;
    }
    ++position;
  }
  if ((a_counter % 2 == 0) && (b_counter % 2 != 0)) {
    return;
  } else --*result;
}

void excludeSubstring_automatic(char* data, int position, int* result)
{
  int a_counter = 0, b_counter = 0;
  while ((data[position] != '\0') && (data[position] != '\n')) {
    if (data[position] == 'a') {
      ++a_counter;
    } else if (data[position] == 'b') {
      ++b_counter;
    }
    ++position;
  }
  if ((a_counter > 0) && (b_counter > 1)) {
    --*result;
  }
}

void excludeSubsequence_automatic(char* data, int position, int* result)
{
  int combo = 0;
  while (data[position] != '\n' && data[position] != '\0') {
    if (data[position] == 'a') {
      if (data[position + 1] == 'b') {
        if (data[position + 2] == 'b') {
          ++combo;
        }
      }
    }
    ++position;
  }
  if (combo != 0) {
    --*result;
  }
}
