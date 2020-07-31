/**
 * Hello World Example
 * Created With Genesis-Code extension for Visual Studio Code
 * Use "Genesis Code: Compile" command to compile this program.
 **/
#include <genesis.h>
#include <string.h>

/*General stuff*/
char msg_start[22] = "Press START to Begin!";
char msg_reset[22] = "Press START to Reset!";
bool game_on = FALSE;

void showText(char s[])
{
    VDP_drawText(s, 20 - strlen(s) / 2, 10);
}

void clearText()
{
    VDP_clearText(0, 10, 32);
}

void startGame()
{
    if (game_on == FALSE)
    {
        game_on = TRUE;
        clearText();
    }
}

void endGame()
{
    if (game_on == TRUE)
    {
        showText(msg_reset);
        game_on = FALSE;
    }
}

void myJoyHandler(u16 joy, u16 changed, u16 state)
{
    if (joy == JOY_1)
    {
        /*Start game if START is pressed*/
        if (state & BUTTON_START)
        {
            if (game_on == FALSE)
            {
                startGame();
            }
        }
        if (state & BUTTON_C)
        {
        }
    }
}

int main()
{
    //Input
    JOY_init();
    JOY_setEventHandler(&myJoyHandler);
    VDP_setPaletteColor(0, RGB24_TO_VDPCOLOR(0x6dc2ca));
    showText(msg_start);

    while (1)
    {
        if (game_on == TRUE)
        {
        }
        VDP_waitVSync();
    }

    return 0;
}
