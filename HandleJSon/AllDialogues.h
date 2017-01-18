#pragma once

#include <vector>
#include "IJsonSerializable.h"

class AllDialogues : public IJsonSerializable
{
private :
	struct Dialogue
	{
	public:
		struct VarDialogue
		{
			std::string	_dialogue;
			std::string	_pathSound;
			std::string	_timerSound;

			/* set this var to 0 if not a dialogue of the player */
			int			_influence;
			std::string	_next;

			bool		_isEmpty;

			//Add IdQuest
		};

	public:
		std::string		_id;
		VarDialogue		_dial1;
		VarDialogue		_dial2;
		VarDialogue		_dial3;
		VarDialogue		_dial4;
	};

public:

	AllDialogues( void );
	virtual ~AllDialogues( void );

	virtual void	Serialize(Json::Value &root);
	virtual void	Deserialize(Json::Value &root);

	void			SerializeVectorString(Json::Value &root, const std::string &key, const std::vector<std::string> &stringVector);
	void			SerializeVectorDialogue(Json::Value &root, const std::string &key, const std::vector<Dialogue> &vectorDialogue);
	void			SerializeDialogue(const Dialogue &dial, Json::Value &branch);
	void			SerializeVarDialogue(const Dialogue::VarDialogue &dial, Json::Value &branch);

	void			DeserializeVectorString(const Json::Value &root, const std::string &key, std::vector<std::string> &stringVector);
	void			DeserializeVectorDialogue(const Json::Value &root, const std::string &key, std::vector<Dialogue> &vectorDialogue);
	void			DeserializeDialogue(const Json::Value &branch, Dialogue &dial);
	void			DeserializeVarDialogue(const Json::Value &branch, Dialogue::VarDialogue &dial);
//	Dialogue		&DeserializeDialogue(Json::Value &root);

private :

/*	std::string		_test;
	std::vector<std::string> _allVector;
	Dialogue		_dialogue;*/
	std::vector<Dialogue> _allDialogues;
	bool			_isParse;

public :

	bool			isParse( void );

};

