#include<bits/stdc++.h>

void solve(){
    double a,b,n;
    std::cin>>a>>b>>n;
    int ans=1;
    if(a/n>=b||a==b){
        std::cout<<1<<"\n";
        return ;
    }else{
        std::cout<<2<<"\n";
        return ;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin>>t;
    while(t--){
        solve();
    }

    return  0;
}