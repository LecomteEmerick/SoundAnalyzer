#version 330 compatibility

layout (location = 0) in vec4 tmp_position;
layout (location = 1) in vec3 color;

uniform mat4 u_projectionMatrix;
uniform mat4 u_viewMatrix;
uniform mat4 u_worldMatrix;

smooth out vec4 theColor;

void main()
{
    gl_Position = u_projectionMatrix * u_viewMatrix * u_worldMatrix * tmp_position;
    theColor = vec4(color,1.0);
}