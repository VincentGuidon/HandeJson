#include <iostream>

#include "HandleJson.h"
#include "AllDialogues.h"
#include "JsonSerializer.h"
#include "ReadFile.h"

int main(int argc, char **argv)
{
	//TODO refaire ReadFile
	ReadFile rd("PNJ1.json");
	std::string allContent = rd.getFile();

	AllDialogues	allDialogues;
	std::string		blabla = "";
	CJsonSerializer::Deserialize(&allDialogues, allContent);

	std::string output;
	CJsonSerializer::Serialize(&allDialogues, output);


	std::cout << "Result :\n" << output << std::endl;

/*	HandleJson testClass;

	testClass.init();
	CJsonSerializer::Deserialize(&testClass, allContent);

	std::cout << "Content file Input\n" << allContent << std::endl << std::endl;
	//testClass.dispAll();
	std::string output;
	CJsonSerializer::Serialize(&testClass, output);

	std::cout << "testClass Serialized Output\n" << output << std::endl;
	*/
	return 0;
}

//	std::string input = "{ \"Handle2\" : {\"testintA\" : 48, \"teststringA\" : 5}, \"testintA\" : 42, \"testfloatA\" : 3.14159, \"teststringA\" : \"foo\", \"testboolA\" : true, \"testVector\" : [\"marche\",\"stp\"], \"stp\" : \"slt\"}\n";
