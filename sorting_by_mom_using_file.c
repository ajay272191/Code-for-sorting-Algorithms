#include<stdio.h>
int kth(int a[1000], int first, int last, int k);
int sort_middle(int a[], int first,int last);
void swap(int *x,int *y);
int position(int a[], int first, int last, int x);
int mom;
int k,count;
int kth_mom()
{
     int n,i=1,a[1000],x;
     FILE *fptr,*fp;
     fptr=fopen("numbers.txt","r");
     fp=fopen("mom_data.txt","w");

     if(fptr==NULL)
        {
         printf("cant find largest number::file not open");
         exit(0);
       }

    while(i!=1001)
     {fscanf(fptr,"%d",&a[i-1]);
     i++;}
     n=i-1;
     printf("Enter the value of K:");
     scanf("%d",&k);

     for(i=100;i<=n;i+=100)
       {
          if(i>=k)
           {
           x=kth(a, 0, i-1, k);
           printf("for ::%d number ::%d th largest  is:: %d and no. of comparison is::%d\n",i,k,x,count);

           fprintf(fp,"%d %d\n",i,count);
           count=0;
           }
       }

     printf("\n heap_data is in in heap_data.txt file\n\n");
     fclose(fp);
     fclose(fptr);
     return 0;

 }

int kth(int a[], int first, int r, int k)
{
        int i,pos,n = r-first+1;
        int median[n/3];

     if(k<=0)
     {
          printf("position can't be negative number\n");
          exit(0);
     }

    if (n>=k)
    {
        for (i=0; i<n/5; i++)
            {count++;
             median[i] = sort_middle(a,first+i*5, 5);

            }
        if (i*5 < n)
        {    count++;
            median[i] = sort_middle(a,first+i*5, n%5);

            i++;
        }

        if(i==1)
        {
           mom=median[i-1];
        }

        else
        {
             count++;
            mom= kth(median, 0, i-1, i/2);
        }
         count++;
         pos = position(a, first, r, mom);

        if (pos-first == k-1)
            {
               return a[pos];
            }

        if (pos-first> k-1)
          {    count++;
               return kth(a,first, pos-1, k);
          }

        else
          {
              count++;
             return kth(a, pos+1, r, k-pos+first-1);
          }

    }

return 0;
}
int sort_middle(int a[], int first,int last)
{
  int i,j ;
  for(i=first;i<first+last-1;i++)
  {
    for(j=i+1;j<first+last;j++)
    {
        count++;
        if(a[i]<a[j])
        {
            swap(&a[i],&a[j]);
        }
    }
  }

    return a[first+(last/2)];
}
int position(int a[],int first,int last,int x)
{
     int i,j,pos=first;

     for (i=first;i<last;i++)
          {
          count++;
          if (a[i] == x)
          break;
          }

     swap(&a[i],&a[last]);

     for (i=first;i<=last-1;i++)
          {
              count++;
             if (a[i] >= x)
              {
              swap(&a[pos],&a[i]);
              pos++;
              }
          }
    swap(&a[pos],&a[last]);

return pos;
}
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}





