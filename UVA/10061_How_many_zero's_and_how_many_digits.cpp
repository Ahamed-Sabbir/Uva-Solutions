#include <bits/stdc++.h>
using namespace std;
typedef int l;
typedef long long int ll;
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

// How many trailing zeros in N! in decimal number system
// ----> Highest power of base (10) that divides N! is the number of trailing zeros in N!
// ----> Same goes for any base number system (Highest power of base that divides N! is the number of trailing zeros)
// ----> For digit count its the logarithm properties of a number

map<l,l> m;
const l maa = 1050000;
const l ma = 800;
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

double ara[maa];
void precal(){
    //cout << "dukche\n";
    for(int i = 1; i < maa; i++){
        ara[i] = log(i) + ara[i-1] + 0.0;
    }
}

l highest_power_of_base_b_that_divides_N_factorial(l n, l b){
    //cout << "dukche\n";
    m.clear();l cnt = 0; bool t = false;
    while(!(b%primes[0])){
        cnt++;
        b/=(primes[0]);
        t = true;
    }
    if(t) m.insert(make_pair(primes[0], cnt));
    for(l i = 1; primes[i]*primes[i] <= b; i++){
        cnt = 0;
        if(!(b%primes[i])){
            while(!(b%primes[i])){
                cnt++;
                b/=(primes[i]);
            }
            m.insert(make_pair(primes[i], cnt));
        }
    }
    if(b > 1) m.insert(make_pair(b, 1));
    l res = INT_MAX;
    for(auto it = m.begin(); it != m.end(); it++){
        cnt = 0;
        for(l num = it->first; num <= n; num*=(it->first)){
            cnt += (n/(num));
        }
        res = min(res, (cnt/(it->second)));
    }
    return res;
}

void solve(l n, l b){
    l cnt = ((ara[n]/(log(b))))+1;//l pwr;
    l pwr = highest_power_of_base_b_that_divides_N_factorial(n, b);
    cout << pwr << " " << cnt << endl;
}

int main()
{
    //clock_t tStart = clock();
    //run();
    sieve();
    precal();
    ll n, b;//cin>>n;
    while(cin>>n>>b){solve(n, b);}
    //printf("Time taken: %.10fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}


