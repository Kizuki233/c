#include <bits/stdc++.h>
using namespace std;

//快排
void quicksort(int *a,int left,int right){
	if(left>=right)
		return;
	int i=left,j=right,key=a[i];
	while(i<j){
	  while(i<j&&key<=a[j]) --j;
	  if(i<j) a[i++]=a[j];
	  while(i<j&&key>=a[i]) ++i;
	  if(i<j) a[j--]=a[i];
	}
	a[i]=key;
	quicksort(a,left,i-1);
	quicksort(a,i+1,right);
}

//归并
void mergr(int *a,int *temp,int left,int mid,int right){
	int i=left,j=mid+1,k=left;
	while(i<=mid&&j<=right)
	  a[i]<a[j]?temp[k++]=a[i++]:temp[k++]=a[j++];
	while(i<=mid)    temp[k++]=a[i++];
	while(j<=right)  temp[k++]=a[j++];
	for(int c=left;c<=right;++c)
	  a[c]=temp[c];
}
void mergesort(int *a,int *temp,int left,int right){
	if(left<right){
	  int mid=(left+right)/2;
	  mergesort(a,temp,left,mid);
	  mergesort(a,temp,mid+1,right);
	  mergr(a,temp,left,mid,right);
	}
}

//堆排序
void adjustheap(int *a,int i,int size){
	for(int child;2*i+1<=size-1;i=child){
		child=2*i+1;
		if(child+1<=size-1&&a[child]<a[child+1])   ++child;
		if(a[child]>a[i])
		  swap(a[i],a[child]);
		else break;
	}		
}
void heapsort(int *a,int size){
    for(int i=size/2-1;i>=0;--i)
    	 adjustheap(a,i,size);
    for(int i=size-1;i>0;--i){
    	 swap(a[0],a[i]);
    	 adjustheap(a,0,i);
    }
}

//冒泡
void bubblesort(int *a,int len){
    for(int i=0;i<len-1;++i){ //趟数
	   for(int j=0;j<len-1-i;++j)
	   	 if(a[j]>a[j+1]) swap(a[j],a[j+1]);
	}
}

//选择
void selectsort(int *a,int len){
	for(int i=0,min;i<len-1;++i){
		min=i;
		for(int j=i+1;j<len;++j){
		  if(a[j]<a[min])  min=j;
		}
		if(min!=i) swap(a[i],a[min]);
	}		
}

//插入
void insertsort(int *a,int len){
  for(int i=1;i<len;++i){
  	for(int j=i;j-1>=0&&a[j-1]>a[j];--j)
  	  swap(a[j],a[j-1]);
  }
}

//希尔
void shellsort(int *a,int len){
	for(int dk=len/2;dk>=1;dk/=2)
	  for(int i=dk;i<len;++i)
	  	for(int j=i;j-dk>=0&&a[j-dk]>a[j];j-=dk)
	  	  swap(a[j],a[j-dk]);
}

//计数
void countsort(int *a,int *b,int k,int len){
	int c[k],i=0;
	memset(c,0,sizeof(int)*k);
	for(i=0;i<len;++i)
		c[a[i]]++;
	for(i=1;i<=20;++i)
		c[i]+=c[i-1];
	for(i=len-1;i>=0;--i){
	// for(i=0;i<len;++i){
       b[c[a[i]]-1]=a[i];
       c[a[i]]--;
    }
    for(i=0;i<len;++i)
      a[i]=b[i];
}

//基数
int Maxbit(int *a,int len){
	int max=1,temp=10;
	for(int i=0;i<len;++i){
		while(a[i]>temp){
			temp*=10;
			++max;
		}
	}
	return max;
}
void radixsort(int *a,int len){
	int maxbit=Maxbit(a,len);
	int radix=1;
	int temp[len];
	int count[10];
	for(int i=1,j,k;i<=maxbit;++i){
       for(j=0;j<10;++j)
       	  count[j]=0;
       for(j=0;j<len;++j){
       	  k=(a[j]/radix)%10;
       	  ++count[k];
       }
       for(j=1;j<10;++j)
       	  count[j]+=count[j-1];
       for(j=len-1;j>=0;--j){
       	   k=(a[j]/radix)%10;
       	   temp[count[k]-1]=a[j];
       	   --count[k];
       }
       for(j=0;j<len;++j)
       	  a[j]=temp[j];
       radix*=10;
	}
}

inline void Print(int *a,int len){
	for(int j=0;j<len;++j)
	 cout<<a[j]<<' ';
	 cout<<endl;
}

int main(){
   int a[50];
   int b[50]={0};
   const int k=50;
   int count,i;
   while(true){
     count=0;
     for(i=0;;++i){
        cin>>a[i];
        count++;  
     	if(getchar()=='\n')  break;  	 
     }
    quicksort(a,0,count-1);
    mergesort(a,b,0,count-1);
    heapsort(a,count);
    bubblesort(a,count);
    selectsort(a,count);
    insertsort(a,count);
    shellsort(a,count);
    countsort(a,b,k,count);
    radixsort(a,count);
    Print(a,count);
 }
   return 0;
}
//√为稳定
//插入排序 直接插入√ 希尔排序(平均O(nlogn))
//选择排序 直接选择 堆排序
//交换排序 冒泡排序√ 快速排序
//归并排序√ O(n) 基数排序√ 

// 线程没有单独的地址空间
// 线程和进程的区别联系：
// 1，进程：子进程是父进程的复制品。子进程获得父进程数据空间、堆和栈的复制品。
// 2，线程：相对与进程而言，线程是一个更加接近与执行体的概念，它可以与同进程的其他线程共享数据，但拥有自己的栈空间，拥有独立的执行序列。   
// 两者都可以提高程序的并发度，提高程序运行效率和响应时间。   
// 线程和进程在使用上各有优缺点：线程执行开销小，但不利于资源管理和保护；而进程正相反。同时，线程适合于在SMP机器上运行，而进程则可以跨机器迁移。
// 根本区别就一点：用多进程每个进程有自己的地址空间(address space)，线程则共享地址空间。所有其它区别都是由此而来的： 
// 1、速度：线程产生的速度快，线程间的通讯快、切换快等，因为他们在同一个地址空间内。 
// 2、资源利用率：线程的资源利用率比较好也是因为他们在同一个地址空间内。 
// 3、同步问题：线程使用公共变量/内存时需要使用同步机制还是因为他们在同一个地址空间内