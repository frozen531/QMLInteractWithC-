import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Item {
    visible: true
    width: 640
    height: 480
//    title: qsTr("暴露Qt C++的对象或类型给QML")   // Item没有title属性

    Column{
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.topMargin: 10
        anchors.leftMargin: 10

        spacing: 10

        Label {                                // 使用 slots函数 将c++传入.text显示控件
            id: slotsLabel;
            height: 50
            color: "#FF0000"
            text: "slotsLabel"                  // 必须加上文本才会有大小，否则不占地方，排列位置有误
            font.pixelSize: 26;
        }

        Label {                                // 使用 Q_INVOKABLE函数 将c++传入.text显示控件
            id: inovkableLabel;
            height: 50
            color: "#FF0000"
            text: "inovkableLabel"
            font.pixelSize: 26;
        }

        Button{
            id:displayValue;
            text: "display_m_string";
            height: 50
            onClicked: {                    // 点击按钮发送数据到.text
                inovkableLabel.text = interactMemberVariable.getMyStringByInvokable();    // 使用 Q_INVOKABLE函数 函数名后面要加括号  1#
                slotsLabel.text = interactMemberVariable.myString;             // 使用 slots函数 函数名后面没有括号  1#
            }
        }

        Button{
            id:changeValueBySlots;
            text: "change_m_stringBySlots";
            height: 50
            onClicked: {                    // 点击按钮 改变m_string的值
                interactMemberVariable.setmyString("second")                   // 1#
            }
        }

        Button{
            id:changeValueByInvokable;
            text: "change_m_stringByInvokable";
            height: 50
            onClicked: {                    // 点击按钮 改变m_string的值
                interactMemberVariable.setMyStringByInvokable("third")           // 1#
            }
        }
    }
}
