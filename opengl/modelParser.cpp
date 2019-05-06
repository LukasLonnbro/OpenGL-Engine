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
std::vector<Mesh> modelParser::loadModel()
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
	processNode(scene->mRootNode, scene);

	return m_Meshes;
}

void modelParser::processNode(aiNode *node, const aiScene *scene)
{
	// process each mesh located at the current node
	for (unsigned int i = 0; i < node->mNumMeshes; i++)
	{
		// the node object only contains indices to index the actual objects in the scene. 
		// the scene contains all the data, node is just to keep stuff organized (like relations between nodes).
		aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
		processMesh(mesh, scene);
	}
	// after we've processed all of the meshes (if any) we then recursively process each of the children nodes
	for (unsigned int i = 0; i < node->mNumChildren; i++)
	{
		processNode(node->mChildren[i], scene);
	}

}

void modelParser::processMesh(const aiMesh * inMesh, const aiScene * scene) 
{
	std::vector<vertexData> vertices;
	std::vector<unsigned int> indices;

	for (unsigned int i = 0; i < inMesh->mNumVertices; i++)
	{
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

		for (unsigned int i = 0; i < inMesh->mNumFaces; i++)
		{
			aiFace face = inMesh->mFaces[i];
			for (unsigned int j = 0; j < face.mNumIndices; j++)
				indices.push_back(face.mIndices[j]);
		}

	m_Meshes.push_back(Mesh(vertices, indices));
}