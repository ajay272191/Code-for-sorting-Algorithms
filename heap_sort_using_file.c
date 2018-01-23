#include<stdio.h>
#define max 1000
int hp_sort(int n,int a[max]);
int sorting(int a[max], int n, int i);
int heap()
{
    FILE *fptr;
    FILE *fp;
    int n=1,x;
    int a[max];
    fptr=fopen("numbers.txt","r");
    fp=fopen("heap_data.txt","w+");

    if(fptr==NULL)
    {
         printf("cant find largest number::file not open");
         exit(0);
    }
    while(n!=1001)
    {
        fscanf(fptr,"%d",&x);
        a[n-1]=x;
        n++;
    }n--;

    for(n=100;n<max;n+=100)
    {     count=0;
     if(n>=k)
          {
          x=hp_sort(n,a);
          fprintf(fp,"%d %d\n",n,count);
          printf("for ::%d number ::%d th largest is ::%d and no. of comparison in heap sort is ::%d  \n ",n,k,x,count);
          }

    }
    printf("\n heap data is in heap_data.txt file\n\n");
    fclose(fp);
    fclose(fptr);
    return 0;
}
int hp_sort(int n,int a[max])
{
    int i,temp,j;

    for (i=n/2-1;i>=0;i--)
    {
        sorting(a,n,i);
        count++;
    }
    for(j=0;j<k-1;j++)
    {
        temp=a[0];
        a[0]=a[n-1];
        a[n-1]=temp;
        n--;
        count++;
        sorting(a, n,0);
    }
    return a[0];
}
int sorting(int a[max], int n, int i)
{
    int root=i;
    int lchild=2*i+1,rchild=2*i+2;
    int temp;
    if ((lchild<n) && a[lchild]>a[root])
        {root = lchild;
         count+=2;
        }
    if ((rchild<n) && a[rchild]>a[root])
        {root = rchild;
         count+=2;
        }
    if (root!=i)
    {
     temp=a[i];
        a[i]=a[root];
        a[root]=temp;
        count++;
        sorting(a,n,root);
    }
}
