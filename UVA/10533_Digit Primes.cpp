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
    freopen("output8.txt", "w", stdout);
#else
#endif
}
const l ma = 1000005;
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

l digit_sum(l n){
    l sum = 0;
    while(n!=0){sum+=(n%10);n/=10;}
    return sum;
}

ll result[ma];
void precal(){
    result[0] = result[1] = 0;
    l j = 0;l sum;ll cnt = 0;
    for(l i = 2; i < ma; i++){
        //if(i%10==0) j++;
        if(!(marked[i])){
            //sum = abs((i-(j*9)));
            sum = digit_sum(i);
            if(!(marked[sum])) cnt++;
        }
        result[i] = cnt;
    }
}

void solve(){
    l a, b;scanf("%d %d", &a, &b);
    //for(l i = 0; i < 21; i++) cout << result[i] << " ";
    //cout << endl;
    printf("%lld\n", result[b] - result[a-1]);
}

int main()
{
    //clock_t tStart = clock();
    //run();
    sieve();
    precal();
    l n;scanf("%d", &n);
    while(n--){solve();}
    //printf("Time taken: %.10fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}


