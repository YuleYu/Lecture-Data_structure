#include <iostream>
#include <vector>

using namespace std;

void cut_repeat(vector<int> &v)
{	
	vector<int> temp;
	temp.push_back(v[0]);
	for (int i=1; i<v.size(); i++){
		bool ju = 1;
		for (int j=0; j<temp.size(); j++){
			if (v[i]==temp[j])
				ju = 0;	
		}
		if (ju)
			temp.push_back(v[i]);
	}
	v = temp;
}

int main()
{
	void cut_repeat(vector<int> &v);
	vector<int> v, v1;
	int a[] = {95, 45, 15, 78, 45, 84, 15, 24, 12, 78};
	for (int i=0; i<10; i++)
		v.push_back(a[i]);
	cout<<"原向量：";
	for (int i=0; i<v.size(); i++)
		cout<<v[i]<<' ';
	cout<<endl;
	cut_repeat(v);
	cout<<"删除后：";
	for (int i=0; i<v.size(); i++)
		cout<<v[i]<<' ';
	cout<<endl;
	return 0;
}
