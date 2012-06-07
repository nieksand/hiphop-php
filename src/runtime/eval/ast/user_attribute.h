/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010- Facebook, Inc. (http://www.facebook.com)         |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/

#ifndef __EVAL_USER_ATTRIBUTE_H__
#define __EVAL_USER_ATTRIBUTE_H__

#include <runtime/eval/ast/expression.h>

namespace HPHP {
namespace Eval {
///////////////////////////////////////////////////////////////////////////////

DECLARE_AST_PTR(UserAttribute);

class UserAttribute : public Expression {
public:
  UserAttribute(EXPRESSION_ARGS, const std::string &name, ExpressionPtr exp);
  virtual Expression *optimize(VariableEnvironment &env);
  virtual Variant eval(VariableEnvironment &env) const;
  virtual bool evalStaticScalar(VariableEnvironment &env, Variant &r) const;
  virtual void dump(std::ostream &out) const;
  const std::string& getName() const { return m_name; }
  ExpressionPtr getExp() const { return m_exp; }
private:
  std::string m_name;
  ExpressionPtr m_exp;
};

///////////////////////////////////////////////////////////////////////////////
}
}

#endif /* __EVAL_USER_ATTRIBUTE_H__ */