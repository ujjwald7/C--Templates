const int maxm=1e18;

vector<P>graph[1000005];
vector<int>dist(1000005,maxm);

void dijkstra(int src)
{
    dist[src]=0;
    set<P>s;
    s.insert(mp(dist[src],src));
    while(!s.empty())
    {
        auto fr=*(s.begin());
        int node=fr.S;
        int dis=fr.F;
        s.erase(s.begin());
        for(auto edge: graph[node])
        {
            if(dis+edge.S<dist[edge.F])
            {
                //delete
                auto finder=s.find(mp(dist[edge.F],edge.F));
                if(finder!=s.end()){
                    s.erase(finder);
                }
                dist[edge.F]=dis+edge.S;
                s.insert(mp(dist[edge.F],edge.F));
            }
        }
    }
}