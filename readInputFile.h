#ifndef READINPUTFILE_H
#define READINPUTFILE_H
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <string.h>
#include <string>
#include <list>
#include <map>


using namespace std;

typedef vector< list<int> > Graph;
typedef vector< list<string> > GraphInverse;

extern Graph statesBorders;
extern map<string, int> statesMap;

int readInput(char *filename);
void makeNullString(char *str);

#endif // READINPUTFILE_H
