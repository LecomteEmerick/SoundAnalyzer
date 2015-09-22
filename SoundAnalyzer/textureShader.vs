#version 330

const vec3 c_lightDirection = vec3(0.0, 1.0, 0.0);

uniform mat4 u_projectionMatrix;
uniform mat4 u_viewMatrix;
uniform mat4 u_worldMatrix;

layout(location=1) in vec4 a_position;
layout(location=2) in vec4 a_color;

//layout(location=3) in vec2 texcoord;

out vec4 v_position;
out vec3 v_normal;
out vec4 v_color;

#define VERTEX_LIGHTING 0

void main(void)
{
	gl_Position = u_projectionMatrix * u_viewMatrix * u_worldMatrix * vec4(1.0,1.0,1.0,1.0);//* a_position;

	vec3 normal = a_position.xyz;
	normal = normalize(normal);
	normal = mat3(u_worldMatrix) * normal;
	v_normal = normal;

#if VERTEX_LIGHTING
	vec3 L = normalize(c_lightDirection);
	float NdotL = max(dot(v_normal, L), 0.0);
	
	v_color = a_color * NdotL;
#else
	v_color = vec4(1.0,1.0,1.0,1.0); // a_color;
#endif
}

