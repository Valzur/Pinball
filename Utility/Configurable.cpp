#include "Configurable.h"

void Configurable::ReadBalls(string TextPath) {
    Vector2D velocity, center;
    string IsMain, Trash;
    int N;
    file.open(TextPath);
    if (file.is_open()) {
        file >> N;
        pBalls = new Ball *[N];

        for (int i = 0; i < N; ++i) {
            //Center first
            file >> Trash;
            file >> center.x;
            file >> center.y;
            //Velocity second
            file >> Trash;
            file >> velocity.x;
            file >> velocity.y;
            //If main last
            file >> Trash;
            file >> IsMain;
            if (IsMain == "YES") {
                pBalls[i] = new Ball(center, velocity, true);
            } else if (IsMain == "NO") {
                pBalls[i] = new Ball(center, velocity, false);
            }
        }
    }
}
