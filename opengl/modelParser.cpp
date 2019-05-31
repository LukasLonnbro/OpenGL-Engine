#include "modelParser.h"

#include <iostream>
// Reads raw input data from file and stores it in a dataModel. 

modelParser::modelParser(const char* modelPath) : path(modelPath)
{
}
modelParser::~modelParser()
{
}

// TODO : Should take an object of some sort and only read relevant data.
void modelParser::loadModel(std::vector<Mesh>* place_here)
{
	Assimp::Importer importer;
	const aiScene *scene = importer.ReadFile(
		path,
		aiProcess_Triangulate |
		aiProcess_FlipWindingOrder |
		aiProcess_FlipUVs |
		aiProcess_JoinIdenticalVertices |
		aiProcess_FindInvalidData |
		aiProcess_FindDegenerates |
		aiProcess_MakeLeftHanded |
		aiProcess_ValidateDataStructure
	);

	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
	{
		std::cout << "ASSIMP ERROR: " << importer.GetErrorString() << std::endl;
		int a;
		std::cin >> a;
	}
	processNode(scene->mRootNode, scene, place_here);
}

void modelParser::processNode(aiNode *node, const aiScene *scene, std::vector<Mesh>* place_here)
{
	for (unsigned int i = 0; i < node->mNumMeshes; i++)
	{
		aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
		processMesh(mesh, scene, place_here);
	}
	for (unsigned int i = 0; i < node->mNumChildren; i++)
	{
		processNode(node->mChildren[i], scene, place_here);
	}

}

void modelParser::processMesh(const aiMesh * inMesh, const aiScene * scene, std::vector<Mesh>* place_here)
{
	std::vector<vertexData> vertices;
	std::vector<unsigned int> indices;

	for (unsigned int i = 0; i < inMesh->mNumVertices; i++) {
		vertexData vertex;
		glm::vec3 vector;
		vector.x = inMesh->mVertices[i].x;
		vector.y = inMesh->mVertices[i].y;
		vector.z = inMesh->mVertices[i].z;
		vertex.position = vector;

		if (inMesh->HasNormals()) {
			vector.x = inMesh->mNormals[i].x;
			vector.y = inMesh->mNormals[i].y;
			vector.z = inMesh->mNormals[i].z;
			vertex.normal = vector;
		}

		vertices.push_back(vertex);
	}

	for (unsigned int i = 0; i < inMesh->mNumFaces; i++) {
		aiFace face = inMesh->mFaces[i];
		for (unsigned int j = 0; j < face.mNumIndices; j++)
			indices.push_back(face.mIndices[j]);
	}

	place_here->push_back(Mesh(vertices, indices));
}