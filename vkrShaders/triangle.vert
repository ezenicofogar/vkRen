#version 460

vec2 tri[3] = vec2[](
	vec2(-0.8,  0.8),
	vec2( 0.0, -0.8),
	vec2( 0.8,  0.8) );

void main()
{
	gl_Position = vec4(tri[gl_VertexIndex], 0.0, 1.0);
}
