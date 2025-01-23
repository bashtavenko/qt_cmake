#ifndef QT_CMAKE__PLOT_DATA_MODEL_H_
#define QT_CMAKE__PLOT_DATA_MODEL_H_

#include <QtQml/QQmlContext>
#include <limits>

class PlotDataModel : public QObject {
  Q_OBJECT
  Q_PROPERTY(QVariantMap point READ point WRITE setPoint NOTIFY pointChanged)

 public:
  explicit PlotDataModel(QObject* parent = nullptr) : QObject(parent) {
    point_["angle"] = std::numeric_limits<float>::max();
    point_["distance"] = std::numeric_limits<float>::max();
  }

  QVariantMap point() const { return point_; }

 public slots:
  void setPoint(const QVariantMap& point);

 signals:
  void pointChanged();

 private:
  QVariantMap point_;
};

#endif  // QT_CMAKE__PLOT_DATA_MODEL_H_
