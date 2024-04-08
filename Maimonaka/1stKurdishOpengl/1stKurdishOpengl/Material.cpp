#include "Material.h"



Sht::Sht()
{
	specularIntensity = 0.0f;
	Shininess = 0.0f;
}
///////////
Sht::Sht(GLfloat sIntensity, GLfloat shine)
{
	specularIntensity = sIntensity;
	Shininess = shine;

}
/////////
void Sht::UseSht(GLuint specularIntensityLocation, GLuint shininessLocation)
{
	glUniform1f(specularIntensityLocation,specularIntensity);
	glUniform1f(shininessLocation,Shininess); // we need to make vector in Camera.h line 19 glm::vec3...

}
////////

Sht::~Sht()
{
}
