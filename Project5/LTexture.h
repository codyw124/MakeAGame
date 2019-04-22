/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redestributed without written permission.*/
//Version: 001

#ifndef LTEXTURE_H
#define LTEXTURE_H

#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <IL/il.h>
#include <stdio.h>
#include <string>

class LTexture
{
    public:
        LTexture();
        ~LTexture();

        bool loadTextureFromPixels32( GLuint* pixels, GLuint width, GLuint height );
        void freeTexture();
        void render( GLfloat x, GLfloat y );
        GLuint getTextureID();
        GLuint textureWidth();
        GLuint textureHeight();
        bool loadTextureFromFile( std::string path );

    private:
        //Texture name
        GLuint mTextureID;

        //Texture dimensions
        GLuint mTextureWidth;
        GLuint mTextureHeight;
};

#endif
