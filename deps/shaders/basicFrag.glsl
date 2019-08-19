#version 330
out vec4 FragColor;

in vec3 FragPos;
in vec3 viewPos;
in vec3 normal;

void main()
{
    float shininess = 0.5;
    vec3 lightPos = vec3(1.0f, 1.0f, 1.0f);
    bool blinn = true;

    vec3 objectColor = vec3(1.0f, 0.3, 1.0f);
    vec3 lightColor = vec3(1.0f, 1.0f, 1.0f);

    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;

    vec3 lightDir   = normalize(lightPos - FragPos);
    vec3 viewDir    = normalize(viewPos - FragPos);
    vec3 halfwayDir = normalize(lightDir + viewDir);

    float spec = pow(max(dot(normal, halfwayDir), 0.0), shininess);
    vec3 specular = lightColor * spec;

    vec3 result = ambient * specular * objectColor;
    FragColor = vec4(result, 1.0f);
}
