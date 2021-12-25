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
    freopen("output7.txt", "w", stdout);
#else
#endif
}

void solve(l a, l b, l c){
    bool ara[a+1][b+1];
    memset(ara, true, sizeof(ara));
    while(c--){
        l x1, y1, x2, y2;cin>>x1>>y1>>x2>>y2;
        if(x1 > x2) swap(x1,x2);
        if(y1 > y2) swap(y1,y2);
        for(l i = x1; i <= x2; i++){
            for(l j = y1; j <= y2; j++){
                ara[i][j] = false;
            }
        }
    }

     ll cnt = 0;
    for(l i = 1; i <= a; i++){
        for(l j = 1; j <= b; j++){
            if(ara[i][j]) cnt++;
        }
    }
    if(cnt==0) cout << "There is no empty spots." << endl;
    else if(cnt == 1) cout << "There is one empty spot." << endl;
    else cout << "There are " << cnt << " empty spots." << endl;
}

int main()
{
    //clock_t tStart = clock();
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //run();
    //l n = 1;cin>>n;
    //dummy getline
    //string s;getline(cin,s);
    //char s[2100];
    //while(cin>>s) {solve(s);}
    //while(n--){solve();}
    l a,b,c;
    while(cin>>a>>b>>c && a+b+c){solve(a,b,c);}
    //cout << endl;
    //printf("Time taken: %.10fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}