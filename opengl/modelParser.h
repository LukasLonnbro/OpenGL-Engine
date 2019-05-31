#pragma once
#include "Mesh.h"

#include <assimp/scene.h>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>

#include <vector>

class modelParser
{
public:
	modelParser(const char* modelPath);
	~modelParser();

	void loadModel(std::vector<Mesh>* place_meshes_here);

private:
	const char* path;
	void processNode(aiNode * node, const aiScene * scene, std::vector<Mesh>* place_here);
	void processMesh(const aiMesh * mesh, const aiScene * scene, std::vector<Mesh>* place_here);
	std::vector<Mesh> m_Meshes;

};

