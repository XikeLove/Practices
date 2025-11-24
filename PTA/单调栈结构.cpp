#include<bits/stdc++.h>
const int MAXN=1000010;

int nums[MAXN];
int st[MAXN];
int ans[MAXN][2];

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin>>n;
    for(int i=0;i<n;i++)std::cin>>nums[i];

    int top=0;
    int cur=0;
    for(int i=0;i<n;i++){
        while(top>0&&nums[st[top-1]]>=nums[i]){
            cur=st[--top];
            ans[cur][0]=top>0?st[top-1]:-1;
            ans[cur][1]=i;
        }
        st[top++]=i;
    }
    
    while(top>0){
        cur=st[--top];
        ans[cur][0]=top>0?st[top-1]:-1;
        ans[cur][1]=-1;
    }

    for(int i=n-2;i>=0;i--){
        if(ans[i][1]!=-1&&nums[ans[i][1]]==nums[i]){
            ans[i][1]=ans[ans[i][1]][1];
        }
    }
    
    for(int i=0;i<n;i++){
        std::cout<<ans[i][0]<<" "<<ans[i][1]<<"\n";
    }


    return 0;
}