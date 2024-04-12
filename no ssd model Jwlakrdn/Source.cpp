
//**************************************<>
//......
//************************************ </>
#define STB_IMAGE_IMPLEMENTATION
//#include"stb_image.h"
#include<stdio.h>
#include<Windows.h>
#include<string.h>
//#include<stdlib.h>
#include<cmath>
#include <cstdlib> // For rand() and srand()
#include<vector> //array list
#ifndef M_PI
#define M_PI    3.14159265358979323846264   /**< pi */
#endif
#include<GL/glew.h>
#include<GLFW/glfw3.h> //keys handle_events

#include<assimp\Importer.hpp>

//#include<glm/mat4x4.hpp> //rotATION TRANSLATION AND SCALE 
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include"CommonValues.h" //
#include "Window.h"
#include "Mesh.h"

#include "Camera.h"
#include "Texture.h"
#include "DirectionalLight.h"
#include"SpotLight.h"
#include "PointLight.h"
//#include "SpotLight.h"
#include "Material.h"
#include "MeshGroups.h"
#include<fstream>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <random>
#include "meshterrain.h"
//#include "gl.h"
#include "Shader2.h"
//#include"../GL/glut.h"
//rotate Angle and stuff...
bool direction = true;
bool sizeDirection = true;
bool sarawa = false;
bool swranawa = false;
bool gawra = false;
bool winFull = false;
bool printModelPositionOnce = true;// A flag to ensure printing occurs only once

//window dimensions 
//const GLint	WIDTH=800, HEIGHT = 600;
const float toRadians = 3.14159265f / 180.0f;
// Vertex Shader
float triOffset = 0.0f; // line 224 while ... 
float triMaxoffset = 0.7f;
float triIncrement = 0.0005f;

float curAngle = 0.0f;

//bool sizeDirection = true;
float curSize = 0.4f;
float maxSize = 0.8f;
float minSize = 0.1f;

////////////Camera stuff
//Random move model 4 stuff
float circleRadius = 0.1f;
float rotationSpeed = 0.005f;  // Adjust based on how fast you want the model to rotate
float angle = 0.0f;
const unsigned int NUM_PATCH_PTS = 4;
glm::vec3 mamaAkamStartPosition = glm::vec3(0.0f, 1.0f, 0.0f);
glm::vec3 mamaAkamCurrentPosition = mamaAkamStartPosition;

glm::vec3 animal_StartPosition = glm::vec3(0.0f, 1.f, 0.0f);
glm::vec3 animal_CurrentPosition = animal_StartPosition;

glm::vec3 marix_StartPosition = glm::vec3(0.0f, 1.01f, 0.0f);
glm::vec3 marix_CurrentPosition = animal_StartPosition;
//glm::vec3 *verticyobj1;
// For random movement:
float moveSpeed = 0.005f;  // Adjust based on how fast you want the model to move
glm::vec3 randomDirection = glm::normalize(glm::vec3(rand() % 100 + 50, 0.0f, rand() % 100 - 50));

//</Random move model 4 stuff
////////////deltaTime and stuff
//////////////////////////////*****************************************************************************************
Texture brick;
Texture kurd;
Texture fog;
Texture sand;
Texture shwsha;
Texture wenakay;
Texture Mars;
Texture atomImg;
Texture terraincode0;
Texture BlueWhaleTexture;
//Texture AkamAliImage;

Sht shinyMaterial;
Sht dullMaterial;

MeshGroups Trump;
MeshGroups BMW;
MeshGroups Chopper; //not using it for now .
MeshGroups cat;
MeshGroups atomModel;
MeshGroups AkamAliPc;
MeshGroups mamaAka;
MeshGroups	BlueWhale;

Mesh myMesh;

DirectionalLight mainLight;
PointLight pointLights[MAX_POINT_LIGHTS];
SpotLight spotLights[MAX_SPOT_LIGHTS];

GLfloat 	deltaTime = 0.0f;
GLfloat 	lastTime = 0.0f;

//**************<bo wenayterrainaka>
int width, height, channels;
// Load image data
unsigned char* imgData = stbi_load("Textures/Resources/Models/cat-texture.jpg", &width, &height, &channels, 0); //code0

//Line 1816 using modelInt to loop the modelPosition echo information 
int modelInt = 10;
//shader.h
class Shader
{
public:
	Shader();

	//this reads file and pass to compileShader(); 
	void createFromString(const char* vertexCode, const char* fragmentCode);
	//little bit code in shader here 40:21 vid clearn up code 
	void createFromFiles(const char* vertexLocation, const char* fragmentlocation);
	void Validate(); //Validate
	void setMat4(const std::string& name, const glm::mat4& mat) const;
	void LoadHeightmapTexture();
	std::string ReadFile(const char* fileLoc);
	void Shader::setInt(const std::string& name, int value) const;
	GLuint GetProjectionLocation();
	GLuint GetModelLocation();
	GLuint GetViewLocation();
	GLuint GetAmbientIntensityLocation();
	GLuint GetAmbientColourLocation();
	GLuint GetDiffuseIntensityLocation();
	GLuint GetDirectionLocation();
	GLuint GetSpecularIntensityLocation();
	GLuint GetShininessLocation();
	GLuint GetEyePositionLocation();
	GLuint GetSkyColourLocation(); //SKY
	GLuint GetvertexInStuff();//Terrain
	GLuint GetuniformterrainVerticesIDUNNOWTHISTHATf();
	//we add another function point light lecture 'NOTE: pass it as a pointer * to &mainLight address 
	void SetDirectionalLight(DirectionalLight* dLight);
	void SetPointLights(PointLight* pLight, unsigned int lightCount);
	void SetSpotLights(SpotLight* sLight, unsigned int lightCount);
	void useShader();
	void clearShader();

public:
	void RenderPass(glm::mat4 viewMatrix, glm::mat4 projectionMatrix);

	GLuint loadTexture(const char* filename); //for loading texture into shader. I mean 'terrains texture'

	~Shader();


private:
	int pointLightCount;
	int spotLightCount;



	GLuint shaderID, uniformProjection, uniformModel, uniformView, uniformEyePosition, uniformModel2,
		//uniformAmbientIntensity,uniformAmbientColour,uniformDiffuseIntensity,UniformDirection,
		uniformSpecularIntensity, uniformShininess, location_skyColour, vertexInStuff, uniformterrainVerticesIDUNNOWTHISTHAT;
	///Struct
	struct
	{
		GLuint uniformColour;
		GLuint uniformAmbientIntensity;
		GLuint uniformDiffuseIntensity;

		GLuint uniformDirection;
	} uniformDirectionalLight;

	////////End Struct
	GLuint uniformPointLightCount;
	////// another Struct

	struct
	{
		GLuint uniformColour;
		GLuint uniformAmbientIntensity;
		GLuint uniformDiffuseIntensity;

		GLuint uniformPosition;
		GLuint uniformConstant;
		GLuint uniformlinear;
		GLuint uniformExponent;
	} uniformPointLight[MAX_POINT_LIGHTS];
	///////
	GLuint uniformSpotLightCount;
	struct
	{
		GLuint uniformColour;
		GLuint uniformAmbientIntensity;
		GLuint uniformDiffuseIntensity;

		GLuint uniformPosition;
		GLuint uniformConstant;
		GLuint uniformlinear;
		GLuint uniformExponent;

		GLuint uniformDirection;
		GLuint uniformedge;

	} uniformSpotLight[MAX_SPOT_LIGHTS];

	void compileShader(const char* vertexCode, const char* fragmentCode);
	void AddShader(GLuint theProgram, const char* shaderCode, GLenum shaderType);
};


static const char* vShader = "Shaders/shader.vert";
// Fragment Shader
static const char* fShader = "Shaders/shader.frag";
std::vector<Shader>shaderList;

void createShaders() {
	Shader* shader1 = new Shader();
	shader1->createFromFiles(vShader, fShader);
	shaderList.push_back(*shader1);
}

//Camera.h
class Camera
{
private:
	// Variables to store previous mouse movement
	GLfloat lastX = 400, lastY = 300; // Set initial cursor position
	GLfloat mouseXOffset = 0, mouseYOffset = 0;
	const GLfloat sensitivity = 0.025f; // Adjust as needed
public:
	// Explicitly define assignment operator
	Camera& operator=(const Camera& other) {
		if (this != &other) {
			position = other.position;
			front = other.front;
			up = other.up;
			right = other.right;
			worldUp = other.worldUp;
			target = other.target;
			yaw = other.yaw;
			pitch = other.pitch;
			moveSpeed = other.moveSpeed;
			turnSpeed = other.turnSpeed;
			centerOfRotation = other.centerOfRotation;
			distanceFromCenter = other.distanceFromCenter;
			lastX = other.lastX;
			lastY = other.lastY;
			mouseXOffset = other.mouseXOffset;
			mouseYOffset = other.mouseYOffset;
			// Note: You may need to handle other member variables depending on your implementation
		}
		return *this;
	}
public:
	Camera();
	Camera(glm::vec3 startPosition, glm::vec3 startUp, GLfloat startYaw, GLfloat startPitch, GLfloat startMoveSpeed, GLfloat startTurnSpeed,
		glm::vec3 rotationCenter, glm::vec3 startDistance);
	//adding another function SetRotationCenter to call it to rotate from a point
	////////////////////////////////
	void keyControl(bool* keys, GLfloat deltaTime);
	void mouseControl(GLfloat Xchange, GLfloat Ychange);
	void SetRotationCenter(glm::vec3 newCenter);
	glm::vec3 getCameraPosition();
	glm::vec3 getCameraDirection();
	glm::mat4 calculateViewMatrix();
	glm::mat4 GetViewMatrix();

	glm::vec3 distanceFromCenter;
	glm::vec3 centerOfRotation;

	glm::vec3 getModelPosition(const glm::mat4& model) {
		return glm::vec3(model[3][0], model[3][1], model[3][2]);
	}
	glm::vec3 getModelPositionMarix(const glm::mat4& modelyMarix) {
		return glm::vec3(modelyMarix[3][0], modelyMarix[3][1], modelyMarix[3][2]);
	}
	glm::vec3 getModelPositionMam(const glm::mat4& modelyMam) { //adgust modelname to desired in case of not working!
		return glm::vec3(modelyMam[3][0], modelyMam[3][1], modelyMam[3][2]);
	}

	~Camera();

public:
	glm::vec3 position;
	glm::vec3 front;
	glm::vec3 up;
	glm::vec3 right;
	glm::vec3 worldUp;
	glm::vec3 target;


	GLfloat yaw;
	GLfloat pitch;

	GLfloat moveSpeed;
	GLfloat turnSpeed;
	void Update();
};

//////////////////////////////*****************************************************************************************
// Camera Cpp

Camera::Camera() {}

Camera::Camera(glm::vec3 startPosition, glm::vec3 startUp, GLfloat startYaw, GLfloat startPitch,
	GLfloat startMoveSpeed, GLfloat startTurnSpeed,
	glm::vec3 rotationCenter, glm::vec3 startDistance)
{
	position = startPosition;
	worldUp = startUp;
	yaw = startYaw;
	pitch = startPitch;
	front = glm::vec3(0.0f, 0.0f, -1.0f);
	moveSpeed = startMoveSpeed;
	turnSpeed = startTurnSpeed;

	//sensitivity = 1.0f * sensitivity; // Adjust as needed
	centerOfRotation = rotationCenter;
	distanceFromCenter = startDistance;

	Update();
}
/////////////

bool i = false; //while(true) {updateModelyMarix()...}
void Camera::keyControl(bool* keys, GLfloat deltaTime) {
	// Delta time is used to smooth movement
	GLfloat velocity = moveSpeed * deltaTime;

	glm::vec3 targetPosition = position; // Initialize target position

	if (keys[GLFW_KEY_W]) {
		targetPosition += front * velocity * 100.0f;
	}
	if (keys[GLFW_KEY_S]) {
		targetPosition -= front * velocity;
	}
	if (keys[GLFW_KEY_A]) {
		targetPosition -= right * velocity;
	}
	if (keys[GLFW_KEY_D]) {
		targetPosition += right * velocity;
	}
	//logics
	if (keys[GLFW_KEY_R]) //rotate 
	{
		sarawa = true;
	}
	if (keys[GLFW_KEY_F]) //reset rotate
	{
		sarawa = false;
	}

	if (keys[GLFW_KEY_T]) // 
	{
		gawra = true;
	}
	if (keys[GLFW_KEY_G]) //reset 
	{
		gawra = false;
	}

	if (keys[GLFW_KEY_J]) // 
	{
		winFull = true;
	}
	if (keys[GLFW_KEY_K]) //reset 
	{
		winFull = false;
	}
	if (keys[GLFW_KEY_Z]) //reset 
	{
	}
	if (keys[GLFW_KEY_Q]) // 
	{
		swranawa = true;
	}
	if (keys[GLFW_KEY_E]) //reset 
	{
		swranawa = false;
	}
	if (keys[GLFW_KEY_L]) //reset 
	{
		i = true;
	}
	if (keys[GLFW_KEY_K]) //reset 
	{
		i = false;
	}

	// Interpolate between current and target position for smoother movement
	position = glm::mix(position, targetPosition, 0.1f); // Adjust interpolation factor as needed

	// Update the target point based on the new position.
	target = position + front;
}


void Camera::mouseControl(GLfloat Xchange, GLfloat Ychange) {
	// Damping mouse movement
	Xchange *= sensitivity;
	Ychange *= sensitivity;

	yaw += Xchange;
	pitch += Ychange;

	// Clamp pitch to avoid flipping
	if (pitch > 89.0f) {
		pitch = 89.0f;
	}
	if (pitch < -89.0f) {
		pitch = -89.0f;
	}

	// Calculate the new front vector based on yaw and pitch.
	glm::vec3 newFront;
	newFront.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	newFront.y = sin(glm::radians(pitch));
	newFront.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	front = glm::normalize(newFront);

	// Update the target point based on the new front vector.
	target = position + front;
}



glm::mat4 Camera::calculateViewMatrix()
{

	if (swranawa)

		return glm::lookAt(position, centerOfRotation, up);
	else
		return glm::lookAt(position, position + front, up); //lookAt functioneka wata bnwara :)


}
/////////////////////////////////////

glm::mat4 Camera::GetViewMatrix()  //learnopengl method camera.h
{
	return glm::lookAt(position, position + front, up);
}
/////////////////////////////////////
///vec3 for shininess and stuff specular lighting 
glm::vec3 Camera::getCameraPosition()
{
	return position; // 
}
//////////////
glm::vec3 Camera::getCameraDirection()
{
	return glm::normalize(front);
}

//////////////
void Camera::Update() {
	// Calculate the new front vector based on yaw and pitch.
	glm::vec3 newFront;
	newFront.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	newFront.y = sin(glm::radians(pitch));
	newFront.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

	// Normalize the new front vector.
	front = glm::normalize(newFront);

	// Recalculate the right and up vectors based on the new front vector and world up vector.
	right = glm::normalize(glm::cross(front, worldUp));
	up = glm::normalize(glm::cross(right, front));

	// Calculate the new camera position based on the center of rotation.
	position = centerOfRotation - front * distanceFromCenter;

	// Update the target point based on the new front vector.
	target = position + front;
}


void Camera::SetRotationCenter(glm::vec3 newCenter)
{
	centerOfRotation = newCenter;
	//-camera.Update();
	// Rotate the camera around the center of rotation.

}
/*  setMat4 Method: This method takes a std::string (the name of the uniform in the shader) and
a glm::mat4 (the matrix to set). It uses glUniformMatrix4fv to update the value of the uniform
in the shader program. */
glm::vec3 getModelPosition(const glm::mat4& model) {
	return glm::vec3(model[3][0], model[3][1], model[3][2]);
}

void Shader::setMat4(const std::string& name, const glm::mat4& mat) const
{
	glUniformMatrix4fv(glGetUniformLocation(shaderID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

//		void Shader::setMat4(const std::string &name, const glm::mat4 &mat) const {
//		glUniformMatrix4fv(glGetUniformLocation(programID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
//		}
Camera::~Camera()
{
}



////////
Camera camera;
/////// 
//Skybox.h
class skyBox
{

public:
	skyBox();

	skyBox(std::vector<std::string> faceLocations);
	void DrawSkybox(glm::mat4 viewMatrix, glm::mat4 projectionMatrix);

	~skyBox();

public:
	//Mesh* veticeModelyYak;
	//Mesh* veticeModelyDw;

	Mesh* skyMesh;
	Shader* skyShader;


	GLuint uniformProjection, uniformView;
private:
	GLuint textureID;

};

// Shader.cpp
Shader::Shader()
{
	shaderID = 0;
	uniformModel = 0;
	uniformModel2 = 0;
	uniformProjection = 0;
	uniformterrainVerticesIDUNNOWTHISTHAT = 0;
	pointLightCount = 0;
	spotLightCount = 0;
}

void Shader::createFromString(const char* vertexCode, const char* fragmentCode)

{
	compileShader(vertexCode, fragmentCode);
}

void Shader::createFromFiles(const char* vertexLocation, const char* fragmentLocation)
{
	std::string vertexString = ReadFile(vertexLocation);
	std::string fragmentString = ReadFile(fragmentLocation);
	const char* vertexCode = vertexString.c_str();
	const char* fragmentCode = fragmentString.c_str();

	compileShader(vertexCode, fragmentCode);

}

std::string Shader::ReadFile(const char* fileloc)
{
	std::string content;
	std::ifstream fileStream(fileloc, std::ios::in);

	if (!fileStream.is_open()) {


		printf("Failed to read %s| File doesn not exist.", fileloc);
		return "";
	}
	std::string line = "";
	while (!fileStream.eof())
	{
		std::getline(fileStream, line);
		content.append(line + "\n");
	}
	fileStream.close();
	return content;
}
void Shader::Validate()
{
	GLint result = 0;
	GLchar eLog[1024] = { 0 };

	glValidateProgram(shaderID);
	glGetProgramiv(shaderID, GL_VALIDATE_STATUS, &result);
	if (!result)
	{
		glGetProgramInfoLog(shaderID, sizeof(eLog), NULL, eLog);
		printf("Error validating program: '%s'\n", eLog);
		return;
	}
}
void Shader::compileShader(const char* vertexCode, const char* fragmentCode)

{

	shaderID = glCreateProgram();
	if (!shaderID) {
		printf("error fragment creating ...");

		return;

	}


	AddShader(shaderID, vertexCode, GL_VERTEX_SHADER);
	AddShader(shaderID, fragmentCode, GL_FRAGMENT_SHADER);


	//chunk of code 27:30 

	GLint result = 0;
	GLchar eLog[1024] = { 0 };

	glLinkProgram(shaderID);
	glGetProgramiv(shaderID, GL_LINK_STATUS, &result);

	if (!result)
	{
		glGetProgramInfoLog(shaderID, sizeof(eLog), NULL, eLog);
		printf("Error Linking Program  %d shader: '%s ", eLog);
		return;

	}
	glValidateProgram(shaderID);
	glGetProgramiv(shaderID, GL_VALIDATE_STATUS, &result);

	if (!result)
	{
		glGetProgramInfoLog(shaderID, sizeof(eLog), NULL, eLog);
		printf("Error Validating Program  %d shader: '%s ", eLog);
		return;

	}
	//uniformModel = glGetUniformLocation(shader, "xMove");
	//vertexInStuff = glGetAttribLocation(shaderID, "heightmapTexture"); /*Ama bo terrain la bri 1518 chwnka natwanm accessy shaderId bkam laweya boya lerawa aykam*/ 
	vertexInStuff = glGetAttribLocation(shaderID, "terrainTexture"); /*Ama bo terrain la bri 1518 chwnka natwanm accessy shaderId bkam laweya boya lerawa aykam*/
	uniformterrainVerticesIDUNNOWTHISTHAT = glGetUniformLocation(shaderID, "terrainTexture");
	uniformProjection = glGetUniformLocation(shaderID, "projection"); //idy projection axata naw variably uniformProjection
	uniformModel = glGetUniformLocation(shaderID, "model"); //idy model axata naw variably uniformModel uniformProjection
	//idy model axata naw variably uniformModel uniformProjection
   //uniformModel2 =
	uniformView = glGetUniformLocation(shaderID, "view");
	uniformDirectionalLight.uniformColour = glGetUniformLocation(shaderID, "directionalLight.base.colour");
	uniformDirectionalLight.uniformAmbientIntensity = glGetUniformLocation(shaderID, "directionalLight.base.ambientIntensity");
	uniformDirectionalLight.uniformDirection = glGetUniformLocation(shaderID, "directionalLight.direction"); //no .base for direction
	uniformDirectionalLight.uniformDiffuseIntensity = glGetUniformLocation(shaderID, "directionalLight.base.diffuseIntensity");
	uniformSpecularIntensity = glGetUniformLocation(shaderID, "sht.specularIntensity");
	uniformShininess = glGetUniformLocation(shaderID, "sht.shininess");
	uniformEyePosition = glGetUniformLocation(shaderID, "eyePosition");
	uniformPointLightCount = glGetUniformLocation(shaderID, "pointLightCount");
	location_skyColour = glGetUniformLocation(shaderID, "skyColour"); //SKY

	for (size_t i = 0; i < MAX_POINT_LIGHTS; i++)       ///// these are all sets our uniform location values
	{
		char lockBuff[100] = { '\0' };
		snprintf(lockBuff, sizeof(lockBuff), "spotLights[%d].base.base.colour", i);
		uniformSpotLight[i].uniformColour = glGetUniformLocation(shaderID, lockBuff);
		snprintf(lockBuff, sizeof(lockBuff), "spotLights[%d].base.base.ambientIntensity", i);
		uniformSpotLight[i].uniformAmbientIntensity = glGetUniformLocation(shaderID, lockBuff);
		snprintf(lockBuff, sizeof(lockBuff), "spotLights[%d].base.base.diffuseIntensity", i);
		uniformSpotLight[i].uniformDiffuseIntensity = glGetUniformLocation(shaderID, lockBuff);
		snprintf(lockBuff, sizeof(lockBuff), "spotLights[%d].base.position", i);
		uniformSpotLight[i].uniformPosition = glGetUniformLocation(shaderID, lockBuff);
		snprintf(lockBuff, sizeof(lockBuff), "spotLights[%d].base.constant", i);
		uniformSpotLight[i].uniformConstant = glGetUniformLocation(shaderID, lockBuff);
		snprintf(lockBuff, sizeof(lockBuff), "spotLights[%d].base.linear", i);
		uniformSpotLight[i].uniformlinear = glGetUniformLocation(shaderID, lockBuff);
		snprintf(lockBuff, sizeof(lockBuff), "spotLights[%d].base.exponent", i);
		uniformSpotLight[i].uniformExponent = glGetUniformLocation(shaderID, lockBuff);
		snprintf(lockBuff, sizeof(lockBuff), "spotLights[%d].direction", i);
		uniformSpotLight[i].uniformDirection = glGetUniformLocation(shaderID, lockBuff);
		snprintf(lockBuff, sizeof(lockBuff), "spotLights[%d].edge", i);
		uniformSpotLight[i].uniformedge = glGetUniformLocation(shaderID, lockBuff);
	}
	///////////// SPOT
	uniformSpotLightCount = glGetUniformLocation(shaderID, "spotLightCount");

	for (size_t i = 0; i < MAX_SPOT_LIGHTS; i++)       ///// these are all sets our uniform location values
	{
		char lockBuff[100] = { '\0' };
		snprintf(lockBuff, sizeof(lockBuff), "spotLights[%d].base.base.colour", i);
		uniformSpotLight[i].uniformColour = glGetUniformLocation(shaderID, lockBuff);
		snprintf(lockBuff, sizeof(lockBuff), "spotLights[%d].base.base.ambientIntensity", i);
		uniformSpotLight[i].uniformAmbientIntensity = glGetUniformLocation(shaderID, lockBuff);
		snprintf(lockBuff, sizeof(lockBuff), "spotLights[%d].base.base.diffuseIntensity", i);
		uniformSpotLight[i].uniformDiffuseIntensity = glGetUniformLocation(shaderID, lockBuff);
		snprintf(lockBuff, sizeof(lockBuff), "spotLights[%d].base.position", i);
		uniformSpotLight[i].uniformPosition = glGetUniformLocation(shaderID, lockBuff);
		snprintf(lockBuff, sizeof(lockBuff), "spotLights[%d].base.constant", i);
		uniformSpotLight[i].uniformConstant = glGetUniformLocation(shaderID, lockBuff);
		snprintf(lockBuff, sizeof(lockBuff), "spotLights[%d].base.linear", i);
		uniformSpotLight[i].uniformlinear = glGetUniformLocation(shaderID, lockBuff);
		snprintf(lockBuff, sizeof(lockBuff), "spotLights[%d].base.exponent", i);
		uniformSpotLight[i].uniformExponent = glGetUniformLocation(shaderID, lockBuff);
		snprintf(lockBuff, sizeof(lockBuff), "spotLights[%d].direction", i);
		uniformSpotLight[i].uniformDirection = glGetUniformLocation(shaderID, lockBuff);
		snprintf(lockBuff, sizeof(lockBuff), "spotLights[%d].edge", i);
		uniformSpotLight[i].uniformedge = glGetUniformLocation(shaderID, lockBuff);

	}
}

void loadSkyColour(float r, float g, float b)
{
	glm::vec3(1.0f, 0.0f, 0.0f);
}
//*****terrain******** 11/11

void Shader::setInt(const std::string& name, int value) const {
	glUniform1i(glGetUniformLocation(shaderID, name.c_str()), value);
}
//</ *****terrain******** 11/11

GLuint Shader::GetProjectionLocation()
{
	return uniformProjection;
}
GLuint Shader::GetModelLocation()
{
	return uniformModel;
}
GLuint Shader::GetViewLocation()
{
	return uniformView;
}
GLuint Shader::GetSkyColourLocation()
{
	return location_skyColour;
}
GLuint Shader::GetAmbientColourLocation()
{
	return uniformDirectionalLight.uniformColour;
}
GLuint Shader::GetAmbientIntensityLocation()
{
	return uniformDirectionalLight.uniformAmbientIntensity;
}
GLuint Shader::GetDiffuseIntensityLocation()
{
	return uniformDirectionalLight.uniformDiffuseIntensity;

}
GLuint Shader::GetDirectionLocation()
{
	return uniformDirectionalLight.uniformDirection;
}
/////////////////
GLuint Shader::GetSpecularIntensityLocation() {
	return uniformSpecularIntensity;
}
GLuint Shader::GetShininessLocation() {
	return uniformShininess;
}
GLuint Shader::GetEyePositionLocation() {
	return uniformEyePosition;
}
GLuint Shader::GetvertexInStuff()
{
	return vertexInStuff;
}
GLuint Shader::GetuniformterrainVerticesIDUNNOWTHISTHATf()
{
	return uniformterrainVerticesIDUNNOWTHISTHAT;
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>/////////
void Shader::SetDirectionalLight(DirectionalLight* dLight)
{
	dLight->UseLight(uniformDirectionalLight.uniformAmbientIntensity, uniformDirectionalLight.uniformColour,
		uniformDirectionalLight.uniformDiffuseIntensity, uniformDirectionalLight.uniformDirection);
}
/////////Point Light <<<<<<<<<<<<<<<
void Shader::SetPointLights(PointLight* pLight, unsigned int lightCount)
{
	if (lightCount > MAX_POINT_LIGHTS) lightCount = MAX_POINT_LIGHTS;
	glUniform1i(uniformPointLightCount, lightCount);
	for (size_t i = 0; i < lightCount; i++)
	{
		pLight[i].UseLight(uniformPointLight[i].uniformAmbientIntensity, uniformPointLight[i].uniformColour,
			uniformPointLight[i].uniformDiffuseIntensity, uniformPointLight[i].uniformPosition,
			uniformPointLight[i].uniformConstant, uniformPointLight[i].uniformlinear,
			uniformPointLight[i].uniformExponent);

	}
}
void Shader::SetSpotLights(SpotLight* sLight, unsigned int lightCount)
{
	if (lightCount > MAX_SPOT_LIGHTS) lightCount = MAX_SPOT_LIGHTS;
	glUniform1i(uniformSpotLightCount, lightCount);
	for (size_t i = 0; i < lightCount; i++)
	{
		sLight[i].UseLight(uniformSpotLight[i].uniformAmbientIntensity, uniformSpotLight[i].uniformColour,
			uniformSpotLight[i].uniformDiffuseIntensity, uniformSpotLight[i].uniformPosition, uniformSpotLight[i].uniformDirection,
			uniformSpotLight[i].uniformConstant, uniformSpotLight[i].uniformlinear,
			uniformSpotLight[i].uniformExponent, uniformSpotLight[i].uniformedge);

	}
}
////////<,,,,,,,,,,,,,,,,,,,,,,,,,,,,
void Shader::useShader()
{
	glUseProgram(shaderID);
}
void Shader::clearShader() {
	if (shaderID != 0) {

		glDeleteProgram(shaderID);
		shaderID = 0;

	}
	uniformModel = 0;
	uniformProjection = 0;
	//uniformView = 0;
	//uniformEyePosition = 0;
	////uniformAmbientIntensity,uniformAmbientColour,uniformDiffuseIntensity,UniformDirection,
	//uniformSpecularIntensity = 0;
	//uniformShininess = 0;
	//	location_skyColour = 0;
	//vertexInStuff = 0;

}

void Shader::AddShader(GLuint theProgram, const char* shaderCode, GLenum shaderType)
{
	GLuint theShader = glCreateShader(shaderType);
	const GLchar* theCode[1];
	theCode[0] = shaderCode;

	GLint codeLength[1];
	codeLength[0] = strlen(shaderCode);

	glShaderSource(theShader, 1, theCode, codeLength);
	glCompileShader(theShader);///////////////////////////

	GLint result = 0;
	GLchar eLog[1024] = { 0 };
	glGetShaderiv(theShader, GL_COMPILE_STATUS, &result);

	if (!result)
	{
		glGetShaderInfoLog(theShader, sizeof(eLog), NULL, eLog);
		printf("Error compiling %d shader: '%s'\n", shaderType, eLog);
		return;
	}
	glAttachShader(theProgram, theShader);
}
skyBox skybox;
Window mainWindow;
std::vector<Mesh*> MeshList;
//<terrainLoading>
void Shader::LoadHeightmapTexture()
{
	// Load the heightmap texture


}
//</terrainloading>
void Shader::RenderPass(glm::mat4 viewMatrix, glm::mat4 projectionMatrix)
{
	glfwPollEvents();
	//glViewport(110, 10, 1366, 768);

	//glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	skybox.DrawSkybox(viewMatrix, projectionMatrix);
	//meshterrain.wenayTerrainBkesha(viewMatrix, projectionMatrix);
	//meshterrain.wenayTerrainBkesha(viewMatrix, projectionMatrix);

	//glUseProgram(shader);

	shaderList[0].useShader();
	uniformModel = shaderList[0].GetModelLocation();
	uniformModel2 = shaderList[0].GetModelLocation();// <|--------- this maybe works who knows?
	uniformProjection = shaderList[0].GetProjectionLocation();
	// you can use it without GetProjectionLocation like this >>>>>>>> uniformProjection = shaderList[0].uniformProjection;

	uniformView = shaderList[0].GetViewLocation();
	//uniformAmbientColour = shaderList[0].GetAmbientColourLocation();
	//uniformAmbientIntensity = shaderList[0].GetAmbientIntensityLocation();
	//uniformDirection = shaderList[0].GetDirectionLocation();
	//uniformDiffuseintensity = shaderList[0].GetDiffuseIntensityLocation();
	uniformEyePosition = shaderList[0].GetEyePositionLocation();
	uniformSpecularIntensity = shaderList[0].GetSpecularIntensityLocation();
	uniformShininess = shaderList[0].GetShininessLocation();


	glm::vec3 LowerLight = camera.getCameraPosition();
	LowerLight.y -= 0.3f;
	spotLights[0].SetFlash(LowerLight, camera.getCameraDirection()); //moving Torch 'Spotlight.cpp, .h

	shaderList[0].SetDirectionalLight(&mainLight);
	shaderList[0].SetPointLights(pointLights, pointLightCount);
	shaderList[0].SetSpotLights(spotLights, spotLightCount);



	//glm 
	glm::mat4 model(1.0f);

	glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
	//glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
	//glUniform3f(uniformEyePosition, camera.getCameraPosition().x, camera.getCameraPosition().y,
		//camera.getCameraPosition().z);


	//CreateObjects();
	//createShaders();

}

//another method just like renderpass but for terrain'for terrains texture to bind to shader '
//GLuint Shader::loadTexture(const char* filename)
//{
//	return GLuint();
//}
GLuint loadTexture(const char* filename) {
	int width, height, nrChannels;
	unsigned char* data = stbi_load(filename, &width, &height, &nrChannels, 0);

	if (!data) {
		std::cerr << "Failed to load texture" << std::endl;
		return 0;
	}

	GLuint textureID;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);

	// Set texture parameters here (glTexParameteri)
	// For example: glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);

	// Assuming the image is loaded in RGB format
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(data); // Free the image memory
	glBindTexture(GL_TEXTURE_2D, 0); // Unbind the texture

	return textureID;
}



Shader::~Shader()
{
	clearShader();

}
//skybox.h







//////////////////// RenderPass

// ///////////////////
// class SkyBox cpp

skyBox::skyBox()
{
}
skyBox::skyBox(std::vector<std::string> faceLocations)
{
	//shader setup for skybox
	skyShader = new Shader();
	//stbi_set_flip_vertically_on_load(true);
	stbi_set_flip_vertically_on_load(false);
	//stbi_set_flip_vertically_on_load(false);

	skyShader->createFromFiles("Shaders/skyBox.vert", "Shaders/skyBox.frag");

	uniformProjection = skyShader->GetProjectionLocation();
	uniformView = skyShader->GetViewLocation();
	//Texture setup for skybox
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
	//stbi_set_flip_vertically_on_load(true);
	int width, height, bitdepth;
	for (size_t i = 0; i < 6; i++)
	{
		unsigned char* texData = stbi_load(faceLocations[i].c_str(), &width, &height, &bitdepth, 0);
		if (!texData)
		{
			printf(" failed ...to do stuff find: %s\n", faceLocations[i].c_str());
			return;
		}
		//glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGBA,
		//width, height, 0, GL_RGBA,GL_UNSIGNED_BYTE, texData); //sometimes skybox throw error use this RGBA

		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, texData); //<--- Alpha stuff RGBA error
		stbi_image_free(texData);
		//stbi_set_flip_vertically_on_load(true);
	}
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//stbi_set_flip_vertically_on_load(true);

	//Mesh Setup for SkyBox
	unsigned int skyBoxindices[] = {
		//front
		0,1,2,
		2,1,3,
		//right
		2,3,5,
		5,3,7,
		//back
		5,7,4,
		4,7,6,
		//left
		4,6,0,
		0,6,1,
		//top
		4,0,5,
		5,0,2,
		//bottom
		1,6,3,
		3,6,7
	};

	float skyBoxVertices[] = {
		-1.0f,1.0f,-1.0f,      0.0f, 0.0f,   0.0f,0.0f,0.0f,
		-1.0f,-1.0f,-1.0f,     0.0f, 0.0f,   0.0f,0.0f,0.0f,
		1.0f,1.0f,-1.0f,       0.0f, 0.0f,   0.0f,0.0f,0.0f,
		1.0f,-1.0f,-1.0f,      0.0f, 0.0f,   0.0f,0.0f,0.0f,


		-1.0f,1.0f,1.0f,      0.0f, 0.0f,   0.0f,0.0f,0.0f,
		1.0f,1.0f,1.0f,       0.0f, 0.0f,   0.0f,0.0f,0.0f,
		-1.0f,-1.0f,1.0f,     0.0f, 0.0f,   0.0f,0.0f,0.0f,
		1.0f,-1.0f,1.0f,      0.0f, 0.0f,   0.0f,0.0f,0.0f
	};
	skyMesh = new Mesh();
	skyMesh->createMesh(skyBoxVertices, skyBoxindices, 64, 36);

}

void skyBox::DrawSkybox(glm::mat4 viewMatrix, glm::mat4 projectionMatrix) {

	viewMatrix = glm::mat4(glm::mat3(viewMatrix));
	glDepthMask(GL_FALSE);

	//stbi_set_flip_vertically_on_load(false);

	skyShader->useShader();

	glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
	glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(viewMatrix));

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
	skyMesh->RenderMesh();

	glDepthMask(GL_TRUE);
}



skyBox::~skyBox() {}



void calcAverageNormals(unsigned int* indices, unsigned int indiceCount, GLfloat* vertices, unsigned int verticeCount,
	unsigned int VLength, unsigned int normalOffset)
{
	for (size_t i = 0; i < indiceCount; i += 3)
	{
		unsigned int in0 = indices[i] * VLength;
		unsigned int in1 = indices[i + 1] * VLength;
		unsigned int in2 = indices[i + 2] * VLength;
		glm::vec3 v1(vertices[in1] - vertices[in0], vertices[in1 + 1] - vertices[in0 + 1], vertices[in1 + 2] - vertices[in0 + 2]);
		glm::vec3 v2(vertices[in2] - vertices[in0], vertices[in2 + 1] - vertices[in0 + 1], vertices[in2 + 2] - vertices[in0 + 2]);
		glm::vec3 normal = glm::cross(v1, v2);
		normal = glm::normalize(normal);

		in0 += normalOffset; in1 += normalOffset; in2 += normalOffset;
		vertices[in0] += normal.x; 	vertices[in0 + 1] += normal.y; 	vertices[in0 + 2] += normal.z;
		vertices[in1] += normal.x; 	vertices[in1 + 1] += normal.y; 	vertices[in1 + 2] += normal.z;
		vertices[in2] += normal.x; 	vertices[in2 + 1] += normal.y; 	vertices[in2 + 2] += normal.z;
	}

	for (size_t i = 0; i < verticeCount / VLength; i++)
	{

		unsigned int nOffset = i * VLength + normalOffset;
		glm::vec3 vec(vertices[nOffset], vertices[nOffset + 1], vertices[nOffset + 2]);
		vec = glm::normalize(vec);
		vertices[nOffset] = vec.x; vertices[nOffset + 1] = vec.y; vertices[nOffset + 2] = vec.z;
	}
}

//<BARD> Ama BARD drwsty krdwa goriwety checky bo zyakrdwa nazanm chi 
void CreateSphere(float radius, int sectorCount, int stackCount)
{
	std::vector <GLfloat> vertices;
	std::vector<unsigned int> indices;

	float sectorStep = 2 * M_PI * radius / sectorCount;
	float stackStep = M_PI * radius / stackCount;
	float sectorAngle, stackAngle;

	for (int i = 0; i <= stackCount; ++i)
	{
		stackAngle = M_PI / 2 - i * stackStep; // starting from pi/2 to -pi/2
		float xy = radius * cosf(stackAngle); // r * cos(u)
		float z = radius * sinf(stackAngle); // r * sin(u)

		// add (sectorCount+1) vertices per stack
		// the first and last vertices have same position and normal, but different texture coordinates
		for (int j = 0; j <= sectorCount; ++j)
		{
			sectorAngle = j * sectorStep; // starting from 0 to 2pi

			// vertex position
			float x = xy * cosf(sectorAngle); // r * cos(u) * cos(v)
			float y = xy * sinf(sectorAngle); // r * cos(u) * sin(v)
			vertices.push_back(x);
			vertices.push_back(y);
			vertices.push_back(z);

			// vertex normal (normalize vector)
			float length = sqrtf(x * x + y * y + z * z);
			vertices.push_back(x / length);
			vertices.push_back(y / length);
			vertices.push_back(z / length);

			// vertex texture coordinates
			float s = static_cast<float>(j) / sectorCount;
			float t = static_cast<float>(i) / stackCount;
			vertices.push_back(s);
			vertices.push_back(t);
		}
	}

	// generate indices
	for (int i = 0; i < stackCount - 1; ++i)
	{
		for (int j = 0; j < sectorCount - 1; ++j)
		{
			// 2 triangles per sector
			indices.push_back(i * (sectorCount + 1) + j);
			indices.push_back((i + 1) * (sectorCount + 1) + j);
			indices.push_back((i + 1) * (sectorCount + 1) + j + 1);

			indices.push_back(i * (sectorCount + 1) + j);
			indices.push_back((i + 1) * (sectorCount + 1) + j + 1);
			indices.push_back(i * (sectorCount + 1) + j + 1);
		}
	}

	// Create a Mesh object and store the sphere data
	Mesh* sphere = new Mesh();
	sphere->createMesh(&vertices[0], &indices[0], vertices.size() / 8, indices.size());
	MeshList.push_back(sphere);
	sphere->getVertices();

}

// CreateObject function after CalcAverageNormals ...
void CreateObjects()
{
	unsigned int indices[] = {
		0, 3, 1,
		1, 3, 2,
		2, 3, 0,
		0, 1, 2
	};

	GLfloat vertices[] = {
		//	x      y      z			u	  v			nx	  ny    nz
			-1.0f, -1.0f, -0.6f,		0.0f, 0.0f,		0.0f, 0.0f, 0.0f,
			0.0f, -1.0f, 1.0f,		0.5f, 0.0f,		0.0f, 0.0f, 0.0f,
			1.0f, -1.0f, -0.6f,		1.0f, 0.0f,		0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f,		0.5f, 1.0f,		0.0f, 0.0f, 0.0f
	};


	const int segments = 1; // Number of segments around the sphere
	const int rings = 1;    // Number of rings from top to bottom

	GLfloat sphereVertices[(segments + 1) * (rings + 1) * 8];
	unsigned int sphereIndices[segments * rings * 6];

	unsigned int floorIndices[] = {
	0, 1, 2,  // first triangle
	2, 1, 3,  // second triangle
	4, 5, 6,  // third triangle
	6, 5, 7,  // fourth triangle
	// add more triangles as needed...
	};

	GLfloat floorVertices[] = {
		// vertex 0
		-1000.0f, -1.0f, -1000.0f,	0.0f, 0.0f,		0.0f, 1.0f, 0.0f,
		// vertex 1
		1000.0f, -1.0f, -1000.0f,	1000.0f, 0.0f,	0.0f, 1.0f, 0.0f,
		// vertex 2
		-1000.0f, -1.0f, 1000.0f,	0.0f, 1000.0f,	0.0f, 1.0f, 0.0f,
		// vertex 3
		1000.0f, -1.0f, 1000.0f,	1000.0f, 1000.0f,	0.0f, 1.0f, 0.0f,
		// vertex 4
		-1000.0f, -1.0f, -1000.0f,	0.0f, 0.0f,			0.0f, 1.0f, 0.0f,
		// vertex 5
		1000.0f, -1.0f, -1000.0f,	1000.0f, 0.0f,		0.0f, 1.0f, 0.0f,
		// vertex 6
		-1000.0f, -1.0f, 1000.0f,	0.0f, 1000.0f,	0.0f, 1.0f, 0.0f,
		// vertex 7
		1000.0f, -1.0f, 1000.0f,	1000.0f, 1000.0f,	0.0f, 1.0f, 0.0f
	};
	GLfloat floorVertices2[] = { //50 Vertices
		// vertex 0
		-50.0f, -1.0f, -50.0f,	0.0f, 0.0f,		0.0f, 1.0f, 0.0f,
		// vertex 1
		50.0f, -1.0f, -50.0f,	50.0f, 0.0f,	0.0f, 1.0f, 0.0f,
		// vertex 2
		-50.0f, -1.0f, 50.0f,	0.0f, 50.0f,	0.0f, 1.0f, 0.0f,
		// vertex 3
		50.0f, -1.0f, 50.0f,	50.0f, 50.0f,	0.0f, 1.0f, 0.0f,
		// vertex 4
		-50.0f, -1.0f, -50.0f,	0.0f, 0.0f,			0.0f, 1.0f, 0.0f,
		// vertex 5
		50.0f, -1.0f, -50.0f,	50.0f, 0.0f,		0.0f, 1.0f, 0.0f,
		// vertex 6
		-50.0f, -1.0f, 50.0f,	0.0f, 50.0f,	0.0f, 1.0f, 0.0f,
		// vertex 7
		50.0f, -1.0f, 50.0f,	50.0f, 50.0f,	0.0f, 1.0f, 0.0f
	};





	GLfloat houseVertices[] = {
		// Base
		-2.0f, 0.0f, -2.0f,  0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
		-2.0f, 0.0f,  2.0f,  0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
		 2.0f, 0.0f,  2.0f,  1.0f, 1.0f, 0.0f, 1.0f, 0.0f,
		 2.0f, 0.0f, -2.0f,  1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
		 // Walls
		 -2.0f, 0.0f, -2.0f,  0.0f, 0.0f, -1.0f, 0.0f, 0.0f,
		-2.0f, 4.0f, -2.0f,  0.0f, 1.0f, -1.0f, 0.0f, 0.0f,
		 2.0f, 4.0f, -2.0f,  1.0f, 1.0f, -1.0f, 0.0f, 0.0f,
		 2.0f, 0.0f, -2.0f,  1.0f, 0.0f, -1.0f, 0.0f, 0.0f,
		-2.0f, 0.0f, -2.0f,  0.0f, 0.0f, 0.0f, 0.0f, -1.0f,
		-2.0f, 0.0f,  2.0f,  0.0f, 1.0f, 0.0f, 0.0f, -1.0f,
		-2.0f, 4.0f,  2.0f,  1.0f, 1.0f, 0.0f, 0.0f, -1.0f,
		-2.0f, 4.0f, -2.0f,  1.0f, 0.0f, 0.0f, 0.0f, -1.0f,
		 2.0f, 0.0f, -2.0f,  0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
		 2.0f, 4.0f, -2.0f,  0.0f, 1.0f, 1.0f, 0.0f, 0.0f,

		 // Roof
	 -2.0f, 4.0f, -2.0f,  0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
	 -2.0f, 4.0f,  2.0f,  0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
	  2.0f, 4.0f,  2.0f,  1.0f, 1.0f, 0.0f, 1.0f, 0.0f,
	  2.0f, 4.0f, -2.0f,  1.0f, 0.0f, 0.0f, 1.0f, 0.0f
	};

	// add more vertices as needed...
	unsigned int houseIndices[] = {
		// Base
		0, 1, 2,
		0, 2, 3,
		// Walls
		4, 5, 6,
		4, 6, 7,
		8, 9, 10,
		8, 10, 11,
		4, 5, 9,
		4, 9, 8,
		6, 7, 11,
		6, 11, 10,
		// Roof
		1, 5, 9,
		1, 9, 2,
		3, 2, 10,
		3, 10, 11

	};
	calcAverageNormals(indices, 12, vertices, 32, 8, 5);
	//****************************************************SKYNET SMART MESH LOOP
	int numberOfModelObjects = 10;
	//initialize it here like in a function(contains this) <<<<<<<<<   here
	//const std::vector<glm::vec3>& outVertices


	//****************************************************</SKYNET SMART MESH LOOP

	Mesh* obj1 = new Mesh();
	obj1->createMesh(vertices, indices, 32, 12); // 12 vertices for now
	MeshList.push_back(obj1);
	//obj1->getVertices();
	const std::vector<glm::vec3>& shpereVerticy = obj1->getVertices();
	for (const auto& shpereVerticy : shpereVerticy)
	{
		std::cout << "Vertex : shpereVerticy.x shpereVerticy.y shpereVerticy.z  (" << shpereVerticy.x << " " << shpereVerticy.y << " " << shpereVerticy.z << ")" << std::endl;
	}
	const std::vector<glm::vec3>& verticesObj1 = obj1->getVertices();


	Mesh* obj2 = new Mesh(); //initialize everything to zero VBO = 0 .... etc 
	obj2->createMesh(vertices, indices, 32, 12); // 12 vertices for now
	MeshList.push_back(obj2);
	const std::vector<glm::vec3>& verticesObj2 = obj2->getVertices();
	//const std::vector<glm::vec3>& verticesObj2 = obj2->getVertices();


	float radius = 10.0f;
	int sectorCount = 720;
	int stackCount = 240;
	CreateSphere(radius, sectorCount, stackCount);

	const std::vector<glm::vec3>& segosha = obj2->getVertices();
	for (const auto& vertex : segosha)
	{
		std::cout << "Vertex : vertex.x vertex.y vertex.z  (" << vertex.x << " " << vertex.y << " " << vertex.z << ")" << std::endl;
	}

	Mesh* house = new Mesh(); //
	house->createMesh(houseVertices, houseIndices, 32, 6); // 
	MeshList.push_back(house);

	const std::vector<glm::vec3>& verticeshouse = house->getVertices();

	skyBox vert1;
	Mesh* obj3 = new Mesh(); //initialize everything to zero VBO = 0 .... etc 
	obj3->createMesh(vertices, indices, 32, 12); // 12 vertices for now
	MeshList.push_back(obj3);

	const std::vector<glm::vec3>& verticesObj3 = obj3->getVertices();




	//bo modely cataka Maybe 'lawanaya ama be'
	const std::vector<glm::vec3>& catVerticy = obj3->getVertices();

	Mesh* obj4 = new Mesh(); //initialize everything to zero VBO = 0 .... etc 
	obj4->createMesh(vertices, indices, 32, 12); // 12 vertices for now
	MeshList.push_back(obj4);
	const std::vector<glm::vec3>& verticesObj4 = obj4->getVertices();

	std::cout << "\033[1mVertices🌟🚀\033[0m (\033[31m" << *sphereVertices <<
		"\033[0m): \033[1mTriangles🌟🚀\033[0m (\033[35m" <<
		*sphereVertices / 3 << "\033[0m)" << std::endl;

	std::cout << "\033[1mhouseVertices\033[0m (\033[31m" << *houseVertices <<
		"\033[0m): \033[1mhouseIndices\033[0m (\033[35m" <<
		*houseIndices << "\033[0m)" << std::endl;
	std::cout << "\033[1mhouseVertices\033[0m (\033[31m" << catVerticy.size() <<
		"\033[0m): \033[1mhouseIndices\033[0m (\033[35m";
}

//</class terrain modified 29/10 
//<class terrain modified 3/11/2023
//terrain.h


//class Shader; // Forward declaration

//********<singleton>
//class MeshTerrain {
//	//
//	static MeshTerrain* yaksar();
//	
//	MeshTerrain* MeshTerrain::yaksar()
//{
//	static MeshTerrain* obj = new MeshTerrain();
//	return obj;
//}
//	int main(){
//		...
//	MeshTerrain::yaksar()->MeshTerrain();
//		...
//***********</singleton>

//class Meshterrain.h



 // Constructor
//unsigned char* heightMap = stbi_load("path/to/heightmap.png", &width, &height, &nrChannels, 0);

//</class terrain modified 3/11/2023

//20/Nov class Meshterrain.h
//Shader2 tessHeightMapShader2;

class MeshTerrain {
public:

	MeshTerrain(const std::string& heightMapFilename);
	~MeshTerrain();
	void LoadTerrainTexture();
	void terrrainVertAattributes();

	void Render();
	void LoadHeightMap(const std::string& filename);
	void LoadTexture(const std::string& textureFilename);
	void MeshTerrain::LoadShaders();
	GLuint textureID;
	//unsigned int terrainVAO, terrainVBO;

private:
	void SetupMesh();


	GLuint VAO, vertexVBO, textureVBO, terrainIBO;
	struct Vertex {
		glm::vec3 Position;
		glm::vec2 TexCoords;
	};
public:
	std::vector<float> vertices;
	std::vector<unsigned int> indices;
	std::vector<glm::vec2> textureCoords;
	int width, height, channels;
	//unsigned char* heightMap;
};

//</ 20/Nov class Meshterrain.h
//888888888888
void MeshTerrain::LoadTerrainTexture()
{
	//

}


void MeshTerrain::terrrainVertAattributes()
{

}


//888888888888


//20/Nov class Meshterrain.cpp
MeshTerrain::MeshTerrain(const std::string& heightMapFilename) {
	//LoadHeightMap(heightMapFilename);
	//SetupMesh();
	//LoadTerrainTexture();
	terrrainVertAattributes();
	LoadShaders();
}

MeshTerrain::~MeshTerrain() {
	//glDeleteBuffers(1, &vertexVBO);
	//glDeleteBuffers(1, &textureVBO);
	//glDeleteBuffers(1, &terrainIBO);
	//glDeleteVertexArrays(1, &VAO);
	//if (heightMap) {
	//	stbi_image_free(heightMap);
	//}
}



//void MeshTerrain::LoadHeightMap(const std::string& filename) {
//	heightMap = stbi_load(filename.c_str(), &width, &height, &channels, 0);
//	if (!heightMap) {
//		std::cerr << "Failed to load heightmap." << std::endl;
//		return;
//	}
//
//
//	for (unsigned i = 0; i <= rez - 1; i++)
//	{
//		for (unsigned j = 0; j <= rez - 1; j++)
//		{
//			//
//		}
//	}
//
//	for (int y = 0; y < height - 1; ++y) {
//		for (int x = 0; x < width - 1; ++x) {
//			//
//		}
//	}
//}


void MeshTerrain::LoadTexture(const std::string& textureFilename) {
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);

	// Set texture wrapping and filtering options (optional)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int texWidth, texHeight, texChannels;
	unsigned char* texData = stbi_load(textureFilename.c_str(), &texWidth, &texHeight, &texChannels, 0);
	if (!texData) {
		std::cerr << "Failed to load texture." << std::endl;
		return;
	}

	// Assuming 4 channels for RGBA texture, adjust if using different formats
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texWidth, texHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, texData);
	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texWidth, texHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, texData); // No Alpha

	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(texData);
	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture
}


void MeshTerrain::LoadShaders() {
	//tessHeightMapShader.createFromFiles("terrainLOpengl.vert", "terrainLOpengl.frag");
}


void MeshTerrain::SetupMesh() {
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &vertexVBO);
	glBindBuffer(GL_ARRAY_BUFFER, vertexVBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glGenBuffers(1, &textureVBO);
	//glBindBuffer(GL_ARRAY_BUFFER, textureVBO);
	//glBufferData(GL_ARRAY_BUFFER, textureCoords.size() * sizeof(float), textureCoords.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(sizeof(float) * 3));
	glEnableVertexAttribArray(1);

	glGenBuffers(1, &terrainIBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, terrainIBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(float), indices.data(), GL_STATIC_DRAW);
	LoadTexture("Textures/grass.ng"); // Replace with your texture path
	glPatchParameteri(GL_PATCH_VERTICES, NUM_PATCH_PTS);

	glBindVertexArray(0);
}
void MeshTerrain::Render() {
	//Shader2 tessHeightMapShader2;

	// render the terrain
	//glBindVertexArray(terrainVAO);
	//glDrawArrays(GL_PATCHES, 0, NUM_PATCH_PTS * rez * rez);
	//mainWindow.swapbuffers();

}

//</20/Nov class Meshterrain.cpp

class GameObject
{
public:
	glm::vec3 Position;
	glm::vec3 Size;
	glm::vec3 Velocity; //Bo collision hezyBarparch pewistman abe

	// Add other attributes if needed

	GameObject(glm::vec3 pos, glm::vec3 size) : Position(pos), Size(size), Velocity(glm::vec3(0.0f)) {}


	void UpdatePosition(const glm::vec3& newPos) {
		Velocity = newPos - Position; // Calculate velocity based on the change in position
		Position = newPos; // Update position
	}

	glm::vec3 GetVelocity() const {
		return Velocity;
	}

};

// *******struct Object
struct Object {
	glm::vec3 Position;
	glm::vec3 Size;  // Use this for scale	
};

struct AABB {
	glm::vec3 min; // The minimum corner of the bounding box.
	glm::vec3 max; // The maximum corner of the bounding box.
};

// vector <glm::vec3> & shtek;
//Bo nmwna 

AABB calculateAABB(const std::vector<glm::vec3>& vertices, const glm::mat4& transform) {
	std::vector<glm::vec3> transformedVertices;

	// Transform all the model's vertices by the provided matrix.
	for (const auto& vertex : vertices) {
		glm::vec4 transformed = transform * glm::vec4(vertex, 1.0f);
		transformedVertices.push_back(glm::vec3(transformed));
	}

	// Find the minimum and maximum x, y, and z coordinates.
	auto [minIt, maxIt] = std::minmax_element(
		transformedVertices.begin(), transformedVertices.end(),
		[](const glm::vec3& a, const glm::vec3& b) {
			// Compare the sum of the coordinates.
			return a.x + a.y + a.z < b.x + b.y + b.z;
		}
	);

	AABB box;
	box.min = *minIt;
	box.max = *maxIt;
	return box;
}



bool CheckCollision(const AABB& a, const AABB& b) {
	// Your collision logic here, as you've defined it initially
	return (a.min.x <= b.max.x && a.max.x >= b.min.x) &&
		(a.min.y <= b.max.y && a.max.y >= b.min.y) &&
		(a.min.z <= b.max.z && a.max.z >= b.min.z);
}
void handleCollision(AABB& box1, AABB& box2, float repulsionForce) {
	// Calculate collision vector (center of box2 - center of box1)
	glm::vec3 collisionVector = (box2.min + box2.max) / 2.0f - (box1.min + box1.max) / 2.0f;

	// Apply repulsion force
	// Assuming the repulsion force is constant for simplicity
	glm::vec3 repulsion = repulsionForce * glm::normalize(collisionVector);

	// Update positions of boxes to resolve collision
	box1.min -= repulsion / 2.0f;
	box1.max -= repulsion / 2.0f;
	box2.min += repulsion / 2.0f;
	box2.max += repulsion / 2.0f;
}

void applyAttraction(AABB& box1, AABB& box2, float attractionStrength) {
	// Calculate center points of each AABB
	glm::vec3 centerBox1 = (box1.min + box1.max) / 2.0f;
	glm::vec3 centerBox2 = (box2.min + box2.max) / 2.0f;

	// Calculate distance vector between centers
	glm::vec3 distanceVector = centerBox2 - centerBox1;

	// Normalize to get direction, then scale by attraction strength
	glm::vec3 attractionVector = glm::normalize(distanceVector) * attractionStrength;

	// Apply the attraction to move boxes towards each other
	// This simulates a simplistic attraction by directly adjusting the min/max points.
	// In a full physics system, you would likely apply this as a force to the velocity of the objects instead.
	box1.min += attractionVector;
	box1.max += attractionVector;
	box2.min -= attractionVector;
	box2.max -= attractionVector;
}


//'enhanced version' ya versioneky bashtr krawy functiony applyattraction'akay sarawa,
// ka lerada lakaty baryakkawtn Stopy pe aka 'stop upon collision'

void applyAttractionAndResolveCollision(AABB& box1, AABB& box2, float attractionStrength, float repulsionForce) {
	// Calculate center points of each AABB
	glm::vec3 centerBox1 = (box1.min + box1.max) / 2.0f;
	glm::vec3 centerBox2 = (box2.min + box2.max) / 2.0f;

	// Calculate distance vector between centers
	glm::vec3 distanceVector = centerBox2 - centerBox1;

	// Normalize to get direction, then scale by attraction strength
	glm::vec3 attractionVector = glm::normalize(distanceVector) * attractionStrength;

	// Apply the attraction to move boxes towards each other
	box1.min += attractionVector;
	box1.max += attractionVector;
	box2.min -= attractionVector;
	box2.max -= attractionVector;

	// Check for collision and resolve if necessary
	if (CheckCollision(box1, box2)) {
		// Calculate overlap vector
		glm::vec3 overlap = glm::min(box1.max - box2.min, box2.max - box1.min);

		// Find minimum overlap direction
		float minOverlap = glm::min(glm::min(overlap.x, overlap.y), overlap.z);

		// Create a push vector based on the smallest overlap
		glm::vec3 pushVector(0.0f);
		if (minOverlap == overlap.x) {
			pushVector = glm::vec3(minOverlap, 0.0f, 0.0f);
		}
		else if (minOverlap == overlap.y) {
			pushVector = glm::vec3(0.0f, minOverlap, 0.0f);
		}
		else {
			pushVector = glm::vec3(0.0f, 0.0f, minOverlap);
		}

		// Determine push direction
		glm::vec3 centerDiff = centerBox2 - centerBox1;
		if (glm::dot(pushVector, centerDiff) > 0) {
			pushVector = -pushVector;
		}

		// Apply push vector to separate the intersecting objects
		box1.min += pushVector * 0.5f;
		box1.max += pushVector * 0.5f;
		box2.min -= pushVector * 0.5f;
		box2.max -= pushVector * 0.5f;
	}
}

//*********************<>




/////////////////////////////////////
///////////////CAMERA2///////////////
///////////////CAMERA2///////////////
/////////////////////////////////////
// Defines several possible options for camera movement. Used as abstraction to stay away from window-system specific input methods
enum Camera_Movement {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};

// Default camera values
const float YAW = -90.0f;
const float PITCH = 0.0f;
const float SPEED = 100.5f;
const float SENSITIVITY = 0.01f;
const float ZOOM = 20.0f;
float minFOV = 1.0f; float maxFOV = 200.0f;  float FOV = 45.0f;

// An abstract camera class that processes input and calculates the corresponding Euler Angles, Vectors and Matrices for use in OpenGL
class Camera2
{
public:
	// camera Attributes
	glm::vec3 Position;
	glm::vec3 Front;
	glm::vec3 Up;
	glm::vec3 Right;
	glm::vec3 WorldUp;
	// euler Angles
	float Yaw;
	float Pitch;
	// camera options
	float MovementSpeed;
	float MouseSensitivity;
	float Zoom;

	// constructor with vectors
	Camera2(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH) : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM)
	{
		Position = position;
		WorldUp = up;
		Yaw = yaw;
		Pitch = pitch;
		updateCameraVectors();
	}
	// constructor with scalar values
	Camera2(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch) : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM)
	{
		Position = glm::vec3(posX, posY, posZ);
		WorldUp = glm::vec3(upX, upY, upZ);
		Yaw = yaw / 100.0f;
		Pitch = pitch / 100.0f;
		updateCameraVectors();
	}

	// returns the view matrix calculated using Euler Angles and the LookAt Matrix
	glm::mat4 GetViewMatrix()
	{
		return glm::lookAt(Position, Position + Front, Up);
	}

	// processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
	void ProcessKeyboard(Camera_Movement direction, float deltaTime)
	{
		float velocity = MovementSpeed * deltaTime;
		if (direction == FORWARD)
			Position += Front * velocity;
		if (direction == BACKWARD)
			Position -= Front * velocity;
		if (direction == LEFT)
			Position -= Right * velocity;
		if (direction == RIGHT)
			Position += Right * velocity;
	}

	// processes input received from a mouse input system. Expects the offset value in both the x and y direction.
	void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true)
	{
		xoffset *= MouseSensitivity;
		yoffset *= MouseSensitivity;

		Yaw += xoffset;
		Pitch += yoffset;

		// make sure that when pitch is out of bounds, screen doesn't get flipped
		if (constrainPitch)
		{
			if (Pitch > 89.0f)
				Pitch = 89.0f;
			if (Pitch < -89.0f)
				Pitch = -89.0f;
		}

		// update Front, Right and Up Vectors using the updated Euler angles
		updateCameraVectors();
	}
	void zoomIn() {
		FOV -= ZOOM; // Decrease the field of view
		if (FOV < minFOV) FOV = minFOV;
	}

	void zoomOut() {
		FOV += ZOOM; // Increase the field of view
		if (FOV > maxFOV) FOV = maxFOV;
	}
	// processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
	void ProcessMouseScroll(float yoffset)
	{
		Zoom -= (float)yoffset;
		if (Zoom < 1.0f)
			Zoom = 1.0f;
		if (Zoom > 45.0f)
			Zoom = 45.0f;
	}
	void zoom(int amount) {
		// Move the camera along the front vector
		Position += Front * static_cast<float>(amount);
	}

	//to drag terrain with mouse 
	void Pan(float xoffset, float yoffset) {
		glm::vec3 right = glm::normalize(glm::cross(Front, WorldUp));
		glm::vec3 up = glm::normalize(glm::cross(right, Front));

		Position += right * xoffset * MouseSensitivity;
		Position += up * yoffset * MouseSensitivity;
	}
private:
	// calculates the front vector from the Camera's (updated) Euler Angles
	void updateCameraVectors()
	{
		// calculate the new Front vector
		glm::vec3 front;
		front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
		front.y = sin(glm::radians(Pitch));
		front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
		Front = glm::normalize(front);
		// also re-calculate the Right and Up vector
		Right = glm::normalize(glm::cross(Front, WorldUp));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
		Up = glm::normalize(glm::cross(Right, Front));
	}
};


/////////////////////////////////////
///////////////CAMERA///////////////</>
///////////////CAMERA///////////////</>
/////////////////////////////////////

const unsigned int SCR_WIDTH = 1920;
const unsigned int SCR_HEIGHT = 1080;



// camera - give pretty starting point
Camera2 camera2(glm::vec3(1.0f, 1.0f, 10.0f),
	glm::vec3(0.0f, 1.0f, 0.0f),
	-128.1f, -42.4f);
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

//collision push constants
float handekDwry = 10.0f;

// SINGLETON 
//ModelyMarixState* ModelyMarixState::daspeka()
//{
//	static ModelyMarixState* ModelyMarixObj = new ModelyMarixState();
//	return ModelyMarixObj;
//} //with enum class kind of not working like that


//flying technique
	// Variables to define a curve
float curveRadius = 10.01f; // Radius of the curve
float angularSpeed = 0.003f; // How fast the object moves along the curve
float durationOfFlyingCurve = 3.0f; // 10 seconds for the Flying Curve phase
float durationOfRandomMovement = 1.0f; // 10 seconds for the random Flying movement
float someThreshold = 2.0f; // Defines a distance of 1 unit as the threshold
float durationOfSlowDown = 8.5f; // 10 seconds for the Flying Curve phase
float durationOfLoopOverHead = 8.5f; // 10 seconds for the Flying Curve phase
float verticalThreshold = 1.0f;

enum class ModelyMarixState {
	FlyingCurve,
	RandomMovement,
	TowardsCamera,
	SlowDown,
	LoopOverHead,
	Idle, // Use this state to pause or stop the movement.
	ChangeDirectionAndPause // New state to change direction and pause

};

//variablek 'gorawek bo' check krdny barwdoxy estaw ba
ModelyMarixState currentState = ModelyMarixState::FlyingCurve;
float stateTime = 0.0f; // Time elapsed in the current state.
glm::vec3 cameraPosition; // Assume this is updated with your camera's position.
//for pause Direction Reverse 
float pauseDuration = 5.0f; // Duration of the pause in seconds
bool hasDirectionChanged = false; // To ensure the direction changes only once per state entry

glm::vec3 modelyMarixPosition;
void transitionTo(ModelyMarixState newState) {
	currentState = newState;
	stateTime = 0.0f; // Reset time for the new state
}
bool checkConditionToResumeFlying = true;

///////////////////////////////////////updateModelyMarix
void updateModelyMarix(float deltaTime) {
	stateTime += deltaTime;
	float angle = 0.0f; // This will be used for calculations
	//cameraPosition = camera.getCameraPosition();
	glm::vec3 cameraPosition = camera.getCameraPosition();
	glm::vec3 directionToCamera = glm::normalize(cameraPosition - modelyMarixPosition);
	float speed = 0.005f; // Speed at which the model moves towards the camera
	modelyMarixPosition += directionToCamera * speed * deltaTime;
	glm::vec3 camPos = camera.getCameraPosition();
	std::cout << "Camera Position: x = " << camPos.x << ", y = " << camPos.y << ", z = " << camPos.z << " ";

	// Calculate directional distance, focusing on vertical distance
	float verticalDistance = abs(modelyMarixPosition.y - cameraPosition.y);
	float horizontalDistance = glm::distance(glm::vec2(modelyMarixPosition.x, modelyMarixPosition.z), glm::vec2(cameraPosition.x, cameraPosition.z));
	float verticalSpeed = 0.01f; // Adjust as necessary for your game's scale and desired visual effect

	switch (currentState) {
	case ModelyMarixState::FlyingCurve:
		// Example: Move in a circular path around the origin
		angle = stateTime * angularSpeed; // Increase angle over time
		modelyMarixPosition.x = sin(angle) * curveRadius; // X position
		modelyMarixPosition.z = cos(angle) * curveRadius; // Z position

		modelyMarixPosition.y += verticalSpeed * deltaTime;// y position

		if (stateTime > durationOfFlyingCurve) {
			transitionTo(ModelyMarixState::RandomMovement);
		}
		break;

	case ModelyMarixState::RandomMovement:
		// For simplicity, let's move randomly on the XZ plane
		modelyMarixPosition.x += (rand() % 7 - 10) * deltaTime; // Randomly move left/right
		modelyMarixPosition.y += (rand() % -3 + 1) * deltaTime; // Randomly move forward/backward
		modelyMarixPosition.z += (rand() % -3 + 1) * deltaTime; // Randomly move up/down
		if (stateTime > durationOfRandomMovement) {
			transitionTo(ModelyMarixState::TowardsCamera);
		}
		break;

		// Implement other states as needed...
	case ModelyMarixState::TowardsCamera:
		// Move towards the camera
		if (glm::distance(modelyMarixPosition, cameraPosition) < someThreshold) {
			std::cout << "transitionTo(ModelyMarixState::TowardsCamera_TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT)";

			transitionTo(ModelyMarixState::SlowDown);

		}
		break;

	case ModelyMarixState::SlowDown:
		// Slow down gradually
		if (verticalDistance < verticalThreshold && horizontalDistance < someThreshold) {
			std::cout << "transitionTo(ModelyMarixState::SlowDown)_SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS";

			transitionTo(ModelyMarixState::LoopOverHead);
		}
		else {
			// Logic to move model towards camera, focusing on reducing vertical distance
			// This could involve adjusting the speed or direction of movement specifically to reduce verticalDistance
			modelyMarixPosition += directionToCamera / speed * deltaTime;
		}
		break;

	case ModelyMarixState::LoopOverHead:
		// Loop over the viewer's head
		if (stateTime > durationOfLoopOverHead) {
			std::cout << "transitionTo(ModelyMarixState::LoopOverHead)_LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL";

			transitionTo(ModelyMarixState::FlyingCurve); // Restart or transition to Idle
		}
		break;


	case ModelyMarixState::Idle:
		// Check if a certain condition is met to resume flying
		if (checkConditionToResumeFlying) { // This is a placeholder for your condition checking logic
			durationOfSlowDown = 6.0f;
			durationOfLoopOverHead = 8.0f;
			curveRadius = 1.1f; // Radius of the curve
			angularSpeed = 0.1f; // How fast the object moves along the curve
			durationOfFlyingCurve = 3.0f; // 10 seconds for the Flying Curve phase
			durationOfRandomMovement = 2.0f; // 10 seconds for the random Flying movement
			someThreshold = 1.0f; // Defines a distance of 1 unit as the threshold
			durationOfSlowDown = 6.5f; // 10 seconds for the Flying Curve phase
			durationOfLoopOverHead = 3.5f; // 10 seconds for the Flying Curve phase
			verticalThreshold = 3.0f;
			std::cout << "transitionTo(ModelyMarixState::SlowDown)_SSSSSSSSSSSSSSSSCASE_IDLEEEESSSSSS______SlowDowndS";
			transitionTo(ModelyMarixState::SlowDown);
			std::cout << "transitionTo(ModelyMarixState::TowardsCamera_TTTTTTTTTTTTTTTCASE_IDLEEEETTTTTT________TowardsCamera)";
			transitionTo(ModelyMarixState::TowardsCamera);
			std::cout << "transitionTo(ModelyMarixState::LoopOverHead)_LLLLLLLLLLLLLLLLCASE_IDLEEEELLLLLL_____LoopOverHead";
			transitionTo(ModelyMarixState::LoopOverHead);
		}
		break;
	case ModelyMarixState::ChangeDirectionAndPause:
		if (!hasDirectionChanged) {
			// Reverse direction. For simplicity, let's flip the X and Z direction.
			modelyMarixPosition.x *= -1;
			modelyMarixPosition.z *= -1;
			//modelyMarixPosition = glm::vec3(0.0f, 0.0f, 1.0f);
			hasDirectionChanged = true;
		}

		if (stateTime < pauseDuration) {
			// Pause movement by not updating modelyMarixPosition
		}
		else {
			// Reset for the next time this state is entered
			hasDirectionChanged = false;
			stateTime = 0.0f;
			// Transition back to a previous state or a new state as needed
			std::cout << "Back to ---------PREVIOUS STATE----------";
			transitionTo(ModelyMarixState::FlyingCurve); // Implement logic to remember the previous state if needed
		}
		break;
	}
}
void updateModelyMam(float deltaTime) {

	//Random number 1-10 'randomNumber'
	std::random_device rd;
	std::mt19937 gen(rd());

	// Define the range
	std::uniform_int_distribution<> dis(1, 10);

	// Generate and print the random number
	int randomNumber = dis(gen);
	//Random number </>
	stateTime += deltaTime;
	float angle = 0.0f; // This will be used for calculations
	curveRadius = curveRadius / randomNumber;
	//cameraPosition = camera.getCameraPosition();
	glm::vec3 cameraPosition = camera.getCameraPosition();
	glm::vec3 directionToCamera = glm::normalize(cameraPosition - mamaAkamCurrentPosition);
	float speed = 0.005f; // Speed at which the model moves towards the camera
	mamaAkamCurrentPosition += directionToCamera * speed * (deltaTime);
	glm::vec3 camPos = camera.getCameraPosition();
	std::cout << "Camera Position: x = " << camPos.x << ", y = " << camPos.y << ", z = " << camPos.z << " ";

	// Calculate directional distance, focusing on vertical distance
	float verticalDistance = abs(mamaAkamCurrentPosition.y - cameraPosition.y);
	float horizontalDistance = glm::distance(glm::vec2(mamaAkamCurrentPosition.x, mamaAkamCurrentPosition.z), glm::vec2(cameraPosition.x, cameraPosition.z));
	float verticalSpeed = 0.01f; // Adjust as necessary for your game's scale and desired visual effect

	switch (currentState) {
	case ModelyMarixState::FlyingCurve:
		// Example: Move in a circular path around the origin
		angle = stateTime * angularSpeed; // Increase angle over time
		mamaAkamCurrentPosition.x = sin(angle) * curveRadius; // X position
		mamaAkamCurrentPosition.z = cos(angle) * curveRadius; // Z position

		mamaAkamCurrentPosition.y += verticalSpeed * deltaTime;// y position

		if (stateTime > durationOfFlyingCurve) {
			transitionTo(ModelyMarixState::RandomMovement);
		}
		break;

	case ModelyMarixState::RandomMovement:
		// For simplicity, let's move randomly on the XZ plane
		mamaAkamCurrentPosition.x += (rand() % 3 - 1) * deltaTime / 10; // Randomly move left/right
		mamaAkamCurrentPosition.y += (rand() % 3 - 1) * deltaTime / 10; // Randomly move forward/backward
		mamaAkamCurrentPosition.z += (rand() % 3 - 1) * deltaTime / 10; // Randomly move up/down
		if (stateTime > durationOfRandomMovement) {
			transitionTo(ModelyMarixState::TowardsCamera);
		}
		break;

		// Implement other states as needed...
	case ModelyMarixState::TowardsCamera:
		// Move towards the camera
		if (glm::distance(mamaAkamCurrentPosition, cameraPosition) < someThreshold) {
			std::cout << "transitionTo(ModelyMarixState::TowardsCamera_TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT)";

			transitionTo(ModelyMarixState::SlowDown);

		}
		break;

	case ModelyMarixState::SlowDown:
		// Slow down gradually
		if (verticalDistance < verticalThreshold && horizontalDistance < someThreshold) {
			std::cout << "transitionTo(ModelyMarixState::SlowDown)_SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS";

			transitionTo(ModelyMarixState::LoopOverHead);
		}
		else {
			// Logic to move model towards camera, focusing on reducing vertical distance
			// This could involve adjusting the speed or direction of movement specifically to reduce verticalDistance
			mamaAkamCurrentPosition += directionToCamera / speed * deltaTime;
		}
		break;

	case ModelyMarixState::LoopOverHead:
		// Loop over the viewer's head
		if (stateTime > durationOfLoopOverHead) {
			std::cout << "transitionTo(ModelyMarixState::LoopOverHead)_LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL";

			transitionTo(ModelyMarixState::FlyingCurve); // Restart or transition to Idle
		}
		break;

	case ModelyMarixState::ChangeDirectionAndPause:
		if (!hasDirectionChanged) {
			// Reverse direction. For simplicity, let's flip the X and Z direction.
			modelyMarixPosition.x *= -1;
			modelyMarixPosition.z *= -1;
			//modelyMarixPosition = glm::vec3(0.0f, 0.0f, 1.0f);
			hasDirectionChanged = true;
		}

		if (stateTime < pauseDuration) {
			// Pause movement by not updating modelyMarixPosition
		}
		else {
			// Reset for the next time this state is entered
			hasDirectionChanged = false;
			stateTime = 0.0f;
			// Transition back to a previous state or a new state as needed
			std::cout << "Back to ---------PREVIOUS STATE----------";
			transitionTo(ModelyMarixState::FlyingCurve); // Implement logic to remember the previous state if needed
		}
		break;
	case ModelyMarixState::Idle:
		// Check if a certain condition is met to resume flying
		if (checkConditionToResumeFlying) { // This is a placeholder for your condition checking logic


			speed = 0.0000001;
			durationOfSlowDown = 6.0f;
			durationOfLoopOverHead = 8.0f;
			curveRadius = curveRadius * randomNumber;
			angularSpeed = 0.1f; // How fast the object moves along the curve
			durationOfFlyingCurve = 3.0f; // 10 seconds for the Flying Curve phase
			durationOfRandomMovement = 2.0f; // 10 seconds for the random Flying movement
			someThreshold = 1.0f; // Defines a distance of 1 unit as the threshold
			durationOfSlowDown = 6.5f; // 10 seconds for the Flying Curve phase
			durationOfLoopOverHead = 3.5f; // 10 seconds for the Flying Curve phase
			verticalThreshold = 3.0f;
			std::cout << "transitionTo(ModelyMarixState::SlowDown)_SSSSSSSSSSSSSSSSCASE_IDLEEEESSSSSS______SlowDowndS";
			transitionTo(ModelyMarixState::TowardsCamera);
			std::cout << "transitionTo(ModelyMarixState::TowardsCamera_TTTTTTTTTTTTTTTCASE_IDLEEEETTTTTT________TowardsCamera)";
			transitionTo(ModelyMarixState::ChangeDirectionAndPause);
			transitionTo(ModelyMarixState::LoopOverHead);
			transitionTo(ModelyMarixState::TowardsCamera);
			transitionTo(ModelyMarixState::ChangeDirectionAndPause);

			transitionTo(ModelyMarixState::TowardsCamera);
			transitionTo(ModelyMarixState::ChangeDirectionAndPause);

			transitionTo(ModelyMarixState::TowardsCamera);
			transitionTo(ModelyMarixState::TowardsCamera);

			std::cout << "transitionTo(ModelyMarixState::LoopOverHead)_LLLLLLLLLLLLLLLLCASE_IDLEEEELLLLLL_____LoopOverHead";
			transitionTo(ModelyMarixState::TowardsCamera);

		}
		break;

	}
}
//</flying technique

int main()
{

	float repulsionForce = 10.0f;
	float radius = 1000.0f; // Adjust as needed

	float angularSpeed = 3.1f; // Adjust as needed




	// Random Number for Model 
	std::random_device rd;  // Obtain a random number from hardware
	std::mt19937 gen(rd()); // Seed the generator
	std::uniform_real_distribution<float> dis(600.0f, 1000.0f); // Define the range

	// Generate a random number between 1 and 10
	float randomRadius = dis(gen);
	float currentTime = glfwGetTime(); // Or your time source

	mainWindow = Window(1920, 1080); //1280 , 1024 or 1024, 768
	if (winFull) {
		mainWindow = Window(1920, 1080); //1280 , 1024 or 1024, 768c
		mainWindow.initialise();
	}
	mainWindow.initialise();
	//********************<meshTerrain>
		//glViewport(310, 10, 1920, 1080);
		//
		// path/to/your/heightMapFilename.png
	//********************</meshTerrain>

	std::cout << "Camera Pos: " << camera2.Position.x << ", " << camera2.Position.y << ", " << camera2.Position.z << std::endl;
	std::cout << "Camera Front: " << camera2.Front.x << ", " << camera2.Front.y << ", " << camera2.Front.z << std::endl;

	//create Triangle`
	Mesh* ObjectVertices;

	CreateObjects();
	createShaders();


	camera = Camera(glm::vec3(0.0f, 0.0f, 5.0f), glm::vec3(0.0f, 1.0f, 0.0f), -60.0f, 0.0f, 1.0f, 0.5f,
		glm::vec3(0.0f, 0.1f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f));





	//////////////////////////*****************************************************************************
	fog = Texture("Textures/sand.png"); // Textures/brick.png Textures/kurd.png Textures/kurdi.png Textures/slemani.png Alla
	fog.LoadTexture();
	brick = Texture("Textures/brick.png"); //haramy zherawa Textures/brick.png Textures/kurd.png Textures/kurdi.png Textures/slemani.png Alla
	brick.LoadTextureA();
	kurd = Texture("Textures/sand.png"); //haramy sarawa 
	kurd.LoadTexture(); //kurd = Texture("Textures/kurd.png");   sand.LoadTexture(); 


	//kurd.LoadTexture();      sumer.LoadTexture();    grass.LoadTexture();
	//0.0f, 1.0f, 1.0f, 0.2f); is green
	Mars = Texture("Textures/Mars.png"); // Textures/brick.png Textures/kurd.png Textures/kurdi.png Textures/slemani.png Alla
	Mars.LoadTexture();
	shwsha = Texture("MeshGroups/Trump/Trump/insan.png");
	shwsha.LoadTextureA();
	wenakay = Texture("Textures/Resources/Models/cat-texture.jpg");
	wenakay.LoadTexture();
	//BlueWhaleTexture.LoadTexture(); 
	atomImg = Texture("Textures/Resources/Models/atom.e3d");
	atomImg.LoadTextureA();

	//BlueWhaleTexture = Texture("Textures/Alien/Alien.png");
	//BlueWhaleTexture.LoadTexture();
	shinyMaterial = Sht(1.0f, 256); // shininess is going like 2 4 16 32 ...etc
	dullMaterial = Sht(0.3f, 4);

	Trump = MeshGroups();
	BMW = MeshGroups();
	Chopper = MeshGroups();
	cat = MeshGroups();
	atomModel = MeshGroups();

	AkamAliPc = MeshGroups();
	mamaAka = MeshGroups();
	//BlueWhale = MeshGroups();
	Trump.LoadModel("MeshGroups/Trump/Trump/insan.obj");//Trump
	BMW.LoadModel("Textures/Resources/Models/BMW X5 4.obj");//BMW
	Chopper.LoadModel("MeshGroups/uh60.obj"); //chopper
	//BlueWhale.LoadModel("Textures/Resources/Models/cat.obj"); //cat
	/*************************************************************************************/
	/*Note : how to getPositionoFthisObject and use it for onmouseClick 'food 4 thought'*/
	/*************************************************************************************/
	atomModel.LoadModel("Textures/Resources/Models/atom.obj");

	//AkamAliPc.LoadModel("Textures/modelMi/mamaAkam.obj");
	//AkamAliPc.LoadModel("Textures/mamaAkam.obj");
	//AkamAliPc.LoadModel("Textures/modelMi/slab.obj"); 
	//AkamAliPc.LoadModel("Textures/modelMi/objLegacy.obj");
	//AkamAliPc.LoadModel("MeshGroups/slab.obj");
	//AkamAliPc.LoadModel("MeshGroups/x-wing.obj");

	//AkamAliPc.LoadModel("Textures/Resources/Models/maAka.obj");
	//AkamAliPc.LoadModel("Textures/Resources/Models/maAkam.obj");
	//AkamAliPc.LoadModel("Textures/modelMi/mamaAkam.ply");
	//AkamAliPc.LoadModel("MeshGroups/maAem.obj");
	//AkamAliPc.LoadModel("MeshGroups/maAkam.obj");
	//AkamAliPc.LoadModel("MeshGroups/mamaAkam.obj");
	// 
	//AkamAliPc.LoadModel("MeshGroups/maAka.obj");
	//mamaAka.LoadModel("MeshGroups/mamAkamkurdcast.obj");

	mamaAka.LoadModel("MeshGroups/sub.obj");
	AkamAliPc.LoadModel("MeshGroups/sub.obj");


	/*************************************************************************************/
	mainLight = DirectionalLight(1.0f, 1.0f, 1.0f,// Matrix Green RGB: 
		0.5f, 0.5f,   //ambient , diffuse
		0.0f, 0.0f, -1.0f);

	unsigned int pointLightCount = 0;
	//////&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& PointLight Stuff
	pointLights[0] = PointLight(0.0f, 3.0f, 0.0f,
		0.0f, 1.0f,
		0.0f, 0.0f, 0.0f,
		0.3f, 0.2f, 0.1f);
	/////&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
	/////////////////////////////////////***********************************************
	//pointLightCount++;
	pointLights[1] = PointLight(0.0f, 1.0f, 0.0f,
		0.0f, 1.0f,
		-4.0f, 2.0f, 0.0f,
		0.3f, 0.1f, 0.1f);
	//pointLightCount++;
	/////&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
	/////////////////////////////////////*******************SPOTLIGHT******************
	unsigned int spotLightCount = 0;
	spotLights[0] = SpotLight(1.0f, 1.0f, 1.0f, //rangy Torchaka
		0.0f, 1.0f,
		0.0f, 0.0f, 0.0f, //side
		0.0f, -1.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		20.0f); //how wide is our spread of angle of the SpotLight 'TORCH' is
	spotLightCount++;
	////////////////////////////////////////////////////////
	spotLights[1] = SpotLight(0.0f, 0.0f, 1.0f,
		0.0f, 1.0f,
		0.0f, 0.0f, 0.0f, //side
		-100.0f, -1.0f, 0.0f,//far to left , ....,....
		1.0f, 0.0f, 0.0f,//attenuation , .....,....
		20.0f); //how wide is our spread of angle of the SpotLight 'TORCH' is
	spotLightCount++;
	/////&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
	std::vector<std::string> skyboxFaces;
	//stbi_set_flip_vertically_on_load(true);
	//skyboxFaces.push_back("Textures/skybox/xpos.png"); Textures/slemani.png
	skyboxFaces.push_back("Textures/skybox/xpos.png");
	skyboxFaces.push_back("Textures/skybox/xneg.png");
	skyboxFaces.push_back("Textures/skybox/ypos.png");
	skyboxFaces.push_back("Textures/skybox/yneg.png");
	skyboxFaces.push_back("Textures/skybox/zpos.png");
	skyboxFaces.push_back("Textures/skybox/zneg.png");
	/////////////////////////////////////***********************************************
	//stbi_set_flip_vertically_on_load(true);
	//skyboxFaces.push_back("Textures/skybox/xpos.png"); Textures/slemani.png
	//****************************************************************
	/*skyboxFaces.push_back("Textures/skybox/SkyAI/xneg.png");
	skyboxFaces.push_back("Textures/skybox/SkyAI/xpos.png");
	skyboxFaces.push_back("Textures/skybox/SkyAI/yneg.png");
	skyboxFaces.push_back("Textures/skybox/SkyAI/ypos.png");
	skyboxFaces.push_back("Textures/skybox/SkyAI/zpos.png");
	skyboxFaces.push_back("Textures/skybox/SkyAI/zneg.png");*/
	//****************************************************************
	/*skyboxFaces.push_back("Textures/skybox/SkyRunaki/right.jpg");
	skyboxFaces.push_back("Textures/skybox/SkyRunaki/left.jpg");
	skyboxFaces.push_back("Textures/skybox/SkyRunaki/top.jpg");
	skyboxFaces.push_back("Textures/skybox/SkyRunaki/bottom.jpg");
	skyboxFaces.push_back("Textures/skybox/SkyRunaki/front.jpg");
	skyboxFaces.push_back("Textures/skybox/SkyRunaki/back.jpg");*/
	/////////////////////////////////////***********************************************/
	skybox = skyBox(skyboxFaces);


	skyBox skybox;

	GLuint uniformProjection = 0, uniformModel = 0, uniformView = 0, uniformEyePosition = 0,
		//uniformAmbientIntensity = 0, uniformAmbientColour = 0, uniformDirection = 0, uniformDiffuseintensity = 0,
		uniformSpecularIntensity = 0, uniformShininess = 0, terrainTextureID = 0, uniformterrainVerticesIDUNNOWTHISTHAT = 0, uniformModel2 = 0; //terrainTextureID = loadTexture("Textures/Capture.PNG");
	/*glm::mat4 projection = glm::perspective(glm::radians(45.0f),
		(GLfloat)mainWindow.getBufferWidth() / mainWindow.getBufferHeight(), 0.1f, 100.0f);
		*/
		//
		//
		//Assimp::Importer importer = Assimp::Importer();
		//
		// 
	//loop untill window closes
		//*********************************************************************<terrain in main>
	//Shader terrainShader;
	//terrainShader.createFromFiles("Shaders/terrain.vert", "Shaders/terrain.frag");
	//Shader2 tessHeightMapShader2("terrainLOpengl.vert", "terrainLOpengl.frag", nullptr, "8.3.gpuheight.tcs", "8.3.gpuheight.tes");
	//MeshTerrain terrain("Textures/skybox/xpos.png");

	//1-1-1-1-1-1-1-1-1--1-1-1-1-1--1-1-1--1-1-1--1-1-1-1--1-1-1
	GLint maxTessLevel;
	glGetIntegerv(GL_MAX_TESS_GEN_LEVEL, &maxTessLevel);
	std::cout << "Max available tess level: " << maxTessLevel << std::endl;

	// configure global opengl state
	// -----------------------------



	// load image, create texture and generate mipmaps
	int width2, height2, nrChannels2;
	// The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
	unsigned char* data = stbi_load("Textures/FRC.jpg", &width2, &height2, &nrChannels2, 0);
	//unsigned char* data = stbi_load("Textures/hMap.jpg", &width, &height, &nrChannels, 0);

	// **************************************

	// 2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2--2-2-2-2-2--2-2-
	unsigned rez = 20;
	std::vector<float> vertices;
	for (unsigned i = 0; i <= rez - 1; i++)
	{
		for (unsigned j = 0; j <= rez - 1; j++)
		{
			vertices.push_back(-width2 / 2.0f + width2 * i / (float)rez); // v.x
			vertices.push_back(0.0f); // v.y
			vertices.push_back(-height2 / 2.0f + height2 * j / (float)rez); // v.z
			vertices.push_back(i / (float)rez); // u
			vertices.push_back(j / (float)rez); // v

			vertices.push_back(-width2 / 2.0f + width2 * (i + 1) / (float)rez); // v.x
			vertices.push_back(0.0f); // v.y
			vertices.push_back(-height2 / 2.0f + height2 * j / (float)rez); // v.z
			vertices.push_back((i + 1) / (float)rez); // u
			vertices.push_back(j / (float)rez); // v

			vertices.push_back(-width2 / 2.0f + width2 * i / (float)rez); // v.x
			vertices.push_back(0.0f); // v.y
			vertices.push_back(-height2 / 2.0f + height2 * (j + 1) / (float)rez); // v.z
			vertices.push_back(i / (float)rez); // u
			vertices.push_back((j + 1) / (float)rez); // v

			vertices.push_back(-width2 / 2.0f + width2 * (i + 1) / (float)rez); // v.x
			vertices.push_back(0.0f); // v.y
			vertices.push_back(-height2 / 2.0f + height2 * (j + 1) / (float)rez); // v.z
			vertices.push_back((i + 1) / (float)rez); // u
			vertices.push_back((j + 1) / (float)rez); // v
		}
	}
	std::cout << "Loaded " << rez * rez << " patches of 4 control points each" << std::endl;
	std::cout << "Processing " << rez * rez * 4 << " vertices in vertex shader" << std::endl;

	// first, configure the cube's VAO (and terrainVBO)
	unsigned int terrainVAO, terrainVBO;
	glGenVertexArrays(1, &terrainVAO);
	glBindVertexArray(terrainVAO);

	glGenBuffers(1, &terrainVBO);
	glBindBuffer(GL_ARRAY_BUFFER, terrainVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertices.size(), &vertices[0], GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// tex attribute
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(sizeof(float) * 3));
	glEnableVertexAttribArray(1);

	glPatchParameteri(GL_PATCH_VERTICES, NUM_PATCH_PTS);




	Shader2 tessHeightMapShader2("Shaders/8.3.gpuheight.vert", "Shaders/8.3.gpuheight.frag", nullptr,            // if wishing to render as is
		"Shaders/8.3.gpuheightT.tesc", "Shaders/8.3.gpuheightT.tese");

	// Set texture parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	if (data)
	{
		//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width2, height2, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);


		tessHeightMapShader2.setInt("model2", 0);
		std::cout << "Loaded heightmap of size " << height << " x " << width << std::endl;
	}
	else
	{
		std::cout << "Failed to load texture here...." << std::endl;
	}
	stbi_image_free(data);



	Texture terraintexture;





	while (!mainWindow.getShouldclose())
	{
		float deltaTime = 0.0f;
		float lastFrame = 0.0f;

		GLfloat now = glfwGetTime(); //IF you using SDL instead of GLFW then ...SDL_getperformancecounter()
		deltaTime = now - lastTime; //for milliSeconds (now - lastTime)* 1000  SDL_getperformanceFrequency()
		lastTime = now;



		//Get + Handle user input ... any event keyboard mouse stuff user moving
		//glfwPollEvents();
		//updateModelyMarix(deltaTime);
		camera.keyControl(mainWindow.getsKeys(), deltaTime);
		camera.mouseControl(mainWindow.getXchange(), mainWindow.getYchange());
		//clear windpw
		//glEnable(GL_DEPTH_TEST); //Depth Testing: Ensure that depth testing is 
								 //enabled if you're rendering other objects in the scene as well
		/*glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);*/


		//glUseProgram(shader);
		shaderList[0].useShader();  //***()()()()()()()()()()()()Use of shader()()()()()()()()***
		uniformModel = shaderList[0].GetModelLocation();


		uniformProjection = shaderList[0].GetProjectionLocation();
		uniformView = shaderList[0].GetViewLocation();
		uniformterrainVerticesIDUNNOWTHISTHAT = shaderList[0].GetvertexInStuff();
		//uniformAmbientColour = shaderList[0].GetAmbientColourLocation();
		//uniformAmbientIntensity = shaderList[0].GetAmbientIntensityLocation();
		//uniformDirection = shaderList[0].GetDirectionLocation();
		//uniformDiffuseintensity = shaderList[0].GetDiffuseIntensityLocation();
		uniformEyePosition = shaderList[0].GetEyePositionLocation();
		uniformSpecularIntensity = shaderList[0].GetSpecularIntensityLocation();
		uniformShininess = shaderList[0].GetShininessLocation();

		spotLights[0].SetFlash(camera.getCameraPosition(), camera.getCameraDirection()); //moving Torch 'Spotlight.cpp, .h

		shaderList[0].SetDirectionalLight(&mainLight);
		shaderList[0].SetPointLights(pointLights, pointLightCount);
		shaderList[0].SetSpotLights(spotLights, spotLightCount);


		//******************************************************************************************
					//<terrainModelRendering>
				//</terrainModelRendering>
				//**********<definey offsetw anglw shtakan>
		glm::vec3 circularOffset;
		circularOffset.x = circleRadius * sin(angle);
		circularOffset.z = circleRadius * cos(angle);

		angle += rotationSpeed;
		if (angle > 2 * 3.14159265f) {  // Reset angle if it goes beyond 360 degrees
			angle = 0.0f;
		}
		//*****************</definey offsetw anglw shtakan>
		// 
		//glm 
		glm::mat4 projectionMatrix;

		//glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projectionMatrix)); 


		//glViewport(110, 10, 1366, 768);
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//********************************************************************************* model zero
		//use 
		glm::mat4 model3arz = glm::mat4(1.0f);

		glm::mat4 previousModel3arz = model3arz;

		tessHeightMapShader2.use(); //***()()()()()()()()()()()()Use of shader2()()()()()()()()***
		//tessHeightMapShader2.


		//transformations...
		glm::mat4 projection2 = glm::perspective(glm::radians(45.0f),
			(float)SCR_WIDTH / (float)SCR_HEIGHT, 1.0f, 10000.0f);
		glm::mat4 view2 = camera.GetViewMatrix(); //camera 'flat ground' , camera2 'right infront of the screen'

		shinyMaterial.UseSht(uniformSpecularIntensity, uniformShininess);



		glBindVertexArray(terrainVAO);
		glDrawArrays(GL_PATCHES, 0, NUM_PATCH_PTS * rez * rez);
		fog.LoadTexture();
		model3arz = glm::scale(model3arz, glm::vec3(1.01f, 1.01f, 1.01f));
		model3arz = glm::translate(model3arz, glm::vec3(0.1f, -4.5f, -0.1f));

		//grass
		//terraintexture.LoadTexture();
		//model3arz = glm::translate(model3arz, glm::vec3(0.001f, 0.001f, -0.001f));
		//model3arz = glm::scale(model3arz, glm::vec3(1.01f, -10.01f, -3.01f));
		//model3arz = glm::rotate(model3arz, curAngle * toRadians * curAngle * curAngle, glm::vec3(100.0f, 100.0f, 100.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model3arz));


		tessHeightMapShader2.setInt("heightMap", 0);
		tessHeightMapShader2.use();
		tessHeightMapShader2.setMat4("model2", model3arz);
		tessHeightMapShader2.setMat4("projection2", projection2);
		tessHeightMapShader2.setMat4("view2", view2);
		/*
		try
		{
			 //here
		}
		catch (const std::exception& e) {
			std::cerr << "Error while rendering the terrain: " << e.what() << std::endl;
		}
		*/

		// <-- Update the uniform again  

	  //********************************************************************************* model zero </>
		//*************************skyBox rendering*************************
		std::vector<glm::vec3> verticesObj1;
		//CreateObjects(verticesObj1);
		glm::mat4 viewMatrix = camera.calculateViewMatrix();
		glm::mat4 projection = glm::perspective(glm::radians(45.0f),
			(GLfloat)mainWindow.getBufferWidth() / mainWindow.getBufferHeight(), 0.1f, 100000.0f);
		Shader renderpassObj;
		//glm::mat4 projection = glm::perspective(glm::radians(45.0f),
			//(GLfloat)mainWindow.getBufferWidth() / mainWindow.getBufferHeight(), 0.1f, 10000.0f);
		renderpassObj.RenderPass(viewMatrix, projection);
		//************************</skyBox rendering*************************

//****************************************************************************************** <model one>
		glm::mat4 model(1.0f);
		//model = glm::mat4(1.0f); //modely Yakam Atomaka
//glm::mat4 model = glm::mat4(1.0f); // Starting with an identity matrix
		glm::vec3 scaleyModel(0.01f, 0.01f, 0.01f); // Define scale factors
		glm::vec3 translateModel(0.0f, -3.0f, -2.5f);

		model = glm::scale(model, scaleyModel); // Apply scaling to the transformation matrix
		model = glm::translate(model, translateModel);

		//model = glm::rotate(model, curAngle * toRadians,glm::vec3(0.0f, 1.0f, 0.0f));		
		glm::vec3 ModelPositionyYakam = getModelPosition(model);
		//bool modelNumb = false; //using this bool to echo the ModelPositionyYakam once.
		for (int i = 0; i < modelInt; i++)
		{
			if (i > 5 && printModelPositionOnce)
			{
				std::cout << " ModelPositionyYakam:/n";
				std::cout << " x " << ModelPositionyYakam.x << " y " << ModelPositionyYakam.y << " z " << ModelPositionyYakam.z;
			}
		}

		if (direction)
		{
			triOffset += triIncrement;
		}
		else
		{
			triOffset -= triIncrement;
		}
		if (abs(triOffset) >= triMaxoffset) //abs means absolute 
		{
			direction = !direction;  //its a switch 
		}
		curAngle += 0.01f;
		if (curAngle >= 360)
		{
			curAngle -= 360;
		}
		if (sizeDirection) {
			curSize += 0.0001f;
		}
		else
		{
			curSize -= 0.0001f;
		}

		if (curSize >= maxSize || curSize <= minSize)
		{
			sizeDirection = !sizeDirection;
		}

		currentTime = glfwGetTime(); // Or your time source
		float RandxPos = cos(currentTime * angularSpeed / 10) / randomRadius / 10; // Calculate new x position
		float RandzPos = sin(currentTime * angularSpeed / 10) * randomRadius / 5; // Calculate new z position
		float xPos = cos(currentTime / angularSpeed) * radius; // Calculate new x position
		float zPos = sin(currentTime * angularSpeed) * radius; // Calculate new z position

		//Lets update
		glm::vec3 traModel1Rand(RandxPos / 1000, 0.0f, 0.0f); //translate model1 Atomaka randomly
		//Ashtwani bley
		translateModel = glm::vec3(4.0f, -13.0f, -1.5f);//Define translateModel again
		//scaleyModel = glm::vec3(0.003f, 0.003f, 0.003f);//updated again to -0.001
		//model = glm::translate(model, glm::vec3(-2.0f, -3.0f, -13.0f)); //model2 = glm::translate(model2, position2);
		//model = glm::scale(model, scaleyModel); // Apply scaling to the transformation matrix

		//model = glm::translate(model, traModel1Rand);




		Mesh* Obj1 = MeshList[0];
		const std::vector<glm::vec3>& vertexy1 = Obj1->getVertices();

		AABB boxymodely1 = calculateAABB(vertexy1, model); // modelyyakam ??? kamyana bo collison detection? bzana kamyana printOuty Ka awa modelaka::>>modely flanSht::()


		//********************* <for collision model 1 'Object'>
		// Model 1
		//modelMamaAkam[3] is the fourth column of the matrix,
		glm::vec3 shwenyMoelyYak = glm::vec3(model[3]);
		//which contains the translation components. wata shwenakay bardawam lakweyaya dyary akain 'continuously shwenakay'
		//********************* </for collision model 1>


		glm::vec3 scaleyQabarayModely1; //To extract the scale, need to compute the lengths of these basis vectors:
		scaleyQabarayModely1.x = glm::length(glm::vec3(model[0]));  // Length of the first column (x-axis scaling)	
		scaleyQabarayModely1.y = glm::length(glm::vec3(model[1]));  // Length of the second column (y-axis scaling)	
		scaleyQabarayModely1.z = glm::length(glm::vec3(model[2]));  // Length of the third column (z-axis scaling)
		//la commentakany sarw am dera columny Matrixaka Bas aka 7apo :) flimi matrix nalem, mathematical Matrix.

		//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//create Object instances using the positions and scales you extracted from your transformation matrices:
		Object Objectycollision1 = { shwenyMoelyYak, scaleyQabarayModely1 }; //wata shwen w qabara waragrin lakweyaya bardawam



		/* short this is how u do it
		*
		* //********************* <for collision model 1 'Object'>
		// Model
		//model[3] is the fourth column of the matrix,
		glm::vec3 shwenyMoelyYak = glm::vec3(model[3]);
		//which contains the translation components. wata shwenakay bardawam lakweyaya dyary akain 'continuously shwenakay'
		//********************* </for collision model 1>


		glm::vec3 scaleyQabarayModely1; //To extract the scale, need to compute the lengths of these basis vectors:
		scaleyQabarayModely1.x = glm::length(glm::vec3(model[0]));  // Length of the first column (x-axis scaling)
		scaleyQabarayModely1.y = glm::length(glm::vec3(model[1]));  // Length of the second column (y-axis scaling)
		scaleyQabarayModely1.z = glm::length(glm::vec3(model[2]));  // Length of the third column (z-axis scaling)
				//after model rendering...
			Object obj1 = { shwenyMoelyYak, scaleyQabarayModely1 };


		later this is how you do it...
		if (CheckCollision(obj1, obj2)) {
	// Collision detected
}
		*/
		//****************************************************************************************** </model one> 


				//****************************************************************************************** <model two>

		marix_CurrentPosition += circularOffset;

		// Modify the position slightly in the random direction:
		marix_CurrentPosition += randomDirection * (0.2f);

		// Occasionally change the random direction:
		if (rand() % 100 < 0) {  // 5% chance to change direction
			randomDirection = glm::normalize(glm::vec3(rand() % 100 - 50, 0.0f, rand() % 100 - 50));
		}
		glm::mat4
			modelyMarix = glm::mat4(1.0f);// modely Dwham Marixaka
		glm::vec3 scaleyMarix(0.01f, 0.01f, 0.01f); // Define scale factors
		glm::vec3 translatyMarix(0.5f, 1.5f, -1.5f);
		glm::vec3 rotatyMarix(5.0f, 1.0f, 10.0f);

		glm::vec3 initialPosition(0.01f, 0.01f, 0.01f);
		glm::mat4 previousModelyMarix = modelyMarix;

		float anglyMarix = curAngle * toRadians;
		// //model2 = glm::translate(model2, position2);
		modelyMarix = glm::scale(modelyMarix, scaleyMarix);
		//modelyMarix = glm::translate(modelyMarix, translatyMarix);
		//modelyMarix = glm::rotate(modelyMarix, anglyMarix ,rotatyMarix);

		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		glUniform3f(uniformEyePosition, camera.getCameraPosition().x, camera.getCameraPosition().y,
			camera.getCameraPosition().z);
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelyMarix));

		//modelyMarix = glm::smoothstep(10.0f,10.0f, 10.0f);
		//modelyMarix = glm::translate(glm::mat4(1.0f), marix_CurrentPosition); //<-- uncomment this add rendomness and stuff
		//shwen yan positiony modelaka dyary akain bam methoday xwarawa

		// For movement
		// Define the starting position of the model
		// Define the direction and distance of movement (straight line along the x-axis)
		glm::vec3 movementDirection(10.0f, 0.0f, 0.0f);
		float distanceToMove = 10.0f; // Change this value as needed
		// Translate the model to its initial position
		//modelyMarix = glm::translate(modelyMarix, initialPosition);

		// Translate the model along the movement direction
		//modelyMarix = glm::translate(modelyMarix, distanceToMove * movementDirection);
		//</ For movement
		//glm::vec3 ModelPositionyDwam = getModelPosition(modelyMarix);


		for (int i = 0; i < modelInt; i++)
		{

			if (i > 5 && printModelPositionOnce)
			{
				//std::cout << " ModelPositionyDwam 🌟🚀:/n";

				//std::cout << " x " << ModelPositionyDwam.x << " y " << ModelPositionyDwam.y << " z " << ModelPositionyDwam.z;
				//printModelPositionOnce = false; la ModelPositionySeham bika ba false boy harseloopy printing position complete kat
			}
		}
		if (gawra)
		{
			//modelyMarix = glm::rotate(modelyMarix, curAngle * 1, glm::vec3(0.0f, 0.01f, 0.0f));
			//model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));
			//modelyMarix = glm::translate(modelyMarix, glm::vec3(-10.0f, -10.01f, -200.0f));

		}
		//Mars.useTexture();  // wata Amjora Texture'a bakar bena bo Am modela.
		//brick.useTexture(); // wata Amjora Texture'a bakar bena bo Am modela.
		Mars.useTexture();
		shinyMaterial.UseSht(uniformSpecularIntensity, uniformShininess);


		if (sarawa)
		{
			//modelyMarix = glm::rotate(modelyMarix, curAngle, glm::vec3(1.0f, -4.0f, 0.0f));
			//modelyMarix = glm::translate(modelyMarix, glm::vec3(0.0f, -1.0f, 100.0f));

		}
		else
		{
			//modelyMarix = glm::rotate(modelyMarix, curAngle, glm::vec3(1.0f, -1.0f, 0.0f));
			//modelyMarix = glm::translate(modelyMarix, glm::vec3(0.0f, -1.0f, 0.0f));
		}
		if (sarawa) {
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		}
		else {
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		}
		//camera.Update();
		// Calculate the direction vector from the center of rotation to the camera position
		if (swranawa)
		{
			glm::vec3 direction = camera.position - camera.centerOfRotation;
			float rotationAngle = glm::radians(0.1f); // less radians slower it moves, I think.
			direction = glm::rotate(glm::mat4(1.0f), rotationAngle, camera.up) * glm::vec4(direction, 0.1f);
			camera.position = camera.centerOfRotation + direction;
		}
		else
		{
		}
		//********************* <for collision model 2 'GameObject'>
		// Model 2
		// modelyMarixPosition = glm::vec3(10.0f, 1.0f, 100.0f);
		glm::vec3 modelyMarixSize = glm::vec3(0.001f, 0.001f, 0.001f);
		GameObject modelyMarixObj(modelyMarixPosition, modelyMarixSize);
		//********************* </for collision model 2>


		//****************************************************************************************** <model three>
		//<rotate in circle aroud something for third model>

		animal_CurrentPosition += circularOffset;

		// Modify the position slightly in the random direction:
		animal_CurrentPosition += randomDirection * (0.08f);

		// Occasionally change the random direction:
		if (rand() % 100 < 0) {  // 5% chance to change direction
			randomDirection = glm::normalize(glm::vec3(rand() % 100 - 50, 0.0f, rand() % 100 - 50));
		}
		//</rotate in circle aroud something for third model>

		glm::mat4
			modelyCat = glm::mat4(1.0f); //modely Seham catak
		glm::mat4 previousModelyCat = modelyCat; //Bo Velocityw collision story Locationaka akain yakamjar
		//modelyCat = glm::translate(glm::mat4(1.0f), animal_CurrentPosition);

		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelyCat));//<---this line 
		//modelyCat = glm::rotate(modelyCat, curAngle * 1, glm::vec3(0.0f, 0.1f, 10.0f));
		//modelyCat = glm::scale(modelyCat, glm::vec3(0.01f, 0.01f, 0.01f));
		//modelyCat = glm::translate(modelyCat, glm::vec3(0.0f, 10.0f, 1.0f));
		//modelyCat = glm::translate(modelyCat, glm::vec3(RandxPos/10, -1.1f, RandzPos /20));


		//modelyCat = glm::transpose

		glm::vec3 ModelPositionySeham = getModelPosition(modelyCat);

		for (int i = 0; i < modelInt; i++)
		{

			if (i > 5 && printModelPositionOnce)
			{
				std::cout << " ModelPositionySeham:/n";
				std::cout << " x " << ModelPositionySeham.x << " y " << ModelPositionySeham.y << " z " << ModelPositionySeham.z;
				printModelPositionOnce = false;
			}
		}

		shinyMaterial.UseSht(uniformSpecularIntensity, uniformShininess);



		Mesh* Obj3 = MeshList[2];
		const std::vector<glm::vec3>& vertexy3 = Obj3->getVertices();

		AABB boxymodely3 = calculateAABB(vertexy3, modelyCat);

		//********************* </for collision model 3>

		//**************************************<>
		//......
		//************************************ </>

		//Qabaray modely 2 bo collision
		glm::vec3 scaleyQabarayModely2; //To extract the scale, need to compute the lengths of these basis vectors:
		scaleyQabarayModely2.x = glm::length(glm::vec3(modelyCat[0]));  // Length of the first column (x-axis scaling)	
		scaleyQabarayModely2.y = glm::length(glm::vec3(modelyCat[1]));  // Length of the second column (y-axis scaling)	
		scaleyQabarayModely2.z = glm::length(glm::vec3(modelyCat[2]));  // Length of the third column (z-axis scaling)
		//la commentakany sarw am dera columny Matrixaka Bas aka 7apo :) flimi matrix nalem, mathematical Matrix.

		shinyMaterial.UseSht(uniformSpecularIntensity, uniformShininess);


		//****************************************************************************************** <model four>
		//move mamaAkam in random directions 
		angle += rotationSpeed;
		if (angle > 2 * 3.14159265f) {  // Reset angle if it goes beyond 360 degrees
			angle = 0.0f;
		}

		//glm::vec3 circularOffset;
		circularOffset.x = circleRadius * sin(angle);
		circularOffset.z = circleRadius * cos(angle);

		mamaAkamCurrentPosition += circularOffset;

		// Modify the position slightly in the random direction:
		mamaAkamCurrentPosition += randomDirection * moveSpeed;

		// Occasionally change the random direction:
		if (rand() % 100 < 5) {  // 5% chance to change direction
			randomDirection = glm::normalize(glm::vec3(rand() % 100 - 50, 0.0f, rand() % 100 - 50));
		}

		glm::mat4 modelMamaAkam = glm::mat4(1.0f);
		//updateModelyMam(deltaTime/1000);
		//modelMamaAkam = glm::translate(glm::mat4(1.0f), mamaAkamCurrentPosition);
		//updateModelyMam(deltaTime);

		//modelMamaAkam = glm::rotate(modelMamaAkam, curAngle * toRadians * curAngle, glm::vec3(1.0f, 100.0f, 100.0f));

		//****************************************************************************************** </model four>

		Mesh* Obj2 = MeshList[1];
		const std::vector<glm::vec3>& vertexy2 = Obj2->getVertices();

		AABB boxymodely2 = calculateAABB(vertexy2, modelyMarix);

		//***************************************


		Mesh* Obj4 = MeshList[3];
		const std::vector<glm::vec3>& vertexy4 = Obj4->getVertices();

		AABB boxymodely4 = calculateAABB(vertexy4, modelMamaAkam);

		bool katekBaryakKawtny1w2 = CheckCollision(boxymodely1, boxymodely2); //Atom w Marix 

		bool katekBaryakKawtny1w3 = CheckCollision(boxymodely1, boxymodely3); //Atom w Cat

		bool katekBaryakKawtny2w3 = CheckCollision(boxymodely2, boxymodely3); //Marix w Cat , 2 w 3

		bool katekBaryakKawtny4w3 = CheckCollision(boxymodely4, boxymodely3); //Mam w Cat 

		bool katekBaryakKawtny4w2 = CheckCollision(boxymodely4, boxymodely2); //Mam w Marix

		bool katekBaryakKawtny4w1 = CheckCollision(boxymodely4, boxymodely1); //Mam w Atom

		//currentFrame = glfwGetTime();
		//deltaTime = currentFrame - lastFrame;
	   //lastFrame = currentFrame;
	   //this is how you do it like a pro gamers there 8 lines below resize as daium
	   //modelyMarixPosition = modelyMarixPosition;

	   //model = glm::scale(model, glm::vec3(0.01f, 0.01f, 0.01f));
	   //modelyMarix = glm::scale(modelyMarix, glm::vec3(0.001f, 0.001f, 0.001f));
		modelyCat = glm::scale(modelyCat, glm::vec3(0.01f, 0.01f, 0.01f));
		modelMamaAkam = glm::scale(modelMamaAkam, glm::vec3(0.01f, 0.01f, 0.01f));

		//model = glm::translate(model, glm::vec3(xPos / 10, 1.1f, zPos / 2));
		//modelyMarix = glm::translate(modelyMarix, glm::vec3(RandzPos/3, 0.1f, zPos / 4));
		//modelyCat = glm::translate(modelyCat, glm::vec3(RandxPos/18, -4.1f, RandzPos /7));
		//modelMamaAkam = glm::translate(modelMamaAkam, glm::vec3(xPos / 10, -1.1f, zPos / 20));

		//model = glm::rotate(model, curAngle * 1, glm::vec3(0.2f, 8.1f, -1.0f));
		//modelyMarix = glm::rotate(modelyMarix, curAngle * 1, glm::vec3(-0.5f, 0.1f, 2.0f));
		//modelMamaAkam = glm::rotate(modelMamaAkam, curAngle * 1, glm::vec3(1.0f, 0.1f, 10.0f));
		//updateModelyMarix(deltaTime);
		modelyMarixPosition += circularOffset;
		updateModelyMarix(deltaTime);
		modelyMarixPosition = (curAngle * 1, modelyMarixPosition);
		modelyMarix = glm::translate(glm::mat4(1.0f), modelyMarixPosition); // Reapply the position to the model matrix 
		while (i)
		{
			updateModelyMarix(deltaTime);

		}

		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelMamaAkam));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelyMarix));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelyCat));

		//updateModelyMarix(deltaTime);
		//`updateModelyMarix(deltaTime);

		if (!updateModelyMarix) {
			std::cout << "no updateModelyMarix ." << modelyMarixPosition.x << "-y" << modelyMarixPosition.y << "-z" << modelyMarixPosition.z << "---";// std::endl;
		}
		else
		{
			std::cout << "updateModelyMarix_works>>modelyMarixPosition .-x" << modelyMarixPosition.x << "-y" << modelyMarixPosition.y << "-z" << modelyMarixPosition.z << "---";// << std::endl;
			//std::cout << " updateModelyMarix works! ."
			//std::cout<<"works!";
		}

		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelyMarix));

		if (katekBaryakKawtny4w1)
		{
			applyAttractionAndResolveCollision(boxymodely4, boxymodely1, 300.0f, repulsionForce);
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelMamaAkam));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
			//applyAttraction(boxymodely4, boxymodely1, 30.0f);
			//applyAttractionAndResolveCollision(boxymodely4, boxymodely1, 1.0f, repulsionForce);
			if (applyAttraction) {

				std::cout << "\033[36;1m()()()()()()()()()Mam w Atom()()()()()()()()🌟🚀\033[0m (\033[33;1m";
				applyAttractionAndResolveCollision(boxymodely4, boxymodely1, 3.0f, 30.0f);
			}

			//handleCollision(box1RepulseCat, box2Repulse3arz, repulsionForce);
			//modelyMarix = glm::scale(modelyMarix, glm::vec3(0.01f, 0.01f, 0.01f));
			//modelyMarix = glm::translate(modelyMarix, distanceToMove * movementDirection);
			//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelyMarix));
			//MeshList[2]->RenderMesh(); //rendery marixaka modely dwam

			std::cout << "\033[1;36m";
			std::cout << "\033[31;mMam w Atom🌟🚀\033[0m (\033[33;1m" << "baryak kawtn rwi yawa .... 4 w 1";

		}



		if (katekBaryakKawtny4w2)
		{
			applyAttractionAndResolveCollision(boxymodely4, boxymodely2, 30.0f, repulsionForce);

			applyAttraction(boxymodely4, boxymodely2, 30.0f);
			if (applyAttraction) {

				std::cout << "\033[32;1m()()()()()()()()()Mam w Marix()()()()()()()()🌟🚀\033[0m (\033[33;1m";

			}

			//handleCollision(box1RepulseCat, box2Repulse3arz, repulsionForce);

			//modelyMarix = glm::translate(modelyMarix, distanceToMove * movementDirection);
			//modelyMarix = glm::scale(modelyMarix, glm::vec3(0.005f, 0.005f, 0.005f));
			//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelyMarix));  // <-- Update the uniform again  

			std::cout << "\033[1;36m";
			std::cout << "\033[32;1mMam w Marix🌟🚀\033[0m (\033[33;1m" << "baryak kawtn rwi yawa .... bo 4 w 2*****";
			//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelyCat));



		}


		// Calculate velocity along each axis
		//applyAttractionAndResolveCollision(boxymodely1, boxymodely2, 3.0f, 30.0f);

		if (katekBaryakKawtny1w2)
		{
			//Mars.useTexture();
			//applyAttraction(boxymodely1, boxymodely2,30.0f);
			//shinyMaterial.UseSht(uniformSpecularIntensity, uniformShininess);
			//sand.LoadTexture();

			//shinyMaterial.UseSht(uniformSpecularIntensity, uniformShininess);
			applyAttractionAndResolveCollision(boxymodely1, boxymodely2, 30.0f, 3.0f);
			//modelyMarix = glm::rotate(modelyMarix, curAngle / toRadians,glm::vec3(0.0f, 1.0f, 10.0f));
			//modelyMarix = glm::scale(modelyMarix, glm::vec3(0.1f, 0.1f, 0.1f));
			//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelyMarix));
			//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelyCat));

			//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelyMarix));  // <-- Update the uniform again  
			//MeshList[2]->RenderMesh();

			std::cout << "\033[1;36m";
			std::cout << "\033[35;1mAtom w Marix.. ....1 w 2🌟🚀\033[0m (\033[33;1m" << " "
				<< "\033[0;32m): 🌟🚀\033[0m (\033[33;1m" << "\033[0;32m)" << "******";

		}



		if (katekBaryakKawtny1w3)
		{
			std::cout << "\033[35;1mVertices🌟🚀\033[0m (\033[33;1m"
				<< "baryak kawtn rwi yawa ....1 w 3 "
				<< "\033[0;34m)" << "******";

			/*std::cout << "\033[32;1mVertices🌟🚀\033[0m (\033[33;1m"
				<< "baryak kawtn rwi Nayawa .... "
				<< "\033[0;32m)" << "******";*/
				//modelyMarix = glm::rotate(modelyMarix, curAngle / toRadians,
					//glm::vec3(10.0f, 10.0f, 10.0f));
				//modelyMarix = glm::scale(modelyMarix, glm::vec3(1.01f, 1.01f, 1.01f));
				//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelyMarix));  // <-- Update the uniform again  
				//MeshList[2]->RenderMesh();
				//applyAttraction(boxymodely1, boxymodely3, 30.0f);
			applyAttractionAndResolveCollision(boxymodely1, boxymodely3, 30.0f, 3.0f);

			//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelyMarix));
			//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelyCat));


		}

		if (katekBaryakKawtny2w3)
		{
			//handleCollision(boxymodely4, boxymodely2, repulsionForce);
			//randomDirection -= randomDirection / moveSpeed;

			//velocityCat += hezyBarParchDanawa * collision_Arasta; // Length of the first column (x-axis scaling)	
			//velocityMarix = -repulsionForce * velocityMarix;

			//modelyMarix = glm::translate(modelyMarix, initialPosition);

			// Translate the model along the movement direction
			//modelyMarix = glm::translate(modelyMarix, distanceToMove * movementDirection);
			//</ For movement

			//modelyMarix = glm::scale(modelyMarix, glm::vec3(0.03f, 0.03f, 0.03f));

			std::cout << "\033[1;36m";
			std::cout << "baryak kawtn rwi yawa bo 2 w 3 .... " << "\033[0;32m)" << "******";
			//applyAttraction(boxymodely2, boxymodely3, 30.0f);
			applyAttractionAndResolveCollision(boxymodely2, boxymodely3, 30.0f, 3.0f);

			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelyCat));


		}

		if (katekBaryakKawtny4w3)
		{

			std::cout << "\033[1;31m";  // ANSI code for bold red text
			std::cout << "baryak kawtn rwi yawa ....4 w 3 " << "******";
			std::cout << "\033[1;32m";
			//mamaAkamCurrentPosition += randomDirection * moveSpeed;
			//randomDirection = glm::normalize(glm::vec3(rand() % 100 - 50, 0.0f, rand() % 100 - 50));
			//modelyCat = glm::rotate(modelyCat, curAngle * toRadians,
				//glm::vec3(4.0f, 1.0f, 1.0f));
			//modelyCat = glm::scale(modelyCat, glm::vec3(0.01f, 0.01f, 0.01f));

			//applyAttraction(boxymodely4, boxymodely3, 10.0f);
			applyAttractionAndResolveCollision(boxymodely4, boxymodely3, 30.0f, 3.0f);

			//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelyMarix));

			//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelyCat));  // <-- Update the uniform again  
			//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelyCat));

		}

		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelyMarix));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelyMarix));
		modelyMarix = glm::scale(modelyMarix, scaleyMarix);

		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelyMarix));
		//updateModelyMarix(deltaTime);
		MeshList[2]->RenderMesh();





		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelyMarix));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelyCat)); 
		modelyCat = glm::rotate(modelyCat, curAngle * 1, glm::vec3(0.0f, 10.1f, 1.0f));
		modelyCat = glm::scale(modelyCat, glm::vec3(0.01f, 0.01f, 0.01f));
		modelyCat = glm::translate(modelyCat, glm::vec3(RandxPos / 18, -4.1f, RandzPos / 7));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelyCat));
		cat.RenderModel(); ///


		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelMamaAkam));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelyMarix));

		scaleyModel = glm::vec3(0.0001f, 0.0001f, 0.0001f); // Define scale factors again
		translateModel = glm::vec3(3.0f, 1.0f, -1.0f);

		//update again 'you have to update everytime when scale or transformations changing':
		model = glm::scale(model, scaleyModel); // Apply scaling to the transformation matrix 
		model = glm::translate(model, translateModel);

		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		atomModel.RenderModel();  // rendery attomaka modely yakam
		// AABB BoxmodelyChahar = calculateAABB(verticesObj1, modelyCat); //  BoxmodelyChahar for AABB for collison detection
		   //********************* <for collision model 4 'GameObject'>
	   // Model 4
		//glm::vec3 modelMamaAkamPosition = glm::vec3(10.0f, 1.0f, 10.0f);
		//glm::vec3 modelMamaAkamSize = glm::vec3(0.1f, 0.1f, 0.1f);
		//GameObject modelMamaAkamObj(modelMamaAkamPosition, modelMamaAkamSize);
		//********************* </for collision model 4> 


		//Trump.RenderModel();
		//Chopper.RenderModel();
		//****************************************************************************************** </model four>

		//***************************************************************************************** <model five>

		atomImg.useTexture();
		shinyMaterial.UseSht(uniformSpecularIntensity, uniformShininess);

		//get mamaAkam model move infront of the camera  
		glm::vec3 cameraDirection = camera.getCameraDirection();

		float distanceInFrontOfCamera = 5.0f; // for instance
		glm::vec3 offset = cameraDirection * distanceInFrontOfCamera;

		glm::vec3 newPosition = camera.getCameraPosition() + offset;
		// Update modelMamaAkam's position
		//modelMamaAkam = glm::translate(glm::mat4(1.0f), newPosition);
		//***************************rendering terrain
		//glm::mat4 modelTerrain = glm::mat4(1.0f);
		//modelMamaAkam = glm::translate(modelMamaAkam, glm::vec3(0.1f, -4.5f, -0.1f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelMamaAkam));  // <-- Update the uniform again  
		//AkamAliPc.RenderModel(); 
		//BlueWhaleTexture.LoadTexture();

		shinyMaterial.UseSht(uniformSpecularIntensity, uniformShininess);
		//dullMaterial.UseSht(uniformSpecularIntensity, uniformShininess);

		mamaAka.RenderModel();

		//modelTerrain = glm::translate(modelTerrain, glm::vec3(0.0f, 1.0f, 1.0f));
		//***************************</rendering terrain




		glUseProgram(0);
		mainWindow.swapbuffers();
	}

	return 0;
}