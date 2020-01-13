#version 330
layout(location=0) in vec3 inPos;
layout(location=1) in vec3 inNormal;
layout(location=2) in vec3 inColor;

uniform mat4 view;
uniform mat4 projection;
uniform mat4 model;

out vec3 fragPos;
out vec3 Normal;

void main()
{
    vec4 position = vec4(inPos, 1.0f);

    fragPos = vec3(model * vec4(inPos, 1.0f));
    Normal = inNormal;

    gl_Position = projection * view * model * position;
}
