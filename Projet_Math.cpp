// Projet_Math.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	//B, C, Dq, Eq
	vector<string> vDir(2);
	vDir[0] = "B";
	vDir[1] = "C";

	for (int i(0); i < vDir.size(); ++i) {
		string dirname = "./BildeKrarup/" + vDir[i] + "/files.lst";
		
		ifstream mydir;
		mydir.open(dirname);
		if (!mydir.is_open()) cerr << "Can't open file " << dirname << '\n';
		else {
			ifstream myfile;
			string line = "", filename ="";

			while (getline(mydir, line)) {
				string fileLine = "";
				filename = "./BildeKrarup/" + vDir[i] + '/' + line;
				cout << "Filename = " << filename << '\n';
				myfile.open(filename);
				if (!myfile.is_open()) cerr << "Can't open file " << filename << '\n';
				
				while (getline(myfile, fileLine)) {
					cout << fileLine;
				}
				cout << '\n';
				myfile.close();
			}
			mydir.close();
		}
	}
	return 0;
}