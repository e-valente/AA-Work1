#include "readInputFile.h"
#include "backtracking.h"


extern Graph statesBorders;

extern map<string, int> statesMap;
extern list<int> listColors;
extern map<int, string> statesFinalMap;
extern map<int, int> statesColored;

int attribs;

void setTotalColors()
{
    for(int i = 0; i < TOTALCOLORS; i++)
        listColors.push_back(i);
}


void setStatesNotColored(int totalStates)
{
    for(int i = 0; i < totalStates; i++)
        statesColored.insert(pair<int, int>(i, -1));
}

int backtrackingSearch(int type)
{
    attribs = 0;
    //configura total de cores possiveis
    setTotalColors();

    //configura total de estados nao pintados
    setStatesNotColored(statesFinalMap.size());

    return backtrackingRecursive(type);
}

int backtrackingRecursive(int type)
{
    int myState, result;

    //se a atribuicao é completa, temos uma solucao
    if(getStateNotColored() == failure) return success;

    //escolher um estado que nao foi atribuido
    //e guardar a variavel
    myState = getStateNotColored();


    //para cada elemento do dominino (cor)
    map<int, int>::iterator it;

    for(int color = 0; color < listColors.size(); color++)
    {
        attribs++;

        if(attribs == LIMIT_ITER)return limit_by_iter;

        if(testColorAndState(color, myState))
        {

            //pinta o estado state de cor color
            //atualiza o estados pintado
            it = statesColored.find(myState);
            it->second = color;

            result = backtrackingRecursive(type);
            if (result != failure) return result;

            //remove var=value
            it->second = -1;

        }


    }

    return failure;

}


//fica melhor se fizer randomico
int getStateNotColored()
{
    map<int, int>::iterator it;

    for(it = statesColored.begin(); it != statesColored.end(); it++)
        //se o estao nao foi pintado, entao sera retornado
        if(it->second == -1) return it->first;


    return failure;
}



bool testColorAndState(int color, int state)
{
    list<int>::iterator it;


    //para cada estado que faz fronteira com estado: state
    for(it = statesBorders[state].begin(); it != statesBorders[state].end(); it++)
    {
        //comparamos sua cor: se for igual
        if(statesColored[*it] == color) return false;

    }

    return true;

}


void generateOutputFile()
{
    ofstream myOutputFile;


    map<int, int>::iterator it;
    map<int, string>::iterator it2;
    map<int, string> colors;


    colors.insert(pair<int, string>(0, "Amarelo"));
    colors.insert(pair<int, string>(1, "Verde"));
    colors.insert(pair<int, string>(2, "Vermelho"));
    colors.insert(pair<int, string>(3, "Azul"));

    myOutputFile.open ("saida.txt");


    for(it = statesColored.begin(); it != statesColored.end(); it++)
    {

        it2 = statesFinalMap.find(it->first);
        // cout <<it2->second <<": " << colors[it->second] << "."<< endl;
        myOutputFile <<it2->second <<": " << colors[it->second] << "."<< endl;

    }

    myOutputFile.close();
}

int getAttribs()
{
    return attribs;
}


