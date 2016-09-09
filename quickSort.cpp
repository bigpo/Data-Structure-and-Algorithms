#include <iostream>
#include <stdlib.h>

using namespace std;


void quickSort(int *array, int lo, int hi);
int partition(int *array, int lo, int hi);


int main() {
	int array[10] = { 2,6,4,1,8,0,3,9,7,5 };
	int len = sizeof(array) / sizeof(array[0]);

	quickSort(array, 0, len);

	for (int i = 0; i < len; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}


void quickSort(int *array, int lo, int hi) { // 0 <= lo < hi <= size
	if (hi - lo < 2) return;

	int mi = partition(array, lo, hi - 1); //在 [lo, hi - 1] 内构造轴点
	quickSort(array, lo, mi); //对前缀进行递归排序，注意这里的mi也是哨兵元素，并不包含在前缀中
	quickSort(array, mi + 1, hi);
}

int partition(int *array, int lo, int hi) { //注意此处的hi不是哨兵
	swap(array[lo], array[lo + rand() % (hi - lo + 1)]); //任选一元素与首元素交换
	int pivot = array[lo];    //以首元素为轴点，经以上交换，等效于随机选取

	while (lo < hi) {
		while ((lo < hi) && (pivot <= array[hi]))
			hi--;
		array[lo] = array[hi];

		while ((lo < hi) && (array[lo] <= pivot))
			lo++;
		array[hi] = array[lo];
	}

	array[lo] = pivot;

	return lo;
}