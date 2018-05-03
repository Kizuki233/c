#include <bits/stdc++.h>
using namespace std;

int main(){
    // map<int, string> mapstring;
    // mapstring.insert(map<int, string>::value_type(1,"one"));
    // mapstring.insert(pair<int,string>(2,"two"));
    // mapstring.insert(pair<int,string>(3,"three"));
    // mapstring.insert(pair<int,string>(4,"four"));
  
    //mapstring[1]="one plus";
    // mapstring[5]="five plus";
    // mapstring[0]="hello map";
    // mapstring[-1]="-1hello map";
    // mapstring.erase(2);
    // map<int,string>::iterator f=mapstring.find(2);
    // if(f!=mapstring.end()){
    // 	mapstring.erase(f);
    // }
    set<char, int> mapstring;
    mapstring.insert(map<int, string>::value_type(1,"one"));
    // mapstring['b']=11;
    // mapstring['z']=17;
    // mapstring['a']=1651;

    set<char,int>::iterator it=mapstring.begin();
    while(it!=mapstring.end()){
    	cout<<(*it).first<<' '<<(*it).second<<endl;
    	++it;
    }

   map<int,string> m;
   m[2]="hello";
   m[5]="hellooo";
   m[3]="helloss";
   m[1]="hellsso";
   for(auto it=m.begin();it!=m.end();++it)
    cout<<(*it).first<<' '<<(*it).second<<endl;
   cout<<endl;
   for(auto it:m)
    cout<<it.first<<' '<<it.second+"two"<<endl;

   return 0;
}