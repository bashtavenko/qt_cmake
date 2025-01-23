#include "plot_data_model.h"

void PlotDataModel::setPoint(const QVariantMap& point) {
  if (point_ != point) {
    point_ = point;
    emit pointChanged();
  }
}