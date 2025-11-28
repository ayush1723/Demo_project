#include<bits/stdc++.h>
using namespace std;

//////////////////////////<-Template->//////////////////////////
#define ll long long int
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define pll pair<long long, long long>
#define PI 3.1415926535897932384626433832795
#define F first
#define S second
#define pb push_back
///////////////////////<-Data Struture->////////////////////////
#define vii vector<int>
#define vll vector<long long>
#define mp map<int, int>
#define mpl map<long long, long long>
#define pq priority_queue<int>
#define pql priority_queue<long long>
#define st set<int> 
#define stl set<long long>
///////////////////////<-Daily use->////////////////
#define MOD 1000000007


int knapsack_Mem(int *weights, int *values, int n, int maxWeight, map<int, int> &seen)
{
	//write your code here
	if(n == 0 || maxWeight == 0){
		return 0;
	}
    if(seen[weights[0]] != -1){
        return seen[weights[0]];
    }
	if(weights[0] > maxWeight){
		return knapsack_Mem(weights + 1, values + 1, n - 1, maxWeight, seen);
	}
	int x = knapsack_Mem(weights + 1, values + 1, n - 1, maxWeight - weights[0], seen) + values[0];
	int y = knapsack_Mem(weights + 1, values + 1, n - 1, maxWeight, seen);
    int ans = max(x, y);
    seen[weights[0]] = ans;
	return ans;
}

int knapsack(int *weights, int *values, int n, int maxWeight)
{
	//write your code here
	if(n == 0 || maxWeight == 0){
		return 0;
	}
	if(weights[0] > maxWeight){
		return knapsack(weights + 1, values + 1, n - 1, maxWeight);
	}
	int x = knapsack(weights + 1, values + 1, n - 1, maxWeight - weights[0]) + values[0];
	int y = knapsack(weights + 1, values + 1, n - 1, maxWeight);
	return max(x, y);
}

void solve(){
    int n;
    cin >> n;
    int v[20];
    int w[20];
    for(int i=0; i<n; i++){
        cin >> w[i];
    }
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    int q;
    cin >> q;
    cout << knapsack(w, v, n, q) << endl;
    map<int, int> seen;
    for(int i=0; i<n; i++){
        seen[w[i]] = -1;
    }
    cout << knapsack_Mem(w, v, n, q, seen) << endl;
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}