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

void solve(char s[]){
    l sz = strlen(s);
    loop(0,sz){
        if(s[i] == '-' || s[i] == 32) cout << s[i];
        else if(s[i] >= 48 && s[i] <= 57) cout << s[i];
        else {
            if(s[i] >= 65 && s[i] <= 67) cout << "2";
            else if(s[i] >= 68 && s[i] <= 70) cout << "3";
            else if(s[i] >= 71 && s[i] <= 73) cout << "4";
            else if(s[i] >= 74 && s[i] <= 76) cout << "5";
            else if(s[i] >= 77 && s[i] <= 79) cout << "6";
            else if(s[i] >= 80 && s[i] <= 83) cout << "7";
            else if(s[i] >= 84 && s[i] <= 86) cout << "8";
            else cout << "9";
        }
    }
    cout << endl;
}

int main()
{
    //clock_t tStart = clock();
    //run();
    //l n;cin>>n;
    char st[50];
    while(scanf(" %[^\n]", &st) != EOF) {solve(st);}
    //printf("Time taken: %.10fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}


