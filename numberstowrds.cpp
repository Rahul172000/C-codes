#include<iostream>

#include<string>
using namespace std;
string words(long long int num)
{
    if(num==0){return "";}
    if(num==1){return "one";}
    if(num==2){return"two";}
    if(num==3){return"three";}
    if(num==4){return"four";}
    if(num==5){return"five";}
    if(num==6){return"six";}
    if(num==7){return"seven";}
    if(num==8){return"eight";}
    if(num==9){return"nine";}
    if(num==10){return"ten";}
    if(num==11){return"eleven";}
    if(num==12){return"twelve";}
    if(num==13){return"thirteen";}
    if(num==14){return"fourteen";}
    if(num==15){return"fifteen";}
    if(num==16){return"sixteen";}
    if(num==17){return"seventeen";}
    if(num==18){return"eighteen";}
    if(num==19){return"nineteen";}
    if(num==20){return"twenty";}
    if(num==30){return"thirty";}
    if(num==40){return"forty";}
    if(num==50){return"fifty";}
    if(num==60){return"sixty";}
    if(num==70){return"seventy";}
    if(num==80){return"eighty";}
    if(num==90){return"ninety";}
    return "";
}

string fun(long long int num,int pos)
{
    if(num==0)
    {
        return "";
    }
    string ans=words(num);
    if(ans=="")
    {
        int temp=num/10;
        temp*=10;
        ans=words(temp);
        ans=ans+" "+words(num%10);
    }
    if(pos==5)
    {
        ans=ans+" thousand";
    }
    else if(pos==7)
    {
        ans=ans+" lakhs";
    }
    else if(pos==9)
    {
        ans=ans+" crore";
    }
    return ans;
}
int main()
{
    long long int num;
    cin>>num;
    int temp;
    int pos=0;
    string ans="";
    while(num!=0)
    {
        temp=0;
        if(pos==2)
        {
            temp=num%10;
            num/=10;
            pos++;
            if(temp!=0)
            {
                ans=words(temp)+" hundred "+ans;
            }
        }
        else
        {
            temp=num%10;
            num/=10;
            temp=temp+num%10*10;
            num/=10;
            pos+=2;
            ans=fun(temp,pos)+" "+ans;
            if(pos==7)
            {
                if(num<=99)
                {
                    continue;
                }
                 else
                {
                    ans="crore "+ans;
                    pos=0;
                }
            }
        }
    }
    cout<<endl<<ans;
}

