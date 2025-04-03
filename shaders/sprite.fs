# version 330 core

in vec2 TexCoords;

out vec4 FragColor;

uniform sampler2D image;
uniform vec3 spriteColor;

void main()
{
    FragColor = vec4(0.0, 1.0, 1.0, 1.0) * texture(image, TexCoords);
}