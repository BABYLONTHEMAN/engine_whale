#pragma once

#include<GL/glew.h>
#include <vector>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include <glm/vec3.hpp> // glm::vec3

struct Vertex {
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
	glm::vec3 Tangent;

	Vertex(const glm::vec3& pos, const glm::vec3& normal, const glm::vec2& tex, const glm::vec3& tangent)
		: Position(pos), Normal(normal), TexCoords(tex), Tangent(tangent) {}
};

class Mesh
{
public:
	Mesh();

	void createMesh(const GLfloat* vertices, const unsigned int* indices, unsigned int numOfVertices, unsigned int numOfIndices);
	void RenderMesh();
	void clearMesh();

	// New method to get the vertices.
	const std::vector<glm::vec3>& getVertices() const { return storedVertices; }
	// Method to set the texture for the mesh.
	
	
	void setTexture(unsigned int textureID) { //code0
		this->textureID = textureID;
	}


	~Mesh();


private:
	GLuint VAO, VBO, IBO;
	GLsizei indexCount;
	GLenum error;

	unsigned int textureID;	//code0


	// New member to store the vertex data.
	std::vector<glm::vec3> storedVertices;
};
