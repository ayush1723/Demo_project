#include<bits/stdc++.h>
using namespace std;

//Hello This is code for Aggresive cows by Ayush Yadav.

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

bool checker(vector<ll>& v, ll n, ll c, ll x){
    ll temp = v[0];
    ll cnt = 1;
    for(ll i = 1; i < n; i++){
        if(v[i] - temp >= x){
            cnt++;
            temp = v[i];
        }
    }
    if(cnt >= c){
        return true;
    }
    else{
        return false;
    }
}
void solve(){
    ll n, c;
    cin >> n >> c;
    vector<ll> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    ll l = 0;
    ll h = 1e12;
    while(l + 1 < h){
        ll mid = (l + h) / 2;
        if(checker(v, n, c, mid)){
            l = mid;
        }
        else{
            h = mid;
        }
    }
    cout << l << endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
