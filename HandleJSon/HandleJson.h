#pragma once

#include <vector>
#include "IJsonSerializable.h"
#include "HandleJson2.h"

class HandleJson : public IJsonSerializable
{
public:
	HandleJson(void);
	virtual ~HandleJson(void);
	virtual void Serialize(Json::Value &root);
	virtual void Deserialize(Json::Value &root);

	void SerializeVectorString(Json::Value &root, const std::string key, std::vector<std::string> &stringVector);
	void DeserializeVectorString(Json::Value &root, const std::string key, std::vector<std::string> &stringVector);
	void HandleJson::DeserializeVectorString(Json::Value &root, const std::string key, HandleJson *js);
	Json::Value	SerializeHandleJson(HandleJson *hj);
	HandleJson	*DeserializeHandleJson(Json::Value &root);

private:
	int           m_nTestInt;
	double        m_fTestFloat;
	std::string   m_TestString;
	bool          m_bTestBool;
	std::vector<std::string> m_vector;
	std::string		m_stp;
	HandleJson		*m_handleJson;
	HandleJson2		m_Class;

public:
	int				getTestInt(void);
	double			getTestDouble(void);
	std::string		getTestString(void);
	bool			getTestBool(void);
	std::vector<std::string>	getTestVector(void);
	std::string		getStp(void);
	HandleJson2		getHandleJson2(void);


	void			setTestInt(int i);
	void			setTestDouble(double d);
	void			setTestString(std::string str);
	void			setTestBool(bool b);
	void			setTestVector(std::vector<std::string> v);
	void			setStp(std::string str);
	void			setHandleJson2(HandleJson2 hj2);
	void			setHandleJson(HandleJson *hj);

	void			dispAll();
	void			dispVector();

	HandleJson		*getHandleJson(void);
	void			init();
};

