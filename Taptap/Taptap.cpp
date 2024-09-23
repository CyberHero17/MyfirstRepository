//#include <iostream>
//using namespace std;
//unsigned long long int get_a_hexadecimal()
//{
//	char c, one = 49;
//	unsigned long long int res = 0;
//}
#include <iostream>
using std::cin;
using std::cout;
void ar() {
	int n, c;
	int g = 0;
	cin >> n;
	int a[10000], b[10000];
	
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cin >> c;
	for (int i = 0; i < n; i++)
	{
		b[i] = a[i];
	}
	for (int j = 0; j < n; j++) {

		for (int k = 0; k < n - j - 1; k++) {
			if (a[k] > a[k + 1]) {
				int tmp = a[k];
				a[k] = a[k + 1];
				a[k + 1] = tmp;
			}
		}
	}
	int c[100], z = 0;
	for (int i = 0; i < n; i++)
	{
		if (b[i] > a[n - c]) {
			c[z] = b[i];
			z++;
		}
	}

}
int main()
{
	ar();
	return 0;
}
