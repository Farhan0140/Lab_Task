#include <bits/stdc++.h>
using namespace std;
 
//_______________________________________________________________________________________________

const int mod = 1e9 + 7;
#define pi 3.141592653
#define ll long long int
#define all(x) x.begin(),x.end()
#define out(x) cout << x << "\n";
#define ina(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define inv(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}

#define tc ll ttc; cin >> ttc; while(ttc--)
#define IOS (ios_base :: sync_with_stdio(false), cin.tie(NULL));

//_______________________________________________________________________________________________
const int S = 1e2;
vector<pair<ll, ll>> adj[S];
bool vis[S];


void solve() {
    ll n, e; cin >> n >> e;

    while(e--) {
        ll u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    memset(vis, false, sizeof(vis));

    priority_queue<pair<ll, ll>, vector<pair<ll,ll>>, greater<pair<ll, ll>>> pq;

    ll total_cost = 0;

    ll src; cin >> src;
    pq.push({0, src});

    while(!pq.empty()) {
        pair<ll, ll> parent = pq.top(); pq.pop();

        ll weight = parent.first, node = parent.second;
        // cout << nod << " " << weg << endl;

        if(vis[node]) { continue; }

        vis[node] = true;
        total_cost += weight;

        for(auto it: adj[node]) {
            ll child_node = it.first;
            ll child_weight = it.second;

            if(!vis[child_node]) {
                pq.push({child_weight, child_node});
            }
        }
    }

    out(total_cost);
}

//_______________________________________________________________________________________________
 
 
int main(){
    IOS;
    /*
    tc
    */
      solve();
    return 0;
}
 
 
//_______________________________________________________________________________________________
/*
8 14
0 1 4
0 7 8
1 7 11
1 2 8
7 6 1
7 8 7
2 3 7
2 5 4
6 5 2
3 5 14
3 4 9
5 4 10
2 8 2
8 6 6
0

--->  37
*/