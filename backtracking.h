#ifndef BACKTRACKING_H
#define BACKTRACKING_H
#include <list>
#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <string.h>
#include <string>
#include <map>

using namespace std;

#define TOTALCOLORS 4
#define success 1
#define failure -1
#define limit_by_iter -2
#define LIMIT_ITER 10000000

//types of backtracking
#define BK1 1
#define BK2 2
#define BK3 3
#define BK4 4

void setTotalColors();
void setStatesNotColored(int totalStates);
int getStateNotColored();
int backtrackingSearch(int type);
int backtrackingRecursive(int type);
bool testColorAndState(int color, int state);
void generateOutputFile();
int getAttribs();

int getAvailableDomainElement(int state, int nColor);
void drawAndUpdateStates(int myColor, int myState);
void undrawAndUpdateStates(int myColor, int myState);
#endif // BACKTRACKING_H
