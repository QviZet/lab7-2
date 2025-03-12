#include "header.h"

int main() {
	const int len = 100000;
	double* arr;
	arr = new double[len];
	for (int i = 0; i < len; i++)
	{
		arr[i] = (rand() % 10000)/ 10.;
	}

	double* frstPart;
	frstPart = new double[len / 2];
	double* scndPart;
	scndPart = new double[len / 2];

	for (int i = 0; i < len/2; i++)
	{
		frstPart[i] = arr[i];
		scndPart[i] = arr[i + (len / 2)];
	}

	auto beginSort = std::chrono::steady_clock::now();

	sortPart(frstPart, len / 2);

	sortPart(scndPart, len / 2);

	sortArr(arr, frstPart, scndPart, len);

	auto endSort = std::chrono::steady_clock::now();
	auto timeSort = std::chrono::duration_cast<std::chrono::milliseconds>(endSort - beginSort);
	std::cout << timeSort.count() << std::endl;

	for (int i = 0; i < 100; i++)
	{
		std::cout << arr[i] << "\n";
	}
	for (int i = 0; i < 100; i++)
	{
		std::cout << arr[len-i-1] << "\n";
	}
	delete[] arr;
	delete[] frstPart;
	delete[] scndPart;
	return 0;
}