#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(),x.end()
#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));
 
//_______________________________________________________________________________________________

class Edge_List{
    public:
      ll u, v, w;
    
    Edge_List(ll u, ll v, ll w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

bool Cmp(Edge_List a, Edge_List b) {
    return a.w < b.w;
}

//_______________________________________________________________________________________________


const ll S = 1e5+5;
ll parent[S];
ll Group_Size[S];

void DSU_Initialize(ll src);
ll Find_Leader(ll node);
void Union_by_Size(ll node1, ll node2);

//_______________________________________________________________________________________________
 
 
int main(){
    fast_read();
    ll n, e; cin >> n >> e;
    DSU_Initialize(n);
    vector<Edge_List> edges;

    while(e--) {
        ll u, v, w; cin >> u >> v >> w;
        edges.push_back(Edge_List(u, v, w));
    }

    sort(all(edges), Cmp);

    ll Total_Cost = 0;
    
    for(Edge_List edg: edges) {
        ll Leader_U = Find_Leader(edg.u);
        ll Leader_V = Find_Leader(edg.v);

        if(Leader_U != Leader_V) {
            Union_by_Size(edg.u, edg.v);
            Total_Cost += edg.w;
        }
    }

    cout << "Minimum Total Cost : " << Total_Cost << endl;
    return 0;
}
 
 
//_______________________________________________________________________________________________

void DSU_Initialize(ll src) {
    for(int i=0; i<src; i++) {
        parent[i] = -1;
        Group_Size[i] = 1;
    }
}

ll Find_Leader(ll node) {
    if(parent[node] == -1) { return node; }
    return parent[node] = Find_Leader(parent[node]);
}

void Union_by_Size(ll node1, ll node2) {
    ll Leader_A = Find_Leader(node1);
    ll Leader_B = Find_Leader(node2);

    if(Group_Size[Leader_A] > Group_Size[Leader_B]) {
        parent[Leader_B] = Leader_A;
        Group_Size[Leader_A] += Group_Size[Leader_B];
    } else {
        parent[Leader_A] = Leader_B;
        Group_Size[Leader_B] += Group_Size[Leader_A];
    }
}

//_______________________________________________________________________________________________

/*
5 7
1 2 10
1 3 5
3 2 4
2 4 1
3 4 2
4 5 3
1 5 2

--> 8
*/