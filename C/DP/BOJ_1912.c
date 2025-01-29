#include <stdio.h>
int d[100005];
int a[100005];

int max(int a, int b)
{
	if(a>=b) return a;
	else return b;
}

int getElement(int num)
{
	int result;
	for(int i = 0; i <= num; i++){
		if(result < d[i]) result = d[i];
	}
	return result;
}

int main()
{
	int num;
	scanf("%d",&num)
	for(int i = 1; i <= num; i++) scanf("%d", a[i]);
	for(int i = 1; i <= num; i++){
		d[i] = max(0,d[i-1])+a[i];
	}
	int result = getElement(num);
	printf("%d",&result);
	return 0;
}
