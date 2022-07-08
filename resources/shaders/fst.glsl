#version 330

in vec2 TexCoord;

uniform float u_time;
uniform vec2 u_resolution;
uniform vec2 u_mouse;

uniform sampler2D texture1;

void main(){
    vec2 st = gl_FragCoord.xy / u_resolution;
    vec2 m = gl_FragCoord.xy / u_mouse;
    //m.x, m.y, abs(sin(u_time))
	gl_FragColor = vec4(m.x, m.y, abs(sin(u_time)), 1.0) * texture(texture1, TexCoord);
}