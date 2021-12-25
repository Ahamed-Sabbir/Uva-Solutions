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
    if(s[0] >= 48 && s[0] <= 57){
        l n;
        sscanf(s, "%d", &n);
        string s4[4]={"", "M", "MM","MMM"};
        string s1[10]={"", "C", "CC","CCC", "CD","D","DC","DCC","DCCC","CM"};
        string s2[10]={"", "X", "XX","XXX", "XL","L","LX","LXX","LXXX","XC"};
        string s3[10]={"", "I", "II","III", "IV","V","VI","VII","VIII","IX"};
        l len = 0, x = n;
        while(n!=0){
            len++;
            n/=10;
        }
        l j;
        if(len==4)  j = 10000;
        if(len==3)  j = 1000;
        if(len==2)  j = 100;
        if(len==1)  j = 10;
        //cout << ((x%j)-(x%100))/10;
        for(l i = 1; i <= len; i++){
            if(j == 10) cout << s3[x%j];
            else if(j == 100 && len >= 2) cout << s2[((x%j)-(x%10))/10];
            else if(j == 1000 && len >= 3) cout << s1[((x%j)-(x%100))/100];
            else if(j == 10000 && len == 4) cout << s4[((x%j)-(x%1000))/1000];
            j = j/10;
        }
        cout << endl;
    }
    else {
        l sz = strlen(s);
        l ans = 0;
        l ara[100];
        ara[73] = 1;ara[88] = 10;ara[86] = 5;ara[76] = 50;ara[67] = 100;ara[68] = 500;ara[77] = 1000;
        for(l i = 0; i < sz;){
            if(s[i] == 'I' && s[i+1] == 'V'){ ans+=4;i+=2;}
            else if(s[i] == 'I' && s[i+1] == 'X'){ans+=9;i+=2;}
            else if(s[i] == 'X' && s[i+1] == 'L'){ans+=40;i+=2;}
            else if(s[i] == 'X' && s[i+1] == 'C'){ans+=90;i+=2;}
            else if(s[i] == 'C' && s[i+1] == 'D'){ans+=400;i+=2;}
            else if(s[i] == 'C' && s[i+1] == 'M'){ans+=900;i+=2;}
            else{
                ans+=(ara[((l)(s[i]))]);
                i++;
            }
        }
        cout << ans << endl;
    }

}

int main()
{
    //clock_t tStart = clock();
    //run();
    //l n;cin>>n;
    char s[100000];
    while(cin>>s) {solve(s);}
    //while(n--){solve();}
    //printf("Time taken: %.10fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}

