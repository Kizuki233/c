#include<iostream>  
#include<string>  
#include<list>  
#include <algorithm>
using namespace std;  
typedef list<int> LISTINT;  

void print(int &e){
	cout<<e<<endl;
}  
int main()  
{  
    LISTINT test;  
    test.push_back(1);  
    test.push_back(5);  
    test.push_back(3);  
    test.push_back(10);  
  
    LISTINT test2;  
    test2.push_back(2);  
    test2.push_back(8);  
    test2.push_back(6);  
    test2.push_back(9);  
  
    test.sort();  
    test2.sort();  
  
    //test.splice(test.begin(),test2);   
    test.merge(test2);
    for_each(test.begin(),test.end(),print);
    // for(LISTINT::iterator it = test.begin();it!=test.end();it++)  
    // {  
    //     cout<<*it<<"\t";  
    // }  
    // cout<<endl;  
    // cout<<test.size()<<"\t"<<test2.size()<<endl;  
    return 0;  
}  

// // merge algorithm example
// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;

// int main () {
//   int first[] = {5,10,15,20,25};
//   int second[] = {50,40,30,20,10};
//   vector<int> v(10);
//   vector<int>::iterator it;

//   sort (first,first+5);
//   sort (second,second+5);
//   merge (first,first+5,second,second+5,v.begin());

//   cout << "The resulting vector contains:";
//   for (it=v.begin(); it!=v.end(); ++it)
//     cout << " " << *it;

//   cout << endl;
  
//   return 0;
// }