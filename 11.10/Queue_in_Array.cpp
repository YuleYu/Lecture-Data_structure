//Queue_in_array project_Experiment4. 
//Created by Yule, Nov_6_2015
//============================================================================== 
#include<iostream>
#include"d_except.h" 
using namespace std;

#define MAXQSIZE 100		// Define the space size of the queue.

template <typename T>
class bqueue
{
	public:
		bqueue():qfront(0), qback(0), count(0){};
		void push(const T& item);
		void pop();
		T& front();
		const T& front() const;
		int size() const;
		bool empty() const;
		bool full() const;
    private:
		T queueArray[MAXQSIZE];
		int qfront, qback;		//qfront指向第一个有效元素
		int count;		//qback指向尾部最后一个元素的
};					//下一空位

template <typename T>
void bqueue<T>::push(const T& item)
{	
	if (count != MAXQSIZE)
		queueArray[qback] = item;
	else
		throw underflowError("bqueue push(): full queue");
	qback = (qback+1) % MAXQSIZE;
	count++;
}

template <typename T>
void bqueue<T>::pop()
{	
	if (count == 0)
		throw underflowError("bqueue pop(): empty queue");
	qfront = (qfront+1) % MAXQSIZE;
	count--;
}

template <typename T>
T& bqueue<T>::front()
{
	if (count == 0)
		throw underflowError("bqueue front(): empty queue");
	return queueArray[qfront];
}
          
template <typename T>
const T& bqueue<T>::front() const
{
	if (count == 0)
		throw underflowError("bqueue front(): empty queue");
	return queueArray[qfront];
}
          
template <typename T>
int bqueue<T>::size() const
{
	return count;
}

template <typename T>
bool bqueue<T>::empty() const
{
	return count == 0;
}

template <typename T>
bool bqueue<T>::full() const
{
	return count == MAXQSIZE;
}

template <typename T>
int choose(bqueue<T> Q)
{
	
}
	

int main ()
{
	bqueue<int> Q;
	char option;
	cout<<"Option: 1-push into the queue, 2-pop from the back,\n"
	 	<<"        3-pop from the front, 4-pop from the back,\n"
	  	<<"        5-display the doublestack, #-quit.\n";
	while(cin>>option && option!='#'){
		int temp;
		switch(option)
		{
			case'1':if (!Q.full()){
						cin>>temp;
						Q.push(temp);
					}
					else
						cout<<"the queue is full!"<<endl;	
					break;
			case'2':Q.pop();
					cout<<"pop successfully!"<<endl;
					break;
			case'3':cout<<Q.front()<<endl;
					break;
			case'4':cout<<"Size:"<<Q.size()<<endl;
					break;
			case'5':Q.empty();
					cout<<"clear successfully!"<<endl;
					break;
			case'#':return 0;
			default:cout<<"Error input! Please try again."<<endl;
		}
	}	
	return 0;	
} 

