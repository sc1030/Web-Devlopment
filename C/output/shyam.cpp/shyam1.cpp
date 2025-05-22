#include <iostream>

using namespace std;

bool isSafe(int **arr, int x, int y, int n)
{
    if(x < n && y < n && arr[x][y] == 1)
    {
        return true;
    }return false;
}
void printSolution(int **solArr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << solArr[i][j] << " ";
        }
        cout << endl;
    }
}
bool ratinMaze(int** arr , int x, int y, int n, int ** solArr)
{
    if((x == (n-1)) && (y == (n-1)))
    {
        solArr[x][y] = 1;
        return true;
    }
    if(isSafe(arr,x, y, n))
    {
        solArr[x][y] = 1;
        if(ratinMaze(arr, x+1, y,n, solArr)){
            return true;
        }
        if(ratinMaze(arr,x,y+1, n, solArr)){
            return true;
        }
        solArr[x][y] = 0;
        return false;
    }
    return false;
}
int main()
{
    int n;
    cout<<" enter the size of the maze: ";
    cin>>n;
    int **arr = new int *[n];
    int **solArr = new int *[n];
    for(int i = 0; i<n; i++){
        arr[i] = new int[n];
        solArr[i] = new int[n];
        for(int j=0; j<n; j++){
            cout<<"Enter element at position: ("<< i <<", "<< j <<"): ";
            cin>>arr[i][j];
            solArr[i][j] = 0;
        }
    }
    if(!ratinMaze(arr, 0, 0 , n, solArr))
    {
        cout<<"No path Exists! "<< endl;
    }else{
        cout<<" Solution path: "<< endl;
        printSolution(solArr, n);
    }
    for(int i=0; i<n; i++){
        delete[] arr[i];
        delete[] solArr[i];
    }
    delete[] arr;
    delete[] solArr;
    
    return 0;
}