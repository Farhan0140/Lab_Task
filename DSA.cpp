bool B_S(vector<int> v, int f) {
    int l=0, r=v.size()-1;

    while(l <= r) {
        int mid = (l+r)/2;

        if(v[mid] == f) { return true; }

        if(f < v[mid]) {
            r = mid-1;
        } else {
            l = mid+1;
        }
    }

    return false;
}

//--------------------------------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

void merge_sort(int arr[], int low, int high);
void Merge(int arr[], int low, int mid, int high);
void Print(int arr[], int s);

int main() {
    int arr[] = {1, 7, 3, 2, 1, 5, 8, 9, 4, 2, 89, 11, 12, 3};
    int s = sizeof(arr)/sizeof(arr[0]);
    // Print(arr, s);
    merge_sort(arr, 0, s-1);
    Print(arr, s);
    return 0;
}

void merge_sort(int arr[], int low, int high){
    if(low < high) {
        int mid = (low+high)/2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid+1, high);
        Merge(arr, low, mid, high);
    }
}

void Merge(int arr[], int low, int mid, int high){
    int L_arr_s = (mid - low) + 1;
    int R_arr_s = high - mid;

    int L_arr[L_arr_s];
    int R_arr[R_arr_s];

    for(int i=low; i<=mid; i++) {
        L_arr[i - low] = arr[i];
    }

    for(int i=mid+1; i<=high; i++) {
        R_arr[i-(mid+1)] = arr[i];
    }

    int L_M = 0, R_M = 0, arrPos = low; // L_M = left marker

    while(L_M < L_arr_s && R_M < R_arr_s) {
        if(L_arr[L_M] < R_arr[R_M]) {
            arr[arrPos] = L_arr[L_M];
            L_M++;
            arrPos++;
        } else {
            arr[arrPos] = R_arr[R_M];
            R_M++;
            arrPos++;
        }
    }

    while(L_M < L_arr_s) {
        arr[arrPos] = L_arr[L_M];
        L_M++;
        arrPos++;
    }

    while(R_M < R_arr_s) {
        arr[arrPos] = R_arr[R_M];
        R_M++;
        arrPos++;
    }
}

void Print(int arr[], int s) {
    for(int i=0; i<s; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


//--------------------------------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

void Print(int arr[], int s);

int set_prevot(int arr[], int low, int high) {
    int pValue = arr[high];
    int pointer = low;

    for(int i=low; i<=high-1; i++) {
        if(arr[i] < pValue) {
            swap(arr[i], arr[pointer]);
            pointer++;
        }
    }

    swap(arr[pointer], arr[high]);
    return pointer;
}


void quick_sort(int arr[], int low, int high) {
    if(low < high) {
        int prevot = set_prevot(arr, low, high);
        quick_sort(arr, low, prevot-1);
        quick_sort(arr, prevot+1, high);
    }
}

int main() {
    int arr[] = {1,7, 3, 2,1, 5, 8, 9, 4};

    quick_sort(arr, 0, 9-1);
    Print(arr, 9);
    return 0;
}

void Print(int arr[], int s) {
    for(int i=0; i<s; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


//--------------------------------------------------------------------------------------------------------
gcd

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b; cin >> a >> b;
    for(int i=min(a,b); i>=1; i--) {
        if(a % i == 0 && b % i == 0) {
            cout << i << endl;
            break;
        }
    }
}


lcm
ll GCD(ll a, ll b){
    if(b == 0){
        return a;
    }
    return GCD(b, (a%b));
}

long long lcm(int a, int b)
{
    return (a / GCD(a, b)) * b;
}

lcm multiplie
#include<iostream>

using namespace std;

int lcm(int a, int b){
    int high=max(a,b);
    while(high%a!=0 || high%b!=0){
        high++;
    }
    return high;
}

int main(){
    int arr[5];
    for(int i=0;i<5;i++){
        cin>>arr[i];
    }
    int temp=arr[0];
    for(int i=1;i<5;i++){
        temp=lcm(temp,arr[i]);
    }
    cout<<temp;
}

//--------------------------------------------------------------------------------------------------------
Greedy_Algorithms
#include <bits/stdc++.h>
using namespace std;

void Print(int arr[], int s);

int main() {
    int weight[5] = {5, 10, 15, 22, 25};
    int profit[5] = {30, 40, 45, 77, 90};
    int capacity = 60;
    double Ratio[5];

    for(int i=0; i < 5; i++) {
        Ratio[i] = (double)profit[i] / (double)weight[i];
    }

    for(int i=0; i<4; i++) {
        for(int j=i+1; j<5; j++) {
            if(Ratio[i] < Ratio[j]) {
                swap(Ratio[i], Ratio[j]);
                swap(weight[i], weight[j]);
                swap(profit[i], profit[j]);
            }
        }
    }

    double ans = 0;
    int W = 0;

    for(int i=0; i<5; i++) {
        if(capacity <= 0) {
            break;
        }
        if(weight[i] <= capacity) {
            ans += profit[i];
            capacity -= weight[i];
        } else {
            ans += capacity * Ratio[i];
            capacity = 0;
        }
    }

    cout << ans << endl;
    return 0;
}


//--------------------------------------------------------------------------------------------------------

void S_O_E(ll n){ // declaring an array
    memset(prime, 0, sizeof(prime));    
    
    for(int i=2; i*i<=n; i++){   
    	if(prime[i] == 0){    
        	for(int j=i*i; j<=n; j+=i){  
            	prime[j] = 1;   
            }
        }
    }
    
    for(int i=2; i<=n; i++){
    	if(prime[i] != 1){    
        	cout << i << " ";
        }
    }
}

//--------------------------------------------------------------------------------------------------------

