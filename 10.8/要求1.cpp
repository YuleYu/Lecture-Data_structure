#include<iostream>
#include<vector>
using namespace std;

int main()
{
	void bubble_sort(int a[], int n);
	int a[] = {25, 45, 65, 78, 74, 11, 24, 72};
	int b[sizeof(a)];
	memcpy(b, a, sizeof(a));
	bubble_sort(b, 8);
	cout<<"原数组："; 
	for (int i=0; i<8; i++)
		cout<<a[i]<<' ';
	cout<<endl;
	cout<<"修改后：";
	for (int i=0; i<8; i++)
		cout<<b[i]<<' ';
	cout<<endl;
	cout<<"原数组："; 
	for (int i=0; i<8; i++)
		cout<<a[i]<<' ';
	cout<<endl<<endl;
	
	void bubble_sort_vec(vector<int> &v);
	vector<int> ve, ve2;
	for (int i=0; i<8; i++)
		ve.push_back(a[i]);	
	ve2 = ve;
	bubble_sort_vec(ve2);
	cout<<"原向量："; 
	for (int i=0; i<8; i++)
		cout<<ve[i]<<' ';
	cout<<endl;
	cout<<"修改后："; 
	for (int i=0; i<8; i++)
		cout<<ve2[i]<<' ';
	cout<<endl;
	cout<<"原向量："; 
	for (int i=0; i<8; i++)
		cout<<ve[i]<<' ';
	return 0;
}

void bubble_sort(int a[], int n)
{
	int temp;
	for (int i=1; i<n; i++)
		for (int j=1; j<n-i+1; j++)
			if (a[j-1] > a[j]){
				temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;	
			}	
}

void bubble_sort_vec(vector<int> &v)
{
	int temp;
	for (int i = 1; i<v.size(); i++) 
		for(int j=1; j<v.size()-i+1; j++)
			if (v[j-1] > v[j]){
				temp = v[j];
				v[j] = v[j-1];
				v[j-1] = temp;
			} 
}

