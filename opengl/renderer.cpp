#include "renderer.h"
#include "abstractLightRender.h"

#include <iostream>
#include <string>

#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>

#include "vertexArray.h"

renderer::renderer()
{
}
renderer::~renderer()
{
}

// Entities all inherit a renderObject. Renderobject are specific types of object that the renderer knows how to interpret data from
// thus allowing entities to contain all data regarding rendering without interfering with renderer data interpretation. 
// Pre game execution, all raw rendering data from the relevant renderObjects are loaded and sorted into arrays of data execution (these 
// calculations can be done before any run time rendering happens) to reduce necessary texture binds, sort by shaders etc. 
// During actual rendering, the renderer grabs all relevant renderObjects, and based of index provided in the preload phase, 
// renders entities in a certain order, keeping texture binds and buffer binds at a minimum.

// The renderer should only work with models that are in work memory. FOr smaller games essentially all models can be loaded into memory at once.
// For larger games with more complex models, this has to be done during in game loading phases.

// Keeping the renderdata and entities separate allows for a better workflow. The data for rendering will always be 
// represented in the same way by entities allowing for rendering optimizations without interfering with actual game logic.

// TLDR: Renderer grabs renderObjects, sorts bindable objects in a manner that reduces necessary binds, 
// and ships it off to the datamanager for data storage management.

void renderer::prep(const std::vector<abstractEntity>* entities)
{
	sortByRenderObject(entities);
}
void renderer::sortByRenderObject(const std::vector<abstractEntity>* entities)
{
	std::vector<const abstractEntity *> pointers(entities->size());
	unsigned short index = 0;

	for (int i = 0; i < entities->size(); i++)
		pointers[i] = &(*entities)[i];

	for (int i = 0; i < entities->size(); i++) {
		char cur = pointers[i]->getRenderObject()->getIdentifier();
		index = i + 1;
		for (int j = index; j < entities->size(); j++) {
			if (cur == pointers[j]->getRenderObject()->getIdentifier()) {
				const abstractEntity* temp = pointers[index];
				pointers[index] = pointers[j];
				pointers[j] = temp;
				index++;
			}
		}
	}
	for (int i = 0; i < entities->size(); i++) {
		std::cout << (*entities)[i].getRenderObject()->getIdentifier();
		std::cout << i << ": \n";
		(*entities)[i].getRenderObject()->coutMat(); 
		std::cout << " ";
		(*entities)[i].getRenderObject()->coutPos();
	}

	for (int i = 0; i < m_Lights->size(); i++) {
		(*m_Lights)[i].getRenderObject()->coutMat();
		(*m_Lights)[i].getRenderObject()->coutPos();
	}

	sortedEntities = pointers;
}

void coutMat(glm::mat4 mat) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << "| " << mat[i][j] << " ";
		}
		std::cout << "|\n";
	}
	std::cout << "\n";
}
void renderer::render()
{
	glClearColor(0.0, 0.0, 0.0, 1.0f);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	m_Camera.update_FIXED_CENTER();

	glm::vec3 viewDir = (*m_Camera.getDir());
	glm::vec3 viewPos = (*m_Camera.getPos());

	glm::mat4 viewMat = (*m_Camera.getViewMatrix());
	glm::mat4 projMat = (*m_Camera.getProjectionMatrix());
	
	//coutMat(viewMat);
	
	char currentShader = 0x0;
	for (unsigned int i = 0; i < sortedEntities.size(); i++) {
		//std::cout << "New shaders binds.\n";
		
		const abstractRenderObject* renderObject = sortedEntities[i]->getRenderObject();
		const abstractShader* shader = renderObject->getShader();
		
		if (shader->getID() != currentShader) {
			currentShader = shader->getID();
			shader->use();
			shader->setMat4("view", glm::value_ptr(viewMat));
			shader->setMat4("projection", glm::value_ptr(projMat));
			shader->setFloat3f("viewPos", glm::value_ptr(viewPos));

			int activeLights = m_Lights->size();
			shader->setInt("activeLights", activeLights);
			for (int i = 0; i < activeLights; i++) {
				const abstractLightRender* light = (*m_Lights)[i].getRenderObject();

				std::string name = "lights[" + std::to_string(i);
				shader->setFloat3f((name + "].ambient").c_str(), glm::value_ptr(light->getAmbient()));
				shader->setFloat3f((name + "].diffuse").c_str(), glm::value_ptr(light->getDiffuse()));
				shader->setFloat3f((name + "].specular").c_str(), glm::value_ptr(light->getSpecular()));
				shader->setFloat3f((name + "].position").c_str(), glm::value_ptr(light->getPosition()));
			}

			//This data should be collected from renderObject. Or uploaded in a texture?
			shader->setFloat3f("material.ambient", 1.0f, 0.5f, 0.31f);
			shader->setFloat3f("material.diffuse", 0.5, 0.5f, 0.31f);
			shader->setFloat3f("material.specular", 0.5f, 0.5f, 0.5f);
			shader->setFloat("material.shininess", 64.0f);
		}
	

		renderObject->renderMeshes();
	}
}