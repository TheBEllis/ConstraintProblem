#include "constraint_exampleApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
constraint_exampleApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

constraint_exampleApp::constraint_exampleApp(InputParameters parameters) : MooseApp(parameters)
{
  constraint_exampleApp::registerAll(_factory, _action_factory, _syntax);
}

constraint_exampleApp::~constraint_exampleApp() {}

void
constraint_exampleApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<constraint_exampleApp>(f, af, s);
  Registry::registerObjectsTo(f, {"constraint_exampleApp"});
  Registry::registerActionsTo(af, {"constraint_exampleApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
constraint_exampleApp::registerApps()
{
  registerApp(constraint_exampleApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
constraint_exampleApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  constraint_exampleApp::registerAll(f, af, s);
}
extern "C" void
constraint_exampleApp__registerApps()
{
  constraint_exampleApp::registerApps();
}
