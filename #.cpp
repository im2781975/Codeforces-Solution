// 1003A
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[101];
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i];
    int pos[204];
    int need[204];
    fill(pos,pos+204,0);
    fill(need,need+204,0);
    vector<int>v;
    for(int i=0; i<n; i++)
    {
        if(pos[a[i]]==0){
            pos[a[i]]=1;
            v.push_back(a[i]);
        }
    }
    int s;
    s=v.size();
    sort(v.begin(),v.end());
//    for(int i=0; i<s; i++)
//        cout<<v[i]<<" ";
    int k=0;
    for(int i=0; i<s; i++){
        for(int j=0; j<n; j++){
            if(v[i]==a[j]){
                need[k]=need[k]+1;
            }
        }
        k++;
    }
    sort(need,need+k,greater<int>());
    cout<<need[0]<<endl;

    return 0;
}
// 1005A
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[1010],step[1010];
    cin>>n;

    int c=0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        if(a[i]==1){
            c++;
        }
    }

    memset(step,0,sizeof(step));
    int k=0;

    for(int i=0; i<n; i++){
        if(a[i]==1){
            step[k]++;
            for(int j=i+1; j<n; j++){
                if(a[j]==1){
                    break;
                }
                else{
                    step[k]++;
                }
            }
            k++;
        }
    }
    cout<<c<<"\n";
    for(int i=0; i<k; i++){
        cout<<step[i]<<" ";
    }
    cout<<"\n";

    return 0;

}
/*
SIMPLE INPUT
7
1 2 3 1 2 3 4

*/
// 1005B
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int l1,l2,len,c=0;
    string s,t;
    cin>>s>>t;
    l1=s.length();
    l2=t.length();
    len=l1+l2;
//    cout<<l1<<" "<<l2<<"\n";
    if(s[l1-1] != t[l2-1]){
        cout<<len<<"\n";
    }

    else{
        l1--,l2--;
//        cout<<l1<<" "<<l2<<"\n";
        while(l1>=0 && l2>=0){
            if(s[l1] == t[l2]){
                c++;
                l1--,l2--;
            }
            else  if( (s[l1] != t[l2]) || (l1==-1 || l2==-1) ){
               break;
            }
        }
        cout<<len-(c*2)<<"\n";
    }

    return 0;
}
/*
SIMPLE INPUT
codeforces
yes
*/
// 1006A
//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define fastread() (ios_base:: sync_with_stdio(false),cin.tie(NULL));
using namespace std;
int main()
{
    fastread();
    int n;
    ll a[1010];
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
        if(a[i] % 2 == 0){
            a[i] = a[i]-1;
        }
    }
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    return 0;
}
// 1017A
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i=0;
    int a,b,c,d;
    int s[1001];
    cin>>n;
    for(i=0; i<n; i++){
        int sum=0;
        cin>>a>>b>>c>>d;
        sum=a+b+c+d;
        s[i]=sum;
    }
//    for(i=0; i<n; i++){
//        cout<<s[i]<<" ";
//    }
    int Smith=s[0];
    sort(s,s+n,greater<int>());
    for(int i=0; i<n; i++){
        if(Smith==s[i]){
            cout<<i+1<<endl;
            break;
        }
    }

    return 0;
}

/*
SIMPLE INPUT
5
100 98 100 100
100 100 100 100
100 100 99 99
90 99 90 100
100 98 60 99

*/
// 1030A
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,tag=0;
// all comments are bug
//    string s;
    cin>>n;
    int s[105];
//    cin>>s;
    for(int i=0; i<n; i++)
    {
        cin>>s[i];
        tag+=s[i];
//        if(s[i]==1)
//        {
//            tag=1;
//            break;
//        }
    }
//    if(tag==1)
    if(tag>0)
        cout<<"HARD";
    else
        cout<<"EASY";
    cout<<endl;

    return 0;
}
// 1043A
//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
#define ll              long long
#define ull             unsigned long long
#define pb              push_back
#define fastread()      (ios_base:: sync_with_stdio(false),cin.tie(NULL));
using namespace std;
int main()
{
    fastread();
    int n;
    int a[101];
    cin>>n;
    int Elodreip = 0, Awruk = 0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        Elodreip += a[i];
    }
    sort(a,a+n);
    int k = a[n-1];
    for(int i=0; i<n; i++){
        Awruk += k - a[i];
    }
    if(Awruk <= Elodreip){
        Awruk = 0;
        while(Awruk < Elodreip){
            for(int i=0; i<n; i++){
                Awruk += k - a[i];
            }
            if(Awruk > Elodreip){
                cout<<k<<endl;
                break;
            }
            else{
                Awruk = 0;
                k++;
            }
        }
    }
    else{
        cout<<k<<endl;
    }

    return 0;
}
// 1047A
//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
#define ll              long long
#define ull             unsigned long long
#define pb              push_back
#define fastread()      (ios_base:: sync_with_stdio(false),cin.tie(NULL));
using namespace std;
int main()
{
    fastread();
    ll n,a,b,c;
    cin>>n;
    if( (n - 2) % 3 == 0){
        a = 1,b = 2,c = (n - 3);
    }
    else{
        a = 1,b = 1,c = (n - 2);
    }
    cout<<a<<" "<<b<<" "<<c<<endl;
    return 0;
}
// 1051B
#include<bits/stdc++.h>
#define ll              long long
#define ull             unsigned long long
#define pb              push_back
#define fastread()      (ios_base:: sync_with_stdio(false),cin.tie(NULL));
using namespace std;
int main()
{
    fastread();
    //freopen("input.txt","r", stdin);
    ll n, l, r,gcd = 0, a, b;
    cin>>l>>r;
    a = l, b = r;
    n = (r - l +1) / 2;
    vector< pair<ll,ll> >v;
    for(ll i=0; i<n; i++){
        v.pb(make_pair(a++,b--));
    }
    for(ll i=0; i<n; i++){
        gcd = __gcd(v[i].first,v[i].second);
        if(gcd > 1){
            if(i+1 < n){
                swap(v[i].first,v[i+1].second);
            }
        }
    }
    bool ok = false;
    for(ll i=0; i<n; i++){
        gcd = __gcd(v[i].first,v[i].second);
        if(gcd == 1){
            ok = true;
        }
        else{
            ok = false;
            break;
        }
    }
    if(ok){
        cout<<"YES\n";
        for(ll i=0; i<n; i++){
            cout<<v[i].first<<" "<<v[i].second<<endl;
        }
    }
    else{
        cout<<"NO\n";
    }
    return 0;
}
// 1060A
//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
int main()
{
    int n,eights=0;
    string s;
    cin>>n>>s;
    for(int i=0; i<n; i++){
        if(s[i] == '8'){
            eights++;
        }
    }
    if(eights >= n/11){
        cout<<n/11<<endl;
    }
    else if(eights < n/11 && n > 11){
        cout<<eights<<endl;
    }
    else{
        cout<<0<<endl;
    }

    return 0;
}
// 1061A
//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
int main()
{
    int n, s, ans = 0;
    cin>>n>>s;
    for(int i=n; i>0; i--){
        ans+=s/i;
        s%=i;
    }
    cout<<ans<<endl;

    return 0;
}
// 1065A
//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define fastread() (ios_base:: sync_with_stdio(false),cin.tie(NULL));
using namespace std;
int main()
{
    fastread();
    int t;
    ll s,a,b,c;
    ull ans,can_buy,div;

    cin>>t;
    while(t--)
    {
        div = can_buy = ans = 0;
        cin>>s>>a>>b>>c;
        can_buy = s/c;
        div = can_buy/a;
        ans = (div*a) + (div*b);
        ans +=(can_buy%a);

        cout<<ans<<endl;
    }

    return 0;
}
// 1073A
#include<bits/stdc++.h>
#define ll              long long
#define ull             unsigned long long
#define pb              push_back
#define fastread()      (ios_base:: sync_with_stdio(false),cin.tie(NULL));
using namespace std;
int main()
{
    fastread();

    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w", stdout);

    ll n;
    string s,t;
    cin>>n>>s;

    bool flag = false;
    for(ll i=0; i<n-1; i++){
        if(s[i] != s[i+1]){
            flag = true;
            t += s[i];
            t += s[i+1];
            break;
        }
        else{
            flag = false;
        }
    }
    if(flag){
        cout<<"YES"<<endl;
        cout<<t<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

    return 0;
}
// 1077A
#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int a,b,q,d;
    long long int ans;
    int t;
    cin>>t;
    while(t--)
    {
        ans=d=0;
        cin>>a>>b>>q;
        if(q%2==1){
            d=(q/2)+1;
        }else{
            d=q/2;
        }
        ans=(d*a)-((q-d)*b);
        cout<<ans<<"\n";
    }
    return 0;
}
/*
SIMPLE INPUT
6
5 2 3
100 1 4
1 10 5
1000000000 1 6
1 1 1000000000
1 1 999999999
*/
// 1077B
//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
#define ll              long long
#define ull             unsigned long long
#define fastread()      (ios_base:: sync_with_stdio(false),cin.tie(NULL));
using namespace std;
int main()
{
    fastread();
    int n,a[101];
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int k = 0;
    for(int i=1; i<n-1; i++){
        if( (a[i] == 0 && (a[i-1] == 1 && a[i+1] == 1)) ){
            k++;
            i += 2;
        }
    }
    cout<<k<<endl;

    return 0;
}
// 1080A
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,k,sum;
    cin>>n>>k;
    long int red,green,blue;
    red=ceil( ( ( 2 * n ) + k - 1 ) / k );
    green=ceil( ( ( 5 * n ) + k - 1 ) / k );
    blue=ceil( ( ( 8 * n ) + k - 1 ) / k );
    sum=red+green+blue;
    cout<<sum<<"\n";
}
// 1081A
//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n == 2){
        cout<<n<<endl;
    }
    else
        cout<<1<<endl;

    return 0;
}
// 1088A
//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define fastread() (ios_base:: sync_with_stdio(false),cin.tie(NULL));
using namespace std;
int main()
{
    fastread();
    int n,a,b;

    int ans1 = 0, ans2 = 0, flag = 0;

    cin>>n;
    if(n < 2){
        cout<<-1<<endl;
        return 0;
    }
    if(n%2 != 0){
        a = n-1;
    }
    else{
        a = n;
    }
    cout<<a<<" "<<2<<endl;

    return 0;
}
// 1088B
//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
#define ll              long long
#define ull             unsigned long long
#define fastread()      (ios_base:: sync_with_stdio(false),cin.tie(NULL));
using namespace std;

int main()
{
    fastread();
    ll n,k,a;
    cin>>n>>k;
    set<ll>s;
    s.insert(0);
    for(ll i=0; i<n; i++){
        cin>>a;
        s.insert(a);
    }

    auto it = s.begin();
    for(auto i=0; i<k; i++){
        if (next(it) == s.end()){
            cout<<0<<endl;
        }
        else{
            cout<<*next(it) - *it<<endl;
            it = next(it);
        }
    }
    return 0;
}
// 1090M
#include<bits/stdc++.h>
#define ll              long long
#define ull             unsigned long long
#define pb              push_back
#define fastread()      (ios_base:: sync_with_stdio(false),cin.tie(NULL));
using namespace std;
int main()
{
    fastread();
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w", stdout);

    ll n,k,a[100001],b[100001];
    cin>>n>>k;
    for(ll i=0; i<n; i++){
        cin>>a[i];
    }
    for(ll i=0; i<n; i++){
        b[i] = 1;
    }
    ll j = 0;
    for(ll i=1; i<n; i++){
        if(a[i] != a[i-1]){
            b[j]++;
        }
        else{
            j++;
        }
    }
    sort(b,b+n,greater<ll>());
    ll ans = b[0];
    cout<<ans<<endl;

    return 0;
}
// 1091A
//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define fastread() (ios_base:: sync_with_stdio(false),cin.tie(NULL));
using namespace std;
int main()
{
    fastread();
    int y,b,r,Min = 0, ans = 0;
    cin>>y>>b>>r;
    if((y == b) && (b == r))
    {
        cout<<y*3-3<<endl;
        return 0;
    }
    Min = min(y,min(b,r));
    if(Min == y){
        if(r >= Min+2){
            ans = (Min * 3) + 3;
        }
        else{
            ans = (Min * 3) ;
        }
    }
    if(Min == b){
        if(r >= Min+1){
            ans = (Min * 3);
        }
        else{
            ans = (Min * 3) - 3;
        }
    }
    if(Min == r){
        ans = (Min * 3) - 3;
    }
    cout<<ans<<endl;

    return 0;
}
// 1092/A
//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
#define ll              long long
#define ull             unsigned long long
#define pb              push_back
#define fastread()      (ios_base:: sync_with_stdio(false),cin.tie(NULL));
using namespace std;
int main()
{
    fastread();
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        char a[] = {"abcdefghijklmnopqrstuvwxyz"};
        int j = 0;
        for(int i=0; i<n; i++){
            cout<<a[j++];
            if(j == k){
                j = 0;
            }
        }cout<<endl;
    }

    return 0;
}
// 1092B
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,s=0,i;
    cin>>n;
    int a[n+5];
    for(i=0; i<n; i++)
        cin>>a[i];
    sort(a,a+n);
    for(i=0; i<n; i+=2)
    {
        if(a[i]!=a[i+1])
            s+=(a[i+1]-a[i]);
    }
    cout<<s<<endl;
    return 0;
}
// 1093A
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    while(t--){
        int ans=0;
        cin>>n;
//        for(int i=7; i>1; i--){
//            ans+=n/i;
//            n=n%i;
//        }
        cout<<n/2<<endl;
    }
}
// 1093B
//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    string s,r;
    cin>>t;
    while(t--)
    {
        cin>>s;
        r=s;
        reverse(r.begin(),r.end());
        int len=s.length();
        int tag=0;
        set<char>S;
        for(int i=0; i<len; i++){
            if(s[i]==r[i])
                tag=1;
            S.insert(s[i]);
        }
        if(tag==0){
            cout<<s<<endl;
        }
        else if(S.size()==1){
            cout<<-1<<endl;
        }
        else if(tag == 1){
            sort(s.begin(),s.end());
            cout<<s<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
}
// 1095A
//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
#define ll              long long
#define ull             unsigned long long
#define pb              push_back
#define fastread()      (ios_base:: sync_with_stdio(false),cin.tie(NULL));
using namespace std;
int main()
{
    fastread();
    int n,k = 3;
    string s,t;
    cin>>n>>s;
    if(n >= 2){
        t += s[0];
        t += s[1];
    }
    else{
        t += s[0];
    }
    for(int i=3; i<n;){
        t += s[i];
        i += k;
        k++;
    }
    cout<<t<<endl;
    return 0;
}
// 1095B
//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
#define ll              long long
#define ull             unsigned long long
#define pb              push_back
#define fastread()      (ios_base:: sync_with_stdio(false),cin.tie(NULL));
using namespace std;
int main()
{
    fastread();
    ll n;
    cin>>n;
    vector<ll>a(n);
    for(ll i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    ll ans = a[n-2] - a[0];
    ans = min(ans,(a[n-1] - a[1]) );
    cout<<ans<<endl;

    return 0;
}
// 1096A
//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
#define ll              long long
#define ull             unsigned long long
#define pb              push_back
#define fastread()      (ios_base:: sync_with_stdio(false),cin.tie(NULL));
using namespace std;
int main()
{
    fastread();
    int t;
    ll l,r;
    cin>>t;
    while(t--){
        cin>>l>>r;

        cout<<l<<" "<<l*2<<endl;
    }

    return 0;
}
// 1097A
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=5,tag=0;
    while(n--)
    {
        string t;
        cin>>t;
//bug        if(s[0]=='A' && t[0]=='A')
        if(s[0]==t[0])
            tag=1;
        else if(s[1]==t[1])
            tag=1;
    }
    if(tag==1)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}
