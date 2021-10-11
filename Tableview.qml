import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Window 2.11
import QtQml 2.10
TableView {
    property string name:"Tableview"
    columnSpacing: 1
    rowSpacing: 1
    clip: true

    delegate:Component
    { Rectangle
        {
        id:tabdelegate
        implicitWidth:29
        implicitHeight:29
        border.width: 1
        Text {
            text: display
            anchors.centerIn: parent
            id : deltext
            font.pointSize: tabmodel.Font

        }
       Connections
       {
           target: tabmodel
           onAnim_start:
           {
               if(t_row==row&&t_column==column)
               {
                   start_animation.start();
               }
           }
       }
       Connections
       {
           target: tabmodel
           onAnim_end:
           {
               if(t_row==row&&t_column==column)
               {
                   end_animation.start();
               }
           }
       }
        NumberAnimation
                    {

                        id:start_animation
                        target: deltext
                        properties: "font.pointSize"
                        from: 1
                        to: tabmodel.Font
                        duration: 500
                        running: false
                      }
        PropertyAnimation
                    {

                        id:end_animation
                        target: deltext
                        properties: "font.pointSize"
                        from:tabmodel.Font
                        to: 1
                        duration: 150
                        running: false
                      }
        MouseArea
        {
            anchors.fill: parent
            onClicked:
            {
                tabmodel.onCurrentChanged(row,column);
            }
        }
    }
}
}
