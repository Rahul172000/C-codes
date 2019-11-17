#include <iostream>
using namespace std;


void insert(int*ip,int s,int el)
{
  int c=s,temp;
  int p=(c-1)/2;
  while(p>=0&&ip[c]<ip[p])
  {
    temp=ip[p];
    ip[p]=ip[c];
    ip[c]=temp;
    c=p;
    p=(c-1)/2;
  }
}
void remove(int*ip,int s)
{
  int temp,p,lc,rc,moc;
  temp=ip[0];
  ip[0]=ip[s-1];
  ip[s-1]=temp;
  s--;
  p=0;
  lc=1;rc=2;
  if(s==2)
  {moc=lc;}
  else{
  if(ip[lc]<ip[rc])
  {moc=lc;}
  else
  {moc=rc;}
  }
  while(moc<s)
  {
    if(ip[p]>ip[moc])
    {
      temp=ip[p];
      ip[p]=ip[moc];
      ip[moc]=temp;
    }
    else
    {break;}
    p=moc;
    lc=2*p+1;
    rc=2*p+2;
    if(lc<s&&rc<s)
    {
      if(ip[lc]<ip[rc])
      {moc=lc;}
      else
      {moc=rc;}
    }
    else
    {
      if(lc<s)
      {moc=lc;}
      else
      {break;}
    }
  }
}
void inplaceHeapSort(int input[], int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Change in the given input itself.
     * Taking input and printing output is handled automatically.
     */
  for(int i=1;i<n;i++)
  {insert(input,i,input[i]);}
  for(int i=0;i<(n-1);i++)
  {remove(input,n-i);}
}


int main() {

	int size;
	cin >> size;
	int *input = new int[1 + size];

	for(int i = 0; i < size; i++)
		cin >> input[i];

	inplaceHeapSort(input, size);
	cout<<"\n";

	for(int i = 0; i < size; i++)
		cout << input[i] << " ";

	return 0;
}
