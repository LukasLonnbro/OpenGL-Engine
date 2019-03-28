#pragma once

#include "abstractEntity.h"

#include <vector>





class entityController
{
public:
	entityController();
	~entityController();

	inline const std::vector<abstractEntity*> * getEntities() const { return &m_Entities; };
	void update();
private: 	
	std::vector<abstractEntity*> m_Entities;
};

