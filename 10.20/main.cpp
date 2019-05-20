//miniNode project_Task4. 
//Created by Yule, Oct_20_2015
//==============================================================================
#include<iostream>
#include<stdlib.h>
#include<time.h> // use for creating random number.
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
	// Declarations of required function.
	void print(node<int> *);
	node<int>* create();			// can be changed into manual input when needed.
	node<int>* random_create();		// create the data by random.
	node<int>* sort(node<int>*);
	node<int>* merge(node<int>*, node<int>*);
	
// data input section. 	
	node<int> *first[2];
	first[0] = first[1] = NULL;
	// use time to give the data a random 'seed'.
	srand(time(NULL));
	for (int i=0; i<2; i++)
		first[i] = random_create();

	// output the original inputted data. 
	for (int i=0; i<2; i++){
		cout<<"The data"<<i+1<<" inputted: "; 
		print(first[i]);
	}
	
	// sort the input data.
	for (int i=0; i<2; i++){
		first[i] = sort(first[i]);
		cout<<"The data"<<i+1<<" sorted: ";
		print(first[i]);
	}
	// merge first[0] and first[1] to data_merged.
	node<int> *data_merged;
	data_merged = merge(first[0], first[1]);
	cout<<"The data merged: ";
	print(data_merged);
	return 0;
}

// Create data by random number.
node<int>* random_create()
{
	int num, temp;
	node<int> *first = NULL, *p[2];
	temp = rand();
	first = new node<int>(temp, NULL);
	p[0] = first; 
	for (int i = 1; i<7; i++){
		temp = rand();
		// using the subscript complementation way to avoid 
		// transmitting points addresses and accelerate the
		// speed. 
		p[i%2] = new node<int>(temp, NULL);
		p[(i-1)%2]->next = p[i%2];
	}
	return first;
}

// Create data by manual inputting.
node<int>* create()
{
int num, temp;
	node<int> *first = NULL, *p[2];
	cout<<"Please enter the sum number of the data: "; 
	cin>>num;
	if (num!=0){
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
	}
	return first;
}

// Output the list with given head pointer.
void print(node<int> *first) 
{	
	node<int> *ser;
	ser = first;
	while(ser!=NULL){
 		cout<<ser->nodeValue<<' ';    
     	ser=ser->next;
	}
	cout<<endl;
}

//Sort one list's data from small to big.
node<int>* sort(node<int> *first)  
{  	
	int length(node<int> *);
    node<int> *ser;  
    int n, temp;  
	// Firstly calculate the elements' sum of the list.
    n = length(first); 
	// Analyse the following situation from others. 
    if(first == NULL || first->next == NULL){  
        return first;  
    }  
    ser = first;  
    for(int j=1; j<n; j++){  
        ser = first;  
        for(int i=0; i<n-j; i++){  
		// Use bubble sort way to change the data's situation.
            if((ser->nodeValue) > (ser->next->nodeValue)){  
                temp = ser->nodeValue;  
                ser->nodeValue = ser->next->nodeValue;  
                ser->next->nodeValue = temp;  
            }  
            ser = ser->next;  
        }  
    }  
    return first;  
}  

// Use to measure the length of the list.
int length(node<int> *head)  
{  
    int sum = 0;  
    node<int> *ser;  
    ser = head;  
    while(ser != NULL)  
    {  
        ser = ser->next;  
        sum++;  
    }  
    return sum;  
}  

// Merge two ordered list to one.
node<int>* merge(node<int> *first1, node<int> *first2)  
{
	// Analyse the following situation from others. 
	// Though it will not happen when random inputting.
	 if (first1 == NULL){  
        return first2;  
    }  
    else if(first2 == NULL){  
        return first1;  
    }  

	node<int> *first = NULL, *ser1 = first1, *ser2 = first2, *ser;
	// the first pointer analyse alone.
	if (ser1->nodeValue < ser2->nodeValue){
		first = ser1;
		ser1 = ser1->next;	
	}
	else{
		first = ser2;
		ser2 = ser2->next;
	}
	// 'first' will be the new list's first pointer.
	// so use ser to participate following argument.
	ser = first;

	// While ser1 and ser2 do not reach the end, just compare two list's 
	// current place's value and assign the smaller one to the new list.
	// Then assigned pointer and new list's pointer move to next. 
	while(ser1 && ser2){
		if (ser1->nodeValue < ser2->nodeValue){
			ser->next = ser1;
			ser1 = ser1->next;
		}
		else{
			ser->next = ser2;
			ser2 = ser2->next;
		}
		ser = ser->next;
	} 	

	// because of the problem of '&&'(when the former is wrong, it will 
	// stop judgement and ignore the latter one),
	// there may still exist same data that don't insert into new list.
	if (ser2)
	while(ser2->next!=NULL){
		ser->next = ser2;
		ser2 = ser2->next;
		ser = ser->next;
	}
	if (ser1)
	while(ser1->next!=NULL){
		ser->next = ser1;
		ser1 = ser1->next;
		ser = ser->next;
	}

	// The final value in old list may lost. So use another judgement to fit
	// the last one.
	if (ser1){  
        ser->next =ser1; 
    }
    if (ser2){  
        ser->next =ser2; 
    } 
	return first;
}
