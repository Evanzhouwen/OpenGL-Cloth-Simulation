#version 330 core

out vec4 color;
uniform vec3 lightPos;
uniform vec3 viewPos;
in vec3 Normal;
in vec3 FragPos;

void main()
{
    vec3 objectColor = vec3(0.0, 0.0, 0.5);
    vec3 lightColor = vec3(1.0f, 1.0f, 1.0f);
    float specularStrength = 0.5f;
    float ambientStrength = 0.1f;

    vec3 ambient = ambientStrength * lightColor;
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);

    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);

    float specValue = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * specValue * lightColor;

    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    vec3 result = (ambient + diffuse + specular) * objectColor;

    color = vec4(result,1);
}
