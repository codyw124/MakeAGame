#include "Texture.h"

Texture::Texture()
{
	//Initialize
	texture = NULL;
	width = 0;
	height = 0;
    renderer = NULL;
    currentClip = NULL;
}

Texture::~Texture()
{
	//Deallocate
	free();
}

bool Texture::setRenderer(SDL_Renderer* rendererToUse)
{
    renderer = rendererToUse;

    return renderer != NULL;
}

bool Texture::loadTextureAndMetaData(const std::string& imageFile, const std::string& metadataFile)
{
    return loadTexture(imageFile) && loadMetaData(metadataFile);
}

bool Texture::loadMetaData(const std::string& metadataFile)
{
    //make a document
    XMLDocument doc;

    //load the relative metadatafile
    doc.LoadFile(metadataFile.c_str());

    //get the element that holds everything
    //to be a valid spritesheet metadata it must have a <spritesheet> tag
    XMLNode* spriteSheet = doc.FirstChild();

    //make an element hat will point to the sprites as we get to them
    XMLNode* currentSprite = spriteSheet->FirstChildElement("sprite");

    //while we can set current sprite t something that is not NULL
    while(currentSprite != NULL)
    {
        SDL_Rect* currentRect = new SDL_Rect;
        currentRect->x = atoi(currentSprite->FirstChildElement("x")->GetText());
        currentRect->y = atoi(currentSprite->FirstChildElement("y")->GetText());
        currentRect->w = atoi(currentSprite->FirstChildElement("w")->GetText());
        currentRect->h = atoi(currentSprite->FirstChildElement("h")->GetText());

        std::string spriteName(currentSprite->FirstChildElement("name")->GetText());
        spriteName.append("_");
        spriteName.append(currentSprite->FirstChildElement("direction")->GetText());

        clips[spriteName] = currentRect;

        currentSprite = currentSprite->NextSiblingElement("sprite");
    }

    return true;
}

void Texture::setClip(const std::string clipName)
{
    currentClip = clips[clipName];
}

bool Texture::loadTexture(const std::string& imageFile )
{
	//Get rid of preexisting texture
	free();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( imageFile.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", imageFile.c_str(), IMG_GetError() );
	}
     else if(renderer == NULL)
    {
        printf( "Renderer not set please set it with this textures setRenderer function\n");
    }
	else
	{
		//Color key image
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", imageFile.c_str(), SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			width = loadedSurface->w;
			height = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );

	}

	//Return success
	texture = newTexture;
	return texture != NULL;
}

void Texture::free()
{
	//Free texture if it exists
	if( texture != NULL )
	{
		SDL_DestroyTexture( texture );
		texture = NULL;
		width = 0;
		height = 0;
        renderer = NULL;
        currentClip = NULL;
        for(std::map<std::string,SDL_Rect*>::iterator it = clips.begin(); it != clips.end(); it++)
        {
            delete it->second;
        }

        //do i need to clear it also? or will the destructor do that for me
        clips.clear();
	}
}

void Texture::render()
{
	//Render to screen
	SDL_RenderCopy( renderer, texture, currentClip, NULL);
}

int Texture::getWidth()
{
	return width;
}

int Texture::getHeight()
{
	return height;
}
