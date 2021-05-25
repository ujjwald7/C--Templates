const int INF = 1e18;
int n;
vector<vector<int>> capacity;
vector<vector<int>> adj;

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(n);
    int new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

void solve()
{   
    cin>>n;
    int m; cin>>m;
    adj.resize(n);
    capacity.resize(n);
    for(int i=0;i<n;i++){
        capacity[i].assign(n,0);
    }
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        x--; y--;
        int c; cin>>c;
        if(capacity[x][y]==0){
            capacity[x][y] = c;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        else{
            capacity[x][y] += c;
        }
    }
    int ans = maxflow(0,n-1);
    cout<<ans<<endl;
}   