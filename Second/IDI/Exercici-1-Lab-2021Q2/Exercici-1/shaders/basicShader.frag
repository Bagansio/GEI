#version 330 core

in vec3 fcolor;

uniform int canviColor;

out vec4 fragColor;

vec3 roig = vec3(1.0, 0.0, 0.0);
vec3 verd = vec3(0.0, 1.0, 0.0);
vec3 blau = vec3(0.0, 0.0, 1.0);

void main() {

    switch(canviColor) {
        case 1:
            fragColor = vec4(roig, 1);
            break;
        
        case 2:
            fragColor = vec4(verd, 1);
            break;
            
        case 3:
            fragColor = vec4(blau, 1);
            break;
            
        default:
            fragColor = vec4(fcolor, 1);
            break;
    }
}

