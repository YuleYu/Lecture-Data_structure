//Postfix expression converse to infix expression. 
//Created by Yule, Nov_14_2015
//==============================================================================
// This program is to change the postfix expression into infix expression.
// 
//CAUTION:
// The inputted expression should only include letter and operator(+,-,*,/,%),
// no number or other symbol should appear in the expression.
// If happened, the output will report error.
//==============================================================================
#include<iostream>
#include<string>
using namespace std;
 
// Given the size of the stored stack for expression.
const int SIZE = 100;

// Create a Stack class for string.
class StrStack
{
	public:
 		StrStack(){count = -1;}	// Initialize the count -1 for convenience.
		bool full()	const;
		bool empty() const;
		void push(char sTemp);
		void push(string sTemp);
		string top();
		bool sec_empty() const;
		string sec_top();
		void pop();
		int size();
		void display();// only use for test.
	private:
		// the stack data store place is based on a string array.
		string StackString[SIZE];
		// count the amouont of the elements.
		int count;
};

//Function: Judge whether the stack is full.
bool StrStack::full() const
{
	if (count == SIZE-1){
		cout<<"The stack is full!"<<endl;
	 	return 1;
	}	
	return 0;
}

//Function: Judge whether the stack is empty.
bool StrStack::empty()	const
{
	if (count == -1){
		cout<<"The stack is empty!"<<endl;
		return 1;
	}
	return 0;
}

//Function: Element grabbed from the inserted line is in char type. 
// push the gotten character into the stack.
void StrStack::push(char s)
{
	if (!full()){
 		count += 1;
 		StackString[count] = s;
	}	
}

//Function: Element grabbed from following operating part is in string type.
// push the gotten string into the stack.
void StrStack::push(string s)
{
	if (!full()){
 		count += 1;
 		StackString[count] = s;
	}	
}

//Function: Show the top element in the stack.
string StrStack::top()
{
	if (!empty())
		return StackString[count];
}

// Especially for changeing into infix expression,
// the operation will always handle two elements in the stack the same time.
// So need another judging function to judge wether could take two elements. 
//Function: Judge wether the stack has two elements insides.
bool StrStack::sec_empty() const
{
	if (count == 0)
		return 1;
	return 0;
}
//Function: Get the element just below the top.
string StrStack::sec_top()
{
	if (!sec_empty()){
		return StackString[count-1];
	}
}

//Function: Pop out the top element.
void StrStack::pop()
{
	if (!empty()){
		count -= 1;
	}
}

//Function: Show the size of stored elements.
int StrStack::size()
{
	return count+1;
}

//Function: Display all the elements in the stack one time.
// Only use for test.
void StrStack::display()
{
	if (!empty()){
		for (int i=0; i<=count; i++)
			cout<<StackString[i]<<endl;
	}
}

//Function: Operater function.
string inFix_Notation_Exchange(string exp)
{
	char token;
	StrStack opStack;	// Create a string stack.
	bool ju = 1;
	int i = 0;
	
	while(ju && i<exp.length()){
		token = exp[i];
		// Only push the letter into the stack.
		if ((token>='A'&&token<='Z') || (token>='a'&&token<='z'))
			opStack.push(token);
		else{
			// Other symbol go into switch sentence.
			// Except +,-,*,/,%, other symbol will report error.
			switch(token)
			{
				case ' ' : 	break;
				case '+' :
				case '-' :
				case '*' :
				case '/' :
							// Judge wether there exists two elements,
							// if so, link two elements with the operator and
							// add brackets both sides. Then pop out two original elements,
							// push the new string into the stack.
				case '%' :	if (!opStack.sec_empty()){
								string temp = '(' + opStack.sec_top() + token + opStack.top() + ')';
								opStack.pop();
								opStack.pop();
								opStack.push(temp);
							}
							else{
								ju = 0;
							}
							break;
				default  :	ju = 0;
			}
		}
		i++;
	}
	// After all character has been token, there should be only one element in the stack,
	// and that is the result to output.
	if (opStack.size()==1 && ju){
		return opStack.top();
	}
	else
		return "ERROR! CHECK THE INPUT EXPREESION AGAIN!";
}


int main()
{
	string inFix_Notation_Exchange(string);
 	string postfixExp;
	cout<<"NOTE: Enter # for postfix expression to stop.\n";
	while(1){
		cout<<"\nPostfix expression? "<<endl;
		getline(cin, postfixExp);
		// Input "#" to get out.
		if (postfixExp == "#")
			break;		
		cout<<"Infix expression is: "<<inFix_Notation_Exchange(postfixExp)<<endl;
	}
	return 0;
}


