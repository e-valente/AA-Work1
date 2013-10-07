#include "readInputFile.h"
#include "backtracking.h"

using namespace std;

void printResult(int);
void printUsage(char*);


int main(int argc, char *argv[])
{
    int bktype, ret;

    if(argc != 3)
    {
        printUsage(argv[0]);
        exit(1);
    }


    //gera o grafo
    readInput(argv[1]);
    bktype = atoi(argv[2]);


    //opcoes disponiveis: BK1, BK2, BK3 e BK4
    //BK1 - Backtracking normal, sem poda
    //BK2 - Backtracking com verificacao adiante
    //BK3 - Backtracking com verificacao adiante e MRV
    //BK4 - Backtracking com verificacao adiante, MRV e grau
    if(bktype > 0 && bktype < 5) ret = backtrackingSearch(bktype);
    else{
        printUsage(argv[0]);
        exit(1);
    }

    printResult(ret);

    return 0;

}




void printResult(int ret)
{

    if(ret == limit_by_iter)
    {
        cout <<"Numero maximo de atribuicoes alcancada: " << LIMIT_ITER << endl;
    }
    else cout <<"Total de atribuicoes: " << getAttribs() << endl;


    //escreve a saida no arquivo
    generateOutputFile();

}

void printUsage(char *program)
{
    cerr <<"Uso: " << program <<" <inputFile> <backtracking type: 1 .. 4>" << endl;
    cerr <<"Backtracking type 1: - Backtracking normal, sem poda" << endl;
    cerr <<"Backtracking type 2: - Bracktracking com verificacao adiante" << endl;
    cerr <<"Backtracking type 3: - Backtracking com verificacao adiante e MRV" << endl;
    cerr <<"Backtracking type 4: - Backtracking com verificacao adiante, MRV e grau" << endl;
    cerr <<"\nExample: " << program << " brasil.in 2"<<endl;

}
