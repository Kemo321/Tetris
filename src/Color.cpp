#include "Color.hpp"


Uint8 getR(Color color) {
    switch (color) {
        case RED:
            return 255;
        case GREEN:
            return 0;
        case BLUE:
            return 0;
        case YELLOW:
            return 255;
        case WHITE:
            return 255;
        case BLACK:
            return 0;
    }
}

Uint8 getG(Color color) {
    switch (color) {
        case RED:
            return 0;
        case GREEN:
            return 255;
        case BLUE:
            return 0;
        case YELLOW:
            return 255;
        case WHITE:
            return 255;
        case BLACK:
            return 0;
    }
}

Uint8 getB(Color color) {
    switch (color) {
        case RED:
            return 0;
        case GREEN:
            return 0;
        case BLUE:
            return 255;
        case YELLOW:
            return 0;
        case WHITE:
            return 255;
        case BLACK:
            return 0;
    }
}
