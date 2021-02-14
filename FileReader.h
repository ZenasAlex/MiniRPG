#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "ofUtils.h"

class FileReader {
public:
	static vector<string> readFile(string fileName);
};
