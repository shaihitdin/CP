#include <bits/stdc++.h>
#include <chrono>
#include <thread>

using namespace std;

int main () {
	cout << std::thread::hardware_concurrency;
	return 0;
}