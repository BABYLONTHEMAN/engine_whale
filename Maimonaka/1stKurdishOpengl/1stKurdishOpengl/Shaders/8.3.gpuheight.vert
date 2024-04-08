#version 410 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTex;

out vec2 TexCoords;

//uniform sampler2D heightMap;
//uniform mat4 model2;
//uniform mat4 view2;
//uniform mat4 projection2;
//uniform mat4 model;


void main()
{
    gl_Position =   vec4(aPos  , 1.0); //   gl_Position =  projection * model * view * vec4(aPos, 1.0);
    TexCoords = aTex;
}