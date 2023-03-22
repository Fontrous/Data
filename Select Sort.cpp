#include<stdio.h>
#include<vector>
using namespace std;
vector<int> Select_Sort(vector<int>& s)
{
    for(int i=0;i<s.size()-1;i++)
    {
        int min=i;
        int temp=s[i];
        int j=0;
        for(j=i+1;j<s.size();j++)
        {
            if(s[min]>s[j])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            s[i]=s[min];
            s[min]=temp;
        }
    }
    return s;
}
void print(vector<int>& s)
{
    for(vector<int>::const_iterator it=s.begin();it!=s.end();it++)
    {
        printf("%d ",*it);
    }
    printf("\n");
}
int main()
{
    vector<int> R;
    printf("输入数据，以-1结束\n");
    int key=0;
    scanf("%d",&key);
    while(key!=-1)
    {
        R.push_back(key);
        scanf("%d",&key);
    }
    Select_Sort(R);
    print(R);
    return 0;
}