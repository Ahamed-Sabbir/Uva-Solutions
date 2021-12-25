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

bool cmp(pair<string, pair<double,double>> a, pair<string, pair<double,double>> b){
    if(a.second.first > b.second.first) return true;
    else if(a.second.first == b.second.first) return a.second.second < b.second.second;
    else return false;
}

l j = 1;
void solve(l n, l m){
    if(j != 1) cout << endl;
    loop(0,n) {string s;getline(cin, s);}
    vector<pair<string, l> > v;
    vector<pair<string, pair<double,double>> > v1;
    loop(0, m){
        string s;getline(cin, s);
        v.push_back({s,i});
        double p;l t;cin>>p>>t;
        double com = (double)(t)/(double)(n);
        v1.push_back({s, {com,p}});
        string d;getline(cin, d);
        loop(0,t) {string d;getline(cin, d);}
    }
    //l sz = v1.size();
    sort(v1.begin(), v1.end(), cmp);
    //l sz = v1.size();
    /*for(l i = 0; i < sz; i++){
        cout << v1[i].first << " " << v1[i].second.first << " " << v1[i].second.second << endl;
    }*/
    //vector<string>v3;
    set<string>v3;
    set<string>::iterator it;
    l sz = v1.size();
    for(l i = 0; i < sz-1; i++){
        if(v1[i].second.first == v1[i+1].second.first){
            if(v1[i].second.second == v1[i+1].second.second){
                v3.insert(v1[i].first);
                v3.insert(v1[i+1].first);
            }
            else{
                if(v1[i].second.second < v1[i+1].second.second) {
                    v3.insert(v1[i].first);break;
                }else{
                    v3.insert(v1[i+1].first);break;
                }
            }
        }
        else break;
    }
    sz = v3.size();
    //cout << sz << endl;
    if(sz==0){
        cout << "RFP " << "#" << j++ << endl;
        cout << v1[0].first << endl;
    }
    else if(sz==1){
        cout << "RFP " << "#" << j++ << endl;
        cout << *(v3.begin()) << endl;
    }
    else{
        l ans = n;
        l st = m; string res = "";
        for(it = v3.begin(); it != v3.end(); it++){
            string p = *it;
            for(l i = 0; i < st; i++){
                if(v[i].first == p){
                    if(v[i].second < ans) {
                        res = v[i].first;
                        ans = v[i].second;
                    }
                }
            }
        }
        cout << "RFP " << "#" << j++ << endl;
        cout << res << endl;
    }
}

int main()
{
    //clock_t tStart = clock();
    //run();
    l n, m;
    while(cin>>n>>m && n+m) {string s; getline(cin,s);solve(n, m);}
    //printf("Time taken: %.10fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}

/*
6 4
engine
brakes
tires
ashtray
vinyl roof
trip computer
Chevrolet
20000.00 3
engine
tires
brakes
Lada
70000.00 4
ashtray
vinyl roof
trip computer
engine
Hyundai
10000.00 3
engine
tires
ashtray
Cadillac
7000.00 4
ashtray
vinyl roof
trip computer
engine
1 1
coffee
Starbucks
1.50 1
coffee
0 0
*/

/*1
RFP # 1
Cadillac

0
RFP # 2
Starbucks
*/


