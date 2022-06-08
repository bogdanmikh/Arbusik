#version 330
uniform float u_time;
uniform vec2 u_resolution;
uniform vec2 u_mouse;

void main(){
    vec2 st = gl_FragCoord.xy / u_resolution;
    vec2 m = gl_FragCoord.xy / u_mouse;
	gl_FragColor = vec4(m.x, m.y, abs(sin(u_time)), 1.0);
}