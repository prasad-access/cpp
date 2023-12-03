/* Problem statement : Given an integer array, find the subarray with the largest sum and the corresponding subarray */
/* Solution using Dynamic programming  - Window sliding technique - fixed window */

#include<iostream>
using namespace std;

int maximum_sum(int arr[],int size, int k,int &index)
{
    /*Sum of initial window elements of length k*/
    int wind_sum = 0;
    for(int i=0; i<k; i++)
        wind_sum+= arr[i];
    int max_sum = wind_sum;
    
    /*Sliding the window towards rhs starting from lhs - element by element */
    for(int i=k; i<size; i++)
    {
        /*remove elements from lhs side of window and add elements from rhs */
        wind_sum+= arr[i] - arr[i-k];
       
        if(wind_sum > max_sum)
        {
            max_sum = wind_sum;
            index = i-k+1;
        }
    }
    
    return max_sum;
}

void print_elements(int arr[], int startindex, int count)
{
    int k=1;
    cout<<"{";
    for(int i = startindex; k<=count;k++)
        cout<<arr[i++]<<",";
    cout<<"}"<<endl;
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    int k = 5;
    int index=0;
    int maxsum = maximum_sum(arr,size,k,index);

    cout<<"Maximum_sum = "<<maxsum<<endl;
    print_elements(arr,index,k);
}
