#include <QtQuick/QQuickView>
#include <QtWidgets/QApplication>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  auto viewer = std::make_unique<QQuickView>();
  viewer->setSource(QUrl("qrc:/main.qml"));
  // or...  it can be QUrl::fromLocalFile("../main.qml")
  viewer->show();
  return app.exec();
}
