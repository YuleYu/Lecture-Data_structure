#include<iostream>
#include"C_d_vector.h"
using namespace std;

int main(){
	miniVector<int> ve1;
	ve1.push_back(4);
	ve1.push_back(2);
	ve1.push_back(1);
	cout<<"�������ǣ�"<<ve1<<endl; 
	ve1.cut(0,4);
	cout<<"�������ǣ�"<<ve1<<endl; 
	ve1.insert(1,7);
	cout<<"�������ǣ�"<<ve1<<endl; 
	miniVector<int> ve2;
	cout<<"���룺"; 
	cin>>ve2;
	cout<<"�������ǣ�"<<ve2<<endl; 
	return 0;
}
