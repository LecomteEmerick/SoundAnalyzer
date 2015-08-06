
varying vec3 v_normal;
varying vec4 v_color;

const vec3 c_lightDirection = vec3(1.0, 1.0, 0.0);

void main(void)
{
    vec3 N = normalize(v_normal);
	vec3 L = normalize(c_lightDirection);
	float NdotL = max(dot(N, L), 1.0);

  	gl_FragColor = v_color * NdotL;
}