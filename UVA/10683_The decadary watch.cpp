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
ll setbit(ll x){return __builtin_popcountll(x);}
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
    freopen("output.txt", "w", stdout);
#else
#endif
}

void solve(string st){
    l h,m,s,ss;
    h = (st[0]-'0')*10;
    h+=(st[1]-'0');
    m = (st[2]-'0')*10;
    m+=(st[3]-'0');
    s = (st[4]-'0')*10;
    s+=(st[5]-'0');
    ss = (st[6]-'0')*10;
    ss+=(st[7]-'0');
    //cout << h << " " << m << " " << s << " " << ss << endl;
    ll total_s = 0LL;
    total_s += (h*360000LL);
    total_s += (m*6000LL);
    total_s += (s*100LL);
    total_s += ss;
    ll total_sec_24h = (24*3600*100LL);
    ll total_sec_10h = (10*100*100*100);
    ll ans = (total_sec_10h*total_s)/(total_sec_24h);
    printf("%07lld\n", ans);
    //cout << ans << endl;

}

int main()
{
    //clock_t tStart = clock();
    //run();
    //l n = 1;//cin>>n;
    string s;
    while(cin>>s) {solve(s);}
    //printf("Time taken: %.10fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
