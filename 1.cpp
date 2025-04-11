#include<bits/stdc++.h>
using namespace std;
int a[]={10,2,3,4,5,6};
int main(){
	int n=sizeof(a)/sizeof(a[0]);
	int *min=min_element(a,a+n);
	printf("%d",*min);
}

