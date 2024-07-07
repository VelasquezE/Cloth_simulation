#version 330 core

layout (points) in; // Primitive input from the vertex shader
layout (triangle_strip, max_vertices = 4) out; //Primitive output

void buildQuads(vec4 vertexPosition)
{
    gl_Position = vertexPosition + vec4(-0.00625, -0.025, 0.0, 0.0);
    EmitVertex();
    gl_Position = vertexPosition + vec4(0.00625, -0.025, 0.0, 0.0);
    EmitVertex();
    gl_Position = vertexPosition + vec4(-0.00625, 0.025, 0.0, 0.0);
    EmitVertex();
    gl_Position = vertexPosition + vec4(0.00625, 0.025, 0.0, 0.0);
    EmitVertex();

    EndPrimitive();
}

void main()
{
    //gl_in retrieves output form previous shader
    buildQuads(gl_in[0].gl_Position);
}



