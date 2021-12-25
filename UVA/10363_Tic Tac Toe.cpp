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

void solve(){
    string s[3];
    loop(0,3) cin>>s[i];
    l cnt_X = 0, cnt_O = 0;
    l x_win = 0, o_win = 0;
    l x = 0, x1 = 0, y = 0, y1 = 0;
    for(l i = 0; i < 3; i++){
        for(l j = 0; j < 3; j++){
            if(s[i][j] == 'X') {cnt_X++;x++;}
            else if(s[i][j] == 'O') {cnt_O++;y++;}
            if(s[j][i] == 'X') x1++;
            else if(s[j][i] == 'O') y1++;

        }
        if(x % 3 == 0 && x) x_win++;
        if(y % 3 == 0 && y) o_win++;
        if(x1 % 3 == 0 && x1) x_win++;
        if(y1 % 3 == 0 && y1) o_win++;
        x = 0, y = 0, x1 = 0, y1 = 0;
    }
    if(s[0][0]=='X'&&s[1][1]=='X'&&s[2][2]=='X') x_win++;
    if(s[0][0]=='O'&&s[1][1]=='O'&&s[2][2]=='O') o_win++;
    if(s[0][2]=='X'&&s[1][1]=='X'&&s[2][0]=='X') x_win++;
    if(s[0][2]=='O'&&s[1][1]=='O'&&s[2][0]=='O') o_win++;
    bool ans;
    if(x_win >= 1  && o_win >= 1) ans = false;
    else if(x_win >= 1 && (cnt_X != (cnt_O+1))) ans = false;
    else if(o_win >= 1 && (cnt_X != cnt_O)) ans = false;
    else if(cnt_X != cnt_O && (cnt_X != (cnt_O+1))) ans = false;
    else ans = true;

    if(ans) cout << "yes" << endl;
    else cout << "no" << endl;
}

int main()
{
    //clock_t tStart = clock();
    //run();
    l n;cin>>n;
    while(n--) {solve();}
    //printf("Time taken: %.10fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}

