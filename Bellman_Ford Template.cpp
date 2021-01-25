vector<int> bellman_ford(vector<vector<int>>graph, int n, int src)
{
    //graph .pb {from,to,weight};
    vector<int>dis(n+1,INT_MAX);
    dis[src]=0;
    //relaxing edges n-1 times
    for(int i=0;i<n-1;i++){
        for(auto x: graph){
            int from=x[0];
            int to=x[1];
            int wt=x[2];
            if(dis[to]>dis[from]+wt and dis[from]!=INT_MAX){
                dis[to]=dis[from]+wt;
            }
        }
    }

    //check for -ve weight cycle
    for(auto x: graph)
    {
        int from=x[0];
        int to=x[1];
        int wt=x[2];
        if(dis[to]>dis[from]+wt and dis[from]!=INT_MAX){
            cout<<"Negative Weight Cycle";
            exit(0);
        }
    }
    //1-based indexing
    return dis;
}