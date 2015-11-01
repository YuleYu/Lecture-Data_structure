//Double_direction_Stack_in_array project_Experiment3. 
//Created by Yule, Nov_1_2015
//============================================================================== 
#include<iostream> 
using namespace std; 

const int SIZE=100; 

// Increate the structure of stack in array ways.
class DoubleStack 
{  
public:  
	DoubleStack()  {frontTop=-1;	backTop=SIZE;}   
	bool full()		const;   
	void frontPush	(int item);	// push from the front   
	void backPush	(int item);	// push form the back
	void frontPop();			// pop from the front
	void backPop();				// pop from the back
	void display();  
	
private:  
	int StackArray[SIZE];  
	int frontTop;   
	int backTop;   
};       

// Judge wether the array is full or not. 
bool DoubleStack::full() const
{
	if (frontTop >= backTop-1){
		cout<<"Stack full!\n";
		return true;
	}          
	return false;   
}     

// push from the front
void DoubleStack::frontPush(int item)  
{	    
	if (!full()){
		frontTop += 1;
		StackArray[frontTop] = item;
	}
}

// push from the back
void DoubleStack::backPush(int item)
{   	   
	if (!full()){   
		backTop -= 1;  
		StackArray[backTop] = item;    
	}   
} 

// pop from the front
void DoubleStack::frontPop()  
{   
	if (frontTop>-1){       
		frontTop -= 1; 
  		cout<<"popped from the front!\n";   
  	}
	else
		cout<<"Front Stack empty!\n";	   
}

// pop from the back
void  DoubleStack::backPop()  
{   
	if (backTop<SIZE){    
		backTop += 1;     
		cout<<"popped from the back!\n";    
	} 
	else  
		cout<<"Back Stack empty!\n";
}   

// display all the elements in the doublestack
void DoubleStack::display()
{       
	// output the front stack
	cout<<"Front stack£º";   
	int i=0;   
	while (i <= frontTop){        
		cout<<StackArray[i]<<" ";       
		i++;       
	}          
	cout<<endl;     
	
	// output the back stack      
	cout<<"Back stack£º"; 
	i = SIZE-1;      
	while (i >= backTop){          
		cout<<StackArray[i]<<" ";        
		i--;      
	}      
	cout<<endl;  
}

int choose(DoubleStack s)
{
	int temp;   
	char c;     
	cout<<"Option: 1-push from the front, 2-push from the back,\n"
	 	<<"        3-pop from the front, 4-pop from the back,\n"
	  	<<"        5-display the doublestack, #-quit.\n";  
	while(1){   
		cout<<"Input the option£º";   
		cin>>c;   
		switch(c)
		{    
			// push from the front
			case'1':cout<<"Input the element£º";     
					cin>>temp;    
					s.frontPush(temp);
					break;
			// push from the back
			case'2':cout<<"Input the element£º";    
					cin>>temp;    
					s.backPush(temp);
					break;
			// pop from the front
			case'3':s.frontPop(); 
					break;
			// pop from the back
			case'4':s.backPop();
					break;
			// display all the elements
			case'5':s.display();
					break;
			case'#':return 0;
			default:cout<<"Error input! Please try again."<<endl;
		}    
	}  	
}   
  
int main() 
{
	int choose(DoubleStack );
	DoubleStack S;  
	choose(S);
	return 0;	
}




