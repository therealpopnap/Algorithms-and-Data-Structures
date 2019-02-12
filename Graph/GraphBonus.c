#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Node
{	
    int vertice;
    int value;
    struct Node* pnext;
};

struct Node* initNode(int v);

struct Graph
{
    int V;
    int* visited;
    struct Node** adjlist; 
};

struct Node* initNode(int vertice) {
	struct Node* newnode = (struct Node*)(malloc(sizeof*newnode));
	newnode->vertice=vertice;
	newnode->pnext=NULL;
	
	return newnode;
}
//Function to initialize a Graph with V vertices
struct Graph* initGraph(int V) {
    struct Graph* newGraph = (struct Graph*)(malloc(sizeof*newGraph));
    newGraph->V=V;
    newGraph->adjlist = malloc(V* sizeof(struct Node*));
    newGraph->visited = malloc(V* sizeof(int));
 
    int i;
    for (i=0; i<V; i++) {
        newGraph->adjlist[i] = NULL;
        newGraph->visited[i] = 0;
    }
    
    return newGraph;
}
//Function to create an Edge between Vertices
void initEdge(struct Graph* newGraph, int src, int des, int value) { 
	struct Node* newNode = initNode(des);
	newNode->value=value;
	newNode->pnext = newGraph->adjlist[src];
    newGraph->adjlist[src] = newNode;
    
    newNode = initNode(src);
	newNode->value=value;
	newNode->pnext = newGraph->adjlist[des];
    newGraph->adjlist[des] = newNode;
}
int cost=0;
int costout=0;
//Function to traverse the graph in DEPTH FIRST STYLE
int Traverse(struct Graph* newGraph, int vertice) {
    struct Node* adjlist = newGraph->adjlist[vertice];
    struct Node* temp = adjlist;
    
    newGraph->visited[vertice] = 1;
    printf("Visit %d \n", vertice);
    
    while(temp!=NULL) {
        int connectedVertice = temp->vertice;
        if(newGraph->visited[connectedVertice] == 0) {
        	cost=cost+temp->value;
            Traverse(newGraph, connectedVertice);
        }
        temp = temp->pnext;
    }
    
    costout=cost;
}

void printGraph(struct Graph* graph)
{
    int v;
    for (v=0; v<graph->V; v++)
    {
        struct Node* temp = graph->adjlist[v];
        printf("\n Adjacency list of vertice %d\n ", v);
        while (temp)
        {
            printf("-> %d  ", temp->vertice);
            printf("v = %d |  ",temp->value);
            temp = temp->pnext;
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    struct Graph* graph = initGraph(7); //Change the number of vertices here
    initEdge(graph,0,1,4); // First two numbers = 2 vertices, last number = weight between them
    initEdge(graph,0,2,8); // Create a new graph here
    initEdge(graph,1,2,9);
    initEdge(graph,2,3,2);
    initEdge(graph,1,3,8);
    initEdge(graph,1,4,10);
    initEdge(graph,2,5,1);
    initEdge(graph,3,4,7);
    initEdge(graph,3,5,9);
    initEdge(graph,4,5,5);
    initEdge(graph,4,6,6);
    initEdge(graph,5,6,2);
    
    
    printGraph(graph); 
    printf("\n");
	
	printf("To traverse the graph, follow this order\n");
	Traverse(graph,6); //Here, choose a vertice to traverse from, in this case is vertice 6
	
	printf("\nThe cost to traverse in this order is %d ",costout);\
	printf("\n");
    
    printf("\nFor the Adjacency Matrix, I chose Linked list\n");
	printf("Reason: For a normal graph, the number of Edges are much more\n");
	printf("smaller than Vertice squared, so creating a matrix would be\n");
	printf("memory consuming and inefficient\n");
	printf("\n");
	printf("Also, I changed the name of the vertices from A B C to 0 1 2\n");
	printf("so the Linked Adjacency List can be created\n");
	printf("\n");
	printf("ABOVE IS THE PROGRAM TO TEST THE GRAPH IN THE EXERCISE, FEEL FREE TO\n");
	printf("TRAVERSE WITH A DIFFERENT VERTICE OR CREATE A NEW GRAPH WITH DIFFERENT DATA");
    
    return 0;
}
