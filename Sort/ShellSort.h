#ifndef SHELLSORT_H
#define SHELLSORT_H


void ShellSort(int arr[], int n);

/////////////////////////////////////////////////////////

void ShellSort(int arr[], int n){
	int h = 1;
	while(h < n/3) h = 3*h + 1;
	while(h >= 1)
	{
		//用i遍历[h, n)每一个元素，这样也就交叉地遍历了所有的分组
		for( int i = h ; i < n ; i ++ ) {
			//在[0, i]范围内，用j遍历i这个元素所在的分组，访问间隔为h，把arr[i]放入arr[i - h]、arr[i - 2*h]、arr[i - 3*h]合适的位置
			for (int j = i; j >= h && arr[j - h] > arr[j]; j -= h)
			{
				swap(arr[j], arr[j-h]);	
			}
		}
		h = h / 3;
	}

	return;
}
#endif //SHELLSORT_H
