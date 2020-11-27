#include<iostream>
using namespace std;
int minJumps(int arr[],int n){
    if(n<=1) return 0;
    int jumps=0;
    pair<int,int> interval={0,0};
    while(true){
        jumps++;
        int can_reach=-1;
        for(int i=interval.first;i<=interval.second;i++){
            can_reach = max(can_reach,i+arr[i]);
        }
        if(can_reach>=n-1)
            return jumps;
        interval = {interval.second+1,can_reach};
        if(interval.first>interval.second)
            return -1;
    }
}
int main(){
    int i,n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<minJumps(arr,n)<<"\n";
    return 0;
}
