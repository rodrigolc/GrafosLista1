#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

//Classe para o grafo (só para encapsular, não deve ficar cheia demais)

class graph{
  public:
    vector< vector< int > > nodes;

    graph(){nodes = vector< vector< int > >();};
    ~graph(){};

    void add_edge(int a, int b){int max = a < b ? b : a; nodes.resize(max,vector<int>());nodes[a].push_back(b);nodes[b].push_back(a);}
};


int main(){
    graph g;
    int n;
    scanf("%d\n",&n);
    char* line;
    int chars_read = 0;
    for(int i = 0; i < n; i++){
        getline(&line,&chars_read,stdin);
        char* to_free = line;
        char* token;
        while(token = strtok(line," \n")){
            line = nullptr;
            if(strlen(token)<1) continue;
            int b = atoi(token);
            g.add_edge(i,b);
        }
        free(line);
    }
    return 0;
}
