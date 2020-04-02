#include "PostProcessing.h"

void PostProcessing::SetPreTexture(sf::Texture *preTexture) {
    PreTexture=preTexture;
}

sf::Texture *PostProcessing::GetPostTexture() {
    return &PostTexture;
}
