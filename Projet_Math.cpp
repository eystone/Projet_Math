// Projet_Math.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.

#include <iostream>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <ostream>
#include <vector>
#include <string>

using namespace std;

vector<string> splitString(string str) {
	vector<string> result;
	string current = "";
	for (int i = 1; i < str.size(); i++) {
		if (isblank(str[i])) {
			result.push_back(current);
			current = "";
		}
		else {
			current += str[i];
		}
	}
	if (current.size() != 0)
		result.push_back(current);
	return result;
}

int minimum(vector<string> range) {
	int actual = stoi(range[2]);
	for (int i = 3; i < range.size(); ++i) {
		actual = min(actual, stoi(range[i]));
	}
	return actual;
}

int Exo2(string fileLine) {
	int Line1 = 0;
	vector<string> result;
	result = splitString(fileLine);
	Line1 = stoi(result[1]);
	return Line1 + minimum(result);
}

int readFiles(string DirName) {
	string dirname = DirName + "/files.lst";
	
	//Open output file
	ofstream outFile;
	outFile.open("./output.txt", ofstream::app);
	if (!outFile.is_open()) {
		cerr << "Can't open file output.txt";
		return 0;
	}

	//open dir file to get filename
	ifstream mydir;
	mydir.open(dirname);
	if (!mydir.is_open()) {
		cerr << "Can't open file " << dirname << '\n';
		return 0;
	}
	else {
		ifstream myfile;
		string line = "", filename = "";

		//for each file
		while (getline(mydir, line)) {
			string strLine = "";
			filename = DirName + '/' + line;
			cout << "Filename = " << filename << '\n';
			int result(0);

			//open each file
			myfile.open(filename);
			if (!myfile.is_open()) {
				cerr << "Can't open file " << filename << '\n';
				return 0;
			}

			//make the sum of each file
			for (int i(0); i < 2; ++i) getline(myfile, strLine);
			while (getline(myfile, strLine)) {
				result += Exo2(strLine);
			}

			myfile.close();
			outFile << filename << " result :" << result << '\n';
		}
		mydir.close();
		outFile.close();
	}
	return 1;
}

int getBildeKrarup() {
	//B, C, Dq, Eq
	vector<string> vDir(0);
	vDir.push_back("B");
	vDir.push_back("C");
	vDir.push_back("Dq");
	vDir.push_back("Eq");

	for (int i(0); i < vDir.size(); i++) {
		if (vDir[i] == "Dq" || vDir[i] == "Eq") {
			for (int j(1); j <= 10; j++) {
				string dirname = "./BildeKrarup/" + vDir[i] + "/" + to_string(j);
				if (!readFiles(dirname)) {
					cerr << "Can't read files " + dirname +'\n';
					return 0;
				}
			}
		}
		else if (!readFiles("./BildeKrarup/" + vDir[i])) {
			cerr << "Can't read files ./BildeKrarup/" + vDir[i]+'\n';
			return 0;
		}
	}
	return 1;
}

int main() {
	if (!getBildeKrarup()) {
		cerr << "Can't get Bilde Krarup Datas";
	}
	return 0;
}