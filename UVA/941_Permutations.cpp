#include <bits/stdc++.h>
using namespace std;
typedef int l;
typedef long long int ll;
#define loop(a, b) for(int i = a; i < b; i++)
#define PI acos(-1.0)
const ll INF = LLONG_MAX;

const ll mod = 1000000007;
ll gcd(ll a,ll b){ if(b == 0) return a; return gcd(b, a % b); }
 ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll power(ll a, ll b){ll res = 1;while(b){if(b&1) res = (res*a)%mod;b>>=1;a = (a*a)%mod;}return res%mod;}
//leftmost set bit
l clz(int N) {return N ? 32 - __builtin_clz(N) : -(1e9+1);}
//ll clz(unsigned long long N){return N ? 64 - __builtin_clzll(N) : -(1e18+1);}
l setbit(l x){return __builtin_popcountll(x);}
//ll power(ll a, ll b){ll res = 1;while(b){if(b&1) res = (res*a);b>>=1;a = (a*a);}return res;}
bool arraySortedOrNot(int arr[], int n){if (n == 0 || n == 1) return true;for (int i = 1; i < n; i++)if (arr[i - 1] > arr[i]) return false;return true;}
// long long v[400002];
// void Quicksort(int begin,int end){
//   int e,b,aux,p;b=begin;e=end;p=v[(e+b)/2];
//   while(v[b]<p){b++;}while(v[e]>p){e--;}while(b<e){aux=v[b];v[b]=v[e];v[e]=aux;do{b++;}while(v[b]<p);
//   do{e--;}while(v[e]>p);}if(begin<e){ Quicksort(begin,e);}
//   if(e+1<end){ Quicksort(e+1,end);}
// }

void run(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output8.txt", "w", stdout);
#else
#endif
}

ll ara[21];
void precal(){
    ara[0] = 1;ara[1] = 1;
    for(l i = 2; i < 21; i++){
        ara[i] = ara[i-1] * i;
    }
    // loop(0, 21) cout << ara[i] << endl;
}

void solve(){
    string s;cin>>s;
    ll n;cin>>n;
    l sz = s.size();
    string res = "";
    n+=1;
    sort(s.begin(), s.end());
    while(sz != 1){
        ll position_of_block = (n / ara[sz-1]);
        if(!(n % ara[sz-1])) position_of_block--;
        res += (s[position_of_block]);
        s.erase(s.begin() + position_of_block);
        n -= (ara[sz-1] * position_of_block);
        sz--;
    }
    res += s[0];
    cout << res << endl;
}

int main()
{
    //clock_t tStart = clock(); 
    //run();
    precal();
    l n;cin>>n;
    while(n--) {solve();}
    //printf("Time taken: %.10fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}


// 3
// abc
// 3
// abcde
// 119
// cba
// 3

// bca
// edcba
// bca