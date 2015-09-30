// block.cpp: removes rows with too few variants
// usage: block THRESHOLD
// keep if #Variants >= THRESHOLD * NPEOPLE

#define NPEOPLE 2504

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main (int argc, char* argv[]) {
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	if (argc != 2) {
		cerr << "Usage: block THRESHOLD\n";
	}

	double THRESHOLD = stod(string(argv[1]));

	cerr << "Threshold: " << THRESHOLD << '\n';

	string line;
	int lineNum = 0, pass = 0;

	while ( getline(cin, line) ) {
		if (line[0] == '#') continue;
		istringstream sin(line);

		vector<string> columns;
		string q;
		while (sin >> q) {
			columns.push_back(q);
		}

		int var = 0;

		for (int i=9; i<columns.size(); ++i) {
			if (columns[i] != "0|0") ++var;
 		}

 		if (var > THRESHOLD * NPEOPLE){ cout << line << '\n'; ++pass; }

 		++lineNum;
 		if (lineNum % 1000 == 0) {
 			cerr << lineNum << " alleles processed, " << pass << " passed\n";
 		}
	}

	return 0;
}