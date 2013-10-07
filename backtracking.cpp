#include "readInputFile.h"
#include "backtracking.h"


extern Graph statesBorders;

extern map<string, int> statesMap;
extern list<int> listColors;
extern map<int, string> statesFinalMap;
extern map<int, int> statesColored;

vector<vector<int> > colorsAvailable;

int attribs;



int backtrackingSearch(int type)
{
    attribs = 0;
    //configura total de cores possiveis
    setTotalColors();

    //configura total de estados nao pintados
    setStatesNotColored(statesFinalMap.size());

    //backtraking com verificacao adiante
    if(type == BK2)
    {
        //aloca linhas
        colorsAvailable.resize(statesMap.size());

        for(int i = 0; i < statesMap.size(); i++)
        {
            colorsAvailable[i].resize(TOTALCOLORS);
            for(int j = 0 ; j < TOTALCOLORS; j++)
            {
                //para o i-esimo estado, teremos
                //a cor j disponivel
                colorsAvailable[i][j] = 1;
            }
        }
    }

    return backtrackingRecursive(type);
}

int backtrackingRecursive(int type)
{
    int myState, myColor, result;

    //se a atribuicao é completa, temos uma solucao
    if(getStateNotColored() == failure) return success;

    //escolher um estado que nao foi atribuido
    //e guardar a variavel
    myState = getStateNotColored();


    //para cada elemento do dominino (cor)
    map<int, int>::iterator it;

    //backtracking padrao
    if(type == BK1)
    {
        for(myColor = 0; myColor < listColors.size(); myColor++)
        {
            attribs++;

            if(attribs == LIMIT_ITER)return limit_by_iter;


            if(testColorAndState(myColor, myState))
            {

                //pinta o estado state de cor color
                //atualiza o estados pintado
                it = statesColored.find(myState);
                it->second = myColor;

                result = backtrackingRecursive(type);
                if (result != failure) return result;

                //remove var=value
                it->second = -1;

            }

        }

        return failure;
    }

    //backtraking com verificacao adiante
    if(type == BK2)
    {
        attribs++;
        myState = getStateNotColored();

        //obtem cor disponivel

        for(int i = 0; i < TOTALCOLORS; i++)
        {
            if(attribs == LIMIT_ITER)return limit_by_iter;
            myColor = getAvailableDomainElement(myState, i);


            if(myColor < 0) return failure;

            //pinta estado e atualiza a lista de
            //restricoes dos estados vizinhos
            drawAndUpdateStates(myColor, myState);

            result = backtrackingRecursive(type);

            if (result != failure) return result;

            //desfaz a pintura e atualiza estados
            // cout <<"vou desfazer estado e cor: " << myState << " " <<myColor << endl;
            undrawAndUpdateStates(myColor, myState);
        }


        return failure;
    }


    return failure;




}

void drawAndUpdateStates(int myColor, int myState)
{
    //pinta estado
    map<int, int>::iterator it;

    it = statesColored.find(myState);
    it->second = myColor;

    //atualiza lista de cores (nenhuma cor possivel) para o estado
    //que esta sendo pintado
    for(int i = 0; int j = 0; j++)
    {
        colorsAvailable[myState][i] = 0;
    }

    list<int>::iterator it2;

    for(it2 = statesBorders[myState].begin(); it2 != statesBorders[myState].end(); it2++)
    {
        colorsAvailable[*it2][myColor] = 0;
    }


}


void undrawAndUpdateStates(int myColor, int myState)
{
    //pinta estado
    map<int, int>::iterator it;

    it = statesColored.find(myState);
    it->second = -1;

    //atualiza lista de cores deixa a cor disponivel para o estado
    //que esta sendo pintado
    for(int i = 0; int j = 0; j++)
    {
        colorsAvailable[myState][i] = 1;
    }

    list<int>::iterator it2;

    for(it2 = statesBorders[myState].begin(); it2 != statesBorders[myState].end(); it2++)
    {
        colorsAvailable[*it2][myColor] = 1;
    }


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


//retona a nColor-esima cor disponivel
int getAvailableDomainElement(int state, int nColor)
{

    int count = 0;

    for(int i = 0; i < TOTALCOLORS; i ++)
        if(colorsAvailable[state][i]  == 1 )
        {
            if(count == nColor)return i;
            count++;
        }

    return -1;
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


