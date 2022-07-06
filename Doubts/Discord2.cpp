#include<bits/stdc++.h>

using namespace std;

void swap(int &x,int &y)
{
    int temp=x;
    x=y;
    y=temp;
}

class minheap{
    public:

    int *harr;
    int capacity;
    int heap_size;

    minheap(int cap)
    {
        heap_size=0;
        capacity=cap;
        harr=new int[cap];
    }
   
    int parent(int i);
    int left(int i);
    int right(int i);
    int getmin();
    int extractmin();
    void insert(int key);
    void heapify(int i);
    bool linearsearch(int val);
    void printarray();
    void decrease(int k);
    void deletekey(int i);   
    int heapsize()
    {
        return heap_size > 0;
    } 
    int height()
    {
        return ceil(log2(heap_size+1))-1;
    }

};

int minheap::getmin(){
    return harr[0];
}
void minheap::printarray()
{
    for(int i=0;i<heap_size;i++)
        cout<<harr[i]<<" ";
    cout<<endl;
}
bool minheap::linearsearch(int x)
{
    for(int i=0;i<heap_size;i++)
    if(harr[i]==x)
    return true;

    return false;
}
void minheap::heapify(int i)
{
    int l=left(i);
    int r=right(i);
    int smallest=i;

    if(l<heap_size && harr[i]>harr[l])
    smallest=l;
    if(r<heap_size && harr[r]<harr[smallest])
    smallest=r;

    if(smallest!=i)
    {
         swap(harr[i],harr[smallest]);
         heapify(smallest); 
    }
}
int minheap::parent(int i)
{
    return (i-1)/2;

}
int minheap::left(int i)
{
    return (2*i+1);
}
int minheap::right(int i)
{
    return (2*i+2);
}
void minheap::decrease(int i)
{
    harr[i]=INT_MIN;
    while(i!=0 && harr[parent(i)]>harr[i])
    {
        swap(harr[i],harr[parent(i)]);
        i=parent(i);
    }
}
void minheap::deletekey(int i)
{
    decrease(i);
    extractmin();
}
void minheap::insert(int key)
{
    if(heap_size==capacity)
     {
         cout<<"heap overflow"<<endl;
         return ;
     }
     heap_size++;
     int i=heap_size-1;
     harr[i]=key;
     while(i!=0 && harr[parent(i)]>harr[i])
        {
            swap(harr[i],harr[parent(i)]);
            i=parent(i);
        }
}
int minheap::extractmin()
{
    if(heap_size<=0)
    return INT_MAX;

    if(heap_size==1)
    {
        heap_size--;
        return harr[0];
    }
    int root=harr[0];
    harr[0]=harr[heap_size-1];
    heap_size--;
    heapify(0);

    return root;
}


int minCost(int x[],int size)
{
    minheap h(size);
    for(int i=0;i<size;i++)
       h.insert(x[i]);
       int sum=0;
       sum=(h.extractmin()+h.extractmin());
    while(h.heapsize())
    {
        h.insert(sum);
        sum+=h.extractmin();
    }

    return sum;
}



int main()
{
    int len[] = { 4, 3, 2, 6 };
    int size = sizeof(len) / sizeof(len[0]);
    cout << "Total cost for connecting ropes is "<<minCost(len, size);
    return 0;
}