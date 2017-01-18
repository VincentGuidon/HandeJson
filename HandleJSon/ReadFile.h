#pragma once

#include <iostream>
#include <fstream>
#include  <string>

class ReadFile
{
public:
	ReadFile(const std::string &fileName);
	~ReadFile();

	std::string getFile(void);

private:
	std::string	_file;
};

