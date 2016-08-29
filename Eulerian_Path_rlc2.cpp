#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <list>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


list<int> *filas;

void add_edge(int a, int b){
    filas[a].push_back(b);
}

list<int> acha_ciclo(int start){
    list<int> ret;
    int cur = start;
    do{
        int next = filas[cur].front();
        filas[cur].pop_front();
        if(next != cur) filas[next].erase(find(filas[next].begin(),filas[next].end(),cur)); //HACK
        //tem de funcionar, pois sempre há o reflexo da aresta no outro vertice
        cur = next;
        ret.push_back(cur);
    }while(cur != start);
    return ret;
}

int main(){

    int n;
    scanf("%d\n",&n);
    filas = new list<int>[n+1];
    string line;
    for(int i = 1; i <= n; i++){//codigo de leitura das arestas

        getline(cin,line);
        char* to_tok = (char*) malloc(sizeof(char)*(line.length() + 1));
        strcpy(to_tok,line.c_str());
        char* aux = to_tok;
        char* token;
        while( ( token = strtok(aux," \n") ) ){
            aux = nullptr;
            if( strlen(token) <1) continue;
            int b = atoi(token);
            add_edge(i,b);
        }
        free(to_tok);
    }

    auto visitados = list<int>{1};

    for(auto icur = visitados.begin(); icur != visitados.end(); icur++){
        auto s = *icur;
        if(filas[s].size()){
            auto x = acha_ciclo(s);
            visitados.insert(next(icur),x.begin(),x.end()); //insere depois,
                            //pois iremos iterar sobre eles tbm
        }
    }
    for(auto s:visitados){
        printf("%d ",s);
    }
    delete filas;
    return 0;
}
