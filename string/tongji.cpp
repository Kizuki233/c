#include<iostream>
#include<string.h>
using namespace std;

string change(string s){
  int len=s.size();
  char ans[2*len];
  int temp[52]={};
  int j=0;
  for(int i=0;i<len;++i){
  	temp[s[i]-'A']++;
  }
  for(int i=26;i<52;++i)
  	if(temp[i]!=0){
       cout<<temp[i]<<char(i+'A');
       ans[j++]=char(temp[i]+'0');
       ans[j++]=char(i+'A');
  	}
  for(int i=0;i<26;++i)
    if(temp[i]!=0){
      cout<<temp[i]<<char(i+'A');
      ans[j++]=char(temp[i]+'0');
      ans[j++]=char(i+'A');
	}
  ans[j]='\0';
  cout<<endl;
  return (string)ans;
}

int main(){
  string str;
  string ans;
  while(cin>>str){
  	ans=change(str);
  	cout<<ans<<endl;
  };
}
