#include "InteractMemberVariable.h"

InteractMemberVariable::InteractMemberVariable(QObject *parent) : QObject(parent)
{

}

QString InteractMemberVariable::getMyStringByInvokable()
{
    qDebug() << "Q_INVOKABLE getMyString()" << m_string;
    return m_string;
}

void InteractMemberVariable::setMyStringByInvokable(QString aString)
{
    if(m_string!=aString)
    {
        m_string = aString;
        qDebug() << "Q_INVOKABLE setmyString(QString aString)" << m_string;
        emit myStringChanged();          // 发送值改变信号
    }
}

void InteractMemberVariable::setmyString(QString aString)
{
    if(m_string!=aString)
    {
        m_string = aString;
        qDebug() << "slots setmyString(QString aString)" << m_string;
        emit myStringChanged();          // 发送值改变信号
    }
}

QString InteractMemberVariable::myString()
{
    qDebug() << "slots myString()" << m_string;
    return m_string;
}
