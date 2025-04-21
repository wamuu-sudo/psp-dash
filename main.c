#include <pspkernel.h>
#include <pspdisplay.h>
#include <pspdebug.h>
#include <pspgu.h>
#include <stdlib.h>
#include <stdio.h>
#include "gfx.h"

PSP_MODULE_INFO("PSP-Dash", 0, 1, 0);
PSP_MAIN_THREAD_ATTR(PSP_THREAD_ATTR_USER);

int main(void) {
    pspDebugScreenInit();
    gfx_init();

    int rpm = 1000;
    int speed = 0;
    int temp = 70;
    int rpm_dir = 1;

    while (1) {
        // Simulation moteur
        rpm += rpm_dir * 200;
        if (rpm >= 7000) rpm_dir = -1;
        if (rpm <= 1000) rpm_dir = 1;

        // Calcul de la vitesse (exemple simple)
        speed = (rpm - 1000) / 20;
        if (speed < 0) speed = 0;

        // Simulation température moteur
        temp = 70 + (rpm / 150);

        // Affichage
        gfx_clear();
        gfx_draw_title("PSP-DASH", 10, 10);
        gfx_draw_label("RPM", 10, 50);
        gfx_draw_bar(10, 65, rpm, 8000);
        gfx_draw_label("SPEED", 10, 95);
        gfx_draw_value(speed, "km/h", 10, 110);
        gfx_draw_label("TEMP", 10, 140);
        gfx_draw_value(temp, "deg C", 10, 155);

        gfx_flush();
        sceKernelDelayThread(40000); // 25 FPS
    }

    return 0;
}
