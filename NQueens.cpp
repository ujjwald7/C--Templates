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

bool canPlace(char board[][100],int row,int col,int n)
{
    for(int i=0;i<col;i++)
    {
        if(board[row][i]=='Q'){
            return false;
        }
    }
    for(int i=0;i<row;i++)
    {
        if(board[i][col]=='Q'){
            return false;
        }
    }
    int i=row;
    int j=col;
    while(i>=0&&j>=0)
    {
        if(board[i][j]=='Q'){
            return false;
        }
        i--;j--;
    }
    i=row;j=col;
    while(i>=0&&j<n)
    {
        if(board[i][j]=='Q'){
            return false;
        }
        i--;
        j++;
    }
    return true;
}

bool SolveNQueens(char board[][100],int n,int row)
{
    if(row==n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return false;
    }

    for(int pos=0;pos<n;pos++)
    {
        if(canPlace(board,row,pos,n))
        {
            board[row][pos]='Q';
            bool nextRakhPaaye=SolveNQueens(board,n,row+1);
            if(nextRakhPaaye){
                return true;
            }
            board[row][pos]='.';
        }
    }
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
    int n;
    cin>>n;
    char board[100][100];
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++){
            board[i][j]='.';
        }
    }
    SolveNQueens(board,n,0);
    return 0;
}