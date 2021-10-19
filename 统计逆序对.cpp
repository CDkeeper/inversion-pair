#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long n;//定义n，采用long long型大数据 
const long long maxn=1000005;//比数值范围稍大一些，防止越界 
long long a[maxn],r[maxn];//定义原数组和辅助数组 
long long ans=0;
void msort(int s,int t) { //进行分治法求解 
	if(s==t) return ;
	int mid=(s+t)>>1;//分成两部分 
	msort(s,mid),msort(mid+1,t); //分别处理 
	int i=s,j=mid+1,k=s;
	while(i<=mid && j<=t) {
		if(a[i]<=a[j]) r[k]=a[i],k++,i++; //如果前面比后面小就继续，并复制给辅助数组 
		else r[k]=a[j],k++,j++,ans+=mid-i+1; //否则存储后统计逆序对数。
	}
	
	while(i<=mid) r[k]=a[i],k++,i++;   //将剩余部分存入辅助数组并赋给原数组使之有序 
	while(j<=t) r[k]=a[j],k++,j++;
	for(int i=s;i<=t;i++) a[i]=r[i];
	return ;
}
int main(){
		scanf("%lld",&n);
	for(int i=0;i<n;++i){
		scanf("%lld",&a[i]);		
	}
		
		msort(0,n-1);
	printf("%lld",ans);
	
	
} 