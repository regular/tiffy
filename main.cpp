//#include <vector>
#include <stdio.h>

#include <xdc/std.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/System.h>

/* BIOS module Headers */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/family/arm/m3/Hwi.h>

#include "Board.h"

#include "lambda-list.hpp"

bool terminated = false;
extern "C" void myExceptionHook(Hwi_ExcContext* ctx) {
  System_printf("\nEXCEPTION\x04");
  System_flush();
  terminated = true;
}

extern "C" void myAbortSystem() {
  if (terminated) return System_abortStd();
  terminated = true;
  System_printf("\nABORT\x04");
  System_flush();
  System_abortStd();
}

extern "C" void myExitSystem(int code) {
  if (terminated) return System_exitStd(code);
  terminated = true;
  System_printf("\nEXIT %d\x04", code);
  System_flush();
  System_exitStd(code);
}

LambdaList<int> idleHandlers;
extern "C" void clockIdle() {
  idleHandlers.invokeAll(5);
}

int main() {
  System_printf("Hello");
  System_flush();

  idleHandlers.addLambda([](int x) {
    System_printf("idle ");
    System_flush();
  });

  BIOS_start();
  return 0;
}

