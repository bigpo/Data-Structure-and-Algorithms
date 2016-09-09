#include <iostream>
#include <stdlib.h>

using namespace std;


void merge(int *array, int lo, int mid, int hi);
void mergeSort(int *array, int lo, int hi);

int main(int argc, char *argv[])
{
	int array[10] = { 2,6,4,1,8,0,3,9,7,5 };
	int len = sizeof(array) / sizeof(array[0]);

	mergeSort(array, 0, len - 1);

	for (int i = 0; i < len; i++)
		printf("%d ", array[i]);
	printf("\n");

	system("pause");
	return 0;
}

void merge(int *array, int lo, int mid, int hi) { //合并例程
												 
	int size = hi - lo + 1;  
	int *tempArray = new int[size]; //申请内存，把待合并的前后两个子数组

	for (int k = 0; k < size; k++) //复制到一个新的临时数组中去
		tempArray[k] = array[lo + k];

	int i = 0;                            // i 指向前半部分有序数组的首元素
	int	j = mid - lo + 1;                // j 指向后半部分有序数组的首元素

	for (int k = lo; k <= hi; k++) {
		if (i > mid - lo)                      //前半部分有序数组已经合并完毕
			array[k] = tempArray[j++];
		else if (j > size - 1)                  //后半部分有序数组已经合并完毕
			array[k] = tempArray[i++];
		else if (tempArray[i] < tempArray[j])    //将小者并入全部有序数组
			array[k] = tempArray[i++];               
		else
			array[k] = tempArray[j++];
	}
	
	delete[] tempArray;   //释放临时数组
}

void mergeSort(int *array, int lo, int hi) { //0 <= lo < hi <= size
	if (array == NULL || hi - lo < 2)
		return;

	int mid = (hi + lo) / 2;

	mergeSort(array, lo, mid); //归并数组的前半部分 [lo, mid]
	mergeSort(array, mid + 1, hi); //归并数组的后半部分 [mid+1, hi]
	merge(array, lo, mid, hi); //合并两个已排序的数组

}
