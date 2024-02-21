//Segment tree
#include <bits/stdc++.h>
using namespace std;
int a[100001];
int seg[400001];
void build(int id, int l, int r){
    if(l==r){
        seg[id]=1;
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    seg[id]=seg[id*2]+seg[id*2+1];
}
int get(int id, int l, int r, int u, int v){
    if(u>r || v<l) return 0;
    if(l>=u && r<=v) return seg[id];
    int mid=(l+r)/2;
    int t1=get(id*2,l,mid,u,v);
    int t2=get(id*2+1,mid+1,r,u,v);
    return t1+t2;
}
void update(int id, int l, int r, int x, int val){
    if(x<l || x>r) return;
    if(l==r){
        seg[id]=val;
        return;
    }
    int mid=(l+r)/2;
    update(id*2,l,mid,x,val);
    update(id*2+1,mid+1,r,x,val);
    seg[id]=seg[id*2]+seg[id*2+1];
}
int main()
{
    freopen("SAPXEP.INP","r",stdin);
    freopen("SAPXEP.OUT","w",stdout);
    int n; cin>>n;
    build(1,1,n);
    for(int i=1;i<=n;++i){
        int ind; cin>>ind;
        a[ind]=i;
    }
    int cnt=0,st=1,ed=n;
    while(cnt!=n){
        if(cnt%2==0){
            cout<<get(1,1,n,1,a[st])-1<<"\n";
            update(1,1,n,a[st],0);
            st++;
        }
        else{
            cout<<get(1,1,n,a[ed],n)-1<<"\n";
            update(1,1,n,a[ed],0);
            ed--;
        }
        cnt++;
    }
    return 0;
}
