#include<iostream>
using namespace std;

int main() {
	int n,m;
	cin>>n>>m;
	int arr[n][m];
	for(int row =0; row <n ;row++){
		for(int col=0 ; col<m ;col++){
			cin>>arr[row][col];
		}
	}
	int count =0;
	int total = n*m;

	int startingRow =0;
	int endingRow = n-1;
	int startingCol = 0;
	int endingCol = m-1;

	while(count < total){
		//printing starting row
		for(int index = startingCol ; index <= endingCol; index++){
			cout<<arr[startingRow][index]<<", ";
			count++;
		}
		startingRow++;

		//printing ending col
		for(int index = startingRow ; index<= endingRow; index++){
			cout<<arr[index][endingCol]<<", ";
			count++;
		}
		endingCol--;

		//printing ending row
		for(int index= endingCol ; index>= startingCol ; index--){
			cout<<arr[endingRow][index]<<", ";
			count++;
		}
		endingRow--;

		//printing starting col
		for(int index = endingRow; index>= startingRow ;index--){
			cout<<arr[index][startingCol]<<", ";
			count++;
		}
		startingCol++;
	}
	cout<<"END";
	return 0;
}