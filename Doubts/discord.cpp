#include <bits/stdc++.h>

using namespace std;

class heap
{
    int *arr;
    int capicity;
    int n;

public:
    heap(int s)
    {
        arr = new int[s];
        n = 0;
        capicity = s;
    }
    int parent(int i)
    { 
        return (i - 1) / 2;
    }
    int left(int i)
    {
        return (2 * i + 1);
    }
    int right(int i)
    {
        return (i * 2 + 2);
    }
    int getmin()
    {
        return arr[0];
    }
    void heapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int small = i;

        if (l < n && arr[l] < arr[i]) small = i;
        if (r < n && arr[r] < arr[small]) small = i;
        if (i != small) swap(arr[i], arr[small]),heapify(small);
    }
    void insert(int key)
    {
        arr[n++] = key;
        int i = n-1;
        while (i != 0 && arr[i] < arr[parent(i)])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
        cout<<"array after insertion is"<<endl;
        for(int i = 0; i<n; i++) cout<<arr[i]<<" ";
        cout<<endl;
    }
    int search(int key)
    {
        for (int i = 0; i < n; i++)
            if (key == arr[i])
                return i;
        return -1;
    }
    void decrease(int i)
    {
        arr[i] = INT_MAX;
        while (i != 0 && arr[i] < arr[parent(i)])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }
    int extractmin()
    {
        if (n <= 0)
            return INT_MIN;
        if (n == 1)
            return arr[0];
        int root = arr[0];
        arr[0] = arr[n - 1];
        n--;
        heapify(0);
        return root;
    }
    void Delete(int key)
    {
        int i = search(key);
        decrease(i);
        extractmin();
    }
};

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    long long int n;
    heap abj(n);

    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int i;
            cin >> i;
            abj.insert(i);
        }
        else if (x == 2)
        {
            int i;
            cin >> i;
            abj.Delete(i);
        }
        else
        {
            cout << abj.getmin() << endl;
        }
    }
}
