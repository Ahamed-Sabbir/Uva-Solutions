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

l j = 1;
bool solve(){
    char wife1[6], wife2[6];cin>>wife1>>wife2;
    char met1[6], met2[6];cin>>met1>>met2;
    l a1,a2;sscanf(wife1, "%d:%d", &a1,&a2);
    l b1,b2;sscanf(wife2, "%d:%d", &b1,&b2);
    l d1,d2;sscanf(met2, "%d:%d", &d1, &d2);
    l c1,c2;sscanf(met1, "%d:%d", &c1, &c2);
    //cout << a1 << " " << a2 << " " << b1 << " " << b2 << endl;
    //cout << c1 << " " << c2 << " " << d1 << " " << d2 << endl;
    //bool pos = true;
    /*if(c1 > a1 && c1 < b1) {
        return false;
    }
    if(c1 >= a1 && c2 >= a2 && c1 <= b1 && c2 <= b2) {
        return false;//cout << 3 << endl;
    }
    if(d1 > a1 && d1 < b1) {
        return false;//cout << 2 << endl;
    }
    if(d1 >= a1 && d2 >= a2 && d1 <= b1 && d2 <= b2) {
       return false;//cout << 1 << endl;
    }
    return true;*/
    //if(c1 == a1 && c2 <= a2) pos = false;
    l wife_start = (a1*60)+a2;
    l wife_end = (b1*60) + b2;
    l met_start = (c1*60)+c2;
    l met_end = (d1*60) + d2;
    if(met_start > wife_end) return true;
    if(met_end < wife_start) return true;
    return false;
}

int main()
{
    //clock_t tStart = clock();
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //run();
    l n;cin>>n;
    //dummy getline
    //string s;getline(cin,s);
    //char s[2100];
    //while(cin>>s) {solve(s);}
    while(n--){
        bool pos = solve();
        if(pos) cout << "Case " << j++ << ": Hits Meeting" << endl;
        else cout << "Case " << j++ << ": Mrs Meeting" << endl;
    }
    //l n;
    //while(cin>>n && n){solve(n);}
    //cout << endl;
    //printf("Time taken: %.10fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}

