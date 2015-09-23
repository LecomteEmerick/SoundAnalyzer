#version 330 compatibility

smooth in vec4 theColor;

out vec4 outputColor;

void main()
{
    outputColor = theColor;
}