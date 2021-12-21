#include<iostream>
//#include<limits>
using namespace std;
template <class T>
    void swap(T *x,T *y)
    {
        T temp= *x;
        *x=*y;
        *y=temp;
    }
template <class T>    
    T SelectionSort()
    {   
        int n;
        cout<<"Enter the number of elements in the array: "<<endl;
        cin>>n;
        T a[n];
        cout<<"Enter the elements of the array: "<<endl;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int i,j,min_index;
        for(i=0;i<n-1;i++)
        {
            min_index=i;
            for(j=i+1;j<n;j++)
            if(a[j]<a[min_index])
                min_index=j;
            swap(&a[min_index], &a[i]);     
        }
        cout<<"Sorted array: "<<endl;
        for(i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<endl;  
       return 0; 
    }
int main()
{ 
  cout<<"Integer sorting: "<<endl;
  SelectionSort<int>();
  cout<<"**********************"<<endl;
  cout<<"Floating point sorting: "<<endl;
  SelectionSort<float>();
  return 0;
}

