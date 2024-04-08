#version 410 core

in float Height;

out vec4 FragColor;

void main()
{
    //float h = (Height * 16)/64.0f;
   // FragColor = vec4(0.5, 0.5, 0.5, 1.0);// gray
   float h = (Height + 16)/64.0f;
    FragColor = vec4( h, h, h, 1.0);
   //FragColor = vec4(h, h, h, 1.0); //dark gray
    //FragColor = vec4(0.76, 0.70, 0.50, 10.0);//chatgpt choosen color of sand for my game <3
    //FragColor = vec4(h, h, h, 1.0); //Original stuff 
}