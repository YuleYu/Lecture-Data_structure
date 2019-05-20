//Drawing tools  
//Created by Yule, Nov_1_2015
//==============================================================================
// Regard the whole square into a plane rectangular coordinate system.
// Every pixel has its own coordinate (x,y).
// When given the original pixel, use dfs function to color the square.
//============================================================================== 
#include<iostream>
using namespace std;


// define the square size N*N
#define N 20
// The coordinate change will use array subscribe for convenience.
int X[] = {-1, 0, 1}, Y[] = {-1, 0, 1};
// The final color-filled square.
int square[N][N];
// Count for the cycle.
int countN;


int main()
{
	int dfs(int, int);
	// clear all the memory in the square
	memset(square, 0, sizeof(square));
	int input_X, input_Y;
	countN = 0;
	
	// Input the start pixel.
	cin>>input_X>>input_Y;
	dfs(input_X-1, input_Y-1);
	return 0;
}

// use dfs recursive function to search the whole suqare
int dfs(int x, int y)
{
	// let the reached pixel's value become 1, so will not
	// go over this plot again.
	square[x][y] = 1;
	countN++;
	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
			// Search while the pixel is in the square size,
			// and never has been reached, which the value of
			// that plot shoule be 0.
			if ((x+X[i])>=0 && (y+Y[j])>=0 &&
				(x+X[i])<N && (y+Y[j])<N && 
				square[x+X[i]][y+Y[j]]==0){
				dfs(x+X[i], y+Y[j]);
			}
			
			// display the current painting part
			system("cls");
			for (int p=0; p<N; p++){
				for (int q=0; q<N; q++){
					if (square[p][q]==1)
						cout<<'*';
					else 
						cout<<' ';
				}
				cout<<endl;
			}
			if (countN==N*N)
					return 0;				
		}
	}
	
}

