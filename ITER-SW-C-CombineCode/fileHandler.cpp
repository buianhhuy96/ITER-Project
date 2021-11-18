
#include "fileHandler.h"

std::vector<std::string> getDirectories(const std::string &s) {
	std::vector<std::string> r;
	for (auto &p : std::filesystem::recursive_directory_iterator(s))
		if (p.is_directory())
			r.push_back(p.path().string() + "/");
	return r;
}

std::vector<std::string> getFiles(const std::string &s) {
	std::vector<std::string> r;
	for (auto &p : std::filesystem::recursive_directory_iterator(s))
			r.push_back(p.path().string() + "/");
	return r;
}

std::string split(const std::string &s, char delim) {
  std::stringstream ss(s);
  std::string item;
  std::vector<std::string> elems;
  while (std::getline(ss, item, delim)) {
    elems.push_back(item);
    // elems.push_back(std::move(item)); // if C++11 (based on comment from @mchiasson)
  }
  return elems.back();
}

MATFile *readMatfile(std::string file){
	// declaring character array
	char *file_array = new char[file.length() + 1];

	// copying the contents of the
	// string to char array
	strcpy(file_array, file.c_str());

	// open MAT-file
	return matOpen(file_array, "r");
	
}
	
