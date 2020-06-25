#pragma once

#include <string_view>

#include "lnast.hpp"

class Semantic_pass {
private:
protected:

  std::vector<std::string_view> temp_list;

  bool is_primitive_op(const Lnast_ntype node_type);
  bool is_tree_structs(const Lnast_ntype node_type);
  bool is_temp_var(std::string_view node_name);
  bool in_temp_list(std::string_view node_name);
  void check_for_temp_var(std::string_view node_name);
  void check_primitive_ops(Lnast* lnast, const Lnast_nid &lnidx_opr, const Lnast_ntype node_type);
  void check_if_op(Lnast* lnast, const Lnast_nid &lnidx_opr);
  void check_for_op(Lnast* lnast, const Lnast_nid &lnidx_opr);
  void check_while_op(Lnast* lnast, const Lnast_nid &lnidx_opr);
  void check_func_def(Lnast* lnast, const Lnast_nid &lnidx_opr);
  void check_func_call(Lnast* lnast, const Lnast_nid &lnidx_opr);

public:
  // NOTE: Only tuple operations implemented are for tuple assignment and tuple concatenation
  void semantic_check(Lnast* lnast);
};