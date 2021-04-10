#version 330 core

in vec3 vertex;
in vec3 color;

uniform mat4 TG;
uniform mat4 Proj;
uniform mat4 View;

uniform int indexColor;

out vec3 fcolor;

void main() {
    switch(indexColor){
        case 0:
            fcolor = vec3(0.2,0.2,0.2);
            break;
        
        case 1:
            fcolor = vec3(0.8,0.8,0.8);
            break;
            
        default:
            fcolor = color;
            break;
    }
    //fcolor = color;
    gl_Position = Proj * View * TG * vec4 (vertex, 1.0);
}
