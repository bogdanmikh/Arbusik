#version 330
uniform float u_time;
uniform vec2 u_resolution;
uniform vec2 u_mouse;

void main(){
    // gl_FragColor = vec4(abs(sin(u_time)), abs(sin(u_time * 1.5)), abs(sin(u_time * 2.5)), 1.0);
    vec2 st = gl_FragCoord.xy / u_resolution;
	gl_FragColor = vec4(st.x, st.y, 0.0, 1.0);
}