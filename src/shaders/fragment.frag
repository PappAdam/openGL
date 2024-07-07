#version 420

layout(location = 0) in vec3 vertex_color;
layout(location = 1) in vec2 texture_coords;
out vec4 out_color;

uniform sampler2D input_texture;

void main() {
    out_color = texture(input_texture, texture_coords) * vec4(vertex_color, 1.);
}