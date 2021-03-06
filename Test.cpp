#include "jrbgraph.hpp"
#include <stdio.h>
#include <iostream>
using namespace std;
void showlist(list <string> g)
{
    list <string> :: iterator it;
    for(auto const& p:g)
        cout<<'\t'<<p;
    cout<<'\n';
}
int main()
{
	int i,n;
	char output[10][10];
    Graph g = createGraph();
    addEdge_str(g, "HNL", "LAX", 2555);
	addEdge_str(g, "LAX", "SFO", 337);
	addEdge_str(g, "LAX", "ORD", 3000);
	addEdge_str(g, "LAX", "DFW", 1233);
	addEdge_str(g, "SFO", "ORD", 1843);
	addEdge_str(g, "ORD", "PVD", 849);
	addEdge_str(g, "ORD", "DFW", 802);
	addEdge_str(g, "DFW", "LGA", 1387);
	addEdge_str(g, "DFW", "MIA", 1120);
	addEdge_str(g, "LGA", "PVD", 142);
	addEdge_str(g, "LGA", "MIA", 1099);
	addEdge_str(g, "MIA", "PVD", 1205);

    
	n = getAdjacentVertices_str (g, "LAX", output);
    printf("Number of adjacent vertices : %d\n",n);
    if (n==0) printf("No adjacent vertices of node \n");
    else {   
       printf("Adjacent vertices of node LAX:");
       for (i=0; i<n; i++) printf("%5s", output[i]);
    } 
    printf("\n");
    
    printf("\nBFS tu LAX\n");
    BFS(g, "LAX");
    Dijkstra(g,"LAX"); 
    printf("\nCac dinh hien co tren do thi: \n");
    list<string> vertexes = getAllVertexes(g);
    showlist(vertexes);
    printf("\n");
    //printf("\nDFS tu HN\n");
	//DFS(g, "HN");
    puffer_code("tree.txt");
    //output_file_ColoredGrarp("dothi.txt");
    return 0;
}
