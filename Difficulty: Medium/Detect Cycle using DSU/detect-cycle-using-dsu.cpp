class Solution {
  public:
    // Function to detect cycle using DSU in an undirected graph.
    vector<int>par;
    vector<int>rank;
    
    int find(int x){
        if(par[x]==x) return x;
        return par[x]=find(par[x]);
    }
    
    void unionn(int x,int y){
        int y_p=find(y);
        int x_p=find(x);
        if(rank[x_p]>rank[y_p]){
            par[y_p]=x_p;
        }
        else if(rank[y_p]>rank[x_p]){
            par[x_p]=y_p;
        }
        else{
            par[y_p]=x_p;
            rank[x_p]+=1;
        }
    }
    int detectCycle(int V, vector<int> adj[]) {
        // Code here
        par.resize(V);
        rank.resize(V);
        for(int i=0;i<V;i++){
            par[i]=i;
            rank[i]=1;
        }
        for(int u=0;u<V;u++){
            for(auto &v:adj[u]){
                if(u<v){
                    int u_p=find(u);
                    int v_p=find(v);
                    if(u_p==v_p) return 1;
                    unionn(u_p,v_p);
                }
            }
        }
        return 0;
    }
};