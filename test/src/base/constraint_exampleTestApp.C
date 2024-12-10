//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "constraint_exampleTestApp.h"
#include "constraint_exampleApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
constraint_exampleTestApp::validParams()
{
  InputParameters params = constraint_exampleApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

constraint_exampleTestApp::constraint_exampleTestApp(InputParameters parameters) : MooseApp(parameters)
{
  constraint_exampleTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

constraint_exampleTestApp::~constraint_exampleTestApp() {}

void
constraint_exampleTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  constraint_exampleApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"constraint_exampleTestApp"});
    Registry::registerActionsTo(af, {"constraint_exampleTestApp"});
  }
}

void
constraint_exampleTestApp::registerApps()
{
  registerApp(constraint_exampleApp);
  registerApp(constraint_exampleTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
constraint_exampleTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  constraint_exampleTestApp::registerAll(f, af, s);
}
extern "C" void
constraint_exampleTestApp__registerApps()
{
  constraint_exampleTestApp::registerApps();
}
