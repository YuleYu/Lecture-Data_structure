#include<iostream>
using namespace std;

int main(){
	bool a[151] = {0};	//0 presents off, 1 presents open.
	
	for (int i=2; i<=150; i++)
		for (int j=i; j<=150; j+=i)
			a[j] = (a[j] ? 0 : 1);

	for (int i=1; i<=150; i++)
		if (!a[i])
			cout<<i<<' ';
	system("pause");
	return 0;
}
