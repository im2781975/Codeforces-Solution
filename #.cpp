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

