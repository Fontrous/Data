#include<stdio.h>
#include<vector>
using namespace std;
vector<int> sort(vector<int>& s)
{
    for(int i=1;i<s.size();i++)
    {
        int temp=0;
        if(s[i]<s[i-1])
        {
            temp=s[i];
            s[i]=s[i-1];
            int j=0;
            for(j=i-1;j>=1&&temp<s[j-1];j--)
            {
                s[j]=s[j-1];
            }
            s[j]=temp;
        }
    }
    return s;
}
int main()
{
    vector<int> SStable;
    printf("请输入数据，以-1结束\n");
    int key=0;
    scanf("%d",&key);
    while(key!=-1)
    {
        SStable.push_back(key);
        scanf("%d",&key);
    }
    sort(SStable);
    for(vector<int>::iterator it=SStable.begin();it!=SStable.end();it++)
    {
        printf("%d ",*it);
    }    
    printf("\n");
    return 0;
}