#version 330 core

in vec3 vertex;
in vec3 normal;

in vec3  matamb;
in vec3  matdiff;
in vec3  matspec;
in float matshin;

uniform mat4 TG;
uniform mat4 Proj;
uniform mat4 View;

out vec3  fvertex;
out vec3  fnormal;
out vec3  fmatamb;
out vec3  fmatdiff;
out vec3  fmatspec;
out float fmatshin;



void main()
{
    // Passem les dades al fragment shader

    fvertex  = (View * TG * vec4(vertex, 1)).xyz;
    mat3 normalMatrix = inverse(transpose(mat3(View * TG)));
    fnormal  = normalize(normalMatrix * normal);
    fmatamb  = matamb;
    fmatdiff = matdiff;
    fmatspec = matspec;
    fmatshin = matshin;

    gl_Position = Proj * View * TG * vec4 (vertex, 1.0);
}
