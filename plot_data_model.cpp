#include "plot_data_model.h"

void PlotDataModel::SetPoints(const QVariantList& points) {
  points_ = points;
  emit PointsChanged();
}