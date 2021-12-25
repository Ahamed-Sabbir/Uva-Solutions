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
void solve(l n){
    l q = n;
    if(j != 1) cout << endl;
    cout << "Case " << j++ << ":" << endl;
    vector<string> v, v1;
    while(n--){
        string s;cin>>s;
        v.push_back(s);
    }
    bool first = true;
    l cnt = 0;
    string p = "", s1, s2;
    for(l i = 0; i < q-1; i++){
        s1 = v[i], s2 = v[i+1];
        ll x = 0, y = 0;
        stringstream is(s1); is>>x;
        stringstream IS(s2); IS>>y;
        if(first) {p = s1;first = false;}
        if(x+1 != y){
            if(!cnt) {v1.push_back(p);}
            else{
                s1 = v[i];
                s2 = p;
                l sz = s1.size();
                l k;
                for(k = 0; k < sz; k++){
                    if(s1[k] != s2[k]) break;
                }
                p+="-";
                for(l d = k; d < sz; d++) p+=(s1[d]);
                v1.push_back(p);
            }
            first = true;
            cnt = 0;
            p = "";
        }
        else cnt++;
    }
    if(p == "") v1.push_back(v[q-1]);
    else{
        s1 = v[q-1];
        s2 = p;
        l sz = s1.size();
        l k;
        for(k = 0; k < sz; k++){
            if(s1[k] != s2[k]) break;
        }
        p+="-";
        for(l d = k; d < sz; d++) p+=(s1[d]);
        v1.push_back(p);
    }
    l sz = v1.size();
    loop(0,sz) cout << v1[i] << endl;
}

int main()
{
    //clock_t tStart = clock();
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //run();
    //l n;cin>>n;
    //dummy getline
    //string s;getline(cin,s);
    //char s[2100];
    //while(cin>>s) {solve(s);}
    //while(n--){solve();}
    l n;
    while(cin>>n && n){solve(n);}
    cout << endl;
    //printf("Time taken: %.10fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}

