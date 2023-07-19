#include <stdio.h>

#include <xdc/std.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/System.h>

/* BIOS module Headers */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/family/arm/m3/Hwi.h>

#include "tiffy.hpp"

int main() {
  System_printf("Hello World. Are you idle? ");
  System_flush();

  idleHandlers.addLambda([](int x) {
    System_printf("idle ");
    System_flush();
  });

  BIOS_start();
  return 0;
}

