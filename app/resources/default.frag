#version 330 core

out vec4 fragColor;

uniform float uGreen;

in vec3 oColor;
in vec2 oTexCoord;


float sin01(float value){
    return sin(value) / 2.0f + 0.5;
}

uniform sampler2D uTexture;
void main()
{
    vec4 texColor = texture(uTexture, oTexCoord);

    fragColor = vec4(texColor.xyz, uGreen);
}