#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main() {
	int result = 0;
	for (int i = 1; i <= 140; ++i) {
		string command = "main.exe " + to_string(i);
		int ans = system(command.c_str());
		if (ans == 1)
			result += 1;
		else if (ans != 0)
			cout << "Segmentation Fault" << endl;
	}
	cout << setprecision(2) << fixed << "Grade: " << result / 140.0 * 10;
	return 0;
}