#include <bits/stdc++.h>
using namespace std;

void buildTree(int* arr, pair<int,int>* tree, int treeNode, int start, int end){
    if(start == end){
        pair<int,int> p;
        p.first = arr[start];
        p.second = INT_MIN;
        tree[treeNode] = p;
        return;
    }
    int mid = (start + end)/2;
    buildTree(arr,tree,2*treeNode,start,mid);
    buildTree(arr,tree,2*treeNode+1,mid+1, end);
    int maxindex = 0, smaxindex = 0;
    if(tree[2*treeNode].first > tree[2*treeNode+1].first){
        maxindex = 2*treeNode;
        smaxindex = 2*treeNode + 1;
    }
    else{
        maxindex = 2*treeNode + 1;
        smaxindex = 2*treeNode;
    }
    pair<int,int> p;
    p.first = tree[maxindex].first;
    p.second = max(tree[smaxindex].first,tree[maxindex].second);
    tree[treeNode] = p;
    return;
}

void update(int* arr, pair<int,int>* tree, int treeNode,int start, int end, int index, int value){
    if(start == end){
        pair<int,int> p;
        p.first = value;
        p.second = INT_MIN;
        tree[treeNode] = p;
        return;
    }
    int mid = (start + end)/2;
    if(index > mid){
        update(arr,tree,2*treeNode + 1, mid+1, end, index, value);
    }
    else{
        update(arr,tree,2*treeNode,start,mid,index,value);
    }
    int maxindex = 0, smaxindex = 0;
    if(tree[2*treeNode].first > tree[2*treeNode+1].first){
        maxindex = 2*treeNode;
        smaxindex = 2*treeNode + 1;
    }
    else{
        maxindex = 2*treeNode + 1;
        smaxindex = 2*treeNode;
    }
    pair<int,int> p;
    p.first = tree[maxindex].first;
    p.second = max(tree[smaxindex].first,tree[maxindex].second);
    tree[treeNode] = p;
    return;
}
pair<int,int> query(int* arr, pair<int,int>* tree, int treeNode, int start, int end, int sv, int ev){
    if(sv > end || ev < start){
        pair<int,int> p;
        p.first = INT_MIN;
        p.second = INT_MIN;
        return p;
    }
    else if(sv <= start && ev >= end){
        return tree[treeNode];
    }
    else{
        int mid = (start + end)/2;
        pair<int,int> p1 = query(arr,tree,2*treeNode,start,mid,sv,ev);
        pair<int,int> p2 = query(arr,tree,2*treeNode+1,mid+1, end,sv,ev);
        pair<int,int> p3;
        if(p1.first > p2.first){
            p3.first = p1.first;
            p3.second = max(p1.second, p2.first);
        }
        else{
            p3.first = p2.first;
            p3.second = max(p1.first,p2.second);
        }
        return p3;
    }
}
int main(){
    int n, arr[100000];
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    pair<int,int> *tree = new pair<int,int>[4*n];
    buildTree(arr,tree,1,0,n-1);
    int m;
    cin>>m;
    while(m--){
        char c;
        int a, b;
        pair<int,int> p;
        cin>>c>>a>>b;
        if(c == 'U'){
            update(arr,tree,1,0,n-1,a-1,b);
        }
        else if(c == 'Q'){
            p = query(arr,tree,1,0,n-1,a-1,b-1);
            cout<<p.first + p.second<<endl;
        }
    }
    delete [] tree;
    return 0;
}