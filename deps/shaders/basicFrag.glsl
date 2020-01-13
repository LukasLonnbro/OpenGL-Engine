#version 330
in vec3 fragPos;
in vec3 Normal;

struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};
struct Light {
    vec3 position;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform vec3 viewPos;
uniform Material material;
uniform Light[10] lights;
uniform int activeLights;

out vec4 FragColor;

float calcDiff(vec3 norm, vec3 lightDir)
{
    return max(dot(norm, lightDir), 0.0f);
}
float calcSpec(vec3 norm, vec3 lightDir)
{
    vec3 viewDir = normalize(viewPos - fragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    return pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
}

void main()
{
    vec3 ambience;
    vec3 diffuse;
    vec3 specular;

    vec3 result;
    for(int i = 0; i < activeLights; i++) {
        vec3 norm = normalize(Normal);
        vec3 lightDir = normalize(lights[i].position - fragPos);

        float diff = calcDiff(norm, lightDir);
        float spec = calcSpec(norm, lightDir);

        ambience = lights[i].ambient  *  material.ambient;
        diffuse  = lights[i].diffuse  * (material.diffuse * diff);
        specular = lights[i].specular * (material.specular * specular);

        result += diffuse + specular;
    }

    FragColor = vec4(result, 1.0f);
}
