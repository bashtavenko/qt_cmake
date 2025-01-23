#include <QtCore/QTimer>
#include <QtQuick/QQuickView>
#include <QtWidgets/QApplication>
#include "plot_data_model.h"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);
  auto viewer = std::make_unique<QQuickView>();
  PlotDataModel model;
  viewer->rootContext()->setContextProperty("scanData", &model);
  viewer->setSource(QUrl("qrc:/main.qml"));
  viewer->show();

  QTimer timer;
  QObject::connect(&timer, &QTimer::timeout, [&]() {
    QVariantMap new_point;
    new_point["angle"] = static_cast<double>(std::rand() % 360);
    new_point["distance"] = 0.4;
    model.setPoint(new_point);
  });
  timer.start(1000);
  return app.exec();
}
