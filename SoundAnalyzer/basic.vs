
attribute vec4 a_position;
attribute vec4 a_color;
uniform vec3 u_offset;


uniform mat4 u_projectionMatrix;
uniform mat4 u_viewMatrix;
uniform mat4 u_worldMatrix;

varying vec3 v_normal;
varying vec4 v_color;

const vec3 c_lightDirection = vec3(1.0, 1.0, 0.0);

#define VERTEX_LIGHTING 0

void main(void)
{
	gl_Position = u_projectionMatrix * u_viewMatrix * u_worldMatrix * (a_position + vec4(u_offset, 0.0));

	vec3 normal = a_position.xyz;
	normal = normalize(normal);
	normal = mat3(u_worldMatrix) * normal;
	v_normal = normal;

	v_color = a_color;
	//v_color = vec4(1.0, 0.0, 0.0, 1.0);
}