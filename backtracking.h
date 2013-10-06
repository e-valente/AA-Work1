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

void setTotalColors();
void setStatesNotColored(int totalStates);
int getStateNotColored();
int backtrackingSearch();
int backtrackingRecursive(int assignment, int state);
bool testColorAndState(int color, int state);
void generateOutputFile();
#endif // BACKTRACKING_H
