#include<iostream>
#include<vector>
using namespace std;
int binSearch(vector<int>&v,int key)
{
    int low=0;
    int high=v.size()-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(key==v[mid])
        {
            return mid;
        }
        else if(key<v[mid])
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return -1;
}
int main()
{
    vector<int> Stable;
    int key=0;
    cout<<"输入数据元素，以-1结束"<<endl;
    cin>>key;
    while(key!=-1)
    {
        Stable.push_back(key);
        cin>>key;
    }
    cout<<"请输入要查找的元素"<<endl;
    int number=0;
    cin>>number;
    int index=binSearch(Stable,number);
    cout<<"元素下标为："<<index<<endl;
    return 0;
}