#include <bits/stdc++.h>
using namespace std;
typedef int l;
typedef long long int ll;
#define loop(a, b) for(int i = a; i < b; i++)
#define PI acos(-1.0)
#define dukse cout << "dukhse" << endl;
const ll INF = LLONG_MAX;

const ll mod = 1000007;
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

void ay_dukh(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output8.txt", "w", stdout);
#else
#endif
}

l sz;
bool mark[1000005];
vector<l> primes;
void sieve(){
    mark[0] = mark[1] = true;
    l limit = sqrt(1000005*1.0)+2;
    for(l i = 4; i < 1000005; i+=2) mark[i] = true;
    primes.push_back(2);
    for(l i = 3; i < 1000005; i+=2){
        if(!(mark[i])){
            primes.push_back(i);
            if(i <= limit){
                for(l j = i*i; j < 1000005; j+=(i*2)){
                    mark[j] = true;
                }
            }
        }
    }
}

l find_pos(l target){
    l left = 0, right = sz - 1;
    while(left <= right){
        l mid = left + ((right-left)>>1);
        if(primes[mid]==target) return mid;
        if(primes[mid] > target) right = mid - 1;
        else left = mid + 1;
    }
}

l find_prime_just_less(l left, l right, l target){
    while(left <= right){
        l mid = left + ((right-left)>>1);
        if((mid==0 || mid == sz-1) || (primes[mid] < target && primes[mid+1] > target)) return mid;
        if(primes[mid] > target) right = mid - 1;
        else left = mid + 1;
    }
}
 
void solve(l m, l a, l b){
    l start = sqrt(m*1.0); l index;
    double bound = (double)(a)/(double)(b);
    if((mark[start])) index = find_prime_just_less(0, sz-1, start);
    else  index = find_pos(start);
    //cout << start << " " << index << " " << primes[index] << endl;
    l cnt = 0;
    l res1, res2, track = -1;
    for(l i = index; i >= 0; i--){
        //cnt++;
        l num = (double)(m)/(double)(primes[i]);
        l index1; if(mark[num]) {
            index1 = find_prime_just_less(i, sz-1, num);
            num = primes[index1];
        }
        else index1 = find_pos(num);
        double bound1;
        for(l j = index1; j >= i; j--){
            //cnt++;
            bound1 = (double)(primes[i])/(double)(primes[j]);
            //cout << bound << " " << bound1 << " " << primes[i] << " " << primes[j] << endl;
            if(bound1 >= bound && (primes[j]*primes[i]) <= m && (primes[j]*primes[i]) > track){
                res1 = primes[i]; res2 = primes[j]; track = primes[j]*primes[i];
                //cout << primes[i] << " " << primes[j] << " " << res1 << " " << res2 << endl;
                break;
            }
            //if(bound1 < bound) break;
            // cout << primes[i] << " " << primes[j] << " " << res1 << " " << res2 << endl;
        }
        if(bound1 < bound) break;
    }
    cout << res1 << " " << res2 << endl;
}

int main()
{
    //clock_t tStart = clock();
    ay_dukh();
    sieve();
    //l n; cin>>n;
    //while(n--){solve();}
    l m, a, b; sz = primes.size();
    while(cin>>m>>a>>b && m+a+b) {solve(m, a, b);}
    //printf("Time taken: %.10fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
