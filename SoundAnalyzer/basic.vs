attribute vec4 a_position;
attribute vec4 a_color;

uniform mat4 u_projectionMatrix;
uniform mat4 u_viewMatrix;
uniform mat4 u_worldMatrix;

varying vec3 v_normal;
varying vec4 v_color;

const vec3 c_lightDirection = vec3(0.0, 1.0, 0.0);

#define VERTEX_LIGHTING 0

void main(void)
{
	gl_Position = u_projectionMatrix * u_viewMatrix * u_worldMatrix * a_position;

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

