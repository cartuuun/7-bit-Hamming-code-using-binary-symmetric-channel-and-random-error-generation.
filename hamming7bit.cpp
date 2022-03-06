#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;
void ham(int a, int r,int c[]);
int a, b, c[30], d, r = 0, d1,r1,rem,k,err[10]={0}; //Max bits here i kept is 30
int main ()
{
	srand(time(0));
    cout << "Enter the No of Data Bits you want to Enter :(Ex: 10011001 so enter 8.) ";
    cin >> a;
    cout << "Enter the Data Bits One by One :" << endl;
    for (int i = 1; i <= a; ++i)
        cin >> c[i];
        rem=4-(a%4);
        for(int i=1; i<=rem;++i)
        c[a+i]=0;
        cout<<"---------Sender side----------";
    cout << endl << "Data bits entered : ";
    for (int i = 1; i <= a+rem; ++i)
        {
		cout << c[i] << " ";
        if(i%4==0)
        cout<<"  ";
        }
    cout << endl;
    int fix=0;
    cout<<endl<<"---------Receiver side----------"<<endl;
    int tempham[5];
    for(int i=1;i<=((a+rem)/4);i++)
    {
    	tempham[1]=c[1+fix];
    	tempham[2]=c[2+fix];
    	tempham[3]=c[3+fix];
    	tempham[4]=c[4+fix];
    	ham(4,3,tempham);
    	fix=fix+4;
	}
}
    
    void ham(int a, int r,int c[])
    {
    int data[a + r], res[a+r];
    d = 0;
    d1 = 1;
    for (int i = 1; i <= a + r; ++i)
    {
      if ((i) == pow (2, d))
        {
        data[i] = 0;
        ++d;
        }
      else
        {
        data[i] = c[d1];
        ++d1;
        }
    }
    cout<<"Data Bits taken are : \t "; 
    for(int i=1;i<=4;i++)
    cout<<c[i]<<" ";
    cout<<endl;
    cout << "Data Bits are Encoded with Parity bits(0): ";
    for (int i = 1; i <= a + r; ++i)
        cout << data[i] << " ";
        
        
    d1 = 0;
    int min, max = 0, parity, s, j;
    /*Parity Bit Calculation */
    for (int i = 1; i <= a + r; i = pow (2, d1))
    {
      ++d1;
      parity = 0;
      j = i;
      s = i;
      min = 1;
      max = i;
      for (j; j <= a + r;)
    {
        for (s = j; max >= min && s <= a + r; ++min, ++s)
        {
        if (data[s] == 1)
            parity++;
        }
        j = s + i;
        min = 1;
    }
      if (parity % 2 == 0) // Even Parity
    {
    data[i] = 0;
    }
      else
    {
    data[i] = 1;
    }
    }
    cout << endl << "Hamming codeword bits for even parity are : ";
    for (int i = 1; i <= a + r; ++i)
        cout << data[i] << " ";
    cout << endl << endl;
    for (int i = 1; i <= a + r; ++i)
        res[i]=data[i];
    k=(rand()%(a+r))+1;
	if(res[k]==0)
	res[k]=1;
	else
	res[k]=0;  
	cout<<"Error introduced code is :"<<endl;
	for (int i = 1; i <= a + r; ++i)
        cout << res[i] << " ";
    cout << endl;
    d1 = 0;max=0;int ec=0;
    //int min, max = 0, parity, s, j;
    /*Parity Bit Calculation */ 
    for (int i = 1; i <= a + r; i = pow (2, d1))
    {
      ++d1;
      parity = 0;
      j = i;
      s = i;
      min = 1;
      max = i;
      for (j; j <= a + r;)
    {
        for (s = j; max >= min && s <= a + r; ++min, ++s)
        {
        if (res[s] == 1)
            parity++;
        }
        j = s + i;
        min = 1;
    }
      if (parity % 2 == 0) // Even Parity
    {
    err[ec]=0;
    ec++;
    }
      else
    {
    err[ec]=1;
    ec++;
    }
    }
    int flag = 1;
    for(int i =r-1;i>=0;i--)
    {
        if(err[i]==1)
        {
            flag =0;
                break;
        }
    }
    if(flag==0)
    {
        int pos=0;
    for(int i =r-1;i>=0;i--)
    {
        if(err[i]==1)
            pos+=pow(2,i);
    }
        cout<<"\nPosition of error :"<<pos;
        res[pos]=!res[pos];
        cout<<"\nAfter correction: ";
        for(int i =1;i<=a+r;i++)
          cout<<res[i]<<" ";
          cout<<endl<<endl;
    }
    else
       cout<<"No Error detected. ";

}
    

//End
