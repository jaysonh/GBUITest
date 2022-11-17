#include "imagehandler.h"

ImageHandler::ImageHandler()
{
    loadImages(defaultFolder);
}

void ImageHandler::loadImages( const string & folderPath )
{
    qDebug() << "Loading images from " << folderPath.c_str();

    // Find all files in folder
    for( const auto & file : std::filesystem::directory_iterator( folderPath ) )
    {
        if(checkFileExtension( file.path().extension().string() ) )  // Check we have an image file
        {
            QPixmap img( file.path().string().c_str() );

            imageSequence.push_back( img );
        }
    }
    std::reverse( imageSequence.begin(), imageSequence.end() );
}

int ImageHandler::getNumImages()
{
    return imageSequence.size();
}

QPixmap & ImageHandler::getImage( const int & indx )
{
    try
    {
        return imageSequence.at(indx);
    }catch (const std::out_of_range& oor) {
      qDebug() << "Out of Range error: " << oor.what() << '\n';
    }
}

bool ImageHandler::checkFileExtension( const string & extension )
{
    bool extOk = false;

    for( auto ext : allowedFileTypes )
    {
        if( extension == ext ){
            extOk = true;
        }
    }

    return extOk;
}
