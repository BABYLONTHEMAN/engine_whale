#include "Mesh.h"
#include <iostream>
//#include "Window.h"
//#include "Texture.h"
#include <cstddef>  // for offsetof


Mesh::Mesh()
{
	VAO =0;
	VBO = 0;
	IBO = 0;
	indexCount = 0;

}
 //redefititiony makarawa
//struct Vertex {
//	glm::vec3 Position;
//	glm::vec3 Normal;
//	glm::vec2 TexCoords;
//	glm::vec3 Tangent;
//	// No virtual functions or other complex features.
//};
	// Create mesh using given vertex and index data
	void Mesh::createMesh(const GLfloat * vertices, const unsigned int* indices, unsigned int numOfVertices, unsigned int numOfIndices) {
		// Save the number of indices for rendering later
		indexCount = numOfIndices;

		// Generate and bind vertex array object (VAO)
		glGenVertexArrays(1, &VAO); 
		glBindVertexArray(VAO); 

		// Generate and bind index buffer object (IBO)
		glGenBuffers(1, &IBO); 
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO); 
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * numOfIndices, indices, GL_STATIC_DRAW); 

		// Generate and bind vertex buffer object (VBO)
		glGenBuffers(1, &VBO); 
		glBindBuffer(GL_ARRAY_BUFFER, VBO); 
		/*glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * numOfVertices * 8, vertices, GL_STATIC_DRAW); */
		if (vertices != nullptr) { 
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * numOfVertices, vertices, GL_STATIC_DRAW); 
		}
		else {
			// handle null pointer case
			// for example, print an error message and return
			std::cerr << "Error: vertices pointer is null" << std::endl; 
			return; 
		}

		//VBO for terrainFlat
		//glBindBuffer(GL_ARRAY_BUFFER, VBO);
		//glBufferData(GL_ARRAY_BUFFER, numOfVertices * sizeof(Vertex), vertices, GL_STATIC_DRAW);

		//</VBO for terrainFlat


		// Set vertex attribute pointers
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 8, 0); 
		glEnableVertexAttribArray(0); 
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 8, (void*)(sizeof(GLfloat) * 3)); 
		glEnableVertexAttribArray(1); 
		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 8, (void*)(sizeof(GLfloat) * 5)); 
		glEnableVertexAttribArray(2); 

		//attribpointer for terrainFlat
		glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Tangent)); 
		glEnableVertexAttribArray(3);
		glBindVertexArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		//UNBIND
	
		while ((error = glGetError()) != GL_NO_ERROR) {
			std::cerr << "OpenGL error: " << error << std::endl;
		}
		 
				storedVertices.clear();
				for (unsigned int i = 0; i < numOfVertices; i += 8) {  // Assuming 8 GLfloats per vertex 
					storedVertices.emplace_back(vertices[i], vertices[i + 1], vertices[i + 2]);
				}
}



void Mesh::RenderMesh()   //called glDrawElements 
{

	// Bind the texture before drawing the mesh
	glBindTexture(GL_TEXTURE_2D, this->textureID); //code0 

	glBindVertexArray(VAO);// bakary aheninawa Bindy akain hamw jare ka bakary ahenin
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO); //some times doesn't need to bind this IBO, this for some graphic card buggs
	glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);// wena akeshin 
	//When glDrawElements is called,it uses count sequential elements from an enabled array, starting at indices to construct a sequence of geometric primitives.
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); //unbind IBO ka eshman penama
	glBindVertexArray(0); //unbind VAO ka eshman penama 

	glBindTexture(GL_TEXTURE_2D, 0); //code0 // Unbind the texture when done (optional, but good practice)

}


void Mesh::clearMesh()
{
	if (IBO != 0)
	{
		glDeleteBuffers(1, &IBO);
		IBO = 0;
	}

	if (VBO != 0)
	{
		glDeleteBuffers(1, &VBO);
		VBO = 0;
	}

	if (VAO != 0)
	{
		glDeleteVertexArrays(1, &VAO);
		VAO = 0;

	}
	indexCount = 0;
}


Mesh::~Mesh()
{

	clearMesh();
}
