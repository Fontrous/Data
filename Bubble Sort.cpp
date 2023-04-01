//冒泡排序
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
void B_sort(vector<int>& s)
{
    for(int j=s.size()-1;j>0;j--)
    {
        for(int i=0;i<j;i++)
        {
            int temp=0;
            if(s[i]>s[i+1])
            {
                temp=s[i+1];
                s[i+1]=s[i];
                s[i]=temp;
            }
        }
    }
}
void mf(int a)
{
    printf("%d ",a);
}
void print(vector<int>& s)
{
    for_each(s.begin(),s.end(),mf);
}
int main()
{
    vector<int> s;
    int key=0;
    printf("输入数据，以-1结束\n");
    scanf("%d",&key);
    while(key!=-1)
    {
        s.push_back(key);
        scanf("%d",&key);
    }
    B_sort(s);
    print(s);
    return 0;
}