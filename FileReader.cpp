#include "FileReader.h"

vector<string> FileReader::readFile(string path){
	path = "data/" + path;
	ifstream file(path);
	vector<string> lines;

	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			lines.push_back(line);
		}
	}
	else {
		cout << "Read erroe: " << path << endl;
	}

	return lines;
}
