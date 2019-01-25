#define BSEARCH 0
#define MSORT 1

#if MSORT 0
#include <iostream>
using namespace std;

int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
int tmp[10] = { 0, };

void merge(int s,int e) {
	int m = (s + e) / 2;
	int i = s;
	int j = m + 1;
	int k = s;

	while (i <= m && j <= e)
		if (arr[i] >= arr[j])tmp[k++] = arr[i++];
		else tmp[k++] = arr[j++];

	if (i >= m) while (j <= e) tmp[k++] = arr[j++];
	
	if (j >= e) while (i <= m) tmp[k++] = arr[i++];
	
	for (int i = s; i <= e; i++) arr[i] = tmp[i];
}

void msort(int s, int e)
{
	int m;
	if (s < e) {
		m = (s + e) / 2;
		msort(s, m);
		msort(m + 1, e);
		merge(s, e);
	}
}


int main() {

	msort(0, 10 - 1);
	cout << "desc sorted array : ";
	for (int i = 0; i < 10; i++)cout << arr[i] << " ";
	cout << endl;
	return 0;
}
#endif

#if BSEARCH
#include<iostream>

using namespace std;

int main() {
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int find = 0;
	cin >> find;
	int s = 0, e = 10 - 1;
	int m;
	int cnt = 0;
	while(s<=e){
		m = (s + e) / 2;
		cnt++;
		if (find == arr[m])break;
		(find < arr[m]) ? e = m - 1 : s = m + 1;
	}
	cout << "count : " << cnt << endl;
	cout << "searching number index : " << m << endl;
	
	return 0;
}
#endif