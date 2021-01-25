#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define V vector
#define pb push_back
#define mp make_pair
#define endl "\n"
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define MOD 1000000007  //1e9+7

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

int visited[100][100]={0};

bool SolveRatMaze(char maze[][100],int n,int m,int row,int col,int solution[][100])
{
    if(row==n&&col==m)
    {
        solution[row][col]=1;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                cout<<solution[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    if(visited[row][col]==1){
        return false;
    }
    visited[row][col]=1;    
    solution[row][col]=1;
    if(row+1<=n&& !visited[row+1][col]){
        bool rightsuccess=SolveRatMaze(maze,n,m,row+1,col,solution);
        if(rightsuccess){
            return true;
        }
    }
    if(col+1<=m&& !visited[row][col+1]){
        bool downsuccess=SolveRatMaze(maze,n,m,row,col+1,solution);
        if(downsuccess){
            return true;
        }
    }
    solution[row][col]=0;
    return false;
}

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE                    //file start
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);   
    #endif                                  //file end
    int n,m;
    cin>>n>>m;
    char maze[100][100];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++){
            cin>>maze[i][j];
            if(maze[i][j]=='X'){
                visited[i][j]=1;
            }
        }
    }
    m--;n--;
    int solution[100][100]={0};
    if(!SolveRatMaze(maze,n,m,0,0,solution))
    {
        cout<<"-1"<<endl;
    }           
    return 0;
}