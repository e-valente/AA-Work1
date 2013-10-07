#include "readInputFile.h"
#include "backtracking.h"

using namespace std;

int main()
{
    //char inputFilename[] = "brasil.in";
    char inputFilename[] = "usa.in";

    int ret;

    //gera o grafo
    readInput(inputFilename);

    ret = backtrackingSearch(BK3);

    cout <<"Mapa: " << inputFilename << endl;

    if(ret == limit_by_iter)
    {
        cout <<"Numero maximo de atribuicoes alcancada: " << LIMIT_ITER << endl;
    }
    else cout <<"Total de atribuicoes: " << getAttribs() << endl;


    //escreve a saida no arquivo
    generateOutputFile();



    return 0;

}
