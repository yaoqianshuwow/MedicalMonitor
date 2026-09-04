#pragma once

#include <QColor>
#include <QWidget>

class QLabel;

class VitalCard final : public QWidget
{
    Q_OBJECT

public:
    explicit VitalCard(const QString &title, const QString &unit,
                       const QColor &color, QWidget *parent = nullptr);
    void setValue(const QString &value);
    void setSecondaryText(const QString &text);

private:
    QLabel *m_valueLabel = nullptr;
    QLabel *m_secondaryLabel = nullptr;
};
