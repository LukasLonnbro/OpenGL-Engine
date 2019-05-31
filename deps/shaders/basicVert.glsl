#version 330
layout(location=0) in vec3 aPos;
layout(location=1) in vec3 aNormal;

uniform mat4 view;
uniform mat4 projection;
uniform mat4 model;

uniform vec3 aViewPos;
uniform vec3 aViewDir;

out vec3 viewPos;
out vec3 FragPos;
out vec3 Normal;

void main()
{
    vec4 position = vec4(aPos, 1.0f);
    
    vec3 viewPos = aViewPos;
    vec3 FragPos = vec3(model * position);
    vec3 Normal = aNormal;

    gl_Position = projection * view * model * position;
}
