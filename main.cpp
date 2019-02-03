#include <iostream>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <cstdio> // To remove the test files with std::remove()

using namespace std::chrono;
using std::cout;
using std::endl;
using std::cerr;
using std::ofstream;
using std::setprecision;

bool printNew();
bool printEnd();

const char* const file1 = "./test1.txt";
const char* const file2 = "./test2.txt";
const char* const file3 = "./testLog.txt";

int main () {
    ofstream logFile(file3, std::ios_base::app); // Appends existing log file
    if (!logFile) {
        cerr << "Could not open log file!\n";
        return -1;
    }
	// Test for printNew() function
    // Holy smokes, the type of start1 is actually pretty hairy.
    auto start1 = high_resolution_clock::now();
	if(!printNew()) return -1;
	auto stop1 = high_resolution_clock::now();
	auto duration1 = duration_cast<microseconds>(stop1 - start1);
	cout    << "\\n took  : "<< duration1.count()
		    << " microseconds." << '\n'; // MICROseconds, not milli!
	logFile << "\\n took:   "<< duration1.count()
		    << " microseconds." << '\n';
	
	// Test for printNew() function
	auto start2 = high_resolution_clock::now();
	if(!printEnd()) return -1;
	auto stop2 = high_resolution_clock::now();
	auto duration2 = duration_cast<microseconds>(stop2 - start2);
	cout    << "endl took: " << duration2.count()
		    << " microseconds." << endl;
	logFile << "endl took: " << duration2.count()
		    << " microseconds." << endl << endl;
    
    cout    << "This means \\n was " << setprecision(2) << std::fixed
            <<  static_cast<double>(duration2.count()) / duration1.count()
            << " times faster than endl.\n\n";
    
    logFile << "This means \\n was " << setprecision(2) << std::fixed
            <<  static_cast<double>(duration2.count()) / duration1.count()
            << " times faster than endl.\n\n";
	
	return 0;
}

bool printNew() {
	ofstream oFile(file1);
	if (!oFile) {
		cerr << "Could not write file." << '\n';
		return false;
	}
	for (int i = 0; i < 1000; i++)
		oFile << "Hello world!\n";
	oFile.close();
    std::remove(file1);
	return true;
}

bool printEnd() {
	ofstream oFile(file2);
	if (!oFile) {
		cerr << "Could not write file." << endl;
		return false;
	}
	for (int i = 0; i < 1000; i++)
		oFile << "Hello world!" << endl;
	oFile.close();
    std::remove(file2);
	return true;
}
