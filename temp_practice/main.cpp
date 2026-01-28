import com.company.test 1.0
Window {
    id:my_root
    width: 600
    height: 400
    title: "main_window"
    visible: true
    color: "blue"
    Best
    {
        id: my_instance
    }
    Column
    {
        anchors.centerIn: parent
        Rectangle {
            id: item_1
            height: 65
            width: 200


        Text {
            id: name_1
            text: qsTr("Response")
            anchors.centerIn: item_1
        }
        }
   Rectangle
   {
    id: my_rect
   // anchors.centerIn: parent
    height: 65
    width: 100
    color: "gray"
    x: 50
    Component.onCompleted:
    {
    print("created")}

    Text {
        anchors.centerIn: parent
        id: name
        text: qsTr("Click me")


    }
    MouseArea
    {
        anchors.fill: parent
        onClicked: name_1.text = my_instance.meow() ;
    }
   }
   }








}
