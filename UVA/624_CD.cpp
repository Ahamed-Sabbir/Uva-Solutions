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

void solve(ll n){
    l cd;cin>>cd;
    ll ara[cd];loop(0,cd) cin>>ara[i];
    ll subset = (1LL<<cd) - 1;
    ll sum = 0;
    ll ma = sum;
    ll ans;
    for(ll i = 1; i <= subset; i++){
        for(ll j = 0; j < cd; j++){
            if((i>>j)&1){
                sum += (ara[j]);
            }
            //cout << sum << " ";
        }
        if(sum <= n && sum > ma) {
            ma = sum;
            ans = i;
        }
        sum = 0;
    }

    for(ll i = 0; i < cd; i++){
        if((ans>>i)&1){
            cout << ara[i] << " ";
        }
    }

    cout << "sum:" << ma << endl;
}

int main()
{
    //clock_t tStart = clock(); 
    //run();
    //precal();
    // l n;cin>>n;
    // while(n--) {solve();}
    ll n;while(cin>>n){solve(n);}
    //printf("Time taken: %.10fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}


// 5 3 1 3 4
// 10 4 9 8 4 2
// 20 4 10 5 7 4
// 90 8 10 23 1 2 3 4 5 7
// 45 8 4 10 44 43 12 9 8 2


// 1 4 sum:5
// 8 2 sum:10
// 10 5 4 sum:19
// 10 23 1 2 3 4 5 7 sum:55
// 43 2 sum:45
