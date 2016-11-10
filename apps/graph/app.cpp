#include "app.h"
#include "graph_icon.h"

namespace Graph {

App::App(Container * container, Context * context) :
  ::App(container, &m_inputViewController, "Graph", ImageStore::GraphIcon),
  ExpressionTextFieldDelegate(),
  m_functionStore(FunctionStore()),
  m_evaluateContext(EvaluateContext(context)),
  m_listController(ListController(nullptr, &m_functionStore)),
  m_listStackViewController(StackViewController(&m_tabViewController, &m_listController)),
  m_graphController(GraphController(nullptr, &m_functionStore)),
  m_valuesController(nullptr, &m_functionStore),
  m_valuesStackViewController(StackViewController(&m_tabViewController, &m_valuesController)),
  m_tabViewController(&m_inputViewController, &m_listStackViewController, &m_graphController, &m_valuesStackViewController),
  m_inputViewController(&m_modalViewController, &m_tabViewController, this)
{
}

InputViewController * App::inputViewController() {
  return &m_inputViewController;
}

Context * App::evaluateContext() {
  return &m_evaluateContext;
}

}
