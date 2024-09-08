#include <iostream>
#include <algorithm>

using namespace std;

//분모의 최대공약수 구하기
int getGcd(int denominator1, int denominator2) {
	int temp;
	int a = max(denominator1, denominator2);
	int b = min(denominator1, denominator2);
	while (b != 0) {
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int main() {
	//입력
	int numerator1, denominator1;
	int numerator2, denominator2;
	cin >> numerator1 >> denominator1;
	cin >> numerator2 >> denominator2;

	//연산
	int gcd = getGcd(denominator1, denominator2); //최대공약수
	int lcm = denominator1 * denominator2 / gcd; //최소공배수

	int product1 = numerator1 * (lcm / denominator1);
	int product2 = numerator2 * (lcm / denominator2);

	int sum = product1 + product2;

	int result_gcd = getGcd(sum, lcm);
	int result_numerator = sum / result_gcd;
	int result_denominator = lcm / result_gcd;

	//출력
	cout << result_numerator << " " << result_denominator;

	return 0;
}