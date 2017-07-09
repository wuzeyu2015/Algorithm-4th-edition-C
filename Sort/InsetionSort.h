#ifndef INSERTION_H
#define INSERTION_H



void InsertionSort(int arr[], int n);
void __portionInsertionSort(int arr[], int l, int r);

/////////////////////////////////////////////////////////


void __portionInsertionSort(int arr[], int l, int r){

	for( int i = l + 1 ; i <= r ; i ++ ) {
		int e = arr[i];
		int j = 0;
		//用j遍历[j, i]内层循环，j保留i应该插入的位置，在此之前先用e保存i的值
		for (j = i; j > l && arr[j - 1] > e; j--)
		{
			arr[j] = arr[j-1];
		}
		arr[j] = e;
	}
	return;
}
void InsertionSort(int arr[], int n){

	for( int i = 1 ; i < n ; i ++ ) {
		int e = arr[i];
		int j = 0;
		//用j遍历[0, i]内层循环，j保留i应该插入的位置，在此之前先用e保存i的值
		for (j = i; j > 0 && arr[j - 1] > e; j--)
		{
			arr[j] = arr[j-1];
		}
		arr[j] = e;
	}
	return;
}


#endif //INSERTION_H
