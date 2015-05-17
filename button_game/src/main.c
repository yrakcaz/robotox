#include <game.h>

int main(void)
{
    init();

    while (1) {
	while (!go()) {}

        int r = 0;
        while (1) {
            r = update();
            if (r)
                break;
            draw();
            delay(500);
        };

        if (r == 1)
            win();
        else if (r == 2)
            loose();
    }

    return 0;
}
