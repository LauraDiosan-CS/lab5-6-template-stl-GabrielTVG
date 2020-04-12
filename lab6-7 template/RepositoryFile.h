#pragma once
#include "Aplicatie.h"
#include "Repository.h"

template <class T> class RepositoryFile : public Repository<Aplicatie>
{
private:
	const char* fileName;
public:
	RepositoryFile();
	RepositoryFile(const char* Name);
	void loadFile(const char* Name);
	void saveFile();
	~RepositoryFile();
};