#include <iostream>
#include <algorithm>
using namespace std;

void printArray(int arr[], int n){
	for(int i=0;i<n;i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

/* Bubble Sort */
void bubbleSort(int a[], int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				swap(a[j], a[j+1]);
			}
		}
	}
}

/* Selection Sort */
void selectionSort(int arr[], int n){
	for(int i=0;i<n-1;i++){
		int min=i;
		for(int j=i+1;j<n;j++){
			if(arr[j]<arr[min]){
				min=j;
			}
		}
		swap(arr[i], arr[min]);
	}
}

/* Insertion Sort */
void insertionSort(int arr[], int n){
	for(int i=1;i<n;i++){
		int key=arr[i];
		int j=i-1;
		while(j>=0 && arr[j]>key){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}

/* Quick Sort with Partition */
int partition(int arr[], int low, int high){
	int pivot = arr[high];
	int i = low-1;
	for(int j=low;j<high;j++){
		if(arr[j]<pivot){
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i+1], arr[high]);
	return i+1;
}

void quickSort(int arr[], int low, int high){
	if(low<high){
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi-1);
		quickSort(arr, pi+1, high);
	}
}

/* Merge Sort */
void merge(int arr[], int l, int m, int r){
	int n1 = m-l+1;
	int n2 = r-m;
	int L[n1], R[n2];

	for(int i=0;i<n1;i++)
		L[i]=arr[l+i];
	for(int j=0;j<n2;j++)
		R[j]=arr[m+1+j];

	int i=0,j=0,k=l;
	while(i<n1 && j<n2){
		if(L[i]<=R[j]){
			arr[k]=L[i];
			i++;
		}else{
			arr[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		arr[k]=L[i];
		i++; k++;
	}
	while(j<n2){
		arr[k]=R[j];
		j++; k++;
	}
}

void mergeSort(int arr[], int l, int r){
	if(l<r){
		int m = (l+r)/2;
		mergeSort(arr,l,m);
		mergeSort(arr,m+1,r);
		merge(arr,l,m,r);
	}
}

/* Heap Sort */
void heapify(int arr[], int n, int i){
	int largest = i;
	int l = 2*i+1;
	int r = 2*i+2;

	if(l<n && arr[l]>arr[largest])
		largest = l;
	if(r<n && arr[r]>arr[largest])
		largest = r;

	if(largest!=i){
		swap(arr[i], arr[largest]);
		heapify(arr,n,largest);
	}
}

void heapSort(int arr[], int n){
	for(int i=n/2-1;i>=0;i--)
		heapify(arr,n,i);

	for(int i=n-1;i>0;i--){
		swap(arr[0],arr[i]);
		heapify(arr,i,0);
	}
}

/* Shell Sort */
void shellSort(int arr[], int n){
	for(int gap = n/2; gap>0; gap/=2){
		for(int i=gap;i<n;i++){
			int temp = arr[i];
			int j;
			for(j=i;j>=gap && arr[j-gap]>temp;j-=gap){
				arr[j] = arr[j-gap];
			}
			arr[j] = temp;
		}
	}
}

int main(){
	int n,key;
	do{
		cout<<"Enter Size of Array: ";
		cin>>n;

		int *arr = new int[n];
		cout<<"Enter Elements: ";
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}

		cout<<"\n------Choose Sorting------\n";
		cout<<"1. Bubble Sort\n2. Insertion Sort\n3. Selection Sort\n4. Quick Sort\n5. Merge Sort\n6. Heap Sort\n7. Shell Sort\n8. Exit\n";
		cout<<"Enter choice: ";
		cin>>key;

		switch(key){
			case 1: bubbleSort(arr,n); cout<<"Bubble Sort.";break;
			case 2: insertionSort(arr,n);cout<<"Insetion Sort."; break;
			case 3: selectionSort(arr,n);cout<<"Selection Sort."; break;
			case 4: quickSort(arr,0,n-1);cout<<"Quick Sort."; break;
			case 5: mergeSort(arr,0,n-1);cout<<"Merge Sort."; break;
			case 6: heapSort(arr,n);cout<<"Heap Sort."; break;
			case 7: shellSort(arr,n);cout<<"Shell Sort."; break;
			case 8: cout<<"Exiting...\n"; continue;
			default: cout<<"Invalid choice\n"; continue;
		}

		cout<<"Sorted Array: ";
		printArray(arr,n);
	}while(key!=8);

	return 0;
}
