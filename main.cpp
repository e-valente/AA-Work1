#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <string.h>
#include <string>
#include <list>
#include <map>

void limpa(char *str);
using namespace std;

typedef vector< list<int> > Graph;
typedef vector< list<string> > GraphInverse;

int main()
{
    int totalStates;
    char buffer[1000];
    char a[1000];
    char b[1000];
    FILE* fp;
    int n, len;
    map<string, int> mymap;




    fp = fopen("brasil.in", "r");

    char ch;
    int length = 0;
    while (ch != '\n' && ch != EOF) {
        ch = getc(fp);
        buffer[length] = ch;
        length++;
    }

    ch = ' ';

    totalStates = atoi(buffer);



    GraphInverse mygraphinverse(totalStates);
    Graph statesborders(totalStates);



    // for(;scanf("%[^\n]\n", buffer)!=EOF;){


    int beg = 0;
    for(int i = 0 ; i < totalStates; i++)
    {
        length = 0;
        while (ch != '\n' && ch != EOF) {
            ch = getc(fp);
            buffer[length] = ch;
            length++;
        }

        buffer[length] = '\n';
        ch = ' ';
        // getc(fp);

        //  cout <<"linha vale: " << buffer << endl;


        beg = 0;
        sscanf(buffer + beg, "%[^:]:%n", a, &n);
        beg += n;
        cout <<"\nEstado: " << i <<" : " << a << " : ";
        mymap.insert(pair<string, int>(a, i));


        for(len = strlen(buffer);beg < len;)
        {
            int n;
            sscanf(buffer + beg,
                   "%*[ ]%[^,.\n]%*[,.\n]%n",
                   b, &n);
            beg+=n;
            cout <<"  " << b;
            mygraphinverse[i].push_back(b);

        }

        limpa(buffer);

    }

    map<string, int>::iterator it;

    for(it = mymap.begin(); it != mymap.end(); it++)
    {
        cout <<"\nindice: " << it->first << " dado: " << it->second << endl;
    }


    list<string>::iterator it2;
    for(int j = 0; j < 27; j++)
    {
        for(it2 = mygraphinverse[j].begin(); it2 != mygraphinverse[j].end(); it2++)
        {
            cout << *it2 << " ";

        }

        cout <<"\n";
    }


    //coloca estados fronteiras no mapa

    for(int i = 0; i < totalStates; i++)
    {
        for(it2 = mygraphinverse[i].begin(); it2 != mygraphinverse[i].end(); it2++)
        {
            statesborders[i].push_back(mymap[*it2]);
            //mymapborders.insert((pair<string, int>(mymap[*it2], i));
           // cout << *it2 << " ";

        }

    }


    cout <<"mapas de fronteiras: \n";
    list<int>::iterator it3;

    for(int i = 0; i < totalStates; i++)
    {
        for(it3 = statesborders[i].begin(); it3 != statesborders[i].end(); it3++)
        {
            cout <<*it3<< " ";

        }

        cout <<"\n";

    }





    fclose(fp);

    return 0;

}

void limpa(char *str)
{
    for(int i = 0; i < 1000; i++)
        str[i] = '\0';
}



