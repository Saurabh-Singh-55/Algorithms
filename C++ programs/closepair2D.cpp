#include <iostream>
#include <iomanip>
#include <fstream>
#include<algorithm>
#include<climits>
#include <bits/stdc++.h>

 using namespace std;



int partition(int arr[],int axy[100][100], int l, int r, int k);
int findMedian(int arr[], int n)
{
    sort(arr, arr+n);  // Sort the array
    return arr[n/2];   // Return middle element
}
int kthSmallest(int arr[],int axy[100][100], int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1)
    {
        int n = r-l+1;
        int i, median[(n+4)/5];
        for (i=0; i<n/5; i++)
            median[i] = findMedian(arr+l+i*5, 5);
        if (i*5 < n)
        {
            median[i] = findMedian(arr+l+i*5, n%5);
            i++;
        }
        int medOfMed = (i == 1)? median[i-1]:
                                 kthSmallest(median,axy, 0, i-1, i/2);
        int pos = partition(arr,axy, l, r, medOfMed);
        if (pos-l == k-1)
            return arr[pos];
        if (pos-l > k-1)
            return kthSmallest(arr,axy, l, pos-1, k);
        return kthSmallest(arr,axy, pos+1, r, k-pos+l-1);
    }
    return INT_MAX;
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[],int axy[100][100], int l, int r, int x)
{
    int i;
    for (i=l; i<r; i++)
        if (arr[i] == x)
           break;
    swap(&arr[i], &arr[r]);
    swap(&axy[i][0], &axy[r][0]);
    swap(&axy[i][1], &axy[r][1]);

    i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(&arr[i], &arr[j]);

    swap(&axy[i][0], &axy[j][0]);
    swap(&axy[i][1], &axy[j][1]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);

    swap(&axy[i][0], &axy[r][0]);
    swap(&axy[i][1], &axy[r][1]);
    return i;
}


float dist(int x1, int y1, int x2, int y2)
{
    // Calculating distance
    return sqrt(pow(x2 - x1, 2) +
                pow(y2 - y1, 2) * 1.0);
}

int across(int arr[100][100],int mid,float d,int len,int start,int *q,int *q2,int *e)
{
    int y[len-mid],k=-1,y1,y2,x1,x2;
    float d1=0.0f;
    for(int i=mid+1;i<=len;i++ )
        y[++k]=arr[i][1];
     for(int i=start;i<=mid;i++ )
     {
         y1=arr[i][1];
         x1=arr[i][0];
         for(int j=mid+1;j<=len;j++ )
         {
            y2=arr[j][1];
             x2=arr[j][0];
            if(((y1>y2)&&((y1-y2)<d))||((y1<y2)&&((y2-y1)<d)))
               {
                d1=dist(x1,y1,x2,y2);
               if(d>d1)
                d=d1;
                 if(d<*e)
                 {
                 *q=i;
                 *q2=j;
                 *e=d;
                 }
               }
         }
     }
     return d;
}

int cp(int arr[100][100],int arx[],int start,int len,int *q,int *q2,int *e)
 {

    int temp[100][100];
     int dl,dr,mid=0;
     float d=*e;
     if (len-start+1==1)
        return -1;
     else if(len-start+1==2)
     {

        int u=dist(arr[len][0],arr[len][1],arr[start][0],arr[start][1]);
        if(u<0)u=u*-1;
        if(u<=*e)
        {
            *e=u;
            *q=start;
            *q2=len;
        }
        return u;
     }
     else
     {
      mid=(len-start+1)/2;
      int s=kthSmallest(arx,arr, start, len,mid );
      mid=mid+start-1;
      dl=cp(arr,arx,start,mid,q,q2,e);
      dr=cp(arr,arx,mid+1,len,q,q2,e);
      if(dl==-1)dl=dr;
      if(dr==-1)dr=dl;
      d=(dl>dr)?dr:dl;
      //for across pair
      int x=across(arr,mid,d,len,start,q,q2,e);
      if(x<d)
        d=x;
     }
     return d;
 }



int main ()
 {
     int n=0;
     char a[100];
     int arr[100][100];
     int arx[100];
     int ary[100];
     cout<<"enter file name: ";
     cin>>a;

     ifstream infile;
     infile.open(a);
     if (!infile)
        {
            cerr << "Unable to open file !";
            return 1;
        }

     cout<<"all the points:\n";
     int i=0;
     while(infile>>arr[i][0])
     {      arx[i]=arr[i][0];
         infile>>arr[i][1];
         ary[i]=arr[i][1];
         cout<<"\n>>>"<<arr[i][0]<<","<<arr[i][1];
         i++;
     }
     int len=i,q=-1,e,q2;
    infile.close();
    if(len>1)
    {
        e=arr[1]-arr[0];
        if(e<0)e=e*-1;
        int dis = cp(arr,arx,0,len-1,&q,&q2,&e);
        cout<<"\n closest pair is ("<<arr[q][0]<<","<<arr[q][1]<<"),("<<arr[q2][0]<<","<<arr[q2][1]<<")";
        cout<<"\n distance : "<<dis;
    }
    else
        cout<<"\n no pairs found";

 }

