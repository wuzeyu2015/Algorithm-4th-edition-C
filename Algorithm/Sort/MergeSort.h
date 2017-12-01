#ifndef MERGE_H
#define MERGE_H

class MergeSort{

public:
	MergeSort(int a[], int length){
		aux = new int[length];
		memset(aux, 0, length);
		sort(a, 0, length - 1);
		memcpy(a, aux, length * sizeof(int));
	}
	~MergeSort(){
		delete aux;
	}

private:
	int* aux;
	void merge(int a[], int lo, int mid, int hi);
	void sort(int a[], int lo, int hi);
};

void MergeSort::merge(int a[], int lo, int mid, int hi){
	int i = lo;
	int j = mid + 1;
	int k = lo;
	while(k <= hi){
		if (a[i] < a[j]) { aux[k++] = a[i++]; }
		else if (a[i] >= a[j]) { aux[k++] = a[j++]; }
		else if (i > mid) { aux[k++] = a[j++]; }
		else if (j > hi) { aux[k++] = a[i++]; }
	}
}
void MergeSort::sort(int a[], int lo, int hi){
	if (lo >= hi)
		return;
	int mid = (lo + hi) / 2;
	sort(a, lo, mid);
	sort(a, mid + 1, hi);
	merge(a, lo, mid, hi);
}


#endif //MERGE_H
