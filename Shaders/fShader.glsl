varying highp vec4 texc;
uniform sampler2D tex;

void main( void )
{
    highp vec3 color = texture2D( tex, texc.st ).rgb;
    color = color * 0.2 + color * 0.8;
    gl_FragColor = vec4( clamp( color, 0.0, 1.0 ), 1.0 );
}
