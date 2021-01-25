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
const int MOD=1e9+7;
#define time() cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" 

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

int k=2;
vector<vector<int>>T(k+1,vector<int>(k+1));
vector<int>F1(k+1);

vector<vector<int>>multiply(vector<vector<int>> A,vector<vector<int>> B ){   
    //third matrix mei result store
    vector<vector<int> > C(k+1,vector<int>(k+1));
    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            for(int x=1;x<=k;x++){               
                C[i][j] = (C[i][j] + (A[i][x]*B[x][j])%MOD)%MOD;
            }               
        }
    }
    return C;
}


vector<vector<int>>pow(vector<vector<int>> A,int p)
{
    //Base case
    if(p==1){
        return A;
    }
    //Rec Case
    if(p&1){
        return multiply(A, pow(A,p-1));
    }
    else{
        
        vector<vector<int>> X = pow(A,p/2);
        return multiply(X,X);
    }   
}

void solve()
{   
    int n; cin>>n;
    if(n<=1){
        cout<<n<<endl;
        return;
    }
    for(int i=1;i<=k;i++){
        F1[i] = i-1;
    }
    //2. Transformation matrix
    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
         if(i==1 and j==1) T[i][j]=0;
         else T[i][j]=1;   
        }
    }
    // 3. T^n-1
    T = pow(T,n-1);
    // 4. multiply by F1
    int res = 0;
    for(int i=1;i<=k;i++){
        res = (res + (T[2][i]*F1[i])%MOD)%MOD;
    }
    cout<<res<<endl;
}   
    
int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE                    //file start
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);   
    #endif                                  //file end
    int t; cin>>t;
    while(t--)
    solve();
    return 0;
}