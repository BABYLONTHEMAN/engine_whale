#version 330

layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 tex;
layout (location = 2) in vec3 norm;

out vec4 vCol;
out vec2 texCoord;
out vec3 normal;
out vec3 fragPos;
out vec4 directionalLightSpacePos;

uniform mat4 model;
uniform mat4 proj;
uniform mat4 view;
uniform mat4 directionalLightTransform;

void main()
{
    gl_Position = proj * view * model * vec4(pos, 1.0f);

    directionalLightSpacePos = directionalLightTransform * model * vec4(pos, 1.0f);

    vCol = vec4(clamp(pos, 0.0f, 1.0f), 1.0f);

    texCoord = tex;

    normal = mat3(transpose(inverse(model))) * norm;

    fragPos = (model * vec4(pos, 1.0f)).xyz;
}
