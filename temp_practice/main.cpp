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
