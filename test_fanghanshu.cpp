// 在C++里，我们通过在一个类中重载括号运算符的方法使用一个函数对象而不是一个普通函数。
// #include <iostream>  
// #include <algorithm>  
// #include <functional> //greater<int>
// using namespace std;  
// template<typename T>  
// class display  
// {  
// public:  
//     void operator()(const T &x)  
//     {  
//         cout<<x<<" ";   
//     }   
// };   
  
  
// int main()  
// {  
//     int ia[]={1,2,3,4,5};  
//     for_each(ia,ia+5,display<int>());   
      
//     return 0;   
// }   

// 加：plus<T>
// 减：minus<T>
// 乘：multiplies<T>
// 除：divides<T>
// 模取：modulus<T>
// 否定：negate<T>
// #include <iostream>  
// #include <numeric>  
// #include <vector>   
// #include <functional>   
// using namespace std;  
  
// int main()  
// {  
//     int ia[]={1,2,3,4,5};  
//     vector<int> iv(ia,ia+5);  
//     cout<<accumulate(iv.begin(),iv.end(),1,multiplies<int>())<<endl;   
      
//     cout<<multiplies<int>()(3,5)<<endl;  
      
//     modulus<int>  modulusObj;  
//     cout<<modulusObj(3,5)<<endl; // 3   
//     return 0;   
// }   

// 逻辑与：logical_and<T>
// 逻辑或：logical_or<T>
// 逻辑否：logical_no<T>
// 等于：equal_to<T>
// 不等于：not_equal_to<T>
// 大于：greater<T>
// 大于等于：greater_equal<T>
// 小于：less<T>
// 小于等于：less_equal<T>
// #include <iostream>  
// #include <algorithm>  
// #include <vector>   
  
// using namespace std;  
  
// template <class T>   
// class display  
// {  
// public:  
//     void operator()(const T &x)  
//     {  
//         cout<<x<<" ";   
//     }   
// };  
  
// int main()  
// {  
//     int ia[]={1,51,4,3,51};  
//     vector<int> iv(ia,ia+5);  
//     sort(iv.begin(),iv.end(),greater<int>());  
//     for_each(iv.begin(),iv.end(),display<int>());   
//     return 0;   
// } 

// 首先STL是一个有自己规则的框架，函数指针无法和STL其他组件搭配（配接器），产生更灵活的变化：
// 仿函数应当有能力被函数配接器修饰，然后彼此合作形成一个整体。
// 为了可配接仿函数需要定义自己的相应型别（和迭代器的型别的作用是一个含义）。
// 由于STL只使用一元和二元仿函数，所以定义了两个class：unaru_function和binary_function。
// 这两个类没有成员，只有一些型别定义。
// 任何仿函数，只要依个人需求选择继承其中一个class，便自动拥有了那些相应型别，也就自动拥有了配接能力。

// 1、 仿函数是智能型函数
// 就好比智能指针的行为像指针，其就可看作是一个指针。
// 但是智能指针是定义的一个类对象，所以在具备指针功能的同时也有其他的能力。
// 仿函数的能力也可以超越operator（）。
// 因为仿函数可以拥有成员函数和成员变量，这意味着仿函数拥有状态。
// 另一个好处是可以在执行期初始化它们。
// 2、 仿函数都有自己的型别
// 这就是泛型编程编写仿函数。
// 3、 仿函数通常比一般函数快
// 就template的概念而言，由于更多细节在编译器就已确定，所以通常可能进行更好的最佳化。

#include <iostream>  
#include <algorithm>  
// #include <functional> //greater<int>
using namespace std;  

bool cmp(const int &a,const int &b){
  return a<b;
}
bool strcmp(const string &s1,const string &s2){
  return s1+s2<s2+s1;
}
  
int main()  
{  
    int arr[10]={2,9,6,4,0,1,3,5,7,8};  
    sort(arr,arr+10,cmp);//arr+10
    // sort(arr,arr+10,less<int>());
    for(int n:arr) 
       cout<<n<<' ';
    cout<<endl;
    std::vector<string> v;
	v.push_back("zc");
	v.push_back("de");
	v.push_back("abc");
	sort(v.begin(),v.end(),strcmp);//v.end()指的是最后一个元素的下一个
	cout<<v[0]+v[1]+v[2]<<endl;
	cout<<*(v.end()-1)<<endl;
    return 0;   
}   