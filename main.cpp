#include <iostream>
#include <fstream>
#include <chrono>

using namespace std::chrono;
using std::cout;
using std::endl;
using std::cerr;
using std::ofstream;

bool printNew();
bool printEnd();

int main () {
	// Test for printNew() function
	auto start1 = high_resolution_clock::now();
	if(!printNew()) return -1;
	auto stop1 = high_resolution_clock::now();
	auto duration1 = duration_cast<microseconds>(stop1 - start1);
	cout << "\\n took: "<< duration1.count()
		 << " milliseconds." << '\n';
	
	// Test for printNew() function
	auto start2 = high_resolution_clock::now();
	if(!printEnd()) return -1;
	auto stop2 = high_resolution_clock::now();
	auto duration2 = duration_cast<microseconds>(stop2 - start2);
	cout << "endl took: " << duration2.count()
		 << " milliseconds." << endl;
	
	return 0;
}

bool printNew() {
	ofstream oFile("./test1.txt");
	if (!oFile) {
		cerr << "Could not write file." << '\n';
		return false;
	}
	for (int i = 0; i < 1000; i++)
		oFile << "Hello world!\n";
	oFile.close();
	return true;
}

bool printEnd() {
	ofstream oFile("./test2.txt");
	if (!oFile) {
		cerr << "Could not write file." << endl;
		return false;
	}
	for (int i = 0; i < 1000; i++)
		oFile << "Hello world!" << endl;
	oFile.close();
	return true;
}
