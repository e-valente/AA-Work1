#include "readInputFile.h"

using namespace std;

//grafo que contera aos estados e fronteiras
//ex: statesBorders[3].begin() -> retorna um iterador
//para o primeiro estado que faz fronteira com o
//estado 3 (zero)
Graph statesBorders;

int main()
{
    char inputFilename[] = "brasil.in";

    //gera o grafo
    readInput(inputFilename);


    return 0;

}


