#include <bits/stdc++.h>
using namespace std;
#define ll long long int

//-----------------------------------------------
void Adjacency_Matrix_to_List(vector<vector<ll>> list, ll n) {
    vector<ll> adj_list[n+5];
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(list[i][j] == 1) {
                adj_list[i].push_back(j);
            }
        }
    }
    
    for(int i=0; i<n; i++) {
        cout << i << " --> ";
        for(auto it: adj_list[i]) {
            cout << it << " ";
        }
        cout << endl;
    }
}

//-----------------------------------------------
void Adjacency_List_To_Matrix(vector<ll> list[], ll n) {
    ll adj_mat[n+5][n+5];
    memset(adj_mat, 0, sizeof(adj_mat));
    
    for(int i=0; i<n; i++) {
        for(auto nodes: list[i]) {
            adj_mat[i][nodes] = 1;
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << adj_mat[i][j] << " ";
        }
        cout << endl;
    }
}

//shortest path-----------------------------------------------
const ll S = 1e5;
vector<ll> Arr[S];
bool visited[S];
ll Parent[S];

void BFS(ll src);

int main(){
    
    ll n, e; cin >> n >> e;
    while(e--) {
        int u, v; cin >> u >> v;
        Arr[u].push_back(v);
        Arr[v].push_back(u); // For Undirected Graph
    }

    memset(visited, false, sizeof(visited));
    memset(Parent, -1, sizeof(Parent));

    ll src, dis; cin >> src >> dis;
    BFS(src);

    vector<ll> Shortest_Path;
    while(dis != -1) {
        // cout << dis << " ";
        Shortest_Path.push_back(dis);
        dis = Parent[dis];
    }

    reverse(all(Shortest_Path));

    for(auto it: Shortest_Path) {
        cout << it << " ";
    }
    return 0;
}

void BFS(ll src){
    queue<ll> q;

    q.push(src);
    visited[src] = true;

    while(!q.empty()) {
        ll parent = q.front(); q.pop();

        for(ll child : Arr[parent]) {
            if(!visited[child]) {
                visited[child] = true;
                Parent[child] = parent;
                q.push(child);
            }
        }
    }
}

//Dfs-----------------------------------------------
const ll S = 1e5+5;
vector<int> Arr[S];
bool visited[S];

void DFS(ll src);
int main(){
    int n, e; cin >> n >> e;
    while(e--) {
        int u, v; cin >> u >> v;
        Arr[u].push_back(v);
        Arr[v].push_back(u); // for Undirected Graph
    }

    memset(visited, false, sizeof(visited));

    int src; cin >> src;
    DFS(src);
    return 0;
}
void DFS(ll src) {
    visited[src] = true;
    cout << src << " ";

    for(ll child: Arr[src]) {
        if(!visited[child]) {
            DFS(child);
        }
    }
}

//Dijkstra-----------------------------------------------
const ll INF = 1e18;
const int S = 1e5+5;
vector<pair<ll, ll>> Arr[S];
ll Dis[S];

void Dijkstra(ll src);
class Cmp{
    public:
      bool operator()(pair<ll, ll> a, pair<ll, ll> b) {
          return (a.second > b.second);
      }
};
int main(){
    ll n, e; cin >> n >> e;
    while(e--) {
        ll u, v, c; cin >> u >> v >> c;
        Arr[u].push_back({v, c});
        Arr[v].push_back({u, c});
    }

    for(int i=1; i<=n; i++) {
        Dis[i] = INF;
    }

    int src; cin >> src;
    Dijkstra(src);

    for(int i=1; i<=n; i++) {
        cout << i << " --> " << Dis[i] << endl;
    }
    return 0;
}
void Dijkstra(ll src) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, Cmp> pq;
    pq.push({src, 0});
    Dis[src] = 0;

    while(!pq.empty()) {
        pair<ll, ll> parent = pq.top(); pq.pop();
        ll p_node = parent.first; 
        ll p_cost = parent.second;

        for(pair<ll, ll> child: Arr[p_node]) {
            ll c_node = child.first; 
            ll c_cost = child.second;

            if(p_cost + c_cost < Dis[c_node]) {
                Dis[c_node] = p_cost + c_cost;
                pq.push({c_node, Dis[c_node]});
            }
        }
    }
}

//floyd warshall-----------------------------------------------
const ll INF = 1e18;
int main(){
    ll n, e; cin >> n >> e;
    ll Adj[n+5][n+5];

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i == j) {
                Adj[i][j] = 0;
            } else {
                Adj[i][j] = INF;
            }
        }
    }

    while(e--) {
        ll u, v, w; cin >> u >> v >> w;
        Adj[u][v] = w;
    }

    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(Adj[i][k] + Adj[k][j] < Adj[i][j]) {
                    Adj[i][j] = Adj[i][k] + Adj[k][j];
                }
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(Adj[i][j] == INF) {
                cout << "INF" << " ";
            } else {
                cout << Adj[i][j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

//prims-----------------------------------------------
const int S = 1e2;
vector<pair<ll, ll>> adj[S];
bool vis[S];
int main() {
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

//0/1Knapsack-----------------------------------------------
int main(){
    int n; cin >> n;
    int weight[n+5], value[n+5];

    for(int i=0; i<n; i++) {
        cin >> weight[i];
    }
    for(int i=0; i<n; i++) {
        cin >> value[i];
    }

    int W; cin >> W; // Knapsack Weight

    int DP[n+5][W+5];

    for(int i=0; i<=n; i++) {
        for(int j=0; j<=W; j++) {
            if(i == 0 || j == 0) {
                DP[i][j] = 0;
            }
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=W; j++) {
            if(weight[i-1] <= j) {
                int option_1 = DP[i-1][j - weight[i-1]] + value[i-1];
                int option_2 = DP[i-1][j];
                DP[i][j] = max(option_1, option_2);

                // DP[i][j] = max(DP[i-1][j - weight[i-1]] + value[i-1], DP[i-1][j])
            } else {
                DP[i][j] = DP[i-1][j];
            }
        }
    }


    cout << DP[n][W] << endl;
    return 0;
}

//fractional Knapsack-----------------------------------------------
class Items{
    public:
      ll weight, value;
    
    Items(ll w, ll v) {
        this->weight = w;
        this->value = v;
    }
};
bool Cmp(Items a, Items b) {
    double ratio_1 = (double)a.value / (double)a.weight;
    double ratio_2 = (double)b.value / (double)b.weight;
    return ratio_1 > ratio_2;
}
int main(){
    // cout << "Enter the Size of Array: ";
    ll n; cin >> n;
    // cout << "Enter Weight & Value {weight, value}\n";

    vector<Items> item; 

    for(int i=0; i<n; i++) {
        ll w, v; cin >> w >> v;
        item.push_back(Items(w, v));
    }

    ll knapsack; cin >> knapsack; // the bag size
    sort(all(item), Cmp);

    double total_profit = 0;

    for(Items it: item) {
        if(it.weight <= knapsack) {
            knapsack -= it.weight;
            total_profit += it.value;
        } else {
            total_profit += it.value * ((double)knapsack / (double)it.weight);
            break;
        }
    }

    cout << total_profit << endl;
    return 0;
}

//coin change 2-----------------------------------------------
int main(){
    int n; cin >> n;
    int weight[n+5];
    for(int i=0; i<n; i++) {
        cin >> weight[i];
    }
    int sum; cin >> sum;
    int DP[n+5][sum+5];

    for(int i=0; i<=sum; i++) {
        DP[0][i] = 0;
    }
    DP[0][0] = 1;

    for(int i=1; i<=n; i++) {
        for(int j=0; j<=sum; j++) {
            if(weight[i-1] <= j) {
                int Option_1 = DP[i][j-weight[i-1]];
                int Option_2 = DP[i-1][j];
                DP[i][j] = Option_1 + Option_2;

                // DP[i][j] = DP[i-1][j-Arr[i-1]] || DP[i-1][j];
            } else {
                DP[i][j] = DP[i-1][j];
            }
        }
    }

    cout << DP[n][sum] << endl;
    return 0;
}

//n queen-----------------------------------------------
int board[100][100];
int N;

bool isSafe(int row, int column){
    for(int r=row-1;r>=0;r--)
        if(board[r][column] == 1)
            return false;

    for(int i=1;i<=min(row, column);i++)
        if(board[row-i][column-i] == 1)
            return false;

    for(int i=1;i<=min(N-row+1, N-column+1);i++)
        if(board[row-i][column+i] == 1)
            return false;

    return true;
}

bool solve(int row){
    if(row == N){
        // print solution
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++)
                cout << board[i][j] << " ";
            cout << endl;
        }

        return true;
    }

    for(int c=0;c<N;c++){
        if( isSafe(row, c) ){
            board[row][c] = 1;
            if( solve(row+1) )
                return true;
            board[row][c] = 0;
        }
    }

    return false;
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            board[i][j] = 0;

    if( !solve(0) )
        cout << "No Solution Exist";
}