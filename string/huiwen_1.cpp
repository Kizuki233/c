// 添加最少字符使字符串整体都是回文字符串
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int dp[20][20];

int lesschar(string str){
	int len=str.size();
	for(int j=1;j<len;++j){
		dp[j-1][j]=str[j-1]==str[j]?0:1;
		for(int i=j-2;i>=0;--i){
		    if(str[i]==str[j])
		      dp[i][j]=dp[i+1][j-1];
		    else
		      dp[i][j]=min(dp[i+1][j]+1,dp[i][j-1]+1);
		}
	}
    return dp[0][len-1];
}

string getpath(string str,int num){
  if(num==0)
    return str;
  int len=str.size();
  // char res[len+num+1];
  string res=str+str;//用[]遍历字符串的时候不能越界
  int i=0;
  int j=len-1;
  int l=0;
  int r=len-1+num;
  while(i<=j&&l<=r){
    if(str[i]==str[j]){
       res[l++]=str[i++];
       res[r--]=str[j--];
    }
    else if(dp[i+1][j]>dp[i][j-1]){
       res[l++]=str[j];
       res[r--]=str[j--];
    }
    else{
       res[l++]=str[i];
       res[r--]=str[i++];
    }
  }
  // res[len+num]='\0';
  // string s=res;
  // return s;
  return res;
}

int main(){
    string str;
    int num=0;
    while(cin>>str){
       dp[20][20]={};
       if(str.size()==1)
      	  num=0;
       num=lesschar(str); 
       cout<<num<<' '<<getpath(str,num)<<endl;   
    }
	return 0;
}