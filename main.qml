import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import TableModel 1.0
import QtQuick.Window 2.11
import QtQml 2.10
Window {
    id: win
    width: 700
    height: 600
    visible: true
    maximumWidth: width
    minimumWidth: width
    maximumHeight: height
    minimumHeight: height
    title: qsTr("Find the amount")
    Flow{
        id :layout
        anchors.fill: parent
        Tableview {
            id :tabview
           height: win.height
           width: height
           model:Tablemodel
           {
               id: tabmodel

           }
        }
        Label
    {
        height:win.height
        width:100
        text:tabmodel.meaning1 + "+ 0 = "+tabmodel.sum;
        font.pointSize:10

    }
    }
}
