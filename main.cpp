#include <iostream>

using namespace std;

void loop_start() { cout << "loop start" << endl; }
void loop_kernel1() { cout << "loop kernel 1" << endl; }
void loop_kernel2() { cout << "loop kernel 2" << endl; }

int entrance(bool b);
void helper(bool b);

int main() {
	entrance(true);
	return 0;
}
