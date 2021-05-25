const int maxm = 2*1e5+5;   //nodes in graph

// 000000000000000 - based indexing

vector<vector<int>>graph,up;
int enter[maxm],leave[maxm];
int timer,n,l;

void dfs(int v, int p)
{
    enter[v] = timer;
    timer++;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : graph[v]) {
        if (u != p)
            dfs(u, v);
    }
    leave[v] = timer;
    timer++;
}

bool is_ancestor(int u, int v)
{
    return enter[u] <= enter[v] && leave[u] >= leave[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    timer = 0;
    l = ceil(log2(n));
    memset(enter,0,sizeof enter);
    memset(leave,0,sizeof leave);
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}
