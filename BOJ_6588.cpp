#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000000;
vector<bool> is_prime(MAX + 1, true);

void getPrimes() {
	is_prime[0] = is_prime[1] = false;

	for (int i = 2; i * i <= MAX; i++) {
		if (!is_prime[i]) {
			continue;
		}
		for (int j = i * i; j <= MAX; j += i) {
			is_prime[j] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	getPrimes();
	int n;
	vector<int> arr;

	//입력
	while (true) {
		cin >> n;
		if (n == 0) {
			break;
		}
		arr.push_back(n);
	}

	//연산
	//출력
	for (int i = 0; i < arr.size(); i++) {
		for (int a = 3; a <= arr[i]; a += 2) {
			//두 수가 모두 소수인 경우
			if (is_prime[a] && is_prime[arr[i] - a]) {
				cout << arr[i] << " = " << a << " + " << arr[i] - a << '\n';
				break;
			}
			//두 수 중 하나라도 소수가 아닌 경우
			else if (is_prime[arr[i] - a] == 1) {
				cout << "Goldbach's conjecture is wrong." << '\n';
			}
		}
	}

    return 0;
}