#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void outputRes(vector<int>arr){
	cout<<"result: "<<endl;
	for(int i = 0; i < arr.size(); i++) cout<<arr[i]<<" ";
	cout<<endl;
}

void maopao(vector<int>arr)
{
	for (int i = 0; i < arr.size(); ++i)
	{
		for(int j = i + 1; j < arr.size(); j++){
			if (arr[i] > arr[j])
			{
				swap(arr[i],arr[j]);
			}
		}
	}
	outputRes(arr);
}

void quickSort(vector<int>&arr, int left,int right)
{
	
	if(left > right) return;
	int base = arr[left];
	int i,j;
	i = left;
	j = right;
	//cout<<"base : "<< base <<endl;
	while(i < j){
		while(arr[j] >= base && i < j) j--;
		while(arr[i] <= base && i < j) i++;
		
		if(i < j) swap(arr[i],arr[j]); 
	}
	//outputRes(arr);
	swap(arr[left],arr[i]);
	quickSort(arr,left,i - 1);
	quickSort(arr,i + 1,right);
}

void mergerSort(vector<int>&arr,vector<int>&temp,int left, int right){
	if(left >= right) return;
	int mid = (left + right) / 2;
	mergerSort(arr,temp,left,mid);
	mergerSort(arr,temp,mid + 1, right);
	int i = left, j = mid + 1 , k =0;
	while(i <= mid && j <= right){
		if(arr[i] > arr[j]){
			temp[k++] = arr[j++];
		}
		else{
			temp[k++] = arr[i++];
		}
	}
	while(i <= mid) temp[k++] = arr[i++];
	while(j <= right) temp[k++] = arr[j++];
	for(int i = left, k = 0; i <= right; i++, k++){
		arr[i] = temp[k];
	}
	
	return;
}
void quick(vector<int>arr)
{
	int left = 0, right = arr.size() ;
	quickSort(arr,left,right);
	outputRes(arr);
}


int main(int argc, char const *argv[])
{
	vector<int>arr = {6,2,6,3,78,9,5};
	//quick(arr);
	//quickSort(arr,0,arr.size() - 1);
	std::cout<<"mergerSort"<<std::endl;
	vector<int>temp(arr.size(), 0);
	mergerSort(arr,temp,0,arr.size() - 1);
	outputRes(arr);
	return 0;
}