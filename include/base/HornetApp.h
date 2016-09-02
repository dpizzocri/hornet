#ifndef HORNETAPP_H
#define HORNETAPP_H

#include "MooseApp.h"

class HornetApp;

template<>
InputParameters validParams<HornetApp>();

class HornetApp : public MooseApp
{
public:
  HornetApp(InputParameters parameters);
  virtual ~HornetApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* HORNETAPP_H */
