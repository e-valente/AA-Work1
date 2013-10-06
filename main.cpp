#include "readInputFile.h"
#include "backtracking.h"

using namespace std;

int main()
{
    char inputFilename[] = "brasil.in";

    //gera o grafo
    readInput(inputFilename);

    backtrackingSearch();

    generateOutputFile();



    return 0;

}
