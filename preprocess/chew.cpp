// chew.cpp: reduces 1000Genomes .vcf files to
// ChromosomeNumber Position Variant0 Variants #00 #0x #xx

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main () {
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	string line;

	while ( getline(cin, line) ) {
		if (line[0] == '#') continue;
		istringstream sin(line);

		vector<string> columns;
		string q;
		while (sin >> q) {
			columns.push_back(q);
		}

		cout << columns[0] << ' ' << columns[1] << ' ' << columns[3] << ' ' << columns[4] << ' ';

		int a[3] = {0,0,0};

		for (int i=9; i<columns.size(); ++i) {
			if (columns[i] == "0|0") ++a[0];
			else if(columns[i][0] == columns[i][2]) ++a[2];
			else ++a[1];
 		}
 		
 		cout << a[0] << ' ' << a[1] << ' ' << a[2];
 		cout << '\n';
	}

	return 0;
}