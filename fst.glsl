#version 330
uniform float u_time;
uniform vec2 u_resolution;
uniform vec2 u_mouse;

void main(){
    gl_FragColor = vec4(abs(sin(u_time * 1.5)), 1.0, 0.0, 1.0);
}