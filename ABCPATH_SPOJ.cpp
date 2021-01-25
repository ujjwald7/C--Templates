#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define V vector
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define endl "\n"
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
const int MOD=1e9+7;

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}
string tostring(int number){stringstream ss; ss<<number; return ss.str();}

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

int h,w;
int dx[]={-1,-1,-1,1,1,1,0,0};
int dy[]={0,1,-1,0,1,-1,-1,1};
int ans;
int dist[51][51];
char grid[51][51];
int dp[51][51];

int dfs(int cur_x,int cur_y)
{
    if(dp[cur_x][cur_y]!=0) return dp[cur_x][cur_y];
    for(int i=0;i<8;i++)
    {
        if(cur_x+dx[i]<h and cur_y+dy[i]<w and cur_x+dx[i]>=0 and cur_y+dy[i]>=0){
            if(grid[cur_x+dx[i]][cur_y+dy[i]]==grid[cur_x][cur_y]+1){
                dist[cur_x+dx[i]][cur_y+dy[i]]=dist[cur_x][cur_y]+1;
                ans=max(ans,dist[cur_x+dx[i]][cur_y+dy[i]]);
                dfs(cur_x+dx[i],cur_y+dy[i]);
            }
      //      dfs(cur_x+dx[i],cur_y+dy[i]);
        //    dist[cur_x+dx[i]][cur_y+dy[i]]=dist[cur_x][cur_y];
        }
    }
    return dp[cur_x][cur_y]=ans;
}

void solve()
{  
    int t=1;
    while(cin>>h>>w){
        if(h==0 and w==0) return;
        ans=0;
        for(int i=0;i<51;i++){
            for(int j=0;j<51;j++){ dist[i][j]=INT_MIN; dp[i][j]=0;}
        }
        vector<P>pts;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin>>grid[i][j];
                if(grid[i][j]=='A'){ ans=1;dist[i][j]=1; pts.pb(mp(i,j));}
            }
        }
        for(auto x:pts) dfs(x.F,x.S);
        cout<<"Case "<<t<<": "<<ans<<endl;
        t++;
    }
}  
    
int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE                    //file start
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);   
    #endif                                  //file end
    //int t; cin>>t;
    //while(t--)
    solve();
    return 0;
}
