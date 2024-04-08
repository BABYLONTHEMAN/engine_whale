#pragma once
#include<GL\glew.h>

class Sht
{
public:
	Sht();
	Sht(GLfloat sIntensity, GLfloat shine);
	void UseSht(GLuint specularIntensityLocation, GLuint shininessLocation);
	~Sht();
private:
	GLfloat specularIntensity;
	GLfloat Shininess;
};

