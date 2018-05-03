#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

void inttostring(int num, char *str){
	int i = 0, j = 0;
	char temp[10];
	if (num<0){
		str[j++] = '-';
		num *= -1;
	}
	while (num){
		temp[i++] = num % 10 + '0';
		num /= 10;
	}
	--i;
	while (i >= 0)
		str[j++] = temp[i--];
	str[j] = '\0';
}

int stringtoint(char *str){
	if (str != nullptr&&str[0] != '\0'){
		int num = 0;
		int sign = 1;
		if (*str == '-'){
			sign = -1;
			++str;
		}
		else if (*str == '+')
			++str;
		if (*str == '\0')
			return -1;
		while (*str != '\0'){
			num = num * 10 + (*str - '0');
			str++;
		}
		return num*sign;
	}
	return -1;
}

bool cmp(string s1,string s2){
	return s1+s2<s2+s1;
}

string test(string s){
	return s;
}

int main(){
	int num = -151054;
	char str[10];
	char strtest[10] = "+";
	int numtest = stringtoint(strtest);
	inttostring(num, str);
	cout << num << ' ' << str << endl;
	cout << strtest << ' ' << numtest << endl;
	int num2 = 110;
	printf("%x %d %o\n", num2, num2, num2);
	cout<<hex<<num2<<' '<<dec<<num2<<' '<<oct<<num2<<endl ;
	std::vector<string> v;
	v.push_back("zc");
	v.push_back("de");
	v.push_back("abc");
	sort(v.begin(),v.end(),cmp);
	cout<<v[0]+v[1]+v[2]<<endl;
	string s1="hello world";
	string s2;
	s2=test(s1);
	cout<<s2<<endl;
	return 0;
}