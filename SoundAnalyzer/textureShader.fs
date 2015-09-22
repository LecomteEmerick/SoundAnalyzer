#version 330
#define VERTEX_LIGHTING 1

const vec3 c_lightDirection = vec3(0.0, 1.0, 0.0);

in vec3 v_normal;
in vec4 v_color;

//out vec4 out_color;

//uniform sampler2D textureSampler;

void main(void)
{
#if VERTEX_LIGHTING
    gl_FragColor = vec4(1.0,1.0,1.0,1.0);//texture(textureSampler, vec2(0,0)) * v_color;
#else
    vec3 N = normalize(v_normal);
	vec3 L = normalize(c_lightDirection);
	float NdotL = max(dot(N, L), 0.0);

  	gl_FragColor = v_color * NdotL;//texture(textureSampler, vec2(0,0)) * vec4(v_color, 1.0);
#endif
}