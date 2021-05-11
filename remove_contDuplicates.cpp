/******************************************************************************
Program to remove continuous occurance of duplicates 
Example :   I/P "MMMMMMMMMMMMMMMMMMMMMMMICCCROOOOFOCUUUUSS";
            O/P : MICROFOCUS

*******************************************************************************/
#include <iostream>
using namespace std;

void remove_duplicate(char str[],int * length)
{
    int index_i = 0;
    int index_j = 1;
    int len = *length;
    while(index_i < len && index_j < len)
    {
        if(str[index_i] == str[index_j])
        {
            index_j++;
        }
        else
        {
            index_i++;
            if(index_i != index_j)
               str[index_i] = str[index_j];
        }
    }
    str[index_i+1] = '\0';
    *length = index_i+1;
    return ;
    
}

int main()
{
  char arr[] = "MMMMMMMMMMMMMMMMMMMMMMMICCCROOOOFOCUUUUSS";
    
    int len = sizeof(arr)/sizeof(arr[0]) - 1;
    cout<<"Before : "<<arr<<" : length = "<<len<<endl;
    remove_duplicate(arr,&len);
    cout<<"After : "<<arr<<" : length = "<<len<<endl;

    return 0;
}
