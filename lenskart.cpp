#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str,ans="",*word=new string;
    cout<<"Enter a string\n";
    getline(cin,str);
    *word="";
    for(int i=0;i<=str.size();i++)
    {
        if(str[i]==' '||str[i]=='\0')
        {
            ans=*word+ans;
            delete word;
            word=new string;
            *word="";
            if(str[i]!='\0')
            ans=' '+ans;
        }
        else
        {
            *word+=str[i];
        }
    }
    cout<<endl<<ans;
}
