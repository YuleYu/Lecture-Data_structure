#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
int main ()
{
    priority_queue<int, vector<int>, less<int> > ipq;
    priority_queue<int, vector<int>, greater<int> > gipq;
    ipq.push(100);
    ipq.push(200);
    ipq.push(300);

    gipq.push(100);
    gipq.push(200);
    gipq.push(300);

    cout << "size of priority_queue ipq = "
         << ipq.size() << endl;
	cout << "ipq <int,vector<int>, less<int> > = ";
    while ( !ipq.empty() )
    {
        cout << ipq.top() << " ";
        ipq.pop();
    }
    cout << endl << endl;
/////////////////////////////////////////////////////////////////	
    cout << "size of priority_queue gipq = "
         << gipq.size() << endl;

    cout << "gipq <int,vector<int>, greater<int> > = ";
    while ( !gipq.empty() )
    {
        cout << gipq.top() << " ";
        gipq.pop();
    }
    cout << endl << endl;
/////////////////////////////////////////////////////////////////
        cout << "priority_queue<string,vector<string> > spq;"
         << endl;

    priority_queue<string,vector<string> > spq;
    for ( int i=1; i<10; i++ )
        spq.push(string(i,'*'));
    while ( !spq.empty() )
    {
        cout << spq.top() << endl;
        spq.pop();
    }
    return 0;
}


//ipq <int,vector<int>, less<int> > = 300  200  100
//gipq <int,vector<int>, greater<int> > = 100  200  300
