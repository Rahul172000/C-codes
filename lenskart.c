#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str,ans,*word=new string;
    cout<<"Enter a string ";
    gets(str);
    for(int i=0;i<str.len();i++)
    {
        if(str[i]==' ')
        {
            ans=word+ans;
            delete word;
            word=new string;
        }
        else
        {
            word+=str[i];
        }
    }
    cout<<endl<<ans;
}
