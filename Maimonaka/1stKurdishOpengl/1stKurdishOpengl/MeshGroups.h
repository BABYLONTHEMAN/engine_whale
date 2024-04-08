#pragma once
#include<vector>
#include<string>

#include<assimp\Importer.hpp>
#include<assimp\scene.h>
#include<assimp\postprocess.h>
#include "Mesh.h"
#include"Texture.h"

// At the top of your file or in a configuration header file
const float TERRAIN_WIDTH = 256;  // The number of vertices along the width of the terrain
const float TERRAIN_HEIGHT = 256; // The number of vertices along the height of the terrain




class MeshGroups
{
public:
	MeshGroups() :terrain(TERRAIN_WIDTH* TERRAIN_HEIGHT) {};

	void LoadModel(const std::string& filename);
	void RenderModel();
	void RenderTerrain(const std::string& heightMapFilename, std::vector<float>& terrain);
	void ClearModel();

	~MeshGroups();

public:
	 std::vector<float> terrain;
	// Getter method for terrain
	const std::vector<float>& getTerrain() const {
		return terrain;
	}
private:
	void LoadNode(aiNode *node, const aiScene *scene);
	void LoadMesh(aiMesh *mesh, const aiScene *scene);
	void LoadSht(const aiScene *scene);
	std::vector<Mesh*> meshList;
	std::vector<Texture*> textureList;
	std::vector<unsigned int> meshToTex;
	int width, height, channels;
	std::vector<glm::vec3> vertices;
	


};

