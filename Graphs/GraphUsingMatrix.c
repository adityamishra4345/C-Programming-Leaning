#include<stdio.h>
#include<stdlib.h>
#define column 10
void init(int arr[][column],int rows){
    for(int i=0;i<rows;i++){
        for(int j=0;j<rows;j++){
            arr[i][j]=0;
        }
    }
}
void addedge(int arr[][column],int start,int end){
    arr[start][end]=1;
}
void deledge(int arr[][column],int start,int end){
    arr[start][end]=0;
}
void printg(int arr[][column],int rows){
    for(int i=0;i<rows;i++){
        for(int j=0;j<rows;j++){
            printf("%d  ",arr[i][j]);
        }
        printf("\n");
    }
}
void dirconn(int arr[][column],int rows){
    for(int i=0;i<rows;i++){
        printf("%d->",i);
        for(int j=0;j<rows;j++){
            if(arr[i][j]==1){
              printf("%d->",j);
            }
        }
        printf("END\n");
    }
}
void bfs(int arr[][column],int rows,int visited[],int curr){

}
void dfs(int arr[][column],int rows,int visited[],int curr){
    visited[curr]=1;
    printf("%d->",curr);
    for(int i=0;i<rows;i++){
        if(visited[i]==0&&arr[curr][i]==1){
            dfs(arr,rows,visited,i);
        }
    }
    
}

int main(){
    int arr[column][column];
    int rows,start,end,edge;
    printf("Enter the no of rows : ");
    scanf("%d",&rows);
    if(rows>column){
        printf("YOU ARE OUT OF BOUND");
        return -1;
    }
    init(arr,rows);
    printf("Enter the no of edge : ");
    scanf("%d",&edge);
    for(int i=0;i<edge;i++){
        printf("Enter the start then end point: ");
        scanf("%d %d",&start,&end);
        addedge(arr,start,end);
    }
    printf("\n");
    int visited[100]={0};
    dfs(arr,rows,visited,0);
    printf("End");
    
    
    return 0;
}