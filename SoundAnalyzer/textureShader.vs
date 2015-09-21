#version 330

in vec4 a_position;
in vec4 a_color;


in mat4 u_projectionMatrix;
in mat4 u_viewMatrix;
in mat4 u_worldMatrix;

out mat4 v_position;
out vec3 v_normal;
out vec4 v_color;

const vec3 c_lightDirection = vec3(0.0, 1.0, 0.0);

#define VERTEX_LIGHTING 1

void main(void)
{
	v_position = u_projectionMatrix * u_viewMatrix * u_worldMatrix * a_position;

	vec3 normal = a_position.xyz;
	normal = normalize(normal);
	normal = mat3(u_worldMatrix) * normal;
	v_normal = normal;

#if VERTEX_LIGHTING
	vec3 L = normalize(c_lightDirection);
	float NdotL = max(dot(v_normal, L), 0.0);
	
	v_color = a_color * NdotL;
#else
	v_color = a_color;
#endif
}

