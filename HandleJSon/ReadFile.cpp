#include "ReadFile.h"

ReadFile::ReadFile(const std::string &fileName)
{
	std::string line;
	std::ifstream myfile(fileName);

	if (myfile.is_open())
	{
		while (std::getline(myfile, line))
		{
			_file += line;
		}
		myfile.close();
	}
	else 
		std::cout << "Unable to open file" << std::endl;

	/*
	    std::ifstream       file("Plop");
    if (file)
    {
	file.seekg(0, std::ios::end);
	std::streampos          length = file.tellg();
	file.seekg(0, std::ios::beg);

	std::vector<char>       buffer(length);
	file.read(&buffer[0], length);

	++ throw error
	*/
}


ReadFile::~ReadFile()
{
	_file = "";
}

std::string ReadFile::getFile(void)
{
	return _file;
}
