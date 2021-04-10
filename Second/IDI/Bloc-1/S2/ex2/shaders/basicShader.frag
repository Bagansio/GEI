#version 330 core

out vec4 FragColor;

void main() {
    float mid = 354.0;

    if(int(gl_FragCoord.y)% 20 <= 10) discard;

    if (gl_FragCoord.x < mid && gl_FragCoord.y < mid)
        FragColor = vec4(1.0,1.0,0.0,1.0);
    if (gl_FragCoord.x < mid && gl_FragCoord.y > mid)
        FragColor = vec4(1.0,0.0,0.0,1.0);
    if (gl_FragCoord.x > mid && gl_FragCoord.y < mid)
        FragColor = vec4(0.0,1.0,0.0,1.0);
    if (gl_FragCoord.x > mid && gl_FragCoord.y > mid)
        FragColor = vec4(0.0,0.0,1.0,1.0);
}

