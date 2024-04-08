#include "SpotLight.h"


//default constructor is example()::example()  :  example() 
SpotLight::SpotLight() : PointLight()
{
	direction = glm::vec3(0.0f, -1.0f, 0.0f);
	edge = 0.0f;
	procEdge = cos(glm::radians(edge));
}

SpotLight::SpotLight(GLfloat red, GLfloat green, GLfloat blue,
	GLfloat aIntensity, GLfloat dIntensity,
	GLfloat xPos, GLfloat yPos, GLfloat zPos,
	GLfloat xDir, GLfloat yDir, GLfloat zDir,
	GLfloat con, GLfloat lin, GLfloat exp,
	GLfloat edg) : PointLight(red, green, blue, 
/* point light base constructor*/ aIntensity,dIntensity,xPos,yPos,zPos,con,lin,exp)
{
	//direction = glm::vec3(xDir, yDir, zDir); // normalize it or rendering wrong colors 
	direction = glm::normalize(glm::vec3(xDir, yDir, zDir)); // 
	edge = edg;
	procEdge = cosf(glm::radians(edge));
}
void SpotLight::UseLight(GLuint ambientIntensityLocation, GLuint ambientColourLocation, 
						 GLuint diffuseIntensityLocation, GLuint positionlocation, GLuint directionLocation, 
						 GLuint constantLocation, GLuint linearlocation, GLuint exponentLocation,
					     GLuint edgeLocation)
{
	////////////////////// la PointLight.cpp yawa copypaste krawa
		glUniform1f(ambientIntensityLocation, ambientIntensity);
		glUniform3f(ambientColourLocation, colour.x, colour.y, colour.z);
		//glUniform3f(directionLocation, direction.x, direction.z, direction.z);
		glUniform1f(diffuseIntensityLocation, diffuseIntensity);
		glUniform3f(positionlocation, position.x, position.y, position.z);
		glUniform1f(constantLocation, constant);
		glUniform1f(linearlocation, linear);
		glUniform1f(exponentLocation, exponent);
		glUniform3f(directionLocation, direction.x, direction.y, direction.z);
		glUniform1f(edgeLocation, procEdge);
	//////////////////////////////////
	
}

void SpotLight::SetFlash(glm::vec3 pos, glm::vec3 dir)
{
	position = pos;
	direction = dir;
}
///////////////////////////////////////////////
SpotLight::~SpotLight()
{
}
