#include<bits/stdc++.h>

using namespace std;


void bfs(vector<vector<int>> &adj, vector<int> &ans, int src){
    int n=adj.size();
    queue<int> q;
    vector<int> vis(n, 0);
    vis[src]=1;
    q.push(src);
    while(!q.empty()){
        int node=q.front();
        ans.push_back(node);
        q.pop();
        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }
}

int main(){
    int n=7;
    vector<vector<int>> adj(n);
    adj[1].push_back(2);
    adj[1].push_back(4);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[3].push_back(4);
    adj[3].push_back(5);
    adj[4].push_back(1);
    adj[4].push_back(3);
    adj[4].push_back(5);
    adj[5].push_back(3);
    adj[5].push_back(4);
    adj[5].push_back(6);
    adj[6].push_back(5);

    vector<int> ans;
    bfs(adj, ans, 2);
    for(auto it: ans) cout<<it<<" ";


    return 0;
}
