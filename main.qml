import QtQuick 2.15
import QtCharts 2.15

Item {
    width: 800
    height: 600

    PolarChartView {
        id: chart
        title: "Lidar Scan Data"
        anchors.fill: parent
        legend.visible: false
        antialiasing: true

        ValueAxis {
            id: axisAngular
            min: 0
            max: 360
            tickCount: 9
        }

        ValueAxis {
            id: axisRadial
            min: 0
            max: 1
            labelFormat: "%.1f"
        }

        ScatterSeries {
            id: lidarSeries
            axisAngular: axisAngular
            axisRadial: axisRadial
            markerSize: 10
        }

        Component.onCompleted: {
            lidarSeries.append(scanData.point.angle, scanData.point.distance);
        }
        Connections {
            target: scanData
            function onPointChanged() {
                // lidarSeries.clear();
                lidarSeries.append(scanData.point.angle, scanData.point.distance);
            }
        }

    }
}
