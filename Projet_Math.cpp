// Projet_Math.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void readFiles(string DirName) {
	string dirname = "./BildeKrarup/" + DirName + "/files.lst";

	ifstream mydir;
	mydir.open(dirname);
	if (!mydir.is_open()) cerr << "Can't open file " << dirname << '\n';
	else {
		ifstream myfile;
		string line = "", filename = "";

		while (getline(mydir, line)) {
			string fileLine = "";
			filename = "./BildeKrarup/" + DirName + '/' + line;
			cout << "Filename = " << filename << '\n';
			myfile.open(filename);
			if (!myfile.is_open()) {
				cerr << "Can't open file " << filename << '\n';
				return;
			}

			while (getline(myfile, fileLine)) {
				//cout << fileLine;
			}
			myfile.close();
		}
		mydir.close();
	}
	return;
}

int main() {
	//B, C, Dq, Eq
	vector<string> vDir(4);
	vDir[0] = "B";
	vDir[1] = "C";
	vDir[2] = "Dq";
	vDir[3] = "Eq";

	for (int i(0); i < vDir.size(); ++i) {
		if (vDir[i] == "Dq" || vDir[i] == "Eq") {
			for (int j(1); j <= 10; ++j) {
				string str = vDir[i] + "/" + to_string(j);
				readFiles(str);
			}
		}
		else {
			readFiles(vDir[i]);
		}
	}
	return 0;
}