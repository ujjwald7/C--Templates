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

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

unordered_map<int,int>dist;
unordered_map<int,bool>visited;

void bfs(int k,int s,map<int,list<int>>&graph,vector<int>&visit_freq)
{   
    queue<int>q;
    q.push(k);
    visit_freq[k]++;
    visited[k]=true;
    while(!q.empty())
    {
        int fr=q.front();
        for(auto edge: graph[fr]){
            if(dist[fr]+1<=s and !visited[edge]){
                q.push(edge);
                visit_freq[edge]++;
                dist[edge]=dist[fr]+1;
                visited[edge]=true;
            }
        }
        q.pop();
    }
}

void solve()
{  
    int n,r,m;  cin>>n>>r>>m;
    map<int,list<int>>graph;
    while(r--){
        int a,b; cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    vector<int>visit_freq(n+1,0);
    while(m--){
        int k,s; cin>>k>>s;
        dist.clear();
        visited.clear();
        bfs(k,s,graph,visit_freq);
    }
    for(int i=1;i<=n;i++){
        if(visit_freq[i]!=1){
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
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