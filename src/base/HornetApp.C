#include "HornetApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<HornetApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

HornetApp::HornetApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  HornetApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  HornetApp::associateSyntax(_syntax, _action_factory);
}

HornetApp::~HornetApp()
{
}

// External entry point for dynamic application loading
extern "C" void HornetApp__registerApps() { HornetApp::registerApps(); }
void
HornetApp::registerApps()
{
  registerApp(HornetApp);
}

// External entry point for dynamic object registration
extern "C" void HornetApp__registerObjects(Factory & factory) { HornetApp::registerObjects(factory); }
void
HornetApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void HornetApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { HornetApp::associateSyntax(syntax, action_factory); }
void
HornetApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
