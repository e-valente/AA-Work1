#include "readInputFile.h"
Graph statesBorders;

map<string, int> statesMap;
list<int> listColors;
map<int, string> statesFinalMap;
map<int, int> statesColored;

int readInput(char *filename)
{
    int totalStates;
    char buffer[1000];
    char stateItself[1000];
    char borderState[1000];
    int countRead, length, begin;
    char ch;

    FILE* fp;

    fp = fopen(filename, "r");


    //le primeira linha: nro de cidades
    length = 0;
    while (ch != '\n' && ch != EOF) {
        ch = getc(fp);
        buffer[length] = ch;
        length++;
    }

    ch = ' ';

    //obtem numero de cidades
    totalStates = atoi(buffer);


    //atualiza tamanho do grafo
    statesBorders.resize(totalStates);

    //atualiza tamanho do grafo auxiliar
    GraphInverse mygraphinverse(totalStates);


    for(int i = 0; i < totalStates; i++)
    {
        length = 0;

        //coloca cada linha em "buffer"
        while (ch != '\n' && ch != EOF) {
            ch = getc(fp);
            buffer[length] = ch;
            length++;
        }

        buffer[length] = '\n';
        ch = ' ';



        //obtem estado (anterior aos dois pontos ":")
        //-> nao é fronteira ainda
        begin = 0;
        sscanf(buffer + begin, "%[^:]:%n", stateItself, &countRead);
        begin += countRead;
        //cout <<"\nEstado: " << i <<" : " << stateItself << " : ";
        statesMap.insert(pair<string, int>(stateItself, i));
        statesFinalMap.insert(pair<int, string>(i, stateItself));


        //obtem estados que fazem fronteira ao estado atual
        //-> depois dos dois pontos ":"
        for(length = strlen(buffer);begin < length;)
        {
            sscanf(buffer + begin,"%*[ ]%[^,.\n]%*[,.\n]%n", borderState, &countRead);
            begin += countRead;
            //cout <<"  " << borderState;
            mygraphinverse[i].push_back(borderState);

        }

        //limpa a string (bug fix)
        makeNullString(buffer);

    }

     list<string>::iterator it2;

//    map<string, int>::iterator it;

//    for(it = statesMap.begin(); it != statesMap.end(); it++)
//    {
//        cout <<"\nindice: " << it->first << " dado: " << it->second << endl;
//    }



//    for(int j = 0; j < totalStates; j++)
//    {
//        for(it2 = mygraphinverse[j].begin(); it2 != mygraphinverse[j].end(); it2++)
//        {
//            cout << *it2 << " ";

//        }

//        cout <<"\n";
//    }


    //coloca estados fronteiras no mapa

    for(int i = 0; i < totalStates; i++)
    {
        for(it2 = mygraphinverse[i].begin(); it2 != mygraphinverse[i].end(); it2++)
        {
            statesBorders[i].push_back(statesMap[*it2]);
            //FMapborders.insert((pair<string, int>(statesMap[*it2], i));
            // cout << *it2 << " ";

        }

    }


//   cout <<"mapas de fronteiras: \n";
//    list<int>::iterator it3;

//    for(int i = 0; i < totalStates; i++)
//    {
//        for(it3 = statesBorders[i].begin(); it3 != statesBorders[i].end(); it3++)
//        {
//            cout <<*it3<< " ";

//        }

//        cout <<"\n";

//    }


    fclose(fp);

    return 0;

}


void makeNullString(char *str)
{
    for(int i = 0; i < 1000; i++)
        str[i] = '\0';
}




