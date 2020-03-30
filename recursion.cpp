#include<iostream>
#include<string>
using namespace std;

int array_sum(int i, int arr[], int size, int sum){
	
	if(i > size){
		return sum;
	}
	sum += arr[i];
	
	array_sum(++i, arr, size, sum);
}

void printing_array_in_reverse(int i, int arr[], int size){
	
	if( i + 1 > size){           // Base check
		return;
	}
	
	i += 1;
	printing_array_in_reverse(i, arr, size);
	cout<<arr[i-1]<<" ";          // when Base check is true
}

int find_max(int i, int arr[], int size, int max){
	
	if(i > size){
		return max;
	}
	
	if(arr[i] > max){
		max = arr[i];
	}
	
	find_max(++i, arr, size, max);
	
}



///////// BONUS QUESTION ///////////////

void string_reverse(string str){
	cin>>str;
	
	if(cin.peek() == '\n'){
		cout<<str<<" ";
		return;
		
	}
	else string_reverse(str);
	cout<<str<<" ";
}
int main(){
	
	int arr[4] = {1, 2, 3 ,4};
	
	cout<<"PRINTING ARRAY IN  REVERSE ORDER "<<endl;
	printing_array_in_reverse(0, arr, 4);
	
	cout<<endl<<"----------------------------"<<endl;
	
	cout<<"SUMMING ARRAY "<<endl;
	cout<<"Sum is "<<array_sum(0, arr, 4, 0);
	
	cout<<endl<<"----------------------------"<<endl;
	
	cout<<"FINDING MAX IN ARRAY "<<endl;
	cout<<"Max is "<< find_max(0, arr, 4, arr[0]);   //  we consider first element as max
	
	cout<<endl<<"----------------------------"<<endl;
	
	cout<<"Reverse Word in String"<<endl;
	string_reverse(" ");
}