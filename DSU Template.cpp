struct DSU{
    vector<int>par;
    vector<int>rank;
    int comps;
    void init(int n){
        par.resize(n+2);
        rank.resize(n+2);
        for(int i=1;i<=n;i++){
            par[i]=i;
            rank[i]=1;
        }
        comps=n;
    }
    int get_superparent(int x){
        if(x==par[x]) return par[x];
        return par[x]=get_superparent(par[x]);
    }
    void unite(int x,int y)
    {
        int super_par_a=get_superparent(x);
        int super_par_b=get_superparent(y);
        //union by rank
        if(super_par_a!=super_par_b){
            if(rank[super_par_a]<rank[super_par_b]){
                par[super_par_a]=super_par_b;
                rank[super_par_b]+=rank[super_par_a];
            }
            else{
                par[super_par_b]=super_par_a;
                rank[super_par_a]+=rank[super_par_b];
            }
        }
    }
    bool has_cycle(int x,int y){
        int super_par_a=get_superparent(x);
        int super_par_b=get_superparent(y);
        if(super_par_a==super_par_b)
            return true;
        return false;
    }
}G;
