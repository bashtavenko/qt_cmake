#ifndef QT_CMAKE__PLOT_DATA_MODEL_H_
#define QT_CMAKE__PLOT_DATA_MODEL_H_

#include <QtQml/QQmlContext>

class PlotDataModel : public QObject {
  Q_OBJECT
  Q_PROPERTY(
      QVariantList points READ Points WRITE SetPoints NOTIFY PointsChanged)

 public:
  explicit PlotDataModel(QObject* parent = nullptr) : QObject(parent) {}

  QVariantList Points() const { return points_; }

 public slots:
  void SetPoints(const QVariantList& point);

 signals:
  void PointsChanged();

 private:
  QVariantList points_;
};

#endif  // QT_CMAKE__PLOT_DATA_MODEL_H_
