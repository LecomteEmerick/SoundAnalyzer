#version 330

in vec3 v_normal;
in vec4 v_color;

out vec4 out_color;

in vec2 Texcoord;
uniform sampler2D textureSampler;

#define VERTEX_LIGHTING 1

const vec3 c_lightDirection = vec3(0.0, 1.0, 0.0);

void main(void)
{
#if VERTEX_LIGHTING
    out_color = texture(textureSampler, Texcoord) * v_color;
	//v_color;
#else
    vec3 N = normalize(v_normal);
	vec3 L = normalize(c_lightDirection);
	float NdotL = max(dot(N, L), 0.0);

  	out_color = texture(textureSampler, Texcoord) * vec4(v_color, 1.0);
	//v_color * NdotL;
#endif
}