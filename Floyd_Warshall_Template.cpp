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

void solve()
{      
    int n,m,q; cin>>n>>m>>q;
    int floyd[502][502];
    // memset(&floyd,INT_MAX,sizeof floyd);
    for(int i=1;i<=n;i++){
        floyd[i][i]=0;
        for(int j=1;j<=n;j++){
            if(i!=j) floyd[i][j]=1e18;
        }
    }
    // db(LONG_MAX,2e9);
    for(int i=0,x,y,c;i<m;i++){
        cin>>x>>y>>c;
        floyd[x][y]=min(floyd[x][y],c);
        floyd[y][x]=min(floyd[y][x],c);
        // floyd[x][y]=c;
        // floyd[y][x]=c;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                floyd[j][k]=min(floyd[j][k],floyd[j][i]+floyd[i][k]);
            }
        }
    }
    for(int i=0,x,y;i<q;i++){
        cin>>x>>y;
        if(floyd[x][y]!=1e18) cout<<floyd[x][y]<<endl;
        else cout<<"-1"<<endl;
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
    // int cases=1;
    // int t; cin>>t;
    // while(t--)
    solve();
    return 0;
}
