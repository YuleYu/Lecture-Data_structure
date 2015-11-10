//Priority_Queue_in_linklist project_Experiment4. 
//Created by Yule, Nov_10_2015
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


template <typename T>
class PriorityQueue
{
    public:
		PriorityQueue():qfront(NULL), qback(NULL), count(0){};
		void push(const T& item);
		// Pop the largest element in the queue.
		void pop();
		// Show the largest element in the queue.
		T& front();
		const T& front() const;
		int size() const;
		bool empty() const;
		void display();				// display function only use for experiment.
		
    private:
		 node<T> *qfront,*qback;
		 // Calculate the number of elements in the queue.
		int count;
};

// Push the element into the queue in order.
template <typename T>
void PriorityQueue<T>::push(const T& item)
{
	// Create a new node for the input element.
	node<T> *newNode=new node<int>(item, NULL);
	// Judge the origin queue elements' number.
	
	// If there is no element in the queue.
	if(qfront==NULL){
		qfront=newNode;
		qback=newNode;
	}
	// If inserted element is smaller than any other element in the queue.
	else if(item > qfront->nodeValue){
		newNode->next = qfront;
		qfront = newNode;
	}
	// If inserted element is larger than any other element in the queue.
	else if(item < qback->nodeValue){
		qback->next = newNode;		
		qback = newNode;
	}
	//Otherwise, the inserted element is ordinary, its value is between the queue.
	else{
		node<T> *tmp=qfront->next, *sub=qfront;
		// When there is only one element in the queue,
		// it can not include in the following cycle.
		// So pick out to argue it alone.
		if ((tmp->nodeValue) < item){
			sub->next = newNode;
			newNode->next= tmp;
		}
		// Find the position that the inserted element is just larger than the next one.
		while(tmp!=NULL){
			if ((tmp->nodeValue)<item){
				// sub points to tmp, so if find the place, let the sub's next points to
				// newnode ,and newnode's next points to tmp.
				sub->next = newNode;
				newNode->next= tmp;
				break;
			}
			// sub and tmp move one step backward.
			sub = sub->next;
			tmp = tmp->next;
		}
	}
	// Push successfully, the number of the queue plus one.
	count++;
	cout<<"Push in successfully!"<<endl;
}

// Pop out the largest element in the queue.
// Because all the elements in the queue are in order,
// so pop the largest one means pop the first one.
template <typename T>
void PriorityQueue<T>::pop()
{
	// When there is no element in the queue, go into the judgement.
	if (empty()){
		cout<<"error! There is no element in the queue!";
		return;
	}
	// The first node stores the largest element,
	// change the head pointer equals pop the first element.
	node<T> *tmp=qfront;
	qfront=qfront->next;
	delete tmp;
	// Push successfully, the number of the queue minus one.
	count--;
	cout<<"Pop out successfully!"<<endl;
}

// Show the largest element in the queue.
// Because all the elements in the queue are in order,
// the first one is the largest one.
template <typename T>
T& PriorityQueue<T>::front()
{
	return qfront->nodeValue;
}

// Show the largest element in the queue as a const element function.
template <typename T>
const T& PriorityQueue<T>::front() const
{
	return qfront->nodeValue;
}

// Show the number of elements in the queue.
template <typename T>
int PriorityQueue<T>::size() const
{
	return count;
}

// Judge wether the queue is empty.
template <typename T>
bool PriorityQueue<T>::empty() const
{
	return count==0;
}          

// Display all the elements in the queue.
template <typename T>
void PriorityQueue<T>::display()
{
	node<T>  *tmp=qfront;
	while(tmp!=NULL){
		cout<<tmp->nodeValue<<' ';
		tmp = tmp->next;
	}
	cout<<endl;
}         

int main()
{
	PriorityQueue<int> P;
	char option;
	cout<<"Option: 1-push into the queue,       2-show the size of the queue,\n"
	 	<<"        3-show the largest element,  4-pop the largest from the queue,\n"
	  	<<"        #-quit.\n";
	while(cin>>option && option!='#'){
		int temp;
		switch(option)
		{
			// Push in the element.
			// The queue is in order.
			case'1':cout<<"insert:";
					cin>>temp;
					P.push(temp);
					break;
			// Show the size of the queue.
			case'2':cout<<"Size:"<<P.size()<<endl;
					break;	
			// Show the largest element in the queue.
					// Firstly, judge wether the queue is empty.
			case'3':if (P.empty())
						cout<<"error! There is no element in the queue!"<<endl;
					else
						cout<<"The largest is:"<<P.front()<<endl;
					break;
			// Pop out the largest element in the queue.
			case'4':P.pop();
					break;
			default:cout<<"Error input! Please try again."<<endl;
		}
	}	
	return 0;
}





