#include <iostream>
#include <stdlib.h>

using namespace std;

void heapSort(int A[], int N);
void sink(int A[], int k, int N);

int main() {
	int array[10] = { 2,6,4,1,8,0,3,9,7,5 };
	int len = sizeof(array) / sizeof(array[0]);

	heapSort(array, len - 1);

	for (int i = 0; i < len; i++)
		printf("%d ", array[i]);
	printf("\n");

	system("pause");
	return 0;
}


void sink(int A[], int k, int N) {

	while (2 * k + 1 <= N) { //k的左孩子存在
		int j = 2 * k + 1; //左孩子的秩记为j
		if (j < N && A[j] < A[j + 1]) //如果右孩子存在，且右孩子的值较大 
			j++;           //将右孩子的秩记为j
		if (A[k] < A[j])   // 如果父亲的值 小于 最大孩子的值
			swap(A[k], A[j]); //交换两者的值
		else
			break; //否则下沉完成，终止循环
		k = j; //将父节点下沉至最大孩子的位置
	}
}

void heapSort(int A[], int N) { //N为数组末尾元素的秩，为 len-1
	int k;

	for (k = N / 2; 0 <= k; k--) //建堆
		sink(A, k, N);
	
	while (N > 0)
	{
		swap(A[0], A[N--]); //依次将最大元素(堆顶)放置末尾(构成有序数组，类似于选择排序)，同时缩减堆的规模
		sink(A, 0, N); //对对顶元素进行下沉操作，以恢复堆序性
	}
}