#include <iostream>
#include <cstdlib>
#include <ctime>

class ArrayList
{
private:
	int len;
	int* data;
	int size;
	void init(int len = 10)
	{
		this->len = len;
		this->size = 0;
		this->data = (int*)malloc(sizeof(int) * len);
	}
	bool indexValid(int index)
	{
		return 0 <= index < this->size;
	}
	void expand() {
		int newLen = static_cast<int>(this->len * 1.5);
		if (newLen <= this->len) {
			newLen = this->len + 10;
		}
		int* newData = (int*)malloc(sizeof(int) * newLen);
		if (newData == nullptr) {
			return;
		}
		for (int i = 0; i < this->size; ++i) {
			newData[i] = this->data[i];
		}
		free(this->data);
		this->data = newData;
		this->len = newLen;
	}

public:
	ArrayList(int len = 10)
	{
		this->init(len);
	}
	ArrayList(ArrayList& list)
	{
		this->init(list.len);
		this->size = list.size;
		for (int i = 0; i < list.size; ++i)
		{
			this->set(i, list.get(i));
		}
	}
	~ArrayList()
	{
		free(this->data);
	}
	void randomize(int min = 10, int max = 99)
	{
		srand(time(0));
		for (int i = 0; i < len; ++i)
		{
			this->data[i] = rand() % (max - min + 1) + min;
		}
		this->size = len;
	}
	void print()
	{
		for (int i = 0; i < this->size; ++i)
		{
			printf("%d ", this->data[i]);
		}
		printf("\n");
	}
	int get(int index)
	{
		if (indexValid(index))
		{
			return this->data[index];
		}
		return -1;
	}
	void set(int index, int value)
	{
		if (indexValid(index))
		{
			this->data[index] = value;
		}
	}
	int count()
	{
		return size;
	}

	void pushBack(int element) {
		if (this->size == this->len) {
			expand();
		}
		this->data[this->size] = element;
		this->size++;
	}
	void pushFront(int element) {
		if (this->size == this->len) {
			expand();
		}
		for (int i = this->size; i > 0; --i) {
			this->data[i] = this->data[i - 1];
		}
		this->data[0] = element;
		this->size++;
	}
	void insert(int index, int element) {
		if (!indexValid(index) && index != size) {
			return;
		}
		if (this->size == this->len) {
			expand();
		}
		for (int i = this->size; i > index; --i) {
			this->data[i] = this->data[i - 1];
		}
		this->data[index] = element;
		this->size++;
	}
	int popBack() {
		if (this->size == 0) {
			return -1;
		}
		int lastElement = this->data[this->size - 1];
		this->size--;
		return lastElement;
	}
	int popFront() {
		if (this->size == 0) {
			return -1;
		}
		int firstElement = this->data[0];
		for (int i = 0; i < this->size - 1; ++i) {
			this->data[i] = this->data[i + 1];
		}
		this->size--;
		return firstElement;
	}
	int extract(int index) {
		if (!indexValid(index)) {
			return -1;
		}
		if (this->size == 0) {
			return -1;
		}
		int extractedElement = this->data[index];
		for (int i = index; i < this->size - 1; ++i) {
			this->data[i] = this->data[i + 1];
		}
		this->size--;
		return extractedElement;
	}
	void reverse(int start, int end) {
		if (!indexValid(start) || !indexValid(end) || start >= end) {
			return;
		}
		for (int i = 0; i <= (end - start) / 2; ++i) {
			int temp = this->data[start + i];
			this->data[start + i] = this->data[end - i];
			this->data[end - i] = temp;
		}
	}
	int sum() {
		int totalSum = 0;
		for (int i = 0; i < this->size; ++i)
		{
			totalSum += this->data[i];
		}
		return totalSum;
	}
	/// Второй по величине элемент
	int secondMax() {
		if (this->size < 2) {
			return -1;
		}
		int maxVal = this->data[0];
		int secondMaxVal = -1;

		if (this->data[1] > maxVal) {
			secondMaxVal = maxVal;
			maxVal = this->data[1];
		}
		else {
			secondMaxVal = this->data[1];
		}


		for (int i = 2; i < this->size; ++i) {
			if (this->data[i] > maxVal) {
				secondMaxVal = maxVal;
				maxVal = this->data[i];
			}
			else if (this->data[i] > secondMaxVal && this->data[i] != maxVal) {
				secondMaxVal = this->data[i];
			}
		}
		return secondMaxVal;
	}
	/// индекс последнего минимального элемента
	int lastMinIndex() {
		if (this->size == 0) {
			return -1;
		}
		int minVal = this->data[0];
		int minIndex = 0;
		for (int i = 1; i < this->size; ++i) {
			if (this->data[i] <= minVal) {
				minVal = this->data[i];
				minIndex = i;
			}
		}
		return minIndex;
	}
	/// сместить на k элементов вправо
	int shift(int k) {
		if (this->size == 0 || k == 0) {
			return 0;
		}
		k = k % this->size;
		if (k < 0) {
			k += this->size;
		}
		if (k == 0) return 0;
		int* tempArray = (int*)malloc(sizeof(int) * this->size);
		if (tempArray == nullptr) {
			return -1;
		}
		for (int i = 0; i < k; ++i) {
			tempArray[i] = this->data[this->size - k + i];
		}
		for (int i = 0; i < this->size - k; ++i) {
			tempArray[k + i] = this->data[i];
		}
		for (int i = 0; i < this->size; ++i) {
			this->data[i] = tempArray[i];
		}
		free(tempArray);
		return 0;
	}
	/// количество нечетных
	int countOdd() {
		int oddCount = 0;
		for (int i = 0; i < this->size; ++i)
		{
			if (this->data[i] % 2 != 0) {
				oddCount++;
			}
		}
		return oddCount;
	}
	/// сумма четных элементов
	int sumEven() {
		int evenSum = 0;
		for (int i = 0; i < this->size; ++i)
		{
			if (this->data[i] % 2 == 0) {
				evenSum += this->data[i];
			}
		}
		return evenSum;
	}
};
int max(ArrayList list)
{
	int mx = list.get(0);
	for (int i = 0; i < list.count(); ++i)
	{
		mx = (mx > list.get(i) ? mx : list.get(i));
	}
	return mx;
}

int main(int argc, char* argv[])
{
	ArrayList list(10);
	list.randomize();
	list.print();
	printf("%d\n", max(list));
	return 0;
}