#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H


void selectionSort(int arr[], int n);
//////////////////////////////////////////////////////

void selectionSort(int arr[], int n){

	for(int i = 0 ; i < n ; i ++){

		int minIndex = i;
		for( int j = i + 1 ; j < n ; j ++ )
			if( arr[j] < arr[minIndex] )
				minIndex = j;

		swap( arr[i] , arr[minIndex] );
	}
}
#endif //SELECTIONSORT_H
