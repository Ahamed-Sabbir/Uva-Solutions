#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int l;
#define loop(a, b) for(int i = a; i < b; i++)
#define PI acos(-1.0)
const ll INF = 1000000000001;

const ll mod = 1000000007;
ll gcd(ll a,ll b){ if(b == 0) return a; return gcd(b, a % b); }
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
//ll power(ll a, ll b){ll res = 1;while(b){if(b&1) res = (res*a)%mod;b>>=1;a = (a*a)%mod;}return res%mod;}
//leftmost set bit
l clz(int N) {return N ? 32 - __builtin_clz(N) : -(1e9+1);}
//ll clz(unsigned long long N){return N ? 64 - __builtin_clzll(N) : -(1e18+1);}
ll setbit(ll x){return __builtin_popcountll(x);}
ll power(ll a, ll b){ll res = 1;while(b){if(b&1) res = (res*a);b>>=1;a = (a*a);}return res;}
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

// l --> long long int

const l ma = 20000003;
bool marked[ma];
vector<l> primes;
void sieve(){
    l limit = sqrt(ma*1.0) + 2;
    for(l i = 4; i < ma; i+=2) marked[i] = true;
    primes.push_back(2);
    for(l i = 3; i < ma; i+=2){
        if(!(marked[i])){
            primes.push_back(i);
            if(i <= limit){
                for(l j = i*i; j < ma; j+=(2*i)) marked[j] = true;
            }
        }
    }
}

void solve(l n, l n_r){
    map<l,l> m;
    l cnt1 = 0, cnt2 = 0;
    for(l two = 2; two <= n; two*=2){ cnt1+=(n/(two));}
    for(l five = 5; five <= n; five*=5){ cnt2+=(n/(five));}
    l cnt3 = 0, cnt4 = 0;
    for(l two = 2; two <= n_r; two*=2){ cnt3+=(n_r/(two));}
    for(l five = 5; five <= n_r; five*=5){ cnt4+=(n_r/(five));}
    l res = 1;
    cnt1 -= (cnt3); cnt2 -= (cnt4);
    if(cnt1 >= cnt2) {
        cnt1 -= cnt2;
        loop(0, cnt1) (res = ((res%10)*2)%10);
    }
    else{
        cnt2 -= cnt1;
        loop(0, cnt2) (res = ((res%10)*5)%10);
    }
    cnt1 = 0;cnt2 = 0;
    for(l three = 3; three <= n; three*=3) cnt1+=(n/three);
    for(l three = 3; three <= n_r; three*=3) cnt2+=(n_r/three);
    cnt1-=cnt2; loop(0, cnt1) (res = ((res%10)*3)%10);
    for(l i = 7; i <= n; i+=2){
        if(!(marked[i])){
            cnt1 = 0, cnt2 = 0;
            for(l prime = i; prime <= n; prime*=i) cnt1+=(n/prime);
            for(l prime = i; prime <= n_r; prime*=i) cnt2+=(n_r/prime);
            cnt1-=cnt2; for(l j = 0; j < cnt1; j++) (res = ((res%10)*i)%10);
        }
    }
    cout << res << endl;
}

int main()
{
    //clock_t tStart = clock();
    //run();
    sieve();
    l n, m;//cin>>n;
    while(cin>>n>>m){solve(n, n-m);}
    //printf("Time taken: %.10fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}


