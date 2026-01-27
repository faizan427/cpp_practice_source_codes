    visible: true
    title: qsTr("Hello World")
  Rectangle
  {
    id:my_rect
    anchors.centerIn: parent
    width: parent.width/4
    height: parent.height/4
    radius: width/2
    gradient: Gradient
    {
        GradientStop{position: 0.4; color: "red"}
        GradientStop{position: 0.1; color: "cyan"}
        GradientStop{position: 0.5; color: "green"}
    }
  }
}
