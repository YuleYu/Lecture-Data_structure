//miniNode project_Task4. 
//Created by Yule, Oct_13_2015
//==============================================================================
#include<iostream>
using namespace std;

template <typename T>
class node
{
	public:
		T nodeValue;      // data held by the node
      	node<T> *next;    // next node in the list
      	node() : next(NULL) {}
      	node(const T& item, node<T> *nextNode = NULL) :  nodeValue(item), next(nextNode)  {}
};


int main()
{
// data input section. 
	int num, temp, max;
	node<int> *first = NULL, *p[2], *ser;
	cout<<"Please enter the sum number of the data: "; 
	cin>>num;
	cout<<"Please enter the data: ";
	
	// using the subscript complementation way to avoid 
	// transmitting points addresses and accelerate the
	// speed. 
	cin>>temp;
	first = new node<int>(temp, NULL);
 	p[0] = first; 
	for (int i = 1; i<num; i++){
		cin>>temp;
		p[i%2] = new node<int>(temp, NULL);
		p[(i-1)%2]->next = p[i%2];
	}
	// output the original inputted data. 
	cout<<"The data inputted: "; 
	ser = first;
	while(ser!=NULL){
 		cout<<ser->nodeValue<<' ';    
     	ser=ser->next;
	}
	cout<<endl;
	
// judge section
	// fit the variable 'max' with the value got, and compare with the next value.
	// by setting the boolean variable to determine whether to meet the requirements.
	bool ju = 1;
	ser = first;
	max = first->nodeValue;
	while(ser!=NULL){
		if(ser->nodeValue < max){
			ju = 0;
		}
		else
			max = ser->nodeValue;
		ser=ser->next;
	}  
	cout<<"This is"<<(ju? "" : " not")<<" sorted by ascending order."<<endl; 
	
	return 0;
}

