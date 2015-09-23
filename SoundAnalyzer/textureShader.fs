#version 430

in vec3 vertexColor;

out vec4 out_color;

uniform sampler2D textureSampler;

void main(void)
{
  	out_color =  vec4(vertexColor, 1.0); //texture(textureSampler, gl_FragCoord.xy).rgba *
}