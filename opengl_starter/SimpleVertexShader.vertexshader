#version 330 core
layout (location = 0) in vec3 position;
layout (location = 2) in vec2 texCoord;

out vec2 TexCoord;
out float ViewDistance;
out float ExitDistance;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform vec3 exit;

void main()
{
	vec3 cameraPosition = -view[3].xyz * mat3(view);
	vec3 worldPosition =  (model * vec4(position, 1.0f)).xyz;
	ViewDistance = length(worldPosition - cameraPosition);
	ExitDistance = length(worldPosition - exit);

    gl_Position = projection * view * model * vec4(position, 1.0f);
    TexCoord = vec2(texCoord.x, 1.0 - texCoord.y);
}