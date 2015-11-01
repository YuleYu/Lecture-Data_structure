//Double_direction_Stack_in_deque project_Experiment3. 
//Created by Yule, Nov_1_2015
//============================================================================== 
#include<iostream> 
#include<deque>
using namespace std; 

int choose(deque<int> de)
{
	void display(deque<int>, int);
	int temp;   
	char c; 
	int cal_num = 0;    // To calculate the size of the front stack. 
	
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
					de.push_front(temp);
					cal_num++;
					break;
			// push from the back
			case'2':cout<<"Input the element£º";    
					cin>>temp;    
					de.push_back(temp);
					break;
			// pop from the front
			case'3':if (cal_num > 0){
						cal_num--; 
						de.pop_front();
						cout<<"popped from the front!\n";
					}
					// if there is no data, don't change cal_num and de.
					else	
						cout<<"Front Stack empty!\n";  	
					break;
			// pop from the back
			case'4':if (de.size()-cal_num > 0){
						de.pop_back();
						cout<<"popped from the back!\n";
					}
					// if there is no data, don't change de.
				 	else
				 		cout<<"Back Stack empty!\n";
					break;
			// display all the elements in the doublestack
			case'5':display(de, cal_num);
					break;
			case'#':return 0;
			default:cout<<"Error input! Please try again."<<endl;
		}    
	}  	
}

// Display the doublestack.
void display(deque<int> de, int num)
{
	// display the front stack.
	int i = num;
	cout<<"Front stack£º";
	while (i--)
		cout<<de[i]<<' ';
	cout<<endl;
	
	// display the back stack.
	// The size of the back stack is reckoned from num.
	int j = num;
	cout<<"Back stack£º"; 
	while (j < de.size()){
		cout<<de[j]<<' ';
		j++;
	}
	cout<<endl;
}

int main() 
{
	int choose(deque<int>);
	deque<int> S;
	choose(S);
	return 0;	
}


