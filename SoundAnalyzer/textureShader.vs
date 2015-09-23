#version 430

uniform mat4 u_projectionMatrix;
uniform mat4 u_viewMatrix;
uniform mat4 u_worldMatrix;

layout(location=0) in vec4 position;
layout(location=1) in vec3 color;

out vec3 vertexColor;

void main(void)
{
	gl_Position = u_projectionMatrix * u_viewMatrix * u_worldMatrix * position;
	vertexColor = color;
}