// This file is distributed under the BSD 3-Clause License. See LICENSE for details.
#pragma once
#include <mutex>
#include <vector>

#include "lgedgeiter.hpp"
#include "lgraph.hpp"
#include "lbench.hpp"
#include "lnast.hpp"
#include "likely.hpp"

class Lcompiler {
private:
  const std::string_view path;  
  const std::string odir;
  const bool gviz;

protected:
  std::mutex lgs_mutex;
  std::vector<LGraph *> lgs;

  void compile_thread(std::shared_ptr<Lnast> ln);
  void compile_thread(std::string_view file); // future allow to call inou.pyrope or inou.verilog or comp error
  void add_thread(std::shared_ptr<Lnast> lnast);

public:
  Lcompiler(std::string_view path, std::string_view odir, bool gviz);

  void add(std::shared_ptr<Lnast> lnast);
  /* void add(std::string_view file); */

  std::vector<LGraph *> wait_all();
};
