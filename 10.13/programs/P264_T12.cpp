//miniNode project_Task12. 
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
// data input section.
	int num, temp, place;
	node<int> *first = NULL, *newNode, *p[2];
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
	node<int> *ser;
	ser = first;
	while(ser != NULL){
 		cout<<ser->nodeValue<<' ';    
     	ser=ser->next;
	}
	cout<<endl;
	
	// Reverse the original nodes, 
	// here only change of the pointers' directions to achieve the goal.
	node<int> *pre, *sub;
	// let pre equals to first
	pre = first;
	// if there doesn't exist any node, pick out to discuss.
	if (pre == NULL)
		cout<<"Output modified data after backward: "<<endl;
	else{
		// save the second node to ser.
		ser = pre->next;
		
		// The original first become the last after reverse,
		// so let it's next point to NULL.
		pre->next = NULL;
		// now pre is the new list's first. And in this new list, 
		// there is only one node, pre.
		
		// go over the original list, start from the second one.
		while(ser){
			// save the current node's next to sub.
			sub = ser->next;
			// change the pre to current node ser's subsequent.  
			ser->next = pre;
			// now pre is the new list's first.
			pre = ser;
			// assign the original list to ser.
			ser = sub;
		}
		// after circulation, pre is the new first.
		// assign to first. 
		first = pre;
		}
	
		//Output modified data
		cout<<"Output modified data after backward: " ;
		ser = first;
		while(ser != NULL){
 			cout<<ser->nodeValue<<' ';    
     		ser=ser->next;
	}
	cout<<endl;

	return 0;
}


