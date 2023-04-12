#include<iostream>
#include <fstream>
#include <time.h>

using namespace std;

int main() {
	srand(time(NULL));
	ofstream outfile;
	outfile.open("data.txt");
	int num;
	for(int i = 0; i < 1000; i ++) {
	        num = rand() % 100 + 1;
		outfile << num << endl;
	}
	return 0;
}
