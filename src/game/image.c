#include "image.h"
#include "gpu.h"

Image makeImage(uint32 address, uint16 width, uint16 height)
{
    Image image;
    image.address     = address;
    image.width       = width;
    image.height      = height;
    image.transparent = true;

    return image;
}

Image makeOpaqueImage(uint32 address, uint16 width, uint16 height)
{
    Image image;
    image.address     = address;
    image.width       = width;
    image.height      = height;
    image.transparent = false;

    return image;
}

Image* createImage(uint32 address, uint16 width, uint16 height)
{
    Image* image = new(Image);
    image->address     = address;
    image->width       = width;
    image->height      = height;
    image->transparent = true;

    return image;
}

Image* createOpaqueImage(uint32 address, uint16 width, uint16 height)
{
    Image* image = new(Image);
    image->address     = address;
    image->width       = width;
    image->height      = height;
    image->transparent = false;

    return image;
}

void drawImage(rom Image* image, Point where, bool isTransparent)
{
    draw(image->address, image->width, image->height, where.x, where.y, isTransparent);
}
