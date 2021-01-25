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
// #pragma comment(linker, '/STACK:200000')        //prevent stack overflow ..STACK Limiter
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

int m,n; 
char grid[1005][1005];
int colour[1005][1005];
int ans=0,cnt=0;
bool vis[1005][1005];
int dx[]={0,1,-1,0};
int dy[]={1,0,0,-1};

void bfsSSSP(int src_x,int src_y)   //Single Source Shortest Path
{
        queue<pair<P,int>>q;
        q.push(mp(mp(src_x,src_y),0));
        colour[src_x][src_y]=0;
        vis[src_x][src_y]=true;
        while(!q.empty())
        {
            auto node=q.front();
            auto x=node.F.F;
            auto y=node.F.S;
            vis[x][y]=true;
            // cout<<node<<" ";
            q.pop();
            //check the neighbors of the current node 
            for(int i=0;i<4;i++)
            {
                if(x+dx[i]>=0 and y+dy[i]>=0 and x+dx[i]<n and y+dy[i]<m)
                {
                    if(grid[x+dx[i]][y+dy[i]]!='_')
                    {
                        if(node.S+(grid[x+dx[i]][y+dy[i]]-'0')<colour[x+dx[i]][y+dy[i]]){
                            q.push(mp(mp(x+dx[i],y+dy[i]),node.S+(grid[x+dx[i]][y+dy[i]]-'0')));
                            colour[x+dx[i]][y+dy[i]]=node.S+(grid[x+dx[i]][y+dy[i]]-'0');
                        }
                    }

                }
            }
        }
    }

void solve()
{
    cin>>n>>m;
    int health=0,infected=0;
    // vis.resize(max(n,m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            colour[i][j]=INT_MAX;
            if(grid[i][j]=='1' or grid[i][j]=='2') health++;
        }
    }
    if(health==0){
        cout<<"0"<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        // bool flag=false;
        for(int j=0;j<m;j++){
            if(grid[i][j]=='0'){
                // memset(vis,false,sizeof(vis));
                bfsSSSP(i,j);
                // cout<<endl<<endl;
            } 
        }
    }
    int ans=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if((grid[i][j]=='2' or grid[i][j]=='1') and colour[i][j]==INT_MAX){
                cout<<"-1"<<endl;
                return;
            }
            if(grid[i][j]!='_' and grid[i][j]!='0') ans=max(ans,colour[i][j]);
            // cout<<colour[i][j]<<" ";
        }
        // cout<<endl;
    }
    cout<<ans<<endl;
}  
    
int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE                    //file start
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);   
    #endif                                  //file end
    // int cases=1;
    int t; cin>>t;
    while(t--)
    solve();
    return 0;
}