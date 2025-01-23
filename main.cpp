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
    QVariantList batchPoints;
    for (int i = 0; i < 100; ++i) {  // Simulating a full sensor sweep
      QVariantMap point;
      point["angle"] = std::rand() % 360;
      point["distance"] = static_cast<double>(std::rand()) / RAND_MAX;
      batchPoints.append(point);
    }
    model.SetPoints(batchPoints);
  });
  timer.start(2000);
  return app.exec();
}
