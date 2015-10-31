//miniNode project_Task7. 
//Created by Yule, Oct_14_2015
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
// data input section
	int num, temp, max, place;
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
 	
// insert section
 	// input the number of requests after the node N.
	cout<<"Please enter the node to insert: "; 
	cin>>place;
	
	// judging whether the input node exists.
	if (place > num)
		cout<<"The location of the input is incorrect!"<<endl;
		
	// ensure the presence of the input node, enter the data .
	else{
		node<int> *insert;
		cout<<"Please enter the data: ";
		cin>>temp;
		
	// if want to enter the node in the first or the last place, 
	// take out the analysis alone. 
		// Node in the first place. It means that insert the data in a 
		// new created space, which links to the original first node's next space 
		// and let the first point points to this new space.
		if (place == 1){	
			insert = new node<int>(temp, first->next);
			first->next = insert;
		}
		
		// Node in the final place. It means that insert the data in a 
		// new created space, which links to NULL space 
		// and let the last NULL point points to this new space.
		else if (place == num){
			ser = first;
			while(ser->next!=NULL)
				ser=ser->next;
			insert = new node<int>(temp, NULL);
			ser->next = insert;	
		}
		
		// when the node is	among the list, it's needed to create two points: 
		// Precursor pointer 'pre' and Subsequent pointer 'sub'.
		// Use pre to find the node, and let the next node become sub.
		// Create a new space to insert the data. Let pre points to this space and 
		// this space points to sub.
		else{
			node<int> *pre, *sub;
			pre = first;
			for (int i=0; i<place-1; i++){
				pre = pre->next;
			}
			sub = pre->next;
			insert = new node<int>(temp, sub);
			pre->next = insert; 
		} 
		
		//Output modified data
		cout<<"Output modified data: ";
		ser = first;
		while(ser!=NULL){
 			cout<<ser->nodeValue<<' ';    
     		ser=ser->next;
		}
		cout<<endl;
	} 
		

	return 0;
}


