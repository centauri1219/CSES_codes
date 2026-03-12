    #include<iostream>
    #include<vector>
    #include<climits>
    #include<string>

    using namespace std;
    void dfs(int i,vector<vector<int>> &adj,vector<int> &vis){
        vis[i] = 1;
        for(auto it : adj[i]){
            if (!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }

    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n,m;
        cin>>n>>m;

        vector<vector<int>> adj(n+1);
        vector<vector<int>> revadj(n+1);

        for(int i = 0 ; i<m;i++){
            int  x,y;
            cin>>x>>y;
            adj[x].push_back(y);
            revadj[y].push_back(x);

        }
        vector<int> vis(n+1,0);

        dfs(1,adj,vis);
        for(int i = 1; i<=n;i++){
            if (vis[i] == 0){   
                cout<<"NO"<<endl;
                cout<<1<<" "<<i<<endl;
                return 0;
            }
        }
        // vis.clear();
        fill(vis.begin(),vis.end(),0);
        dfs(1,revadj,vis);
        for(int i = 1; i<=n;i++){
            if (vis[i] == 0){
                cout<<"NO"<<endl;
                cout<<i<<" "<<1<<endl;
                return 0;
            }
        }
                
                
                
        
        cout<<"YES\n";
        return 0;
    }