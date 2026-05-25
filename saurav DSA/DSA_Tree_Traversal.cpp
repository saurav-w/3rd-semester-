#include <iostream>
using namespace std;

int graph[10][10], visited[10], n;

/* BFS Function */
void BFS(int start){
    int queue[10], front = 0, rear = 0;

    for(int i=0;i<n;i++)
        visited[i]=0;

    queue[rear++] = start;
    visited[start] = 1;

    cout<<"BFS Traversal: ";

    while(front < rear){
        int node = queue[front++];
        cout<<node<<" ";

        for(int i=0;i<n;i++){
            if(graph[node][i]==1 && visited[i]==0){
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

/* DFS Function */
void DFS(int node){
    cout<<node<<" ";
    visited[node]=1;

    for(int i=0;i<n;i++){
        if(graph[node][i]==1 && visited[i]==0)
            DFS(i);
    }
}

int main(){
    int choice, start;

    cout<<"Enter number of vertices: ";
    cin>>n;

    cout<<"Enter adjacency matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>graph[i][j];
        }
    }

    do{
        cout<<"\n--- Menu ---\n";
        cout<<"1. BFS Traversal\n";
        cout<<"2. DFS Traversal\n";
        cout<<"3. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice){

        case 1:
            cout<<"Enter starting vertex: ";
            cin>>start;
            BFS(start);
            cout<<endl;
            break;

        case 2:
            for(int i=0;i<n;i++)
                visited[i]=0;

            cout<<"Enter starting vertex: ";
            cin>>start;

            cout<<"DFS Traversal: ";
            DFS(start);
            cout<<endl;
            break;

        case 3:
            cout<<"Program Ended\n";
            break;

        default:
            cout<<"Invalid choice\n";
        }
        

    }while(choice!=3);

    return 0;
}

