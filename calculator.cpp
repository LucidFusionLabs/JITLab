/*
 * $Id: calculator.cpp 1334 2014-11-28 09:14:21Z justin $
 * Copyright (C) 2009 Lucid Fusion Labs

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifdef LFL_CLING
#include "cling/Interpreter/Interpreter.h"
#endif

#include "core/app/app.h"
#include "core/web/dom.h"
#include "core/web/css.h"
#include "core/app/flow.h"
#include "core/app/gui.h"
#include "core/ml/lp.h"

namespace LFL {
DEFINE_string(linear_program, "", "Linear program input");
DEFINE_string(llvm_dir, "../../../cling-build/inst", "LLVM dir");
DEFINE_string(lfl_dir, "../..", "LFL dir");
static const char* cling_argv[] = { "cling", nullptr };

struct MyAppState {
#ifdef LFL_CLING
  // llvm::llvm_shutdown_obj shutdownTrigger;
  cling::Interpreter interp;
  MyAppState() : interp(1, cling_argv, FLAGS_llvm_dir.c_str()) {
    interp.AddIncludePath(FLAGS_lfl_dir.c_str());
  }
#endif
} *my_app;

int Frame(LFL::Window *W, unsigned clicks, int flag) {
#ifdef LFL_CLING
  char buf[8192]={0}, result[512]={0}, *space;
  if (!FGets(buf, sizeof(buf))) return false;
  my_app->interp.process(buf);
#else
  screen->shell->FGets();
#endif
  return 0;
}

}; // namespace LFL
using namespace LFL;

extern "C" void MyAppCreate() {
  app = new Application();
  screen = new Window();
  app->name = "Calculator";
  screen->shell = make_unique<Shell>(nullptr, nullptr, nullptr);
  screen->frame_cb = Frame;
  screen->width = 420;
  screen->height = 380;
}

extern "C" int MyAppMain(int argc, const char* const* argv) {
  if (app->Create(argc, argv, __FILE__)) return -1;
  if (app->Init()) return -1;
  screen->target_fps = 1;
  my_app = new MyAppState();

  if (!FLAGS_linear_program.empty()) {
    LocalFile lf(FLAGS_linear_program, "r");
    LinearProgram::Solve(&lf, 1);
    return 0;
  }

  app->StartNewWindow(screen);
  return app->Main();
}
