/*
 * 暴露Qt C++的对象或类型给QML
*/

#ifndef InteractMemberVariable_H
#define InteractMemberVariable_H

#include <QObject>
#include <QDebug>

class InteractMemberVariable : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString myString READ myString WRITE setmyString NOTIFY myStringChanged) // 1# myString可与外交互的变量
public:
    explicit InteractMemberVariable(QObject *parent = nullptr);

    Q_INVOKABLE QString getMyStringByInvokable(); // 2# 可被qml直接调用的函数
    Q_INVOKABLE void setMyStringByInvokable(QString aString); // 2# 可被qml直接调用的函数

signals:
    void myStringChanged();             // 1# myString值改变的信号函数，值改变触发的信号text.text = "按下按钮，m_string值改变"
    void labelDisplay();              // 这个函数的功能是按钮显示m_string，触发text.text = "m_string值显示"

public slots:  // 2# 可被qml直接调用的函数
    void setmyString(QString aString);  // 1# myString从qml传入 的槽函数
    QString myString();                 // 1# myString从c++传出 的槽函数

private:
    QString m_string = "first";
};

#endif // InteractMemberVariable_H
