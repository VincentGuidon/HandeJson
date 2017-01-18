#include "HandleJson.h"
#include <iostream>

HandleJson::HandleJson()
{
}

HandleJson::~HandleJson()
{
}

void HandleJson::Serialize(Json::Value &root)
{
	/*Easy Param*/
	root["testintA"] = m_nTestInt;
	root["testfloatA"] = m_fTestFloat;
	root["teststringA"] = m_TestString;
	root["testboolA"] = m_bTestBool;
	SerializeVectorString(root, "testVector", m_vector);
	root["stp"] = m_stp;

	/*HandleJson2*/
	Json::Value branch;
	branch["testintA"] = m_Class.getcaca();
	branch["teststringA"] = m_Class.getcoucou();
	root["Handle2"] = branch;

	/*HandleJson*/
	if (m_handleJson != NULL)
		root["HandleJson"] = SerializeHandleJson(m_handleJson);
	else
		root["HandleJson"] = "NULL";

}

void HandleJson::Deserialize(Json::Value &root)
{
	/*Easy Param*/
	m_nTestInt = root.get("testintA", 0).asInt();
	m_fTestFloat = root.get("testfloatA", 0.0).asDouble();
	m_TestString = root.get("teststringA", "").asString();
	m_bTestBool = root.get("testboolA", false).asBool();
	DeserializeVectorString(root, "testVector", m_vector);
	//m_handleJson->Deserialize(root["testHandleJson"]);
	m_stp = root.get("stp", "").asString();

	/*TryHard*/
	Json::Value tmp;
	tmp = root["HandleJson"];
	if (!tmp.isString())
	{
		m_handleJson = DeserializeHandleJson(root);
	}
	else
		m_handleJson = NULL;


	/* HandleJson2*/
	HandleJson2 hj2;
	Json::Value branch;
	branch = root["Handle2"];
	hj2.setcaca(branch.get("testintA", 0).asInt());
	hj2.setcoucou(branch.get("teststringA", 0).asInt());
	m_Class = hj2;
}

void HandleJson::SerializeVectorString(Json::Value &root, const std::string key, std::vector<std::string> &stringVector)
{
	for (std::vector<std::string>::const_iterator memberIt = stringVector.begin() ; memberIt != stringVector.end() ; ++memberIt)
		root[key].append(*memberIt);
}

void HandleJson::DeserializeVectorString(Json::Value &root, const std::string key, std::vector<std::string> &stringVector)
{
	if (root[key].isArray())
	{
		for (uint32_t i = 0 ; i < root[key].size() ; i++)
			stringVector.push_back(root[key][i].asString());
	}
}
/*
void HandleJson::SerializeVectorString(Json::Value &root, const std::string key, std::vector<std::string> &stringVector)
{
	for (std::vector<std::string>::const_iterator memberIt = stringVector.begin(); memberIt != stringVector.end(); ++memberIt)
		root[key].append(*memberIt);
}
*/
void HandleJson::DeserializeVectorString(Json::Value &root, const std::string key, HandleJson *js)
{
	std::vector<std::string> stringVector;
	if (root[key].isArray())
	{
		for (uint32_t i = 0; i < root[key].size(); i++)
			stringVector.push_back(root[key][i].asString());
	}
	js->setTestVector(stringVector);
}

Json::Value HandleJson::SerializeHandleJson(HandleJson * hj)
{
	Json::Value br;
	br["testintA"] = hj->getTestInt();
	br["testfloatA"] = hj->getTestDouble();
	br["teststringA"] = hj->getTestString();
	br["testboolA"] = hj->getTestBool();
	SerializeVectorString(br, "testVector", hj->getTestVector());

	//HandleJson2
	Json::Value branch;
	branch["testintA"] = hj->getHandleJson2().getcaca();
	branch["teststringA"] = hj->getHandleJson2().getcoucou();
	br["Handle2"] = branch;
	
	if (hj->getHandleJson() == NULL)
		br["HandleJson"] = "NULL";
	else
		br["HandleJson"] = SerializeHandleJson(hj->getHandleJson());

	return br;
}

HandleJson *HandleJson::DeserializeHandleJson(Json::Value &root)
{
	Json::Value br;
	HandleJson *hj = new HandleJson();

	br = root["HandleJson"];

	hj->setTestInt(br.get("testintA", 0).asInt());
	hj->setTestDouble(br.get("testfloatA", 0.0).asDouble());
	hj->setTestString(br.get("teststringA", "").asString());
	hj->setTestBool(br.get("testboolA", false).asBool());
	DeserializeVectorString(br, "testVector", hj);
	hj->setStp(br.get("stp", "").asString());

	// HandleJson2
	HandleJson2 hj2;
	Json::Value branch;
	branch = br["Handle2"];
	hj2.setcaca(branch.get("testintA", 0).asInt());
	hj2.setcoucou(branch.get("teststringA", 0).asInt());
	hj->setHandleJson2(hj2);

	
	Json::Value tmp;
	tmp = br["HandleJson"];
	if (tmp.isString())
	{
		hj->setHandleJson(NULL);
	}
	else
	{
		hj->setHandleJson(DeserializeHandleJson(br));
	}
	//	return hj;
//
	return hj;
}

int HandleJson::getTestInt(void)
{
	return this->m_nTestInt;
}

double HandleJson::getTestDouble(void)
{
	return m_fTestFloat;
}

std::string HandleJson::getTestString(void)
{
	return m_TestString;
}

bool HandleJson::getTestBool(void)
{
	return m_bTestBool;
}

std::vector<std::string> HandleJson::getTestVector(void)
{
	return m_vector;
}

std::string HandleJson::getStp(void)
{
	return m_stp;
}

void HandleJson::setTestDouble(double d)
{
	m_fTestFloat = d;
}

void HandleJson::setTestInt(int i)
{
	m_nTestInt = i;
}

void HandleJson::setTestString(std::string str)
{
	m_TestString = str;
}

void HandleJson::setTestBool(bool b)
{
	m_bTestBool = b;
}

void HandleJson::setTestVector(std::vector<std::string> v)
{
	m_vector = v;
}

void HandleJson::setStp(std::string str)
{
	m_stp = str;
}

void HandleJson::setHandleJson2(HandleJson2 hj2)
{
	m_Class.setcaca(hj2.getcaca());
	m_Class.setcoucou(hj2.getcoucou());
}
void HandleJson::setHandleJson(HandleJson *hj)
{
	this->m_handleJson = hj;
}


void HandleJson::dispAll()
{
	std::cout << "\ntestintA : " << m_nTestInt
		<< "\ntestfloaA : " << m_fTestFloat
		<< "\nteststringA : " << m_TestString
		<< "\ntestboolA : " << m_bTestBool
		<< "\ntestVector : ";
	dispVector();

	std::cout << "\n stp : " << m_stp
		<< "\n Handle2 :" << "\n\ttestIntA : " << m_Class.getcaca()
		<< "\n\tteststringA : " << m_Class.getcoucou()
		<< "\nHandleJson : " << "\n\ttestintA : " << m_handleJson->getTestInt()
		<< "\n\ttestFloatA : " << m_handleJson->getTestDouble()
		<< "\n\ttestVector : ";
	m_handleJson->dispVector();
	std::cout << "\n\t Handle2 :" << "\n\t\t testIntA : " << m_handleJson->getHandleJson2().getcaca()
		<< "\n\t\t teststringA : " << m_handleJson->getHandleJson2().getcoucou() << std::endl;

}

void HandleJson::dispVector()
{
	for (std::vector<std::string>::const_iterator memberIt = m_vector.begin(); memberIt != m_vector.end(); ++memberIt)
	{
		std::cout << *memberIt << ", ";
	}
}

HandleJson *HandleJson::getHandleJson(void)
{
	return m_handleJson;
}

HandleJson2 HandleJson::getHandleJson2(void)
{
	return m_Class;
}


void HandleJson::init()
{
	m_handleJson = new HandleJson();
}
