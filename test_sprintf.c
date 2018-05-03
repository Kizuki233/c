#include <stdio.h>
int main ()
{
char sentence []="Rudolph is 12 years old";
char str [20];
int i;
sscanf (sentence,"%s %*s %d",str,&i);
printf ("%s -> %d\n",str,i);
return 0;
}

// #include <stdio.h>
// int main ()
// {
// char buffer [50];
// int n, a=5, b=3;
// n=sprintf (buffer, "%d plus %d is %d", a, b, a+b);
// printf ("[%s] is a %d char long string\n",buffer,n);
// return 0;
// }