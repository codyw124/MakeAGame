//Cody Ware
//8/31/19
#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include <map>
#include "tinyxml2.h"

using namespace tinyxml2;

//Texture wrapper class
class Texture
{
	public:
		//Initializes variables
		Texture();

		//Deallocates memory
		~Texture();

		//Loads image at specified path
		bool loadTexture(const std::string& path);

		//loads the image file and clips the images in it using the info
		//in the meta data file
		bool loadTextureAndMetaData(const std::string& imageFile, const std::string& metadataFile);

        //loads the clips for the texture from a metadata file
        bool loadMetaData(const std::string& metadataFile);

		//Deallocates texture
		void free();

		//Renders texture at given point
		void render();

		//Gets image dimensions
		int getWidth();
		int getHeight();

        bool setRenderer(SDL_Renderer* rendererToUse);

        void setClip(const std::string clipName);

	private:
		//The actual hardware texture
		SDL_Texture* texture;

        //the renderer that manages this texture
        SDL_Renderer* renderer;

        //store the rectangles that hold the clips
        //in a vector for easy random access
        std::map<std::string,SDL_Rect*> clips;

        SDL_Rect* currentClip;

		//Image dimensions
		int width;
		int height;
};
