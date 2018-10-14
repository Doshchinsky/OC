#ifndef AUTOLIB_H
#define AUTOLIB_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>

int automatic_processing(char* data, int choice);
void unsigned_automatic(char* data, int position, int* result);
void fiveletter_automatic(char* data, int position, int* result);
void ordered_automatic(char* data, int position, int* result);
void evenodd_automatic(char* data, int position, int* result);
void excludeSubstring_automatic(char* data, int position, int* result);
void excludeSubsequence_automatic(char* data, int position, int* result);

#endif
