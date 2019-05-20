#include <iostream>
#include <vector>

using namespace std;

void cut_repeat(vector<int> &v)
{
	for (int i=0; i<v.size(); i++)
		for (int j=i+1; j<v.size(); j++)
			if (v[i]==v[j])
				v.erase(v.begin()+j);
}

int main()
{
	vector<int> v, v1;
	int ar[] = {95, 45, 15, 78, 45, 84, 15, 24, 12, 78};
	for (int i=0; i<10; i++)
		v.push_back(ar[i]);
	cout<<"原向量：";
	for (int i=0; i<v.size(); i++)
		cout<<v[i]<<' ';
	cout<<endl;
	 
	cut_repeat(v);
	cout<<"修改后：";
	for (int i=0; i<v.size(); i++)
		cout<<v[i]<<' ';
	return 0;
}
