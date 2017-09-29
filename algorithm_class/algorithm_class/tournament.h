#ifndef TOURNAMENT_HEADER
#define TOURNAMENT_HEADER

#include <stdlib.h>
#include <time.h>
#include <string.h>

char* match(char*, char*);
void tournament(char**, int);
char* tournament_recursive(char**, int, int);
void result(char**, int);

#endif
