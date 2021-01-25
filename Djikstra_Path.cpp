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
#define time() cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" 

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

list<char>l;
map<char,bool>visited;
map<char,list<pair<char,int>>>graph;

void Topologicalsort(char src)
{
	visited[src]=true;
	for(auto x:graph[src]){
		if(!visited[x.F]){
			Topologicalsort(x.F);
		}
	}
	l.push_front(src);
}

void Djkstra_Path_Me(char src)
{
	map<char,int>dist;
	for(auto x : graph){
		dist[x.F]=INT_MAX;
	}
	dist[src]=0;
	set<pair<int,char>>s;
	s.insert(mp(0,src));
	while(!s.empty())
	{
		auto it = *s.begin();
		int temp_dis=it.first;
		char temp_src=it.second;
		s.erase(it);
		for(auto child : graph[temp_src]){
			if(temp_dis+child.second < dist[child.first])
			{
				int newdis=temp_dis+child.second;
				auto fr=child.first;
				auto me=s.find(mp(dist[fr],fr));
				if(me!=s.end()){
					s.erase(me);
				}
				dist[child.first]=newdis;
				s.insert(mp(newdis,fr));
			}
		}
		cout<<"distance of "<<temp_src<<" from src is "<<dist[temp_src]<<endl;
	}
}

void solve()
{	
	int n; cin>>n;
	for(int i=0,x;i<n;i++){
		char f,g;
		cin>>f>>g>>x;
		graph[f].pb(mp(g,x));
		graph[g].pb(mp(f,x));
	}
	//Topologicalsort('E');
	Djkstra_Path_Me('E');
	//for(auto x : l ) cout<<x<<" ";
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