vector<int> graph[n+3],graph_rev[n+3];	//graph[x].pb(y) and graph_rev[y].pb(x)
vector<bool> vis[n+3],comp[n+3];
vector<int>order;	

void dfs(int src)
{
	vis[src]=true;
	for(auto x:graph[src]){
		if(!vis[x]) dfs(x);
	}
	order.pb(src);
}

void dfs_rev(int src,int colour)
{
	comp[src]=colour;
	vis[src]=true;
	for(auto x:graph_rev[src]){
		if(!vis[x]) dfs_rev(x,colour);
	}
}

void kosaraju()
{
	memset(vis,false,sizeof vis);
	for(int i=1;i<=n;i++){
		if(!vis[i]) dfs(i);
	}
	memset(vis,false,sizeof vis);
	int colour=1;
	for(int i=n;i>=1;i--){
		if(!vis[order[i]]){
			dfs_rev(order[i],colour);
			colour++;
		}
	}
	//print component of every node
	for(int i=1;i<=n;i++){
		cout<<i<<"->"<<comp[i]<<endl;
	}
}