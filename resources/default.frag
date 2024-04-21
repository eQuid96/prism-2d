#version 330 core

out vec4 fragColor;

uniform float uGreen;

void main()
{
    fragColor = vec4(0.0, uGreen, 0.0, 1.0);
}