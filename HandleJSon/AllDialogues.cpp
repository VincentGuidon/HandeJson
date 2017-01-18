#include "AllDialogues.h"

AllDialogues::AllDialogues() : _isParse(false)
{
}


AllDialogues::~AllDialogues()
{
}

void AllDialogues::Serialize(Json::Value &root)
{
/*	root["test"] = _test;
	SerializeVectorString(root, "allDialogues", _allVector);

	SerializeDialogue(_dialogue, root["dialogue"]);*/
	SerializeVectorDialogue(root, "allDialogues", _allDialogues);
}



void AllDialogues::SerializeVectorString(Json::Value &root, const std::string &key, const std::vector<std::string> &stringVector)
{
	for (std::vector<std::string>::const_iterator memberIt = stringVector.begin();
		memberIt != stringVector.end(); ++memberIt)
	{
		root[key].append(*memberIt);
	}
}

void AllDialogues::SerializeVectorDialogue(Json::Value &root, const std::string &key, const std::vector<Dialogue> &VectorDialogue)
{
	Json::Value appendDialogue;

	for (std::vector<Dialogue>::const_iterator memberIt = VectorDialogue.begin(); memberIt != VectorDialogue.end(); ++memberIt)
	{
		SerializeDialogue(*memberIt, appendDialogue["allDialogues"]);
		root[key].append(appendDialogue);
	}
}

void	AllDialogues::SerializeDialogue(const Dialogue &dial, Json::Value &branch)
{
	branch["id"] = dial._id;
	SerializeVarDialogue(dial._dial1, branch["containerDialogue1"]);
	SerializeVarDialogue(dial._dial2, branch["containerDialogue2"]);
	SerializeVarDialogue(dial._dial3, branch["containerDialogue3"]);
	SerializeVarDialogue(dial._dial4, branch["containerDialogue4"]);
}

void AllDialogues::SerializeVarDialogue(const Dialogue::VarDialogue &dial, Json::Value &branch)
{
	branch["dialogue"] = dial._dialogue;
	branch["pathSound"] = dial._pathSound;
	branch["timerSound"] = dial._timerSound;
	branch["influence"] = dial._influence;
	branch["next"] = dial._next;
}


void AllDialogues::Deserialize(Json::Value &root)
{
	DeserializeVectorDialogue(root, "allDialogues", _allDialogues);
}

void AllDialogues::DeserializeVectorString(const Json::Value &root, const std::string &key, std::vector<std::string> &stringVector)
{
	if (root[key].isArray())
	{
		for (uint32_t i = 0; i < root[key].size(); i++)
			stringVector.push_back(root[key][i].asString());
	}
}

void AllDialogues::DeserializeVectorDialogue(const Json::Value &root, const std::string &key, std::vector<Dialogue> &vectorDialogue)
{
	Dialogue dial;

	if (root[key].isArray())
	{
		for (uint32_t i = 0; i < root[key].size(); i++)
		{
			DeserializeDialogue(root[key][i], dial);
			vectorDialogue.push_back(dial);
		}
	}
}

void AllDialogues::DeserializeDialogue(const Json::Value &branch, AllDialogues::Dialogue &dial)
{
	dial._id = branch.get("id", "").asString();
	DeserializeVarDialogue(branch["containerDialogue1"],  dial._dial1);
	DeserializeVarDialogue(branch["containerDialogue2"], dial._dial2);
	DeserializeVarDialogue(branch["containerDialogue3"], dial._dial3);
	DeserializeVarDialogue(branch["containerDialogue4"], dial._dial4);
}

void AllDialogues::DeserializeVarDialogue(const Json::Value &branch, Dialogue::VarDialogue &dial)
{
	dial._dialogue = branch.get("dialogue", "").asString();
	dial._pathSound = branch.get("pathSound", "").asString();
	dial._timerSound = branch.get("timerSound", "").asString();
	dial._influence = branch.get("influence", "").asInt();
	dial._next = branch.get("next", "").asString();
}

void AllDialogues::FindByIdDialogue(const std::string & id, Dialogue &dialogue)
{
	for (std::vector<Dialogue>::const_iterator memberIt = _allDialogues.begin(); memberIt != _allDialogues.end(); ++memberIt)
	{
		if ((*memberIt)._id == id)
		{
			dialogue = (*memberIt);
		}
	}

}


bool AllDialogues::isParse(void)
{
	return _isParse;
}

