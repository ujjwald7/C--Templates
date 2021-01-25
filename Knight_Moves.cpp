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

map<string,list<string>>graph;
map<string,int>dist;
map<string,bool>visited;

void bfs(string src,string dest)
{
    for(auto x: graph){
        dist[x.F]=INT_MAX;
    }
    queue<string>q;
    q.push(src);
    dist[src]=0;
    while(!q.empty())
    {
        string front=q.front();
        if(front==dest) return;
        q.pop();
        for(auto edge : graph[front]){
            if(dist[edge]==INT_MAX){
                q.push(edge);
                dist[edge]=dist[front]+1;
            }    
        }
        visited[front]=true;
    }
}

void solve()
{	
    string src,dest; cin>>src>>dest;
    bfs(src,dest);
    cout<<dist[dest]<<endl;
    dist.clear();
    visited.clear();
}   
	
int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE                    //file start
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);   
    #endif                                  //file end
    char tempx,tempy;
    int temp,y1,y2,x1,x2;
    string tempo;
    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++){
            char c=i-1+'a';
            char f=j+'0';
            string curr;
            curr+=c;
            curr+=f;
            if(i>2 and j<8){
                temp=i-2;
                y1=j+1;
                tempx=temp-1+'a';
                tempy=y1+'0';
                tempo=tempx;
                tempo+=tempy;
                graph[curr].pb(tempo);
                graph[tempo].pb(curr);
            }   
            if(i>2 and j>1){
                temp=i-2;
                y1=j-1;
                tempx=temp-1+'a';
                tempy=y1+'0';
                tempo=tempx;
                tempo+=tempy;
                graph[curr].pb(tempo);
                graph[tempo].pb(curr);
            }
            if(i<7 and j>1){
               temp=i+2;
                y1=j-1;
                tempx=temp-1+'a';
                tempy=y1+'0';
                tempo=tempx;
                tempo+=tempy;
                graph[curr].pb(tempo);
                graph[tempo].pb(curr); 
            }
            if(i<7 and j<8){
                temp=i+2;
                y1=j+1;
                tempx=temp-1+'a';
                tempy=y1+'0';
                tempo=tempx;
                tempo+=tempy;
                graph[curr].pb(tempo);
                graph[tempo].pb(curr);
            }
            if(i<8 and j>2){
                temp=i+1;
                y1=j-2;
                tempx=temp-1+'a';
                tempy=y1+'0';
                tempo=tempx;
                tempo+=tempy;
                graph[curr].pb(tempo);
                graph[tempo].pb(curr);
            }
            if(i>1 and j>2){
                temp=i-1;
                y1=j-2;
                tempx=temp-1+'a';
                tempy=y1+'0';
                tempo=tempx;
                tempo+=tempy;
                graph[curr].pb(tempo);
                graph[tempo].pb(curr);
            }
            if(i<8 and j<7){
                temp=i+1;
                y1=j+2;
                tempx=temp-1+'a';
                tempy=y1+'0';
                tempo=tempx;
                tempo+=tempy;
                graph[curr].pb(tempo);
                graph[tempo].pb(curr);
            }
            if(i>1 and j<7){
                temp=i-1;
                y1=j+2;
                tempx=temp-1+'a';
                tempy=y1+'0';
                tempo=tempx;
                tempo+=tempy;
                graph[curr].pb(tempo);
                graph[tempo].pb(curr); 
            }
        }
    }
    int t; cin>>t;
    while(t--)
    solve();
    return 0;
}