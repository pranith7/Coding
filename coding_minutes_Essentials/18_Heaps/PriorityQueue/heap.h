#include<vectors>
using namespace std;

// int main()
class Heap{

    vector<int> v;
    void heapify(int i)
    {
        int left = 2*i;
        int right = 2*i + 1;
        int minidx = i;

        if(left < v.size() and v[left] < v[i])
        {
            minidx = left;
        }
        if(right < v.size() and v[right] < v[minidx])
        {   
            minidx = right;
        }
        if(minidx!=i)
        {
            swap(v[i],v[minidx]);
            heapify(minidx);
        }
    }

public:
    Heap(int default_size = 10)
    {
        v.reserve(default_size+1);
        v.push_back(-1);
    }

    void insert(int data)
    {
        v.push_back(data);
        int idx = v.size()-1;
        int parent = idx/2;
        while(index>1 and v[index] < v[parent])
        {
            swap(v[index],v[parent]);
            index = parent;
            parent = parent/2;
        }
    }
    void getmin()
    {
        return v[1];
    }

    void pop()
    {
        swap(v[1],v[vise()-1]);//swapping first and last elements
        v.pop_back();//removing last element;
        heapify(1);

    }

    bool isEmpty()
    {
        return v.size() == 1;
    }

};