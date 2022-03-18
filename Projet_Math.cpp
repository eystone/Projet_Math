// Projet_Math.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <ostream>

#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;

VI splitLineToInt(string str) {
	VI result;
	string current = "";
	for (int i = 0; i < str.size(); i++) {
		if (isblank(str[i])) {
			if (current != "") {
				result.push_back(stoi(current));
				current = "";
			}
			continue;
		}
		else {
			current += str[i];
		}
	}
	if (current.size() != 0)
		result.push_back(stoi(current));
	return result;
}

pair<int, int> minimum(VI column) {
	int actualMin = column[0];
	int indMin = 0;
	for (int i = 1; i < column.size(); ++i) {
		if (actualMin > column[i]) {
			actualMin = column[i];
			indMin = i;
		}
	}
	return make_pair(indMin, actualMin);
}

VI removeDouble(VI VInt) {
	VI result;
	sort(VInt.begin(), VInt.end());
	VInt.erase(unique(VInt.begin(), VInt.end()), VInt.end());

	for (auto it = VInt.cbegin(); it != VInt.cend(); ++it) {
		// cout << *it << ' ';
		result.push_back(*it);
	}
	return result;
}

int Exo2(vector<string> file, int NbCol, int NbLine) {
	VVI result;
	VI indexUse;
	VI Vcol;
	pair<int, int> pIndVal;
	int sum = 0;

	for (int i(0); i < file.size(); ++i) {
		result.push_back(splitLineToInt(file[i]));
	}

	for (int i = 2; i < NbCol; ++i) {
		Vcol.clear();
		for (int j = 0; j < NbLine; ++j) {
			Vcol.push_back(result[j][i]);
		}
		pIndVal = minimum(Vcol);
		sum += pIndVal.second;
		indexUse.push_back(pIndVal.first);
	}
	indexUse = removeDouble(indexUse);
	for (int i = 0; i < indexUse.size(); ++i) {
		sum += result[indexUse[i]][1];
	}
	return sum;
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
			vector<string> strFile;
			string strLine = "";
			filename = DirName + '/' + line;
			cout << "Filename = " << filename << '\n';
			int result = 0;
			int nbLin = 0;
			int nbCol = 0;

			//open each file
			myfile.open(filename);
			if (!myfile.is_open()) {
				cerr << "Can't open file " << filename << '\n';
				return 0;
			}

			//Get number of line and col
			for (int i(0); i < 2; ++i) getline(myfile, strLine);
			nbLin = splitLineToInt(strLine)[0];
			nbCol = splitLineToInt(strLine)[1];

			//read file
			while (getline(myfile, strLine)) {
				strFile.push_back(strLine);
			}
			//Make calcul + save results
			result = Exo2(strFile, nbCol, nbLin);
			outFile << filename << " result :" << result << '\n';

			myfile.close();
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