#include <graphics.h>

int main(void)
{
    int midX, midY,
        leftEyeX, rightEyeX, eyeY,
        noseX, noseY,
        headRadius,
        eyeNoseRadius,
        smileRadius,
        stepX, stepY,

        initwindow(500, 400, "Happy Face - press key to close", 200, 150);

    midX = getmaxx() / 2;
    midY = getmaxy() / 2;
    headRadius = getmaxy() / 4;
    circle(midX, midY, headRadius);

    stepX = headRadius / 4;
    stepY = stepX;
    leftEyeX = midX - stepX;
    eyeY = midY - stepY;
    eyeNoseRadius = headRadius / 10;
    circle(leftEyeX, eyeY, eyeNoseRadius);
    circle(rightEyeX, eyeY, eyeNoseRadius);

    noseX = midX;
    noseY = midY + stepY;
    circle(noseX, noseY, eyeNoseRadius);

    smileRadius = (int)(0.75 * headRadius + 0.5);
    arc(midX, midY, 210, 330, smileRadius);

    getch();
    closegraph();

    return (0);
}
