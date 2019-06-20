// SIMPLEX NOISE SHADER: VERTEX SHADER 
varying vec3 position; // toa do dinh dung cho fragment shader 
 
void main() { 
    position = gl_Vertex.xyz; 
	 gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex; 
}