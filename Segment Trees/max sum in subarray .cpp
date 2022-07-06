#include <bits/stdc++.h>
using namespace std;
void buildTree(int* arr, int* tree, int treeNode, int start, int end){
    if(start == end){
        tree[treeNode] = arr[start];
        return;
    }
    int mid = (start+end)/2;
    buildTree(arr,tree,2*treeNode,start,mid);
    buildTree(arr,tree,2*treeNode + 1,mid+1,end);
    if(tree[2*treeNode] < 0 || tree[2*treeNode + 1] < 0){
        tree[treeNode] = max(tree[2*treeNode],tree[2*treeNode + 1]);
    }
    else{
        tree[treeNode] = tree[2*treeNode] + tree[2*treeNode + 1];
    }
    return;
}
int query(int* tree,int treeNode, int start, int end, int x, int y){
    if(start >= x && end <= y){
        return tree[treeNode];
    }
    else if(start > y || end < x){
        return 0;
    }
    else{
        int mid = (start + end)/2;
        int a = query(tree,2*treeNode,start,mid,x,y);
        int b = query(tree,2*treeNode + 1, mid+1,end,x,y);
        if(a < 0 || b < 0){
            return max(a,b);
        }
        return (a+b);
    }
}
int main(){
    int n,arr[100000];
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    int* tree = new int[4*n];
    buildTree(arr,tree,1,0,n-1);
    int m;
    cin>>m;
    while(m--){
        int x, y;
        cin>>x>>y;
        cout<<query(tree,1,0,n-1,x-1,y-1)<<" ";
    }
    return 0;
}