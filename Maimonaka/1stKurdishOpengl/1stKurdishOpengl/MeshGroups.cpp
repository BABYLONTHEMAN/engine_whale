#include "MeshGroups.h"
#include <iostream>



////////RenderModel
void MeshGroups::RenderModel()
{
	for (size_t i = 0; i < meshList.size(); i++)
	{
		unsigned int shtIndex = meshToTex[i];
		if (shtIndex < textureList.size() && textureList[shtIndex])
		{
			textureList[shtIndex]->useTexture();
		}
		meshList[i]->RenderMesh();
	}
}
////////

//<for terrain>
void MeshGroups::RenderTerrain(const std::string& heightMapFilename, std::vector<float>& terrain) {
	int width, height, channels;

	// Load the heightmap using stb_image, this time inside the function where we can handle it more predictably.
	unsigned char* heightMap = stbi_load(heightMapFilename.c_str(), &width, &height, &channels, 0);

	if (!heightMap) {
		std::cerr << "Failed to load heightmap." << std::endl;
		return;
	}

	if (width != TERRAIN_WIDTH || height != TERRAIN_HEIGHT) {
		std::cerr << "Heightmap dimensions do not match terrain." << std::endl;
		stbi_image_free(heightMap);
		return;
	}
	//Mesh *terrainMesh;

	//terrainMesh->getVertices();

	// Process heightmap data to populate the terrain array and create vertices.
	// Assuming vertices is a globally accessible container; otherwise, pass it as a parameter.
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			int index = (i * width + j) * channels; // Indexing into heightmap data.
			terrain[i * width + j] = (float)heightMap[index] / 255.0f; // Normalized height value.

			// Create vertex for each point, Y is up, scale height value if necessary.
			vertices.push_back(glm::vec3(j, terrain[i * width + j], i));
		}
	}
	for (size_t i = 0; i < meshList.size(); i++)
	{
		unsigned int shtIndex = meshToTex[i];
		if (shtIndex < textureList.size() && textureList[shtIndex])
		{
			textureList[shtIndex]->useTexture();
		}
		meshList[i]->RenderMesh();
	}
	// Free the heightmap image data after we are done processing.
	stbi_image_free(heightMap);
}

// </for terrain>
/////////////////////////////////////////////////////****************************************
//LoadModel
/////////////////////////////////////////////////////****************************************
void MeshGroups::LoadModel(const std::string & filename)
{
	Assimp::Importer importer;
	const aiScene *scene = importer.ReadFile(filename, aiProcess_Triangulate | aiProcess_FlipUVs |
		aiProcess_GenSmoothNormals | aiProcess_JoinIdenticalVertices);

	if (!scene)
	{
		printf("scene or Model is failed to Load : %s",filename,importer.GetErrorString());
		return;
	}

	LoadNode(scene->mRootNode,scene);
	LoadSht(scene);
}
//....................
/////////////////////////////////////////////////////****************************************
//LoadNode
/////////////////////////////////////////////////////****************************************
void MeshGroups::LoadNode(aiNode * node, const aiScene * scene)
{
	for (size_t i = 0; i < node->mNumMeshes; i++)
	{
		LoadMesh(scene->mMeshes[node->mMeshes[i]], scene);
	}
	/////
	for (size_t i = 0; i < node->mNumChildren; i++)
	{
		LoadNode(node->mChildren[i], scene);
	}
}
/////////////////////////////////////////////////////****************************************
//LoadMesh
/////////////////////////////////////////////////////****************************************
void MeshGroups::LoadMesh(aiMesh * mesh, const aiScene * scene)
{


	// Check for null pointers immediately after entering the function
	if (!mesh || !scene) {
		// Handle error, e.g., log an error message
		std::cerr << "Received null pointer for mesh or scene." << std::endl;
		return;
	}


	std::vector<GLfloat> vertices;
	std::vector<unsigned int> indices;
	
	for (size_t i = 0; i < mesh->mNumVertices; i++)
	{
		vertices.insert(vertices.end(), { mesh->mVertices[i].x,mesh->mVertices[i].y,mesh->mVertices[i].z });
		if (mesh->mTextureCoords[0])
		{
			vertices.insert(vertices.end(), { mesh->mTextureCoords[0][i].x,mesh->mTextureCoords[0][i].y});
		}
		else
		{
			vertices.insert(vertices.end(), { 0.0f,0.0f });
		}
		vertices.insert(vertices.end(), { -mesh->mNormals[i].x, -mesh->mNormals[i].y, -mesh->mNormals[i].z }); // instead of Negative sign -
	}																									//you can  do this ... put - 
																											// in Frag shader ... like -normalize(direction)),0.0f);
		for (size_t i = 0; i < mesh->mNumFaces; i++)
		{
			aiFace face = mesh->mFaces[i];
			for (size_t j = 0; j < face.mNumIndices; j++)
			{
				indices.push_back(face.mIndices[j]);
			}
		}
	
		Mesh* newMesh = new Mesh();
		newMesh->createMesh(&vertices[0], &indices[0], vertices.size(), indices.size());
		meshList.push_back(newMesh);
		meshToTex.push_back(mesh->mMaterialIndex);
	
}
/////////////////////////////////////////////////////****************************************
//LoadSht
void MeshGroups::LoadSht(const aiScene * scene)

{
	textureList.resize(scene->mNumMaterials);

	for (size_t i = 0; i < scene->mNumMaterials; i++)
	{
		aiMaterial* material = scene->mMaterials[i];

		textureList[i] = nullptr;

		if (material->GetTextureCount(aiTextureType_DIFFUSE))
		{
			aiString path;
			if (material->GetTexture(aiTextureType_DIFFUSE, 0, &path) == AI_SUCCESS)
			{
				int idx = std::string(path.data).rfind("\\");
				std::string filename = std::string(path.data).substr(idx + 1);

				std::string texPath = std::string("Textures/") + filename;

				textureList[i] = new Texture(texPath.c_str());

				if (!textureList[i]->LoadTexture())
				{
					printf("Failed to load texture at: %s\n", texPath);
					delete textureList[i];
					textureList[i] = nullptr;
				}
			}
		}

		if (!textureList[i])
		{
			textureList[i] = new Texture("Textures/plain.png");
			textureList[i]->LoadTextureA();
		}
	}
}

//{
//	textureList.resize(scene->mNumMaterials);
//
//	for (size_t i = 0; i < scene->mNumMaterials; i++)
//	{
//		aiMaterial* sht = scene->mMaterials[i];
//
//		textureList[i] = nullptr; //it means Null Pointer
//
//		if (sht->GetTextureCount(aiTextureType_DIFFUSE))
//		{
//			aiString path;
//			if (sht->GetTexture(aiTextureType_DIFFUSE, 0, &path) == AI_SUCCESS)
//			{
//				int idx = std::string(path.data).rfind("\\"); //back slash is ESCAPE character so 2 of them means escape twice 
//				std::string filename = std::string(path.data).substr(idx + 1);
//
//				//******************************************
//				std::string texPath1 = std::string("Textures/") + filename;
//				std::string texPath2 = std::string("Textures/Resources/Models") + filename;
//				//textureList[i] = new Texture(texPath.c_str());
//
//
//				// Attempt to load texture from the first path
//				textureList[i] = new Texture(texPath2.c_str());
//				if (textureList[i]) {
//					std::cout << "Texture loaded successfully from " << texPath1 << std::endl;
//
//
//
//					std::cout << "Error: texture not found in either " << texPath1 << " or " << texPath2 << std::endl;
//
//
//					delete textureList[i];
//					textureList[i] = nullptr;
//
//					//***************************************
//					//if TextureA alpha stuff is failed or not .....
//					/*if (!textureList[i]->LoadTexture())
//					{
//						printf("Failed to load texture ... %s\n", texPath1);
//
//						delete textureList[i];
//						textureList[i] = nullptr;
//					}*/
//					if (!textureList[i])
//					{
//						textureList[i] = new Texture(texPath2.c_str());
//						textureList[i]->LoadTextureA();
//						//std::cout << "wasup somtn not workn";
//
//					}
//				}
//		
//		
//			
//		
//		
//	     }
//}

/////////////////////////////////////////////////////****************************************
// endOfLoadSht


//////// ClearModel
void MeshGroups::ClearModel()
{
	for (size_t i = 0; i < meshList.size(); i++)
	{
		if (meshList[i])
		{
			delete meshList[i];
			meshList[i] = nullptr;
		}
	}


	for (size_t i = 0; i < textureList.size(); i++)
	{
		if (textureList[i])
		{
			delete textureList[i];
			textureList[i] = nullptr;
		}
	}
}
	


MeshGroups::~MeshGroups()
{
}
